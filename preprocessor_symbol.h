/*
 *	CREATED BY SHPEGUN60
 *
 *   SYMBOL MACROCES
 */

#ifndef __PREPROCESSOR_SYMBOL_H__
#define __PREPROCESSOR_SYMBOL_H__ 1

/* -- Headers -- */

#include "preprocessor_if.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros-- */

/************************************************************************************************************************************************************
 * Macros which expand to common values
 */
#define PREPROCESSOR_EMPTY()
#define PREPROCESSOR_EMPTY_VARIADIC(...)

#define PREPROCESSOR_PASS(...) __VA_ARGS__

#define PREPROCESSOR_EAT(...)

#define PREPROCESSOR_COMMA() ,
#define PREPROCESSOR_COMMA_VARIADIC(...) ,

#define PREPROCESSOR_PLUS() +
#define PREPROCESSOR_PLUS_VARIADIC(...) +

#define PREPROCESSOR_ZERO() 0
#define PREPROCESSOR_ZERO_VARIADIC(...) 0

#define PREPROCESSOR_ONE() 1
#define PREPROCESSOR_ONE_VARIADIC(...) 1

#define PREPROCESSOR_UNDERSCORE() _
#define PREPROCESSOR_UNDERSCORE_VARIADIC(...) _

#define PREPROCESSOR_COMMA_POINT() ;
#define PREPROCESSOR_COMMA_POINT_VARIADIC(...) ;



/************************************************************************************************************************************************************
 * CommaIf implementation.
 *
 *      PREPROCESSOR_COMMA_IF_IMPL(1)() // expand to , (PREPROCESSOR_COMMA())
 *      PREPROCESSOR_COMMA_IF_IMPL(0)() // expand to nothing (PREPROCESSOR_EMPTY())
 */

#define PREPROCESSOR_COMMA_IF_IMPL(x) \
    PREPROCESSOR_IF_ELSE(x)(PREPROCESSOR_COMMA, PREPROCESSOR_EMPTY)

#define PREPROCESSOR_COMMA_IF(x) \
    PREPROCESSOR_COMMA_IF_IMPL(x)

/************************************************************************************************************************************************************
 * SymbolIf implementation.
 *
 *      PREPROCESSOR_SYMBOL_IF(1, PREPROCESSOR_PLUS)()      // expand to + (PREPROCESSOR_PLUS())
 *      PREPROCESSOR_SYMBOL_IF(0, PREPROCESSOR_PLUS)()      // expand to nothing (PREPROCESSOR_EMPTY())
 */

#define PREPROCESSOR_SYMBOL_IF_IMPL(x, symbol) \
    PREPROCESSOR_IF_ELSE(x)(symbol, PREPROCESSOR_EMPTY)

#define PREPROCESSOR_SYMBOL_IF(x, symbol) \
    PREPROCESSOR_SYMBOL_IF_IMPL(x, symbol)


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_SYMBOL_H__ */
