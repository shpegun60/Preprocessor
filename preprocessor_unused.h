#ifndef __PREPROCESSOR_UNUSED_H__
#define __PREPROCESSOR_UNUSED_H__ 1

#include "preprocessor_cycle.h"
/************************************************************************************************************************************************************
 *
 *       PREPROCESSOR_UNUSED_SERIAL(_1, _2, _3)
 *
 * EXPANDS TO:
 *      (void)_1 ; (void)_2 ; (void)_3 ;
 *
 *
 */


#define PREPROCESSOR_UNUSED_FOO(x) (void)x
#define PREPROCESSOR_UNUSED_SERIAL(...) PREPROCESSOR_FOR_EACH(PREPROCESSOR_UNUSED_FOO, PREPROCESSOR_COMMA_POINT, __VA_ARGS__)



#endif /* __PREPROCESSOR_UNUSED_H__ */
