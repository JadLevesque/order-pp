# ifndef ORDER_EXAMPLE_ENUM_HPP_VAJK20041119
# define ORDER_EXAMPLE_ENUM_HPP_VAJK20041119

// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

# include <string>
# include <stdexcept>

# include "order/interpreter.h"

// ## Enumerations with a Textual Presentation
//
// In this example we will implement a macro for defining enumerated
// types. The C++-language inherited the `enum'-construct from C
// practically without extensions. The `enum'-construct is a fairly
// low level feature that goes well with the spirit of C. I assume
// that the reader is familiar with the syntax, semantics and
// pragmatics (use) of `enum'.
//
// One of the most commonly desired extensions to `enum' would be to
// allow conversion from a string to an enumerator and vice versa.
// In his article \emph{Generic Printable ENUM++}, Mitch Besser
// introduced a set of macros named `ENUM_<n>' for defining
// enumerated types with a textual presentation \cite{besser:2003}.
// The `ENUM_<n>'-macros offered several features beyond `enum', but
// the design and implementation of the macros also left much to be
// desired. Incidentally, Besser's original implementation relied on
// bugs in the compiler used for testing the macros. However, the
// most obvious annoyance was the need to specify the number of
// enumerators to the macro. The implementation was also highly
// repetitive requiring $O(n^2)$ characters of source code to
// support enumerations with up to $n$ enumerators.\footnote{In
// general, one of the main points of C preprocessor metaprogramming
// facilities like the Order-interpreter and the Boost Preprocessor
// -library is to eliminate the need to write repetitive macros. If
// you implement a non-trivial macro with the aid of some Cpp
// metaprogramming facility, and your macro implementation is highly
// repetitive then something is wrong.} In this example we implement
// a somewhat simpler `ENUM'-macro and leave it as a set of
// exercises to the reader to implement further extensions.
//
// ### Goal
//
// What we want is a macro
//<
//   ENUM(<name>, (<enumerator-1>) ... (<enumerator-N>));
//>
// that generates an `enum'
//<
//   enum <name> {<enumerator-1>, ..., <enumerator-N>};
//>
// along with a couple of useful functions
//<
//   <name>      to_<name>(const string& identifier);
//   const char* to_string(<name> value);
//>
// For example, given the definition
//<
//   ENUM(opt_type, (opt_for_time)
//                  (opt_for_space)
//                  (opt_for_both))
//>
// we would have the `enum'
//<
//   enum opt_type { opt_for_time,
//                   opt_for_space,
//                   opt_for_both };
//>
// as well as the functions
//<
//   opt_type    to_opt_type(const string& identifier);
//   const char* to_string(opt_type value);
//>
// with the properties
//<
//   to_opt_type("opt_for_time" ) == opt_for_time
//   to_opt_type("opt_for_space") == opt_for_space
//   to_opt_type("opt_for_both" ) == opt_for_both
//   to_opt_type(  <otherwise>  ) => runtime_exception
//
//   to_string(opt_for_time ) == string("opt_for_time")
//   to_string(opt_for_space) == string("opt_for_space")
//   to_string(opt_for_both ) == string("opt_for_both")
//   to_string( <otherwise> ) => runtime_exception
//>
// Of course, many other kind of features could be desired in
// specific circumstances.
//
// ### Auxiliary Data and Functions
//
// In order to be able to convert between the (integral) values and
// (textual) identifiers of enumerators, we need to build some
// representation of the association between them. In this example,
// we build a simple array of `enum_entry'-structures. An
// `enum_entry' is a simple structure that has two fields: `value'
// and `identifier'.
//<
namespace detail {
  struct enum_entry {
    unsigned long value;
    const char* identifier;
  };
}
//>
// Given a range of entries and the identifier (string) of an
// enumerator, we can now find the value of the enumerator using the
// following linear algorithm:
//<
namespace detail {
  inline unsigned long to_value(const std::string& identifier,
                                const enum_entry* begin,
                                const enum_entry* end) {
    while (begin != end)
      if (begin->identifier == identifier)
        return begin->value;
      else
        ++begin;

    throw std::runtime_error("Unknown enum identifier.");
  }
}
//>
// A linear algorithm may be a bit disappointing, but it is not very
// common to have enumerations with hundreds of enumerators. So, the
// inefficiency of the search algorithm is unlikely to be very
// important.
//
// The same range of entries can also be used to find the identifier
// corresponding to the value of an enumerator using a similar
// linear algorithm:
//<
namespace detail {
  inline const char* to_string(unsigned long value,
                               const enum_entry* begin,
                               const enum_entry* end) {
    while (begin != end)
      if (begin->value == value)
        return begin->identifier;
      else
        ++begin;

    throw std::runtime_error("Unknown enum value.");
  }
}
//>
// In certain fairly common cases, the conversion from the value of
// an enumerator to the identifier of the enumerator could easily be
// done in $O(1)$ time. An uncommon special case is when we know
// that the values of the enumerators are consecutive. We leave it
// as an exercise to the reader to implement such an optimization.
//
// ### Implementation of the `ENUM'-macro
//
//
//<
#define ENUM(name, rators)                                      \
enum name                                                       \
{ ORDER_PP(8seq_for_each_with_delimiter                         \
           (8fn(8X,                                             \
                8if(8equal(1, 8tuple_size(8X)),                 \
                    8put_open(8X),                              \
                    8print(8tuple_at_0(8X) (=)                  \
                           8open(8tuple_drop_1(8X))))),         \
            8emit_comma,                                        \
            8vseq_to_seq_of_tuples(8(rators)))) };              \
                                                                \
const detail::enum_entry ORDER_PP_FRESH_ID(name)[] =            \
{ ORDER_PP(8seq_for_each_with_delimiter                         \
           (8fn(8I,                                             \
                8print(({) 8I (,) 8stringize(8I) (}))),         \
            8emit_comma,                                        \
            8seq_map(8tuple_at_0,                               \
                     8vseq_to_seq_of_tuples(8(rators))))) };    \
                                                                \
inline const char* to_string(name value) {                      \
  return detail::to_string(static_cast<unsigned long>(value),   \
                           ORDER_PP_FRESH_ID(name),             \
                           ORDER_PP_FRESH_ID(name) +            \
                           sizeof(ORDER_PP_FRESH_ID(name)) /    \
                           sizeof(*ORDER_PP_FRESH_ID(name)));   \
}                                                               \
                                                                \
inline name to_##name(const std::string& identifier) {          \
  return static_cast<name>(detail::to_value                     \
                           (identifier,                         \
                            ORDER_PP_FRESH_ID(name),            \
                            ORDER_PP_FRESH_ID(name) +           \
                            sizeof(ORDER_PP_FRESH_ID(name)) /   \
                            sizeof(*ORDER_PP_FRESH_ID(name)))); \
}
//>

# endif
