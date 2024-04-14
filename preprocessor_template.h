/*
 *	CREATED BY SHPEGUN60
 *
 *   TEMPLATE MACROCES
 */

#ifndef __PREPROCESSOR_TEMPLATE_H__
#define __PREPROCESSOR_TEMPLATE_H__ 1

#include "preprocessor_map.h"
#include "preprocessor_symbol.h"

//#define PREPROCESSOR_TEMPLATE_HARD_VERSION 1

/************************************************************************************************************************************************************
 * PREPROCESSOR TEMPLATE EMULATION ON C99
 *
 * Example Usage:
 *      TEMPLATE(sum, int, double)
 *
 * Which expands to:
 *      sum_int_double
 */


#ifdef PREPROCESSOR_TEMPLATE_HARD_VERSION
#   define TEMPLATE(X, ...) PREPROCESSOR_MAP_ALL_TO_ONE(X, PREPROCESSOR_UNDERSCORE(), __VA_ARGS__) // slow compiling implementation
#   undef PREPROCESSOR_TEMPLATE_HARD_VERSION
#else
#   define _PREPROCESSOR_TEMPLATE_1(_x1, ...) _x1##_
#   define _PREPROCESSOR_TEMPLATE_2(_x1, ...) _x1##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_3(_x1, _x2, ...) _x1##_##_x2##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_4(_x1, _x2, _x3, ...) _x1##_##_x2##_##_x3##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_5(_x1, _x2, _x3, _x4, ...) _x1##_##_x2##_##_x3##_##_x4##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_6(_x1, _x2, _x3, _x4, _x5, ...) _x1##_##_x2##_##_x3##_##_x4##_##_x5##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_7(_x1, _x2, _x3, _x4, _x5, _x6, ...) _x1##_##_x2##_##_x3##_##_x4##_##_x5##_##_x6##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_8(_x1, _x2, _x3, _x4, _x5, _x6, _x7, ...) _x1##_##_x2##_##_x3##_##_x4##_##_x5##_##_x6##_##_x7##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_9(_x1, _x2, _x3, _x4, _x5, _x6, _x7, _x8, ...) _x1##_##_x2##_##_x3##_##_x4##_##_x5##_##_x6##_##_x7##_##_x8##_##__VA_ARGS__
#   define _PREPROCESSOR_TEMPLATE_10(_x1, _x2, _x3, _x4, _x5, _x6, _x7, _x8, _x9, ...) _x1##_##_x2##_##_x3##_##_x4##_##_x5##_##_x6##_##_x7##_##_x8##_##_x9##_##__VA_ARGS__
#
#   define TEMPLATE(X, ...) PREPROCESSOR_CONCAT(_PREPROCESSOR_TEMPLATE_, PREPROCESSOR_ARGS_COUNT(X, __VA_ARGS__))(X, __VA_ARGS__)
#endif /* PREPROCESSOR_TEMPLATE_HARD_VERSION */


#endif /* __PREPROCESSOR_TEMPLATE_H__ */
