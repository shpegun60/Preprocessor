/*
 *	CREATED BY SHPEGUN60
 *
 *  DETECTION MACROCES
 */

#ifndef __PREPROCESSOR_DETECTION_H__
#define __PREPROCESSOR_DETECTION_H__ 1

/* -- Headers -- */

#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

/************************************************************************************************************************************************************
 * Expects a single input (not containing commas). Returns 1 if the input is
 * PREPROCESSOR_PROBE() and otherwise returns 0.
 *
 * This can be useful as the basis of a NOT function.
 *
 * This macro abuses the fact that PREPROCESSOR_PROBE() contains a comma while other valid
 * inputs must not.
 *
 * PREPROCESSOR_IS_PROBE(PREPROCESSOR_PROBE())      // Expands to 1
 * PREPROCESSOR_IS_PROBE(xxx)                       // Expands to 0
 */

#   define PREPROCESSOR_IS_PROBE_SND(...)            PREPROCESSOR_IS_PROBE_SND_IMPL(__VA_ARGS__, ~)
#   define PREPROCESSOR_IS_PROBE_SND_IMPL(_x, _y, ...) _y

#define PREPROCESSOR_IS_PROBE(...) _PREPROCESSOR_IS_PROBE(__VA_ARGS__) // expand all arguments
#define _PREPROCESSOR_IS_PROBE(...) PREPROCESSOR_IS_PROBE_SND(__VA_ARGS__, 0)
#define PREPROCESSOR_PROBE() ~, 1


// #define PREPROCESSOR_UNT(...) __VA_ARGS__

// #define PREPROCESSOR_ARGS_SND1(_x, ...)   PREPROCESSOR_ARGS_SND_IMPL1(_x, __VA_ARGS__, ~)
// #define PREPROCESSOR_ARGS_SND_IMPL1(_x, ...) PREPROCESSOR_GET_ARG(1) _x


// #define PREPROCESSOR_IS_PROBE(x) PREPROCESSOR_ARGS_SND1((bbb), 0)
// #define PREPROCESSOR_PROBE() (~, 1)


/************************************************************************************************************************************************************
 * Detection for parenthesis --> ()
 *
 *      PREPROCESSOR_IS_PAREN(())  // Expands to 1
 *      PREPROCESSOR_IS_PAREN(xxx) // Expands to 0
 */
#define PREPROCESSOR_IS_PAREN(x) _PREPROCESSOR_IS_PAREN(x) // expand x
#define _PREPROCESSOR_IS_PAREN(x) PREPROCESSOR_IS_PROBE(PREPROCESSOR_IS_PAREN_PROBE x)
#define PREPROCESSOR_IS_PAREN_PROBE(...) PREPROCESSOR_PROBE()

/************************************************************************************************************************************************************/




#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_DETECTION_H__ */
