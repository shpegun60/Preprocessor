/*
 *	CREATED BY SHPEGUN60
 *
 *  BIT & LOGICAL MACROCES
 */


#ifndef __PREPROCESSOR_LOGICAL_H__
#define __PREPROCESSOR_LOGICAL_H__ 1

/* -- Headers -- */

#include "preprocessor_complement.h"
#include "preprocessor_concatenation.h"
#include "preprocessor_boolean.h"


#ifdef __cplusplus
extern "C" {
#endif

/* -- Methods -- */

#define PREPROCESSOR_TRUE(...)  1
#define PREPROCESSOR_FALSE(...) 0


/************************************************************************************************************************************************************
 * Simple preprocessor BINARY operation (other implementation):
 * Logical NOT. Simply performs a lookup.
 */
#define PREPROCESSOR_PRIMITIVE_NOT(b) PREPROCESSOR_CONCAT(PREPROCESSOR_PRIMITIVE_NOT_, b)
#define PREPROCESSOR_PRIMITIVE_NOT_0  1
#define PREPROCESSOR_PRIMITIVE_NOT_1  0



/************************************************************************************************************************************************************
 * Simple preprocessor BINARY bit operation:
 *
 *      PREPROCESSOR_BIT_AND(1)(x) //Expands to x
 *      PREPROCESSOR_BIT_AND(0)(x) //Expands to 0
 *
 *      PREPROCESSOR_BIT_OR(1)(x) //Expands to 1
 *      PREPROCESSOR_BIT_OR(0)(x) //Expands to x
 *
 *      PREPROCESSOR_BIT_XOR(1)(x) //Expands to !x
 *      PREPROCESSOR_BIT_XOR(0)(x) //Expands to x
 *
 *      x - must be 0 or 1
 *
 */

//BINARY AND
#define PREPROCESSOR_BIT_AND(x) PREPROCESSOR_CONCAT(_PREPROCESSOR_BIT_AND_, x)
#define _PREPROCESSOR_BIT_AND_0(x) 0
#define _PREPROCESSOR_BIT_AND_1(x) x

//BINARY OR
#define PREPROCESSOR_BIT_OR(x) PREPROCESSOR_CONCAT(_PREPROCESSOR_BIT_OR_, x)
#define _PREPROCESSOR_BIT_OR_0(x) x
#define _PREPROCESSOR_BIT_OR_1(x) 1

//BINARY XOR
#define PREPROCESSOR_BIT_XOR(x) PREPROCESSOR_CONCAT(_PREPROCESSOR_BIT_XOR_, x)
#define _PREPROCESSOR_BIT_XOR_0(x) x
#define _PREPROCESSOR_BIT_XOR_1(x) PREPROCESSOR_COMPL(PREPROCESSOR_BOOL(x))



/************************************************************************************************************************************************************
 * Simple preprocessor BINARY operation (other implementation):
 * Logical OR. Simply performs a lookup.
 */
#define PREPROCESSOR_OR(a,b) PREPROCESSOR_CONCAT3(_PREPROCESSOR_OR_, a, b)
#define _PREPROCESSOR_OR_00 0
#define _PREPROCESSOR_OR_01 1
#define _PREPROCESSOR_OR_10 1
#define _PREPROCESSOR_OR_11 1


#define PREPROCESSOR_OR3(a, b, c)    PREPROCESSOR_OR(a, PREPROCESSOR_OR(b, c))
#define PREPROCESSOR_OR4(a, b, c, d) PREPROCESSOR_OR3(a, b, PREPROCESSOR_OR(c, d))

/************************************************************************************************************************************************************
 * Simple preprocessor BINARY operation (other implementation):
 * Logical AND. Simply performs a lookup.
 */
#define PREPROCESSOR_AND(a,b) PREPROCESSOR_CONCAT3(_PREPROCESSOR_AND_, a, b)
#define _PREPROCESSOR_AND_00 0
#define _PREPROCESSOR_AND_01 0
#define _PREPROCESSOR_AND_10 0
#define _PREPROCESSOR_AND_11 1

/************************************************************************************************************************************************************
 * Simple preprocessor BINARY operation (other implementation):
 * Logical XOR. Simply performs a lookup.
 */
#define PREPROCESSOR_XOR(x, y) PREPROCESSOR_CONCAT3(_PREPROCESSOR_XOR_, x, y)
#define _PREPROCESSOR_XOR_00    0
#define _PREPROCESSOR_XOR_01    1
#define _PREPROCESSOR_XOR_10    1
#define _PREPROCESSOR_XOR_11    0


/************************************************************************************************************************************************************
 * Simple preprocessor BOOLEAN COMPARATOR
 */
#define PREPROCESSOR_BOOL_EQ(x, y) PREPROCESSOR_CONCAT3(_PREPROCESSOR_BOOL_EQ_, x, y)
#define _PREPROCESSOR_BOOL_EQ_00    1
#define _PREPROCESSOR_BOOL_EQ_01    0
#define _PREPROCESSOR_BOOL_EQ_10    0
#define _PREPROCESSOR_BOOL_EQ_11    1


/************************************************************************************************************************************************************
 * BITAND - for user logic macro
 *
 *      BITAND(0)(x,y,z) // Expands to 0
 *      BITAND(1)(x,y,z) // Expands to x,y,z
 */
#define PREPROCESSOR_BITAND(x) PREPROCESSOR_CONCAT(PREPROCESSOR_BITAND_, x)
#define PREPROCESSOR_BITAND_0(...) 0
#define PREPROCESSOR_BITAND_1(...) __VA_ARGS__


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_LOGICAL_H__ */
