// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_DEF_8vseq_to_seq_of_tuples ORDER_PP_FN_NATIVE(1,9VSEQ_TO_SEQ_OF_TUPLES)
#define ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_A P##s)
#define ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_A(...) ((__VA_ARGS__))ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_B
#define ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_A0
#define ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_B(...) ((__VA_ARGS__))ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_A
#define ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES_B0

#define ORDER_PP_DEF_8seq_append ORDER_PP_OP_LEFT_NATIVE(9SEQ_JOIN)

#define ORDER_PP_DEF_8seq_at ORDER_PP_FN_NATIVE(2,9SEQ_AT)
#define ORDER_PP_9SEQ_AT(P,i,s) ORDER_PP_FY(SEQ_AT,(,0,ORDER_PP_9SEQ_REST_N(,P##i,P##s)))

#define ORDER_PP_DEF_8seq_first ORDER_PP_FN_CM(1,8SEQ_FIRST)
#define ORDER_PP_8SEQ_FIRST(P,s,...) (,ORDER_PP_SEQ_AT(,0,P##s),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_first_n ORDER_PP_FN_NATIVE(2,9SEQ_FIRST_N)
#define ORDER_PP_9SEQ_FIRST_N(P,n,s) ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_SEQ_SPLIT_AT(,P##n,P##s),))()

#define ORDER_PP_DEF_8seq_iota ORDER_PP_FN_NATIVE(2,9SEQ_IOTA)
#define ORDER_PP_9SEQ_IOTA(P,i0,i1) ORDER_PP_FX(PM,ORDER_PP_8FOR_EACH_IN_RANGE(,(,8PUT_PARENTHESIZED),P##i1,P##i0,8STOP,))
#define ORDER_PP_8PUT_PARENTHESIZED(P,x,K,...) ORDER_PP_##K(,,P##__VA_ARGS__)(P##x)

#define ORDER_PP_DEF_8seq_is_nil ORDER_PP_FN_CM(1,8SEQ_IS_NIL)
#define ORDER_PP_8SEQ_IS_NIL(P,s,...) (,ORDER_PP_TEST(,ORDER_PP_IS_EDIBLE_TEST P##s,8false,8true),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_isnt_nil ORDER_PP_FN_CM(1,8SEQ_ISNT_NIL)
#define ORDER_PP_8SEQ_ISNT_NIL(P,s,...) (,ORDER_PP_TEST(,ORDER_PP_IS_EDIBLE_TEST P##s,8true,8false),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_join ORDER_PP_FN_NATIVE(2,9SEQ_JOIN)
#define ORDER_PP_9SEQ_JOIN(P,l,r) ORDER_PP_LEFT(,l##P)P##r

#define ORDER_PP_DEF_8seq_last ORDER_PP_FN_CM(1,8SEQ_LAST)
#define ORDER_PP_8SEQ_LAST(P,s,...) (,ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_FX(SEQ_SPLIT_LAST_SWAP_A,ORDER_PP_FX(SEQ_SPLIT_LAST_SHIFT,ORDER_PP_SEQ_TO_PSEQ(,P##s))(0,)),)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_map_seq ORDER_PP_FN_NATIVE(1,9VSEQ_TO_SEQ_OF_TUPLES)

#define ORDER_PP_DEF_8seq_nil 8DEF_CONST,,

#define ORDER_PP_DEF_8seq_pop_at ORDER_PP_FN_NATIVE(2,9SEQ_POP_AT)
#define ORDER_PP_9SEQ_POP_AT(P,i,s) ORDER_PP_FX(SEQ_POP_AT_B,(,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s)))
#define ORDER_PP_SEQ_POP_AT_B(P,l,r) l##P r##P

#define ORDER_PP_DEF_8seq_pop_back ORDER_PP_FN_CM(1,8SEQ_POP_BACK)
#define ORDER_PP_8SEQ_POP_BACK(P,s,...) (,ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_FX(SEQ_SPLIT_LAST_SWAP_A,ORDER_PP_FX(SEQ_SPLIT_LAST_SHIFT,ORDER_PP_SEQ_TO_PSEQ(,P##s))(0,)))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_pop_front ORDER_PP_FN_CM(1,8SEQ_REST)

#define ORDER_PP_DEF_8seq_pop_range ORDER_PP_FN_NATIVE(3,9SEQ_POP_RANGE)
#define ORDER_PP_9SEQ_POP_RANGE(P,i,n,s) ORDER_PP_FX(9SEQ_POP_RANGE_B,(,P##n,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s)))
#define ORDER_PP_9SEQ_POP_RANGE_B(P,n,l,r) P##l()ORDER_PP_FY(TUPLE_AT_1,(,ORDER_PP_SEQ_SPLIT_AT(,P##n,P##r),))

#define ORDER_PP_DEF_8seq_push_at ORDER_PP_FN_NATIVE(3,9SEQ_PUSH_AT)
#define ORDER_PP_9SEQ_PUSH_AT(P,i,s,x) ORDER_PP_FX(SEQ_PUSH_AT_B,(,P##x,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),))
#define ORDER_PP_SEQ_PUSH_AT_B(P,x,l,r,...) l##P()(P##x)P##r

#define ORDER_PP_DEF_8seq_push_back ORDER_PP_FN_NATIVE(2,9SEQ_PUSH_BACK)
#define ORDER_PP_9SEQ_PUSH_BACK(P,x,s) P##s(P##x)

#define ORDER_PP_DEF_8seq_push_front ORDER_PP_FN_NATIVE(2,9SEQ_PUSH_FRONT)
#define ORDER_PP_9SEQ_PUSH_FRONT(P,x,s) (P##x)P##s

#define ORDER_PP_DEF_8seq_push_range ORDER_PP_FN_NATIVE(3,9SEQ_PUSH_RANGE)
#define ORDER_PP_9SEQ_PUSH_RANGE(P,i,s,ss) ORDER_PP_FX(9SEQ_PUSH_RANGE_B,(,P##ss,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s)))
#define ORDER_PP_9SEQ_PUSH_RANGE_B(P,ss,l,r) P##l()ORDER_PP_LEFT(,ss##P)P##r

#define ORDER_PP_DEF_8seq_range ORDER_PP_FN_NATIVE(3,9SEQ_RANGE)
#define ORDER_PP_9SEQ_RANGE(P,i,n,s) ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_FX(SEQ_SPLIT_AT,(,P##n,ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),)))),))()

#define ORDER_PP_DEF_8seq_rest ORDER_PP_FN_CM(1,8SEQ_REST)
#define ORDER_PP_8SEQ_REST(P,s,...) (,ORDER_PP_EAT P##s,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_rest_n ORDER_PP_FN_NATIVE(2,9SEQ_REST_N)
#define ORDER_PP_9SEQ_REST_N(P,n,s) ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_SEQ_SPLIT_AT(,P##n,P##s),))

#define ORDER_PP_DEF_8seq_reverse ORDER_PP_FN_NATIVE(1,9SEQ_REVERSE)
#define ORDER_PP_9SEQ_REVERSE(P,s) ORDER_PP_FX(PSEQ_TO_SEQ,(,ORDER_PP_FX(PSEQ_REVERSE,(,ORDER_PP_SEQ_TO_PSEQ(,P##s)))))
#define ORDER_PP_PSEQ_REVERSE(P,s) ORDER_PP_PM(,ORDER_PP_SEQ_REV_PAIR_A P##s(0,),8SEQ_REV_EXIT,)

#define ORDER_PP_8SEQ_REV_PAIR(P,s,...) (,ORDER_PP_SEQ_REV_PAIR_A P##s(0,),8SEQ_REV_SWAP,P##__VA_ARGS__)
#define ORDER_PP_SEQ_REV_PAIR_A(P,x) ORDER_PP_SEQ_REV_PAIR_B##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_B(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_C
#define ORDER_PP_SEQ_REV_PAIR_B0(...)
#define ORDER_PP_SEQ_REV_PAIR_C(P,x) ORDER_PP_SEQ_REV_PAIR_D##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_D(P,x) P##x,))ORDER_PP_SEQ_REV_PAIR_E
#define ORDER_PP_SEQ_REV_PAIR_D0(...) ,0))
#define ORDER_PP_SEQ_REV_PAIR_E(P,x) ORDER_PP_SEQ_REV_PAIR_F##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_F(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_G
#define ORDER_PP_SEQ_REV_PAIR_F0(...)
#define ORDER_PP_SEQ_REV_PAIR_G(P,x) ORDER_PP_SEQ_REV_PAIR_H##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_H(P,x) P##x,))ORDER_PP_SEQ_REV_PAIR_I
#define ORDER_PP_SEQ_REV_PAIR_H0(...) ,0)),8SEQ_REV_PAIR
#define ORDER_PP_SEQ_REV_PAIR_I(P,x) ORDER_PP_SEQ_REV_PAIR_J##P(,x##P)
#define ORDER_PP_SEQ_REV_PAIR_J(P,x) (,(,P##x,ORDER_PP_SEQ_REV_PAIR_G
#define ORDER_PP_SEQ_REV_PAIR_J0(...) ,8SEQ_REV_PAIR

#define ORDER_PP_8SEQ_REV_SWAP(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_REV_SWAP_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_REV_EXIT(P,s,...) ,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_REV_SWAP_A P##s))
#define ORDER_PP_SEQ_REV_SWAP_A(P,PxyS) ORDER_PP_SEQ_REV_SWAP_B PxyS##P
#define ORDER_PP_SEQ_REV_SWAP_A0
#define ORDER_PP_SEQ_REV_SWAP_B(P,x,y,S) ORDER_PP_SEQ_REV_SWAP_F##S(,P##y)(,P##x)ORDER_PP_SEQ_REV_SWAP_C
#define ORDER_PP_SEQ_REV_SWAP_C(P,PxyS) ORDER_PP_SEQ_REV_SWAP_D PxyS##P
#define ORDER_PP_SEQ_REV_SWAP_C0
#define ORDER_PP_SEQ_REV_SWAP_D(P,x,y,S) ORDER_PP_SEQ_REV_SWAP_F##S(,P##y)(,P##x)ORDER_PP_SEQ_REV_SWAP_A
#define ORDER_PP_SEQ_REV_SWAP_F
#define ORDER_PP_SEQ_REV_SWAP_F0(...)

#define ORDER_PP_DEF_8seq_set ORDER_PP_FN_NATIVE(3,9SEQ_SET)
#define ORDER_PP_9SEQ_SET(P,i,s,x) ORDER_PP_FX(SEQ_SET_B,(,P##x,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s),))
#define ORDER_PP_SEQ_SET_B(P,x,l,r,...) l##P()(P##x)ORDER_PP_EAT r##P

#define ORDER_PP_DEF_8seq_size ORDER_PP_FN_CM(1,8SEQ_SIZE)
#define ORDER_PP_8SEQ_SIZE(P,s,...) (,ORDER_PP_FX(PSEQ_TO_SEQ,(,ORDER_PP_FX(PSEQ_REVERSE,(,ORDER_PP_PM(,P##s,8SEQ_SIZE_TO_DEC_FIRST,))))),P##__VA_ARGS__)

#define ORDER_PP_8SEQ_SIZE_TO_DEC_FIRST(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_SIZE_A_FIRST P##s)
#define ORDER_PP_SEQ_SIZE_A_FIRST(...) ORDER_PP_SEQ_SIZE_B
#define ORDER_PP_SEQ_SIZE_A_FIRST0 ,8STOP,)(,00)

#define ORDER_PP_8SEQ_SIZE_TO_DEC(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_SIZE_A P##s)
#define ORDER_PP_SEQ_SIZE_A(...) ORDER_PP_SEQ_SIZE_B
#define ORDER_PP_SEQ_SIZE_A0 ,8STOP,)
#define ORDER_PP_SEQ_SIZE_B(...) ORDER_PP_SEQ_SIZE_C
#define ORDER_PP_SEQ_SIZE_B0 ,8STOP,)(,01)
#define ORDER_PP_SEQ_SIZE_C(...) ORDER_PP_SEQ_SIZE_D
#define ORDER_PP_SEQ_SIZE_C0 ,8STOP,)(,02)
#define ORDER_PP_SEQ_SIZE_D(...) ORDER_PP_SEQ_SIZE_E
#define ORDER_PP_SEQ_SIZE_D0 ,8STOP,)(,03)
#define ORDER_PP_SEQ_SIZE_E(...) ORDER_PP_SEQ_SIZE_F
#define ORDER_PP_SEQ_SIZE_E0 ,8STOP,)(,04)
#define ORDER_PP_SEQ_SIZE_F(...) ORDER_PP_SEQ_SIZE_G
#define ORDER_PP_SEQ_SIZE_F0 ,8STOP,)(,05)
#define ORDER_PP_SEQ_SIZE_G(...) ORDER_PP_SEQ_SIZE_H
#define ORDER_PP_SEQ_SIZE_G0 ,8STOP,)(,06)
#define ORDER_PP_SEQ_SIZE_H(...) ORDER_PP_SEQ_SIZE_I
#define ORDER_PP_SEQ_SIZE_H0 ,8STOP,)(,07)
#define ORDER_PP_SEQ_SIZE_I(...) ORDER_PP_SEQ_SIZE_J
#define ORDER_PP_SEQ_SIZE_I0 ,8STOP,)(,08)
#define ORDER_PP_SEQ_SIZE_J(...) ()ORDER_PP_SEQ_SIZE_K
#define ORDER_PP_SEQ_SIZE_J0 ,8STOP,)(,09)

#define ORDER_PP_SEQ_SIZE_K(...) ORDER_PP_SEQ_SIZE_L
#define ORDER_PP_SEQ_SIZE_K0 ,8SEQ_SIZE_TO_DEC,)(,0)
#define ORDER_PP_SEQ_SIZE_L(...) ORDER_PP_SEQ_SIZE_M
#define ORDER_PP_SEQ_SIZE_L0 ,8SEQ_SIZE_TO_DEC,)(,1)
#define ORDER_PP_SEQ_SIZE_M(...) ORDER_PP_SEQ_SIZE_N
#define ORDER_PP_SEQ_SIZE_M0 ,8SEQ_SIZE_TO_DEC,)(,2)
#define ORDER_PP_SEQ_SIZE_N(...) ORDER_PP_SEQ_SIZE_O
#define ORDER_PP_SEQ_SIZE_N0 ,8SEQ_SIZE_TO_DEC,)(,3)
#define ORDER_PP_SEQ_SIZE_O(...) ORDER_PP_SEQ_SIZE_P
#define ORDER_PP_SEQ_SIZE_O0 ,8SEQ_SIZE_TO_DEC,)(,4)
#define ORDER_PP_SEQ_SIZE_P(...) ORDER_PP_SEQ_SIZE_Q
#define ORDER_PP_SEQ_SIZE_P0 ,8SEQ_SIZE_TO_DEC,)(,5)
#define ORDER_PP_SEQ_SIZE_Q(...) ORDER_PP_SEQ_SIZE_R
#define ORDER_PP_SEQ_SIZE_Q0 ,8SEQ_SIZE_TO_DEC,)(,6)
#define ORDER_PP_SEQ_SIZE_R(...) ORDER_PP_SEQ_SIZE_S
#define ORDER_PP_SEQ_SIZE_R0 ,8SEQ_SIZE_TO_DEC,)(,7)
#define ORDER_PP_SEQ_SIZE_S(...) ORDER_PP_SEQ_SIZE_T
#define ORDER_PP_SEQ_SIZE_S0 ,8SEQ_SIZE_TO_DEC,)(,8)
#define ORDER_PP_SEQ_SIZE_T(...) ()ORDER_PP_SEQ_SIZE_K
#define ORDER_PP_SEQ_SIZE_T0 ,8SEQ_SIZE_TO_DEC,)(,9)

#define ORDER_PP_DEF_8seq_split_at ORDER_PP_FN_NATIVE(2,9SEQ_SPLIT_AT)
#define ORDER_PP_9SEQ_SPLIT_AT(P,i,s) (ORDER_PP_FX(9SEQ_SPLIT_AT_B,(,ORDER_PP_SEQ_SPLIT_AT(,P##i,P##s))))
#define ORDER_PP_9SEQ_SPLIT_AT_B(P,l,r) l##P(),r##P

#define ORDER_PP_DEF_8seq_to_tuple ORDER_PP_FN_CM(1,8SEQ_TO_TUPLE)
#define ORDER_PP_8SEQ_TO_TUPLE(P,s,...) (,ORDER_PP_FX(SEQ_TO_TUPLE_TERMINATE,(ORDER_PP_SEQ_TO_TUPLE_A P##s)),P##__VA_ARGS__)
#define ORDER_PP_SEQ_TO_TUPLE_TERMINATE(...) ORDER_PP_SEQ_TO_TUPLE_##__VA_ARGS__##0
#define ORDER_PP_SEQ_TO_TUPLE_ORDER_PP_SEQ_TO_TUPLE_A0
#define ORDER_PP_SEQ_TO_TUPLE_0(P,x) (P##x
#define ORDER_PP_SEQ_TO_TUPLE_A(x) 0(,x)ORDER_PP_SEQ_TO_TUPLE_B
#define ORDER_PP_SEQ_TO_TUPLE_B(x) ORDER_PP_RIGHT(,,x)ORDER_PP_SEQ_TO_TUPLE_C
#define ORDER_PP_SEQ_TO_TUPLE_B0 )
#define ORDER_PP_SEQ_TO_TUPLE_C(x) ORDER_PP_RIGHT(,,x)ORDER_PP_SEQ_TO_TUPLE_B
#define ORDER_PP_SEQ_TO_TUPLE_C0 )

#define ORDER_PP_DEF_8seq_zip ORDER_PP_FN_NATIVE(2,9SEQ_ZIP)
/*
    --- (,a)(,b)(,c)(,d),(,1)(,2)(,3)(,4)
    ==> (,(,a,b,))(,(,c,d,)),(,(,1,2,))(,(,3,4,))
    ==> (,(,(,a,b,),(,c,d,),)),(,(,(,1,2,),(,3,4,),))
    ==> (,(,a,b,))(,(,1,2,))(,(,c,d,))(,(,3,4,))
    ==> (,a)(,1)(,b)(,2)(,c)(,3)(,d)(,4)
    ==> ((a,1))((b,2))((c,3))((d,4))
*/
#define ORDER_PP_9SEQ_ZIP(P,sl,sr)

// Higher-order functions

#define ORDER_PP_DEF_8seq_count ORDER_PP_FN_CM(2,8SEQ_COUNT)
#define ORDER_PP_8SEQ_COUNT(P,f,...) (,(,8SEQ_COUNT_F,P##f),8SEQ_FOLD,0,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_COUNT_F(P,n,f,...) (,(,ORDER_PP_OPEN f##P,8SEQ_COUNT_G,P##n),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_COUNT_G(P,b,n,...) (,ORDER_PP_IF_##b(ORDER_PP_,NUM_UOP,TUPLE_REST)(,INC,P##n),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_exists ORDER_PP_FN_CM(2,8SEQ_EXISTS)
#define ORDER_PP_8SEQ_EXISTS(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,8false,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_EXISTS_4,P##f,ORDER_PP_SEQ_AT_1 P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_EXISTS_4(P,b,f,x,xs,...) (,ORDER_PP_SELECT_4(ORDER_PP_,IF_##b,SEQ_IS_NIL(,P##xs))(,8true,8true,ORDER_PP_LEFT(,P##x,ORDER_PP_OPEN f##P),P##x,ORDER_PP_OPEN f##P,8SEQ_EXISTS_4,P##f,ORDER_PP_SEQ_AT_0 P##xs),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_filter ORDER_PP_FN_CM(2,8SEQ_FILTER)
#define ORDER_PP_8SEQ_FILTER(P,f,s,...) (,0,8SEQ_FILTER_O,,P##f,ORDER_PP_EAT,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FILTER_O(P,b0,x0,f,out,b,x,...) (,ORDER_PP_WHEN_##b(,P##x,ORDER_PP_OPEN f##P,8SEQ_FILTER_O,P##x,P##f,)P##out ORDER_PP_WHEN_##b0(,())(P##x0)ORDER_PP_EAT ORDER_PP_UNLESS_##b(,()),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_fold ORDER_PP_FN_CM(3,8SEQ_FOLD)
#define ORDER_PP_8SEQ_FOLD(P,f,x,s,...) (,P##x,8SEQ_FOLD_O,P##f,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOLD_O(P,y,f,b,x,...) (,P##y,ORDER_PP_WHEN_##b(,ORDER_PP_OPEN f##P,8AP,P##x,8SEQ_FOLD_O,P##f,)P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_all ORDER_PP_FN_CM(2,8SEQ_FOR_ALL)
#define ORDER_PP_8SEQ_FOR_ALL(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,8true,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_FOR_ALL_4,P##f,ORDER_PP_SEQ_AT_1 P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_ALL_4(P,b,f,x,xs,...) (,ORDER_PP_IF_NOT_##b(,8false,P##x,ORDER_PP_OPEN f##P ORDER_PP_SEQ_IS_NIL(,P##xs)(,,,8SEQ_FOR_ALL_4,P##f,ORDER_PP_SEQ_AT_0 P##xs)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each ORDER_PP_FN_CM(2,8SEQ_FOR_EACH)
#define ORDER_PP_8SEQ_FOR_EACH(P,f,s,...) (,,8SEQ_FOR_EACH_O,P##f,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_EACH_O(P,_,f,b,x,...) (,ORDER_PP_WHEN_##b(,P##x,ORDER_PP_OPEN P##f,8SEQ_FOR_EACH_O,P##f),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each_in_product ORDER_PP_FN_CM(2,8SEQ_FOR_EACH_IN_PRODUCT)
#define ORDER_PP_8SEQ_FOR_EACH_IN_PRODUCT(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,,8SEQ_FOR_EACH_O,(,ORDER_PP_OPEN f##P,8SEQ_FOR_EACH_IN_PRODUCT,ORDER_PP_EAT s##P),ORDER_PP_FX(SEQ_OPEN,(,ORDER_PP_SEQ_AT(,0,P##s)))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each_with_idx ORDER_PP_FN_CM(3,8SEQ_FOR_EACH_WITH_IDX)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_IDX(P,f,i,s,...) (,,ORDER_PP_IS_EDIBLE(,P##i)(8SEQ_FOR_EACH_WITH_IDX_,NAT,LIT),P##i,P##f,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_IDX_LIT(P,_,i,f,b,x,...) (,ORDER_PP_WHEN_##b(,P##i,ORDER_PP_OPEN f##P,8AP,P##x,ORDER_PP_TEST(8SEQ_FOR_EACH_WITH_IDX_,ORDER_PP_SYM_100_##i(,),NAT,LIT),ORDER_PP_LIT_INC_##i,P##f),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_IDX_NAT(P,_,i,f,b,x,...) (,ORDER_PP_WHEN_##b(,P##i,ORDER_PP_OPEN f##P,8AP,P##x,8SEQ_FOR_EACH_WITH_IDX_NAT,ORDER_PP_NAT_SUCC P##i,P##f),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_for_each_with_delimiter ORDER_PP_FN_CM(3,8SEQ_FOR_EACH_WITH_DELIMITER)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_DELIMITER(P,f,d,s,...) (,(,ORDER_PP_OPEN P##f,ORDER_PP_OPEN P##d),8SEQ_FOR_EACH_WITH_DELIMITER_S,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##f,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_DELIMITER_S(P,fd,b0,x0,f,...) (,ORDER_PP_WHEN_##b0(,,8SEQ_FOR_EACH_WITH_DELIMITER_O,P##fd,P##x0,P##f),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_FOR_EACH_WITH_DELIMITER_O(P,_,fd,x0,b1,x1,f,...) (,P##x0,ORDER_PP_IF_NOT_##b1(ORDER_PP_,OPEN f##P,OPEN fd##P,8SEQ_FOR_EACH_WITH_DELIMITER_O,P##fd,P##x1,P##f),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_map ORDER_PP_FN_CM(2,8SEQ_MAP)
#define ORDER_PP_8SEQ_MAP(P,f,in,...) (,ORDER_PP_SEQ_IS_NIL(,P##in)(,,ORDER_PP_SEQ_AT(,0,P##in),ORDER_PP_OPEN f##P,8SEQ_MAP_O,P##f,,ORDER_PP_FX(SEQ_OPEN,(,ORDER_PP_EAT in##P))),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MAP_O(P,y,f,out,b,x,...) (,ORDER_PP_WHEN_##b(,P##x,ORDER_PP_OPEN f##P,8SEQ_MAP_O,P##f,)P##out(P##y),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_merge ORDER_PP_FN_CM(3,8SEQ_MERGE)
#define ORDER_PP_8SEQ_MERGE(P,f,ls,rs,...) (,ORDER_PP_SELECT_4(ORDER_PP_,SEQ_IS_NIL(,P##ls),SEQ_IS_NIL(,P##rs))(,,P##rs,P##ls,ORDER_PP_SEQ_AT(,0,P##ls),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##rs),8SEQ_MERGE_L,ORDER_PP_SEQ_AT_0 ls##P,ORDER_PP_SEQ_AT_0 rs##P,P##f,),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MERGE_L(P,b,l,ls,r,rs,f,out,...) (,ORDER_PP_IF_##b(ORDER_PP_8SEQ_MERGE_,LS,RS)(,P##l,P##ls,P##r,P##rs,P##f,P##out),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MERGE_LS(P,l,ls,r,rs,f,out) ORDER_PP_SEQ_IS_NIL(,P##ls)(,,ORDER_PP_SEQ_AT(,0,P##ls),ORDER_PP_OPEN f##P,8AP,P##r,8SEQ_MERGE_L,ORDER_PP_SEQ_AT_0 ls##P,P##r,P##rs,P##f,)P##out(P##l)ORDER_PP_SEQ_IS_NIL(,P##ls)(,(P##r)P##rs,)
#define ORDER_PP_8SEQ_MERGE_RS(P,l,ls,r,rs,f,out) ORDER_PP_SEQ_IS_NIL(,P##rs)(,,P##l,ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##rs),8SEQ_MERGE_L,P##l,P##ls,ORDER_PP_SEQ_AT_0 rs##P,P##f,)P##out(P##r)ORDER_PP_SEQ_IS_NIL(,P##rs)(,(P##l)P##ls,)

#define ORDER_PP_DEF_8seq_merge_sort ORDER_PP_FN_CM(2,8SEQ_MERGE_SORT)
#define ORDER_PP_8SEQ_MERGE_SORT(P,f,s,...) (,(,8SEQ_MERGE_SORT_B,P##f),8SEQ_REDUCE,ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES(,P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MERGE_SORT_B(P,ls,f,K,...) ORDER_PP_##K(,(,8SEQ_MERGE_SORT_C,ORDER_PP_SEQ_AT_0 P##ls,P##f),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_MERGE_SORT_C(P,rs,l,ls,f,...) (,P##l,ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,0,P##rs),8SEQ_MERGE_L,P##l,P##ls,ORDER_PP_SEQ_AT_0 rs##P,P##f,,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_partition ORDER_PP_FN_CM(2,8SEQ_PARTITION)
#define ORDER_PP_8SEQ_PARTITION(P,f,s,...) (,P##f,8SEQ_PARTITION_O,,,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),8PAIR,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_O(P,f,ot,of,b,x,K,...) (,ORDER_PP_IF_NOT_##b(,ORDER_PP_OPEN(,P##ot,P##K,P##of),P##x,ORDER_PP_OPEN f##P,8SEQ_PARTITION_B,P##x,P##ot,P##of,P##f,P##K),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_B(P,b,x,ot,of,f,...) ORDER_PP_8SEQ_PARTITION_O(,P##f,ORDER_PP_LEFT(,ot##P)ORDER_PP_WHEN_##b(,(P##x)),ORDER_PP_LEFT(,of##P)ORDER_PP_UNLESS_##b(,(P##x)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_partition_sort ORDER_PP_FN_CM(2,8SEQ_PARTITION_SORT)
#define ORDER_PP_8SEQ_PARTITION_SORT(P,f,s,...) (,ORDER_PP_SEQ_IS_NIL(,P##s)(,,ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8SEQ_PARTITION_O,,,ORDER_PP_SEQ_TERMINATE(ORDER_PP_FX(SEQ_OPEN_A,ORDER_PP_EAT s##P)),8SEQ_PARTITION_SORT_B,ORDER_PP_SEQ_AT(,0,P##s),P##f),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_B(P,st,sf,m,f,...) (,P##f,8SEQ_PARTITION_SORT,P##st,8SEQ_PARTITION_SORT_C,P##sf,P##m,P##f,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_C(P,st,sf,m,f,...) (,P##f,8SEQ_PARTITION_SORT,P##sf,8SEQ_PARTITION_SORT_D,P##m,P##st,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_PARTITION_SORT_D(P,sl,m,sr,...) (,P##sl(P##m)P##sr,P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_reduce ORDER_PP_FN_CM(2,8SEQ_REDUCE)
#define ORDER_PP_8SEQ_REDUCE(P,f,s,...) (,ORDER_PP_OVERLOAD(8SEQ_REDUCE,ORDER_PP_SEQ_SATURATED_SIZE(,4,P##s))(,P##f,P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_REDUCE_0(P,f,s)
#define ORDER_PP_8SEQ_REDUCE_1(P,f,s) ORDER_PP_REM s##P
#define ORDER_PP_8SEQ_REDUCE_2(P,f,s) ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,1,P##s)
#define ORDER_PP_8SEQ_REDUCE_3(P,f,s) ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,1,P##s),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,2,P##s)
#define ORDER_PP_8SEQ_REDUCE_4(P,f,s) ORDER_PP_SEQ_AT(,0,P##s),ORDER_PP_OPEN f##P,8AP,ORDER_PP_SEQ_AT(,1,P##s),8SEQ_REDUCE_L,P##f,ORDER_PP_SEQ_FIRST_2 ORDER_PP_EAT_2 s##P
#define ORDER_PP_8SEQ_REDUCE_L(P,y,f,x0,x1,xs,...) (,P##x0,ORDER_PP_OPEN f##P,8AP,P##x1,ORDER_PP_SEQ_IS_NIL(,P##xs)(,ORDER_PP_OPEN f##P ORDER_PP_OPEN(,,8AP,P##y),8SEQ_REDUCE_L,P##f,ORDER_PP_SEQ_FIRST_2 P##xs(P##y)),P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_select ORDER_PP_FN_CM(3,8SEQ_SELECT)
#define ORDER_PP_8SEQ_SELECT(P,f,x0,s,...) (,,8SEQ_SELECT_O,,P##x0,P##f,ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8SEQ_SELECT_O(P,c,x0,x1,f,b,x2,...) (,ORDER_PP_IF_##c(,P##x1,P##x0),ORDER_PP_WHEN_##b(,ORDER_PP_OPEN f##P,8AP,P##x2,8SEQ_SELECT_O,ORDER_PP_IF_##c(,P##x1,P##x0),P##x2,P##f,)P##__VA_ARGS__)

#define ORDER_PP_DEF_8seq_sort ORDER_PP_FN_CM(2,8SEQ_MERGE_SORT)

#define ORDER_PP_DEF_8seq_unfold ORDER_PP_FN_CM(4,8SEQ_UNFOLD)
#define ORDER_PP_8SEQ_UNFOLD(P,c,s,f,x,...) ORDER_PP_8SEQ_UNFOLD_5(,P##x,P##c,P##s,P##f,,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_UNFOLD_5(P,x,c,...) (,P##x,ORDER_PP_OPEN c##P,8SEQ_UNFOLD_B,P##x,c##P,P##__VA_ARGS__)
#define ORDER_PP_8SEQ_UNFOLD_B(P,b,x,c,s,f,...) (,ORDER_PP_WHEN_##b(,P##x,ORDER_PP_OPEN f##P,8SEQ_UNFOLD_C,P##x,P##c,s##P,f##P,)P##__VA_ARGS__)
#define ORDER_PP_8SEQ_UNFOLD_C(P,y,x,c,s,f,ys,...) (,P##x,ORDER_PP_OPEN s##P,8SEQ_UNFOLD_5,P##c,P##s,P##f,P##ys(P##y),P##__VA_ARGS__)

// Details

#define ORDER_PP_SEQ_FIRST_2(x) x,ORDER_PP_SEQ_AT_0

#define ORDER_PP_EAT_2(...) ORDER_PP_EAT

#define ORDER_PP_SEQ_AT(P,i,s) ORDER_PP_SEQ_AT_B(ORDER_PP_SEQ_AT_##i P##s)
#define ORDER_PP_SEQ_AT_B(xs) ORDER_PP_TUPLE_AT_0(,xs)
#define ORDER_PP_SEQ_AT_0(x) x,
#define ORDER_PP_SEQ_AT_1(...) ORDER_PP_SEQ_AT_0
#define ORDER_PP_SEQ_AT_2(...) ORDER_PP_SEQ_AT_1

#define ORDER_PP_PSEQ_CLOSE(P,s) ORDER_PP_PSEQ_CLOSE_A P##s(0,)
#define ORDER_PP_PSEQ_CLOSE_A(P,x) )ORDER_PP_PSEQ_CLOSE_B##P
#define ORDER_PP_PSEQ_CLOSE_A0
#define ORDER_PP_PSEQ_CLOSE_B(P,x) )ORDER_PP_PSEQ_CLOSE_A##P
#define ORDER_PP_PSEQ_CLOSE_B0

#define ORDER_PP_SEQ_IS_NIL(P,s) ORDER_PP_TEST(ORDER_PP_IF_,ORDER_PP_IS_EDIBLE_TEST P##s,0,)

#define ORDER_PP_SEQ_SATURATED_SIZE(P,max,s) ORDER_PP_SEQ_SATURATED_SIZE_B(ORDER_PP_SEQ_SATURATED_SIZE_##max P##s)
#define ORDER_PP_SEQ_SATURATED_SIZE_B(x) ORDER_PP_SEQ_SATURATED_SIZE_C(,x,4,3,2,1,0,)
#define ORDER_PP_SEQ_SATURATED_SIZE_C(P,_,D,C,B,A,x,...) P##x

#define ORDER_PP_SEQ_SATURATED_SIZE_1(x) ,
#define ORDER_PP_SEQ_SATURATED_SIZE_2(x) ,ORDER_PP_SEQ_SATURATED_SIZE_1
#define ORDER_PP_SEQ_SATURATED_SIZE_3(x) ,ORDER_PP_SEQ_SATURATED_SIZE_2
#define ORDER_PP_SEQ_SATURATED_SIZE_4(x) ,ORDER_PP_SEQ_SATURATED_SIZE_3

#define ORDER_PP_SEQ_TERMINATE(...) ORDER_PP_SEQ_TERMINATE_B(__VA_ARGS__)
#define ORDER_PP_SEQ_TERMINATE_B(...) __VA_ARGS__##0

#define ORDER_PP_SEQ_OPEN(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_OPEN_A P##s)
#define ORDER_PP_SEQ_OPEN_A(x) ,x,ORDER_PP_SEQ_OPEN_B
#define ORDER_PP_SEQ_OPEN_A0 0,
#define ORDER_PP_SEQ_OPEN_B(x) ,x,ORDER_PP_SEQ_OPEN_A
#define ORDER_PP_SEQ_OPEN_B0 0,

#define ORDER_PP_SEQ_TO_PSEQ(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_SEQ_TO_PSEQ_A P##s)
#define ORDER_PP_SEQ_TO_PSEQ_A(...) (,__VA_ARGS__)ORDER_PP_SEQ_TO_PSEQ_B
#define ORDER_PP_SEQ_TO_PSEQ_A0
#define ORDER_PP_SEQ_TO_PSEQ_B(...) (,__VA_ARGS__)ORDER_PP_SEQ_TO_PSEQ_A
#define ORDER_PP_SEQ_TO_PSEQ_B0

#define ORDER_PP_PSEQ_TO_SEQ(P,s) ORDER_PP_SEQ_TERMINATE(ORDER_PP_PSEQ_TO_SEQ_A P##s)
#define ORDER_PP_PSEQ_TO_SEQ_A(P,x) (P##x)ORDER_PP_PSEQ_TO_SEQ_B
#define ORDER_PP_PSEQ_TO_SEQ_A0
#define ORDER_PP_PSEQ_TO_SEQ_B(P,x) (P##x)ORDER_PP_PSEQ_TO_SEQ_A
#define ORDER_PP_PSEQ_TO_SEQ_B0

#define ORDER_PP_SEQ_SPLIT_AT(P,i,s) ORDER_PP_IS_EDIBLE(,P##i)(ORDER_PP_SEQ_SPLIT_AT_,NAT,LIT)(,P##i,P##s)
#define ORDER_PP_SEQ_SPLIT_AT_LIT(P,i,s) ORDER_PP_PRIMITIVE_CAT(ORDER_PP_SEQ_SPLIT_AT_,P##i)s##P
#define ORDER_PP_SEQ_SPLIT_AT_NAT(P,i,s) ORDER_PP_PM(,ORDER_PP_NAT_DIV_100 i##P,8SEQ_SPLIT_AT_B,ORDER_PP_OVERLOAD(SEQ_SPLIT_AT,ORDER_PP_SCAN(ORDER_PP_NAT_MOD_100_LIT i##P))s##P,)
#define ORDER_PP_8SEQ_SPLIT_AT_B(P,n,first_n,rest,...) ORDER_PP_NAT_IS_ZERO P##n(ORDER_PP_8SEQ_SPLIT_AT_,C,D)(,P##n,P##first_n,P##rest)
#define ORDER_PP_8SEQ_SPLIT_AT_C(P,n,first_n,rest) ,P##first_n,P##rest)
#define ORDER_PP_8SEQ_SPLIT_AT_D(P,n,first_n,rest) (,ORDER_PP_NAT_PRED n##P,8SEQ_SPLIT_AT_B,P##first_n()ORDER_PP_SEQ_SPLIT_AT_100 P##rest,)

#define ORDER_PP_SEQ_SPLIT_LAST_SHIFT(P,x) (,x##P,ORDER_PP_SEQ_SPLIT_LAST_SHIFT_A##P
#define ORDER_PP_SEQ_SPLIT_LAST_SHIFT_A(P,x) P)(,x##P,ORDER_PP_SEQ_SPLIT_LAST_SHIFT_B##P
#define ORDER_PP_SEQ_SPLIT_LAST_SHIFT_A0 )
#define ORDER_PP_SEQ_SPLIT_LAST_SHIFT_B(P,x) P)(,x##P,ORDER_PP_SEQ_SPLIT_LAST_SHIFT_A##P
#define ORDER_PP_SEQ_SPLIT_LAST_SHIFT_B0 )

#define ORDER_PP_SEQ_SPLIT_LAST_SWAP_A(P,x,b) ORDER_PP_IF_##b(,,,ORDER_PP_REM)(P##x)ORDER_PP_IF_##b(ORDER_PP_,SEQ_SPLIT_LAST_SWAP_B,EAT)
#define ORDER_PP_SEQ_SPLIT_LAST_SWAP_B(P,x,b) ORDER_PP_IF_##b(,,,ORDER_PP_REM)(P##x)ORDER_PP_IF_##b(ORDER_PP_,SEQ_SPLIT_LAST_SWAP_A,EAT)

#include "order/prelude/seq_tables.h"
