/*
 *	CREATED BY SHPEGUN60
 *
 *  PREPROCESSOR CONTEXT CAPTURE/GETTING LIBRARY
 */
#ifndef __PREPROCESSOR_CTX_H__
#define __PREPROCESSOR_CTX_H__ 1

#include "preprocessor_map.h"
/*********************************************************************************************************************
 *  PREPROCESSOR CONTEXT TYPE
 *
 *      PREPROCESSOR_CTX_TYPE(ctx)       // expands to --> void* const * const ctx
 */
#define PREPROCESSOR_CTX_TYPE_GET() void* const * const
#define PREPROCESSOR_CTX_TYPE(name) PREPROCESSOR_CTX_TYPE_GET() name

#define PREPROCESSOR_CTX_MUTABLE_TYPE_GET() void**
#define PREPROCESSOR_CTX_MUTABLE_TYPE(name) PREPROCESSOR_CTX_MUTABLE_TYPE_GET() name


#define PREPROCESSOR_CTX_TYPE_CAST(name) ((void* const) name)


/*********************************************************************************************************************
 *  PREPROCESSOR CONTEXT CAPTURE
 *
 *      uint8_t val1 = 254;
 *      uint16_t val2 = 12896;
 *      uint32_t val3 = 40000000;
 *
 *      PREPROCESSOR_CTX_CAPTURE({&dta, &val1, &val2, &val3})       // expands to --> (void* []){&dta, &val1, &val2, &val3}
 */
#define PREPROCESSOR_CTX_CAPTURE(...) (void* const []) __VA_ARGS__


/*********************************************************************************************************************
 *  PREPROCESSOR CONTEXT GET
 *
 *          PREPROCESSOR_CTX_GET(ctx,
 *                               uint8_t  * val1,
 *                               uint16_t * val2,
 *                               uint32_t * val3)
 *
 *                               // expands to-->
 *                              uint8_t  * val1 = ctx[0];
 *                              uint16_t * val2 = ctx[1];
 *                              uint32_t * val3 = ctx[2];
 *
 *  * ATTENTION!!! For deep optimization you need write "const" in pointers -->
 *      PREPROCESSOR_CTX_GET(ctx,
 *                               uint8_t  * const val1,
 *                               uint16_t * const val2,
 *                               uint32_t * const val3)
 *      OR BETTER:
 *      PREPROCESSOR_CTX_GET(ctx,
 *                               const uint8_t  * const val1,
 *                               const uint16_t * const val2,
 *                               const uint32_t * const val3)
 *
 */


#define PREPROCESSOR_CTX_GET(name, ...) PREPROCESSOR_MAP_CTX(name, PREPROCESSOR_EMPTY, __VA_ARGS__)



#define PREPROCESSOR_MAP_CTX(name, sep, ...) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_CTX_INNER(name, sep, 0, __VA_ARGS__)))

#define PREPROCESSOR_MAP_CTX_INNER(name, sep, counter, cur_val, ...)                                                \
  cur_val = name[counter];                                                                                          \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (                                                       \
    PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_CTX_INNER)()(name, sep, PREPROCESSOR_INC(counter), __VA_ARGS__)           \
  )
#define _PREPROCESSOR_MAP_CTX_INNER() PREPROCESSOR_MAP_CTX_INNER


/*********************************************************************************************************************
    EXAMPLE:

#include <stdint.h>

void foo(PREPROCESSOR_CTX_TYPE(ctx))
{
    PREPROCESSOR_CTX_GET(ctx,
                                   const uint8_t  * const val1,
                                   const uint16_t * const val2,
                                   const uint32_t * const val3)
}

int main()
{
    uint8_t val1 = 254;
    uint16_t val2 = 12896;
    uint32_t val3 = 40000000;

    foo(PREPROCESSOR_CTX_CAPTURE({
                                    &val1,
                                    &val2,
                                    &val3
                                 }));
}

*/


#endif /* __PREPROCESSOR_CTX_H__ */
