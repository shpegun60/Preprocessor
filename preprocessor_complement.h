/*
 *	CREATED BY SHPEGUN60
 *
 *  COMPLEMENT FIND MACROCES
 */

#ifndef __PREPROCESSOR_COMPLEMENT_H__
#define __PREPROCESSOR_COMPLEMENT_H__ 1

#ifdef __cplusplus
extern "C" {
#endif

/* -- Definitions -- */

#define PREPROCESSOR_COMPL_IMPL_0 1
#define PREPROCESSOR_COMPL_IMPL_1 0

/* -- Macros -- */

/*****************************************************************************************************************************
 * Complementry digit find
 *
 *      PREPROCESSOR_COMPL(0)   // expand to 1
 *      PREPROCESSOR_COMPL(1)   // expand to 0
 *      PREPROCESSOR_COMPL(aaa) // expand to PREPROCESSOR_COMPL_IMPL_aaa ->is not work!!! need: PREPROCESSOR_COMPL(PREPROCESSOR_BOOL(aaa)) --> expands to 0
 *
 */

#if defined(_MSC_VER) && !defined(__clang__)
    #define PREPROCESSOR_COMPL_IMPL_EXPAND(x) x
    #define PREPROCESSOR_COMPL_IMPL(x)		 PREPROCESSOR_COMPL_IMPL_EXPAND(PREPROCESSOR_COMPL_IMPL_##x)
#else
    #define PREPROCESSOR_COMPL_IMPL(x) PREPROCESSOR_COMPL_IMPL_##x
#endif

#if defined(__MWERKS__)
    #define PREPROCESSOR_COMPL_TOKEN(x) PREPROCESSOR_COMPL_IMPL##x
    #define PREPROCESSOR_COMPL(x)	   PREPROCESSOR_COMPL_TOKEN((x))
#else
    #define PREPROCESSOR_COMPL(x) PREPROCESSOR_COMPL_IMPL(x) // expand x
#endif

/*****************************************************************************************************************************/

#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_COMPLEMENT_H__ */
