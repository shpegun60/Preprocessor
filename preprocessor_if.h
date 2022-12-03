/*
 *	CREATED BY SHPEGUN60
 *
 *  PREPROCESSOR IF, IF_ELSE MACROCES
 */

#ifndef __PREPROCESSOR_IF_H__
#define __PREPROCESSOR_IF_H__ 1

/* -- Headers -- */

#include "preprocessor_boolean.h"
#include "preprocessor_concatenation.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */


/************************************************************************************************************************************************************
 * Macro if statement. Usage:
 *
 *   PREPROCESSOR_IF(c)(expansion when true)
 *
 * Here's how:
 *
 * 1. The preprocessor expands the arguments to _IF casting the condition to '0'
 *    or '1'.
 * 2. The casted condition is concatencated with _PREPROCESSOR_IF_ giving _PREPROCESSOR_IF_0 or _PREPROCESSOR_IF_1.
 * 3. The _PREPROCESSOR_IF_0 and _PREPROCESSOR_IF_1 macros either returns the argument or doesn't (e.g.
 *    they implement the "choice selection" part of the macro).
 * 4. Note that the "true" clause is in the extra set of brackets; thus these
 *    become the arguments to _PREPROCESSOR_IF_0 or _PREPROCESSOR_IF_1 and thus a selection is made!
 */
#define PREPROCESSOR_IF(c) _PREPROCESSOR_IF(PREPROCESSOR_BOOL(c))
#define _PREPROCESSOR_IF(c) PREPROCESSOR_CONCAT(_PREPROCESSOR_IF_, c)
#define _PREPROCESSOR_IF_0(...)
#define _PREPROCESSOR_IF_1(...) __VA_ARGS__

/************************************************************************************************************************************************************
 * Macro if/else statement. Usage:
 *
 *   PREPROCESSOR_IF_ELSE(c)( \
 *     expansion when true, \
 *     expansion when false \
 *   )
 *
 * The mechanism is analogous to IF.
 */
#define PREPROCESSOR_IF_ELSE(c) _PREPROCESSOR_IF_ELSE(PREPROCESSOR_BOOL(c))
#define _PREPROCESSOR_IF_ELSE(c) PREPROCESSOR_CONCAT(_PREPROCESSOR_IF_ELSE_, c)
#define _PREPROCESSOR_IF_ELSE_0(t,...) __VA_ARGS__
#define _PREPROCESSOR_IF_ELSE_1(t,...) t



#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_IF_H__ */
