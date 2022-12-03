/*
 *	CREATED BY SHPEGUN60
 *
 *   LINE CONCATENATION MACROCES
 */

#ifndef __PREPROCESSOR_SERIAL_H__
#define __PREPROCESSOR_SERIAL_H__ 1

/* -- Headers -- */
#include "preprocessor_concatenation.h"

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

#define PREPROCESSOR_SERIAL_ID_IMPL(expr) \
	PREPROCESSOR_CONCAT(expr, __LINE__)

#define PREPROCESSOR_SERIAL_ID(expr) \
	PREPROCESSOR_SERIAL_ID_IMPL(expr)

#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_SERIAL_H__ */
