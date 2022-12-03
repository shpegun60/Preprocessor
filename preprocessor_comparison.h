/*
 *	CREATED BY SHPEGUN60
 *
 *  CHAR LITERALS EQUALUATION MACROCES
 */

#ifndef __PREPROCESSOR_COMPARISON_H__
#define __PREPROCESSOR_COMPARISON_H__ 1

/* -- Headers -- */

#include "preprocessor_detection.h"
#include "preprocessor_logical.h"
#include "preprocessor_if.h"
#include "preprocessor_symbol.h"


#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

/************************************************************************************************************************************************************
 *
 * USE:
 *  #define foo(x) x
 *  #define bar(x) x
 *
 *   PREPROCESSOR_PRIMITIVE_COMPARE(foo, bar) // Expands to 1
 *   PREPROCESSOR_PRIMITIVE_COMPARE(foo, foo) // Expands to 0
 *
 *   PREPROCESSOR_NOT_EQUAL(foo, bar)    // Expands to 1
 *   PREPROCESSOR_NOT_EQUAL(foo, foo)    // Expands to 0
 *   PREPROCESSOR_NOT_EQUAL(foo, unfoo)  // Expands to 1
 *
 *   PREPROCESSOR_EQUAL(foo, bar)        // Expands to 0
 *   PREPROCESSOR_EQUAL(foo, foo)        // Expands to 1
 *   PREPROCESSOR_EQUAL(foo, unfoo)      // Expands to 0 (unfoo is not defined)
 *
 ***********************************************************************************************************************************************************
 */
#define PREPROCESSOR_IS_COMPARABLE(x) _PREPROCESSOR_IS_COMPARABLE(x) // expand x
#define _PREPROCESSOR_IS_COMPARABLE(x) PREPROCESSOR_IS_PAREN(x(()))

#define PREPROCESSOR_PRIMITIVE_COMPARE(x, y) _PREPROCESSOR_PRIMITIVE_COMPARE(x, y) // expand x, y
#define _PREPROCESSOR_PRIMITIVE_COMPARE(x, y) PREPROCESSOR_IS_PAREN \
    ( \
        x(y)(()) \
    )

#define PREPROCESSOR_NOT_EQUAL(x, y) _PREPROCESSOR_NOT_EQUAL(x, y)  // expand x, y
#define _PREPROCESSOR_NOT_EQUAL(x, y) \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_BITAND(PREPROCESSOR_IS_COMPARABLE(x))(PREPROCESSOR_IS_COMPARABLE(y))) ( \
       PREPROCESSOR_PRIMITIVE_COMPARE, \
       1 PREPROCESSOR_EAT \
    )(x, y)

#define PREPROCESSOR_EQUAL(x, y) PREPROCESSOR_NOT(PREPROCESSOR_NOT_EQUAL(x, y))


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_COMPARISON_H__ */
