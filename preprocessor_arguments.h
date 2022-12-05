/*
 *	CREATED BY SHPEGUN60
 *
 *  VARIADIC MACRO INSTRUMENTS
 *
 */

#ifndef __PREPROCESSOR_ARGUMENTS_H__
#define __PREPROCESSOR_ARGUMENTS_H__ 1

/* -- Headers -- */

#include "preprocessor_arithmetic.h"
#include "preprocessor_boolean.h"
#include "preprocessor_symbol.h"
#include "preprocessor_concatenation.h"
#include "preprocessor_if.h"
#include "preprocessor_tuple.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Definitions -- */
/*********************************************************************************************************************
 * MAXIMUM VARIADIC INPUT MACRO
 *      If you want increase number of arguments you must extends next macro:
 *          - PREPROCESSOR_ARGS_COUNT_SEQ_IMPL,
 *          - PREPROCESSOR_ARGS_N_IMPL,
 *          - PREPROCESSOR_ARGS_SIZE
 *
 *      WARNING!!! some compilers do not support when number of arguments more than 127
 */

#define PREPROCESSOR_ARGS_SIZE 64
/******************************************************************************************************************/

/* -- Macros -- */

/************************************************************************************************************************************************************
 * Get the first ... N argument and ignore the rest, adds variadic end symbol. Maximum 10 elements !!!!! if you need more, please implement this
 *
 *      PREPROCESSOR_GET_ARG(9)(1aa,2bb,3cc,4dd,5ee,6ff,7gg,8hh,9gg,10kk, 11lll)    // expands to 10kk
 *      PREPROCESSOR_GET_ARG(1)(x, y, z)                                            // expands to y
 *      PREPROCESSOR_GET_ARG(0)(0, 1, 2)                                            // expands to 0
 *      PREPROCESSOR_EVAL(PREPROCESSOR_GET_ARG(2)PREPROCESSOR_TUPLE_MAKE(x,y,z))    // expands to z
 *      PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_TUPLE_MAKE(x, x), 1, 2)                // expands to (x, x)
 */

#define PREPROCESSOR_GET_ARG(x) PREPROCESSOR_GET_ARG_IMPL(x)
#define PREPROCESSOR_GET_ARG_IMPL(x) PREPROCESSOR_CONCAT(PREPROCESSOR_ARGS_GET_, x)

#define PREPROCESSOR_ARGS_GET_0(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_0(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_1(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_1(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_2(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_2(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_3(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_3(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_4(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_4(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_5(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_5(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_6(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_6(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_7(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_7(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_8(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_8(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_9(...)  PREPROCESSOR_ARGS_PRIMITIVE_GET_9(__VA_ARGS__, ~)
#define PREPROCESSOR_ARGS_GET_10(...) PREPROCESSOR_ARGS_PRIMITIVE_GET_10(__VA_ARGS__, ~)


#define PREPROCESSOR_ARGS_PRIMITIVE_GET_0(_0, ...) _0                 // Get the first argument and ignore the rest.
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_1(_0, _1, ...) _1
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_2(_0, _1, _2, ...) _2
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_3(_0, _1, _2, _3, ...) _3
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_4(_0, _1, _2, _3, _4, ...) _4
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_5(_0, _1, _2, _3, _4, _5, ...) _5
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_6(_0, _1, _2, _3, _4, _5, _6, ...) _6
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_7(_0, _1, _2, _3, _4, _5, _6, _7, ...) _7
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9
#define PREPROCESSOR_ARGS_PRIMITIVE_GET_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) _10

/************************************************************************************************************************************************************
 *  HEAD, TAIL, SND VARIADIC GETTING
 *
 *      PREPROCESSOR_ARGS_HEAD(x,y,z) // expands to x
 *      PREPROCESSOR_ARGS_TAIL(x,y,z) // expands to y,z
 *      PREPROCESSOR_ARGS_SND(x,y,z)  // expands to y
 *
 */

#   define PREPROCESSOR_ARGS_HEAD(...)        PREPROCESSOR_ARGS_IMPL(__VA_ARGS__, ~)
#   define PREPROCESSOR_ARGS_IMPL(x, ...) x
#
#   define PREPROCESSOR_ARGS_TAIL(...)         PREPROCESSOR_ARGS_TAIL_IMPL(__VA_ARGS__)
#   define PREPROCESSOR_ARGS_TAIL_IMPL(_x, ...) __VA_ARGS__
#
#   define PREPROCESSOR_ARGS_SND(...)            PREPROCESSOR_ARGS_SND_IMPL(__VA_ARGS__, ~)
#   define PREPROCESSOR_ARGS_SND_IMPL(_x, _y, ...) _y



/************************************************************************************************************************************************************
 * Remove the first ... N argument and ignore the rest. Maximum 10 elements !!!!! if you need more, please implement this
 *
 *      PREPROCESSOR_REMOVE_ARG(9)(1aa,2bb,3cc,4dd,5ee,6ff,7gg,8hh,9gg,10kk, 11lll)     // expands to 1aa, 2bb, 3cc, 4dd, 5ee, 6ff, 7gg, 8hh, 9gg, 11lll
 *      PREPROCESSOR_REMOVE_ARG(0)(x, y, z)                                             // expands to y, z
 *      PREPROCESSOR_REMOVE_ARG(1)(0, 1, 2)                                             // expands to 0, 2
 *      PREPROCESSOR_EVAL(PREPROCESSOR_REMOVE_ARG(1)PREPROCESSOR_TUPLE_MAKE(x,y,z))     // expands to x, z
 *      PREPROCESSOR_REMOVE_ARG(0)((x, x), y, (z, z))                                   // expands to y, (z, z)
 */

#define PREPROCESSOR_REMOVE_ARG(x) PREPROCESSOR_REMOVE_ARG_IMPL(x)
#define PREPROCESSOR_REMOVE_ARG_IMPL(x) PREPROCESSOR_CONCAT(PREPROCESSOR_ARGS_REMOVE_, x)

// remove element
#define PREPROCESSOR_ARGS_REMOVE_0(_0, ...) __VA_ARGS__ // Remove the first argument and ignore the rest.

#define PREPROCESSOR_ARGS_REMOVE_1(_0, _1, ...) \
    _0 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_2(_0, _1, _2, ...) \
    _0, _1 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_3(_0, _1, _2, _3, ...) \
    _0, _1, _2 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_4(_0, _1, _2, _3, _4, ...) \
    _0, _1, _2, _3 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_5(_0, _1, _2, _3, _4, _5, ...) \
    _0, _1, _2, _3, _4 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_6(_0, _1, _2, _3, _4, _5, _6, ...) \
    _0, _1, _2, _3, _4, _5 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_7(_0, _1, _2, _3, _4, _5, _6, _7, ...) \
    _0, _1, _2, _3, _4, _5, _6 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) \
    _0, _1, _2, _3, _4, _5, _6, _7 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) \
    _0, _1, _2, _3, _4, _5, _6, _7, _8 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)
#define PREPROCESSOR_ARGS_REMOVE_10(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, ...) \
   _0, _1, _2, _3, _4, _5, _6, _7, _8, _9 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (, __VA_ARGS__)


/*********************************************************************************************************************
 * VARIADIC ARGUMENTS IS EMPTY IMPLEMENTATION
 *
 *          PREPROCESSOR_ARGS_EMPTY()           // expand to 1
 *          PREPROCESSOR_ARGS_EMPTY(x)          // expand to 0
 *          PREPROCESSOR_ARGS_EMPTY(x, y, z)    // expand to 0
 *          PREPROCESSOR_ARGS_EMPTY(,,)         // expand to 0
 *          PREPROCESSOR_ARGS_EMPTY(,)          // expand to 0
 *          PREPROCESSOR_ARGS_EMPTY(, a)        // expand to 0
 *
 */

#define PREPROCESSOR_ARGS_EMPTY(...)                                                 \
    PREPROCESSOR_ARGS_EMPTY_IMPL(                                                    \
        PREPROCESSOR_ARGS_CONTAINS_COMMA(__VA_ARGS__),                               \
        PREPROCESSOR_ARGS_CONTAINS_COMMA(PREPROCESSOR_COMMA_VARIADIC __VA_ARGS__),   \
        PREPROCESSOR_ARGS_CONTAINS_COMMA(__VA_ARGS__ ()),                            \
        PREPROCESSOR_ARGS_CONTAINS_COMMA(PREPROCESSOR_COMMA_VARIADIC __VA_ARGS__ ()) \
    )

#define PREPROCESSOR_ARGS_EMPTY_IMPL(_0, _1, _2, _3) PREPROCESSOR_ARGS_EMPTY_IMPL_I(_0, _1, _2, _3)
#define PREPROCESSOR_ARGS_EMPTY_IMPL_I(_0, _1, _2, _3) PREPROCESSOR_ARGS_CONTAINS_COMMA(PREPROCESSOR_ARGS_EMPTY_CASE(PREPROCESSOR_ARGS_EMPTY_CASE_IMPL_, _0, _1, _2, _3))
#define PREPROCESSOR_ARGS_EMPTY_CASE(_0, _1, _2, _3, _4) _0 ## _1 ## _2 ## _3 ## _4
#define PREPROCESSOR_ARGS_EMPTY_CASE_IMPL_0001 ,

/*********************************************************************************************************************
 * VARIADIC ARGUMENTS IS NOT EMPTY IMPLEMENTATION
 *
 *          PREPROCESSOR_ARGS_NOT_EMPTY()           // expand to 0
 *          PREPROCESSOR_ARGS_NOT_EMPTY(x)          // expand to 1
 *          PREPROCESSOR_ARGS_NOT_EMPTY(x, y, z)    // expand to 1
 *          PREPROCESSOR_ARGS_NOT_EMPTY(,,)         // expand to 1
 *          PREPROCESSOR_ARGS_NOT_EMPTY(,)          // expand to 1
 *          PREPROCESSOR_ARGS_NOT_EMPTY(, a)        // expand to 1
 *
 */
#define PREPROCESSOR_ARGS_NOT_EMPTY(...) \
    PREPROCESSOR_NOT(PREPROCESSOR_ARGS_EMPTY(__VA_ARGS__))


/*********************************************************************************************************************
 * VARIADIC ARGUMENTS COUNT IMPLEMENTATION
 *
 *      PREPROCESSOR_ARGS_COUNT()                                    // expand to 0
 *      PREPROCESSOR_ARGS_COUNT(x,y,z)                               // expand to 3
 *      PREPROCESSOR_ARGS_COUNT(x, PREPROCESSOR_TUPLE_MAKE(1,2,3))   // expand to 2
 *      PREPROCESSOR_ARGS_COUNT(,,)                                  // expand to 3
 *
 */


#define PREPROCESSOR_ARGS_COUNT(...) \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_ARGS_EMPTY(__VA_ARGS__)) ( \
        0, \
        PREPROCESSOR_ARGS_COUNT_IMPL(__VA_ARGS__, PREPROCESSOR_ARGS_COUNT_SEQ_IMPL()) \
    )

#define PREPROCESSOR_ARGS_COUNT_IMPL(...) PREPROCESSOR_ARGS_N_IMPL(__VA_ARGS__)


// MACRO COUNT TABLES ------------------------------------------------------------------------
#define PREPROCESSOR_ARGS_COUNT_SEQ_IMPL()  \
    63, 62, 61, 60,                         \
    59, 58, 57, 56, 55, 54, 53, 52, 51, 50, \
    49, 48, 47, 46, 45, 44, 43, 42, 41, 40, \
    39, 38, 37, 36, 35, 34, 33, 32, 31, 30, \
    29, 28, 27, 26, 25, 24, 23, 22, 21, 20, \
    19, 18, 17, 16, 15, 14, 13, 12, 11, 10, \
    9, 8, 7, 6, 5, 4, 3, 2, 1, 0


#define PREPROCESSOR_ARGS_N_IMPL(                       \
    _1, _2, _3, _4, _5, _6, _7, _8, _9, _10,            \
    _11, _12, _13, _14, _15, _16, _17, _18, _19, _20,   \
    _21, _22, _23, _24, _25, _26, _27, _28, _29, _30,   \
    _31, _32, _33, _34, _35, _36, _37, _38, _39, _40,   \
    _41, _42, _43, _44, _45, _46, _47, _48, _49, _50,   \
    _51, _52, _53, _54, _55, _56, _57, _58, _59, _60,   \
    _61, _62, _63,                                      \
    N, ...) N


/************************************************************************************************************************************************************
 * Macro which checks if it has any arguments. Returns '0' if there are no
 * arguments, '1' otherwise.
 *
 * Limitation: PREPROCESSOR_SIMPLE_HAS_ARGS(,1,2,3) returns 0 -- this check essentially only checks
 * that the first argument exists.
 *
 * This macro works as follows:
 *
 * 1. PREPROCESSOR_END_OF_ARGUMENTS_ is concatenated with the first argument.
 * 2. If the first argument is not present then only "PREPROCESSOR_END_OF_ARGUMENTS_" will
 *    remain, otherwise "PREPROCESSOR_END_OF_ARGUMENTS_ something_here" will remain. This
 *    remaining argument can start with parentheses.
 * 3. In the former case, the PREPROCESSOR_END_OF_ARGUMENTS_(0) macro expands to a
 *    0 when it is expanded. In the latter, a non-zero result remains. If the
 *    first argument started with parentheses these will mostly not contain
 *    only a single 0, but e.g a C cast or some arithmetic operation that will
 *    cause the PREPROCESSOR_BOOL in PREPROCESSOR_END_OF_ARGUMENTS_ to be one.
 * 4. PREPROCESSOR_BOOL is used to force non-zero results into 1 giving the clean 0 or 1
 *    output required.
 *
 *          PREPROCESSOR_SIMPLE_HAS_ARGS()          // expands to 0
 *          PREPROCESSOR_SIMPLE_HAS_ARGS(,)         // expands to 0
 *          PREPROCESSOR_SIMPLE_HAS_ARGS(, a)       // expands to 0
 *          PREPROCESSOR_SIMPLE_HAS_ARGS(a,b,c)     // expands to 1
 *          PREPROCESSOR_SIMPLE_HAS_ARGS(a,b)       // expands to 1
 *          PREPROCESSOR_SIMPLE_HAS_ARGS(a)         // expands to 1
 */
#define PREPROCESSOR_SIMPLE_HAS_ARGS(...) PREPROCESSOR_BOOL(PREPROCESSOR_ARGS_HEAD(PREPROCESSOR_END_OF_ARGUMENTS_ __VA_ARGS__)(0))
#define PREPROCESSOR_END_OF_ARGUMENTS_(...) PREPROCESSOR_BOOL(PREPROCESSOR_ARGS_HEAD(__VA_ARGS__))


/*********************************************************************************************************************
 * VARIADIC ARGUMENT COMMA FINDER IMPLEMENTATION
 *  Check if the next sequence symbol comma (,) is exists
 *
 *      PREPROCESSOR_ARGS_CONTAINS_COMMA(x)      // expands to 0
 *      PREPROCESSOR_ARGS_CONTAINS_COMMA()       // expands to 0
 *      PREPROCESSOR_ARGS_CONTAINS_COMMA(,)      // expands to 1
 *      PREPROCESSOR_ARGS_CONTAINS_COMMA(x,y)    // expands to 1
 *
 */

#define PREPROCESSOR_ARGS_CONTAINS_COMMA(...)                      PREPROCESSOR_ARGS_X_AS_COMMA(__VA_ARGS__, PREPROCESSOR_COMMA(), ~)
#define PREPROCESSOR_ARGS_X_AS_COMMA(_head, x, ...)                PREPROCESSOR_ARGS_CONTAINS_COMMA_RESULT(x, 0, 1, ~)
#define PREPROCESSOR_ARGS_CONTAINS_COMMA_RESULT(x, _, result, ...) result


/*********************************************************************************************************************
 * VARIADIC IS SINGLE IMPLEMENTATION
 *  Check if the next sequence symbol comma (,) is exists
 *
 *      PREPROCESSOR_ARGS_IS_SINGLE(x)      // expands to 1
 *      PREPROCESSOR_ARGS_IS_SINGLE()       // expands to 1
 *      PREPROCESSOR_ARGS_IS_SINGLE(,)      // expands to 0
 *      PREPROCESSOR_ARGS_IS_SINGLE(x,y)    // expands to 0
 *
 */

#define PREPROCESSOR_ARGS_IS_SINGLE(...) PREPROCESSOR_NOT(PREPROCESSOR_ARGS_CONTAINS_COMMA(__VA_ARGS__))


/************************************************************************************************************************************************************
 * Overloads @p f on a number of arguments.
 *
 * This function counts the number of provided arguments, appends it to @p f and calls the resulting
 * macro identifier with provided arguments.
 *
 * At most 63 variadic arguments are acceptable.
 *
 * # Examples
 *
 * @code
 *
 * #define X(...)    PREPROCESSOR_OVERLOAD(X_, __VA_ARGS__)
 * #define X_1(a)    Billie & a
 * #define X_2(a, b) Jean & a & b
 *
 * // Billie & 4
 * X(4)
 *
 * // Jean & 5 & 6
 * X(5, 6)
 * @endcode
 *
 */
#define PREPROCESSOR_OVERLOAD(f, ...) PREPROCESSOR_OVERLOAD_IMPL(f, __VA_ARGS__)
#define PREPROCESSOR_OVERLOAD_IMPL(f, ...) PREPROCESSOR_CONCAT(f, PREPROCESSOR_ARGS_COUNT(__VA_ARGS__))(__VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_ARGUMENTS_H__ */
