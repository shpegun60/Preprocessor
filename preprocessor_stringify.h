/*
 *	CREATED BY SHPEGUN60
 *
 *   STRINGLIFY MACROCES
 */

#ifndef __PREPROCESSOR_STRINGIFY_H__
#define __PREPROCESSOR_STRINGIFY_H__ 1

/* -- Headers -- */


#ifdef __cplusplus
extern "C" {
#endif

/* -- Macros -- */

#if defined(_MSC_VER) && !defined(__clang__)
    #define PREPROCESSOR_STRINGIFY_IMPL_II(...) #__VA_ARGS__
    #define PREPROCESSOR_STRINGIFY_IMPL(...)                      \
        PREPROCESSOR_IF_ELSE(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))( \
            PREPROCESSOR_STRINGIFY_IMPL_II(__VA_ARGS__),          \
            "")
#else
	#define PREPROCESSOR_STRINGIFY_IMPL(expr) #expr
#endif /* defined(_MSC_VER) && !defined(__clang__) */

#if defined(__MWERKS__)
    #define PREPROCESSOR_STRINGIFY_IMPL_I(tuple) PREPROCESSOR_STRINGIFY_IMPL##tuple
    #define PREPROCESSOR_STRINGIFY(expr)		 PREPROCESSOR_STRINGIFY_IMPL_I((expr))
#elif defined(_MSC_VER) && !defined(__clang__)
    #define PREPROCESSOR_STRINGIFY_IMPL_I(tuple) PREPROCESSOR_STRINGIFY_IMPL tuple
    #define PREPROCESSOR_STRINGIFY(expr)		 PREPROCESSOR_STRINGIFY_IMPL_I((expr))
#else
    #define PREPROCESSOR_STRINGIFY(expr) PREPROCESSOR_STRINGIFY_IMPL(expr)
#endif /* defined(__MWERKS__) */

#define PREPROCESSOR_STRINGIFY_VARIADIC(...) \
    PREPROCESSOR_FOR_EACH(PREPROCESSOR_STRINGIFY, PREPROCESSOR_EMPTY, __VA_ARGS__)

#ifdef __cplusplus
}
#endif

#endif /* __PREPROCESSOR_STRINGIFY_H__ */
