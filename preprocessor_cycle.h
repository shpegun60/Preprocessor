/*
 *	CREATED BY SHPEGUN60
 *
 *  MACROCES FOR, WHILE REPEAT
 */

#ifndef __PREPROCESSOR_CYCLE_H__
#define __PREPROCESSOR_CYCLE_H__ 1

/* -- Headers -- */


#include "preprocessor_base.h"
#include "preprocessor_map.h"
#include "preprocessor_if.h"
#include "preprocessor_arguments.h"
#include "preprocessor_arithmetic.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

/************************************************************************************************************************************************************
 *
 *      #define FOO(x) x
 *      PREPROCESSOR_FOR_EACH(FOO, PREPROCESSOR_COMMA_POINT, A,B,C,D)
 *
 * EXPANDS TO:
 *      A ; B ; C ; D
 *
 *
 */
#define PREPROCESSOR_FOR_EACH(op, sep, ...)  PREPROCESSOR_MAP(op, sep, __VA_ARGS__)


/************************************************************************************************************************************************************
 *
 *      #define FOO(par, x) par + x
 *      PREPROCESSOR_FOR_EACH_PARAMETER(USER, FOO, PREPROCESSOR_COMMA_POINT, A,B,C,D)
 *
 * EXPANDS TO:
 *      USER + A ; USER + B ; USER + C ; USER + D
 *
 */
#define PREPROCESSOR_FOR_EACH_PARAMETER(par, op, sep, ...)  PREPROCESSOR_MAP_PARAMETER(par, op, sep, __VA_ARGS__)



/************************************************************************************************************************************************************
 * repeat some macro
 *
 * USE:
 *      #define M(i, ...) i
 *      PREPROCESSOR_REPEAT_MACRO(8, M, ~)
 *
 * Which expands to:
 *      0 1 2 3 4 5 6 7
 ***********************************************************************************************************************************************************
 */
#define PREPROCESSOR_REPEAT_MACRO(...) \
    PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_REPEAT_MACRO_INNER(__VA_ARGS__)))

#define PREPROCESSOR_REPEAT_MACRO_INNER(count, macro, ...)                                                              \
    PREPROCESSOR_IF(count) (                                                                                            \
        PREPROCESSOR_DEFER2(_PREPROCESSOR_REPEAT_MACRO_INNER) () (PREPROCESSOR_DEC(count), macro, ##__VA_ARGS__)        \
        PREPROCESSOR_DEFER2(macro) (PREPROCESSOR_DEC(count), ##__VA_ARGS__)                                             \
    )
#define _PREPROCESSOR_REPEAT_MACRO_INNER() PREPROCESSOR_REPEAT_MACRO_INNER


/************************************************************************************************************************************************************
 * WHILE macro with predicate
 *
 * WHILE will keep on applying the op macro until the pred returns true.
 *
 * USE:
 *      #define PRED(state, ...) PREPROCESSOR_BOOL(state)
 *      #define OP(state, ...) PREPROCESSOR_DEC(state), state, __VA_ARGS__
 *      PREPROCESSOR_WHILE_MACRO(PRED, OP, 8)
 *
 * Which expands to
 *      0, 1, 2, 3, 4, 5, 6, 7, 8,
 *
 ***********************************************************************************************************************************************************
 */
#define PREPROCESSOR_WHILE_MACRO(...) \
    PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_WHILE_MACRO_INNER(__VA_ARGS__)))

#define PREPROCESSOR_WHILE_MACRO_INNER(pred, op, ...)\
    PREPROCESSOR_IF_ELSE(pred(__VA_ARGS__)) ( \
        PREPROCESSOR_DEFER2(_PREPROCESSOR_WHILE_MACRO_INNER) () (pred, op, op(__VA_ARGS__)), \
        __VA_ARGS__ \
    )
#define _PREPROCESSOR_WHILE_MACRO_INNER() PREPROCESSOR_WHILE_MACRO_INNER



#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_CYCLE_H__ */
