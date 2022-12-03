/*
 *	CREATED BY SHPEGUN60
 *
 *  BOOLEAN PREPROCESSOR CAST MACROCES
 */

#ifndef __PREPROCESSOR_BOOLEAN_H__
#define __PREPROCESSOR_BOOLEAN_H__ 1

/* -- Headers -- */
#include "preprocessor_detection.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Definitions -- */

/************************************************************************************************************************************************************
 * Logical negation. 0 is defined as false and everything else as true.
 *
 * When 0, _PREPROCESSOR_NOT_0 will be found which evaluates to the PROBE. When 1 (or any other
 * value) is given, an appropriately named macro won't be found and the
 * concatenated string will be produced. PREPROCESSOR_IS_PROBE then simply checks to see if
 * the PROBE was returned, cleanly converting the argument into a 1 or 0.
 *
 *      PREPROCESSOR_NOT(1)     // expand to 0
 *      PREPROCESSOR_NOT(0)     // expand to 1
 *      PREPROCESSOR_NOT(aaa)   // expand to 0 (aaa - is not defined than equal 1)
 *      PREPROCESSOR_NOT()      // expand to 0 (empty parameter than equal 1)
 */
#define PREPROCESSOR_NOT(x) _PREPROCESSOR_NOT(x) // expand x
#define _PREPROCESSOR_NOT(x) PREPROCESSOR_IS_PROBE(PREPROCESSOR_CONCAT(_PREPROCESSOR_NOT_, x))
#define _PREPROCESSOR_NOT_0 PREPROCESSOR_PROBE()

/************************************************************************************************************************************************************
 * Macro version of C's famous "cast to bool" operator (i.e. !!) which takes
 * anything and casts it to 0 if it is 0 and 1 otherwise.
 *
 *      PREPROCESSOR_BOOL(1)    // expand to 1
 *      PREPROCESSOR_BOOL(0)    // expand to 0
 *      PREPROCESSOR_BOOL(aaa)  // expand to 1 (aaa - is not defined)
 *      PREPROCESSOR_BOOL()     // expand to 1 (empty parameter)
 */
#define PREPROCESSOR_BOOL(x) PREPROCESSOR_NOT(PREPROCESSOR_NOT(x))

/************************************************************************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_BOOLEAN_H__ */
