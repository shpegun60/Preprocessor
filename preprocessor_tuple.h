/*
 *	CREATED BY SHPEGUN60
 *
 *   TUPLE MACROCES
\**********************************************************************************************************************
 * Tuples: `(x, y, z)`.
 *
 * A tuple is represented as `(x1, ..., xN)`. Tuples are a convenient way to deal with product
 * types.
 **********************************************************************************************************************
 */

#ifndef __PREPROCESSOR_TUPLE_H__
#define __PREPROCESSOR_TUPLE_H__ 1

/* -- Headers -- */

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

/***********************************************************************************************************
 * Checks whether x takes the form `(...) (...) ...`.
 *
 * This often happens when you miss a comma between items:
 *  - `(1, 2, 3) (4, 5, 6)`
 *  - etc.
 *
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING()                        // expands to 0
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING(2)                       // expands to 0
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((2))                     // expands to 0
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((2) (3))                 // expands to 1
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((123) (456))             // expands to 1
 *              PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING((1, 2, 3) (4, 5, 6))     // expands to 1
 */
#define PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING(x)                                                     \
    PREPROCESSOR_ARGS_CONTAINS_COMMA(PREPROCESSOR_EXPAND(PREPROCESSOR_COMMA_VARIADIC PREPROCESSOR_EMPTY_VARIADIC x))

/************************************************************************************************************
 * FAST CHECK IF NEXT VALUE IS NOT TUPLE
 *
 *
 *      PREPROCESSOR_IS_UNTUPLE_FAST(PREPROCESSOR_TUPLE_MAKE(x, y, z))                // expand to 0
 *      PREPROCESSOR_IS_UNTUPLE_FAST(x)                                               // expand to 1
 *      PREPROCESSOR_IS_UNTUPLE_FAST((1,2,3,))                                        // expand to 0
 *      PREPROCESSOR_IS_UNTUPLE_FAST(())                                              // expand to 0
 *      PREPROCESSOR_IS_UNTUPLE_FAST()                                                // expand to 1
 *
 *      PREPROCESSOR_IS_UNTUPLE the same then PREPROCESSOR_IS_UNTUPLE_FAST, but PREPROCESSOR_IS_UNTUPLE checs if input x takes the form `(...) (...) ...
 *
 */

#define PREPROCESSOR_IS_UNTUPLE_FAST(x) PREPROCESSOR_IS_UNTUPLE_FAST_IMPL(x)
#define PREPROCESSOR_IS_UNTUPLE_FAST_IMPL(x) PREPROCESSOR_ARGS_SND(PREPROCESSOR_IS_UNTUPLE_FAST_TEST x, 1)
#define PREPROCESSOR_IS_UNTUPLE_FAST_TEST(...) ~, 0


#define PREPROCESSOR_IS_UNTUPLE(x)                                                                    \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_IS_DOUBLE_TUPLE_BEGINNING(x)) (                                 \
        PREPROCESSOR_TRUE,                                                                            \
        PREPROCESSOR_IS_UNTUPLE_FAST)                                                                 \
    (x)


/************************************************************************************************************
 * FAST CHECK IF NEXT VALUE IS TUPLE
 *
 *
 *      PREPROCESSOR_IS_TUPLE_FAST(PREPROCESSOR_TUPLE_MAKE(x, y, z))                // expand to 1
 *      PREPROCESSOR_IS_TUPLE_FAST(x)                                               // expand to 0
 *      PREPROCESSOR_IS_TUPLE_FAST((1,2,3,))                                        // expand to 1
 *      PREPROCESSOR_IS_TUPLE_FAST(())                                              // expand to 1
 *      PREPROCESSOR_IS_TUPLE_FAST()                                                // expand to 0
 *
 *      PREPROCESSOR_IS_TUPLE the same then PREPROCESSOR_IS_TUPLE_FAST, but PREPROCESSOR_IS_TUPLE checs if input x takes the form `(...) (...) ...
 *
 */
#define PREPROCESSOR_IS_TUPLE_FAST(x) PREPROCESSOR_NOT(PREPROCESSOR_IS_UNTUPLE_FAST(x))

#define PREPROCESSOR_IS_TUPLE(x) PREPROCESSOR_NOT(PREPROCESSOR_IS_UNTUPLE(x))


/************************************************************************************************************
 * TUPLE UNTUPLING
 *
 *          PREPROCESSOR_UNTUPLE((x,y,z)) // expands just to x,y,z (deletes parenthesis)
 */
#define PREPROCESSOR_UNTUPLE(...) PREPROCESSOR_UNTUPLE_IMPL __VA_ARGS__
#define PREPROCESSOR_UNTUPLE_IMPL(...) __VA_ARGS__


/************************************************************************************************************
 * TUPLE MAKE
 *
 *          PREPROCESSOR_TUPLE_MAKE(x,y,z) // expands just to (x,y,z) (add parenthesis)
 */
#define PREPROCESSOR_TUPLE_MAKE(...) (PREPROCESSOR_UNTUPLE_IMPL(__VA_ARGS__))

/************************************************************************************************************
 * TUPLE EXPANDING SOME MACRO
 */
#define PREPROCESSOR_TUPLE_EXPAND_MACRO(macro, ...) macro __VA_ARGS__


/************************************************************************************************************
 * TUPLE PREPEND
 *
 *      PREPROCESSOR_TUPLE_PREPEND(x1, (x, y, z)) // expands to (x1, x, y, z)
 */

#define PREPROCESSOR_TUPLE_PREPEND(expr, tuple) \
    PREPROCESSOR_TUPLE_MAKE(expr, PREPROCESSOR_UNTUPLE(tuple))

/************************************************************************************************************
 * TUPLE APPEND
 *
 *      PREPROCESSOR_TUPLE_APPEND(x1, (x, y, z)) // expands to (x, y, z, x1)
 */

#define PREPROCESSOR_TUPLE_APPEND(expr, tuple) \
    PREPROCESSOR_TUPLE_MAKE(PREPROCESSOR_UNTUPLE(tuple), expr)

/************************************************************************************************************
 * TUPLE MERGE
 *
 *      PREPROCESSOR_TUPLE_MERGE((x1, y1, z1), (x, y, z))                   // expands to (x1, y1, z1, x, y, z)
 *      PREPROCESSOR_TUPLE_MERGE_VARIADIC((1,2,3) ,(6,5,4), (3,2,1))        // expands to (1,2,3 , 6,5,4 , 3,2,1)
 */

#define PREPROCESSOR_TUPLE_MERGE(tuple1, tuple2) \
    PREPROCESSOR_TUPLE_MAKE(PREPROCESSOR_UNTUPLE(tuple1), PREPROCESSOR_UNTUPLE(tuple2))

#define PREPROCESSOR_TUPLE_MERGE_VARIADIC(...)\
    PREPROCESSOR_TUPLE_MAKE(PREPROCESSOR_FOR_EACH(PREPROCESSOR_UNTUPLE, PREPROCESSOR_COMMA, __VA_ARGS__))

/************************************************************************************************************
 * TUPLE HEAD / TAIL
 *
 *      PREPROCESSOR_TUPLE_TAIL((x,y,z)) // expands to y,z
 *      PREPROCESSOR_TUPLE_HEAD((x,y,z)) // expands to x
 */
#define PREPROCESSOR_TUPLE_TAIL(x)         PREPROCESSOR_ARGS_TAIL(PREPROCESSOR_UNTUPLE(x))
#define PREPROCESSOR_TUPLE_HEAD(x)         PREPROCESSOR_ARGS_HEAD(PREPROCESSOR_UNTUPLE(x))


/************************************************************************************************************
 * TUPLE COUNTS OF ARGUMENT
 *
 *      PREPROCESSOR_TUPLE_COUNT((x,y,z, x1)) // expands to 4
 */
#define PREPROCESSOR_TUPLE_COUNT(x)        PREPROCESSOR_ARGS_COUNT(PREPROCESSOR_UNTUPLE(x))

/************************************************************************************************************
 * TUPLE IS SINGLE OF ARGUMENT
 *
 *      PREPROCESSOR_TUPLE_IS_SINGLE((x,y,z, x1))   // expands to 0
 *      PREPROCESSOR_TUPLE_IS_SINGLE((x))           // expands to 1
 */

#define PREPROCESSOR_TUPLE_IS_SINGLE(x)    PREPROCESSOR_ARGS_IS_SINGLE(PREPROCESSOR_UNTUPLE(x))

/************************************************************************************************************
 * TUPLE HAS ARGUMENTS
 *
 *      PREPROCESSOR_TUPLE_IS_NOT_EMPTY((x,y,z))   // expands to 1
 *      PREPROCESSOR_TUPLE_IS_NOT_EMPTY((x))       // expands to 1
 *      PREPROCESSOR_TUPLE_IS_NOT_EMPTY(())        // expands to 0
 */

#define PREPROCESSOR_TUPLE_IS_NOT_EMPTY(x)    PREPROCESSOR_ARGS_NOT_EMPTY(PREPROCESSOR_UNTUPLE(x))



/************************************************************************************************************
 * TUPLE GET / REMOVE
 *
 *
 *          PREPROCESSOR_EVAL(PREPROCESSOR_TUPLE_GET(1)PREPROCESSOR_TUPLE_MAKE(x, y, z))    // expands to y
 *          PREPROCESSOR_TUPLE_GET(1)(x, y, z)                                              // expands to y
 *
 *          PREPROCESSOR_TUPLE_REMOVE(1)(x, y, z)                                           // expands to x , z
 *          PREPROCESSOR_EVAL(PREPROCESSOR_TUPLE_REMOVE(1)PREPROCESSOR_TUPLE_MAKE(x, y, z)) // expands to x , z
 */

#define PREPROCESSOR_TUPLE_GET(x)       PREPROCESSOR_GET_ARG(x)
#define PREPROCESSOR_TUPLE_REMOVE(x)    PREPROCESSOR_REMOVE_ARG(x)


/************************************************************************************************************
 * TUPLE FOR_EACH
 *
 *      #define TUPLE_FOO(x) printf("%d" x)
 *      PREPROCESSOR_TUPLE_FOR_EACH_ELEM(TUPLE_FOO, PREPROCESSOR_COMMA_POINT, (1,2,3) ,(6,5,4), (3,2,1))
 *
 * Which expands to:
 *      printf("%d" 1) ; printf("%d" 2) ; printf("%d" 3) ; printf("%d" 6) ; printf("%d" 5) ; printf("%d" 4) ; printf("%d" 3) ; printf("%d" 2) ; printf("%d" 1)
 *
 *
 *      #define TUPLE_FOO(x) PREPROCESSOR_CONCAT(myFoo, PREPROCESSOR_TUPLE_COUNT(x)) x
 *      PREPROCESSOR_TUPLE_FOR_EACH(TUPLE_FOO, PREPROCESSOR_COMMA_POINT, (1,2,3,4), (6,5), (3))
 *
 * Which expands to:
 *      myFoo4 (1,2,3,4) ; myFoo2 (6,5) ; myFoo1 (3)
 */

#define PREPROCESSOR_TUPLE_FOR_EACH_ELEM(f, sep, ...) \
    PREPROCESSOR_FOR_EACH(f, sep, PREPROCESSOR_UNTUPLE(PREPROCESSOR_TUPLE_MERGE_VARIADIC(__VA_ARGS__)))


#define PREPROCESSOR_TUPLE_FOR_EACH(f, sep, ...) \
    PREPROCESSOR_FOR_EACH(f, sep, __VA_ARGS__)

/************************************************************************************************************
 * TUPLE FOR_EACH with parameter
 * the same as PREPROCESSOR_TUPLE_FOR_EACH but contains some user parameter (may be tuple)
 *
 *       #define TUPLE_FOO(par, x) printf(par); PREPROCESSOR_CONCAT(myFoo, PREPROCESSOR_TUPLE_COUNT(x)) x
 *       PREPROCESSOR_TUPLE_FOR_EACH_PARAMETER("next par------", TUPLE_FOO, PREPROCESSOR_COMMA_POINT, (1,2,3,4), (6,5), (3))
 *
 *      Which expands to:
 *           printf("next par------");
 *           myFoo4(1, 2, 3, 4);
 *           printf("next par------");
 *           myFoo2(6, 5);
 *           printf("next par------");
 *           myFoo1(3)
 *
 *          **** parameters may be tuple -->(2, 3, 4), but progremmer must proceed this
 *
 */

#define PREPROCESSOR_TUPLE_FOR_EACH_PARAMETER(par, f, sep, ...) \
    PREPROCESSOR_FOR_EACH_PARAMETER(par, f, sep, __VA_ARGS__)


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_TUPLE_H__ */
