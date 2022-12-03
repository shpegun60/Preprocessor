/*
 *	CREATED BY SHPEGUN60
 *
 *   TEMPLATE MACROCES
 */

#ifndef __PREPROCESSOR_TEMPLATE_H__
#define __PREPROCESSOR_TEMPLATE_H__ 1

#include "preprocessor_map.h"
#include "preprocessor_symbol.h"

/************************************************************************************************************************************************************
 * PREPROCESSOR TEMPLATE EMULATION ON C99
 *
 * Example Usage:
 *      TEMPLATE(sum, int, double)
 *
 * Which expands to:
 *      sum_int_double
 */

#define TEMPLATE(X, ...) PREPROCESSOR_MAP_ALL_TO_ONE(X, PREPROCESSOR_UNDERSCORE(), __VA_ARGS__)

#endif /* __PREPROCESSOR_TEMPLATE_H__ */
