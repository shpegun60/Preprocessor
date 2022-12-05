/*
 *	CREATED BY SHPEGUN60
 *
 *  TEXT CONCATENATION MACROCES
 */

#ifndef __PREPROCESSOR_CONCATENATION_H__
#define __PREPROCESSOR_CONCATENATION_H__ 1

/* -- Headers -- */

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

/************************************************************************************************************************************************************
 * PREPROCESSOR EXPAND
 */
#define PREPROCESSOR_CONCAT_EXPAND(...) __VA_ARGS__


/************************************************************************************************************************************************************
 * Indirection around the standard ## concatenation operator. This simply
 * ensures that the arguments are expanded (once) before concatenation.
 */


#define PREPROCESSOR_CONCAT(a, ...) PREPROCESSOR_CONCAT_IMPL(a, __VA_ARGS__)
#define PREPROCESSOR_CONCAT_IMPL(a, ...) PREPROCESSOR_CONCAT_EXPAND(a ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT3(a, b, ...) PREPROCESSOR_CONCAT3_IMPL(a, b, __VA_ARGS__)
#define PREPROCESSOR_CONCAT3_IMPL(a, b, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT4(a, b, c, ...) PREPROCESSOR_CONCAT4_IMPL(a, b, c, __VA_ARGS__)
#define PREPROCESSOR_CONCAT4_IMPL(a, b, c, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT5(a, b, c, d, ...) PREPROCESSOR_CONCAT5_IMPL(a, b, c, d, __VA_ARGS__)
#define PREPROCESSOR_CONCAT5_IMPL(a, b, c, d, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT6(a, b, c, d, e, ...) PREPROCESSOR_CONCAT6_IMPL(a, b, c, d, e, __VA_ARGS__)
#define PREPROCESSOR_CONCAT6_IMPL(a, b, c, d, e, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT7(a, b, c, d, e, f, ...) PREPROCESSOR_CONCAT7_IMPL(a, b, c, d, e, f, __VA_ARGS__)
#define PREPROCESSOR_CONCAT7_IMPL(a, b, c, d, e, f, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT8(a, b, c, d, e, f, g, ...) PREPROCESSOR_CONCAT8_IMPL(a, b, c, d, e, f, g, __VA_ARGS__)
#define PREPROCESSOR_CONCAT8_IMPL(a, b, c, d, e, f, g, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT9(a, b, c, d, e, f, g, h, ...) PREPROCESSOR_CONCAT9_IMPL(a, b, c, d, e, f, g, h, __VA_ARGS__)
#define PREPROCESSOR_CONCAT9_IMPL(a, b, c, d, e, f, g, h, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT10(a, b, c, d, e, f, g, h, i, ...) PREPROCESSOR_CONCAT10_IMPL(a, b, c, d, e, f, g, h, i, __VA_ARGS__)
#define PREPROCESSOR_CONCAT10_IMPL(a, b, c, d, e, f, g, h, i, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT11(a, b, c, d, e, f, g, h, i, j, ...) PREPROCESSOR_CONCAT11_IMPL(a, b, c, d, e, f, g, h, i, j, __VA_ARGS__)
#define PREPROCESSOR_CONCAT11_IMPL(a, b, c, d, e, f, g, h, i, j, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT12(a, b, c, d, e, f, g, h, i, j, k, ...) PREPROCESSOR_CONCAT12_IMPL(a, b, c, d, e, f, g, h, i, j, k, __VA_ARGS__)
#define PREPROCESSOR_CONCAT12_IMPL(a, b, c, d, e, f, g, h, i, j, k, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT13(a, b, c, d, e, f, g, h, i, j, k, l, ...) PREPROCESSOR_CONCAT13_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, __VA_ARGS__)
#define PREPROCESSOR_CONCAT13_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT14(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) PREPROCESSOR_CONCAT14_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, __VA_ARGS__)
#define PREPROCESSOR_CONCAT14_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT15(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) PREPROCESSOR_CONCAT15_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, n, __VA_ARGS__)
#define PREPROCESSOR_CONCAT15_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, n, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## n ## __VA_ARGS__)

#define PREPROCESSOR_CONCAT16(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) PREPROCESSOR_CONCAT16_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, __VA_ARGS__)
#define PREPROCESSOR_CONCAT16_IMPL(a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, ...) PREPROCESSOR_CONCAT_EXPAND(a ## b ## c ## d ## e ## f ## g ## h ## i ## j ## k ## l ## m ## n ## o ## __VA_ARGS__)


/************************************************************************************************************************************************************/


#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_CONCATENATION_H__ */
