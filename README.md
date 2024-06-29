# Preprocessor
 * PREPROCESSOR - a library that allows you to summon the devil or other evil spirits in the programming language C99 or later, and no joke, it allows you to use preprocessor metaprogramming in C
 
 # Supported Compilers:
 *      MSVC: After Visual Studio 2019 verion 16.6;	Compiler version after--> msvc v19.26, 
         you must add /Zc:preprocessor to your compilation flags
 - Announcing full support for a C/C++ conformant preprocessor in MSVC: https://devblogs.microsoft.com/cppblog/announcing-full-support-for-a-c-c-conformant-preprocessor-in-msvc/
 - Stackoverflow problem: https://stackoverflow.com/questions/9183993/msvc-variadic-macro-expansion
 - /Zc:preprocessor (Enable preprocessor conformance mode) instruction: https://learn.microsoft.com/en-us/cpp/build/reference/zc-preprocessor?view=msvc-170
 - Partial supporting on old Visual Studio versions (not tested) with other compilation flag, /experimental:preprocessor (Enable preprocessor conformance mode) instruction: https://learn.microsoft.com/en-us/cpp/build/reference/experimental-preprocessor?view=msvc-170
 
 *      GCC: All compilers supported
 *      Clang: All compilers supported
 
 # Supported C standards:
 *      All after GNU/ISO C99
 
 Compilation checked with "Compiler Explorer", you can import file: compiler_explorer_project.zip
 * Github: https://github.com/compiler-explorer/compiler-explorer
 * Web: https://godbolt.org/
 # Evil spirit looks like:
<img src="evil_spirit/evil.jpg" width="650" title="hover text">

# EXAMPLE Preprocessor context capture
```c
#include <stdint.h>
#include "preprocessor_ctx.h"

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

```

# Spells to summon a real devil in this language really look like this:
```c
#ifndef ENTITY_MACRO_H
#define ENTITY_MACRO_H

#include "entity_manager.h"

#ifdef C_ENTITY_FRAMEWORK_LIB_ENA
#include "preprocessor.h"
#include "my_ctypes.h"
#include "my_ctype_id.h"


// TUPLE((entityName, descr, isCustomSpace, isHeap, arg, (parent1 p1; ... parentN pN;)), (type1, name1, bitFlags1, descr1, incrementSize1, fieldInitEnable1, arrayStartNumber1, specSymbol1, fieldPath1) ... (typeN, nameN, bitFlagsN, descrN, incrementSizeN, fieldInitEnableN, arrayStartNumberN, specSymbolN, fieldPathN))
// parameter: (breakExpr, entityNumber, fieldNumber, entityPtr, structObjectPointer, structName)

#define ENTITY_STRUCT_MAKE_VAR(x) PREPROCESSOR_IF(PREPROCESSOR_PRIMITIVE_NOT(PREPROCESSOR_NAT_EQ(PREPROCESSOR_TUPLE_COUNT(x), 9)))(\
                                        PREPROCESSOR_IF( PREPROCESSOR_PRIMITIVE_NOT(PREPROCESSOR_NAT_EQ(PREPROCESSOR_TUPLE_COUNT(x), 7))) (PREPROCESSOR_GET_ARG(7)(PREPROCESSOR_UNTUPLE(x))) PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)) PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))   /* for making struct fields (auto adds [] if this field is array)*/  \
                                        PREPROCESSOR_IF( PREPROCESSOR_PRIMITIVE_NOT(PREPROCESSOR_NAT_EQ(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x)), 1)) )([PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))]);\
                                  )



#define ENTITY_STRUCT_COUNTER(x) PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))                                                   // for counting fields

#define ENTITY_STRUCT_INIT_FIELD(par, x) if (                                                                                                                                                                                                                                                                                                                                   \
                                            (PREPROCESSOR_IF_ELSE(PREPROCESSOR_NAT_EQ(PREPROCESSOR_TUPLE_COUNT(x), 9))(                                                                                                                                                                                                                                                         \
                                                    PREPROCESSOR_IF_ELSE(PREPROCESSOR_NAT_EQ(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x)), 1))(                                                                                                                                                                                                                             \
                                                        PREPROCESSOR_IF_ELSE( PREPROCESSOR_AND(PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par))), PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(x)))) )(                                                                                                                                   \
                                                                                                    initField(     (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                    /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        (void*)(&((PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par)))->PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x))))) ,                                               /* &structObjectPointer->nameN */                   \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                                                                    initField(     (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                    /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        NULL)                                                                                                                                                               /* field_ptr */                                     \
                                                        ),                                                                                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                        PREPROCESSOR_IF_ELSE( PREPROCESSOR_AND(PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par))), PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(x)))) )(                                                                                                                                   \
                                                                                                    initFieldArray( (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                   /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* incrementSizeN */                                \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        (void*)(&((PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par)))->PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x)))) ,                                                /* &structObjectPointer->nameN */                   \
                                                                                                                                                        PREPROCESSOR_GET_ARG(6)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                  /* arrayStartNumber */                              \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                                                                    initFieldArray( (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                   /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(8)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* incrementSizeN */                                \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        NULL,                                                                                                                                                               /* field_ptr */                                     \
                                                                                                                                                        PREPROCESSOR_GET_ARG(6)(PREPROCESSOR_UNTUPLE(x)))                                                                                                                   /* arrayStartNumber */                              \
                                                        )                                                                                                                                                                                                                                                                                                                       \
                                                    ), /* ----------------------------------------empty field path------------------------------------------------------------------------------------------------------- */                                                                                                                                                    \
                                                     PREPROCESSOR_IF_ELSE(PREPROCESSOR_NAT_EQ(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x)), 1))(                                                                                                                                                                                                                            \
                                                        PREPROCESSOR_IF_ELSE( PREPROCESSOR_AND(PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par))), PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(x)))) )(                                                                                                                                   \
                                                                                                    initField(     (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                    /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        (void*)(&((PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par)))->PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))))) ,                                               /* &structObjectPointer->nameN */                   \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                                                                    initField(     (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                    /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        NULL)                                                                                                                                                               /* field_ptr */                                     \
                                                        ),                                                                                                                                                                                                                                                                                                                      \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                        PREPROCESSOR_IF_ELSE( PREPROCESSOR_AND(PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par))), PREPROCESSOR_BOOL(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(x)))) )(                                                                                                                                   \
                                                                                                    initFieldArray( (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                   /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* incrementSizeN */                                \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        (void*)(&((PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(par)))->PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x)))) ,                                                /* &structObjectPointer->nameN */                   \
                                                                                                                                                        PREPROCESSOR_GET_ARG(6)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                  /* arrayStartNumber */                              \
                                                                                                                                                                                                                                                                                                                                                                                \
                                                                                                    initFieldArray( (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(par))),                                                                                                                                                   /* entityPtr */                                     \
                                                                                                                                                        (&PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(par))),                                                                                                              /* &fieldNumber */                                  \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* bitFlagsN */                                     \
                                                                                                                                                        offsetof(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(par)), PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(x))),                                                     /* offsetof(structName, nameN) */                   \
                                                                                                                                                        (MY_CTYPE_GET_TYPE_ID(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(x)))),                                                                                           /* number of typeN */                               \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* incrementSizeN */                                \
                                                                                                                                                        (PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(x))),                                                                                                                 /* descrN */                                        \
                                                                                                                                                        NULL,                                                                                                                                                               /* field_ptr */                                     \
                                                                                                                                                        PREPROCESSOR_GET_ARG(6)(PREPROCESSOR_UNTUPLE(x)))                                                                                                                   /* arrayStartNumber */                              \
                                                        )                                                                                                                                                                                                                                                                                                                       \
                                                    )                                                                                                                                                                                                                                                                                                                           \
                                            )                                                                                                                                                                                                                                                                                                                                   \
                                        ) == ENTITY_NUMBER_ERROR) {                                                                                                                                                                                                                                                                                                             \
                                            PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(par));                                                                                                                                                                                                                                                                                 \
                                        }







#define ENTITY_MACRO_EXPAND_STRUCT(...) ENTITY_MACRO_EXPAND_STRUCT_IMPL(__VA_ARGS__)
#define ENTITY_MACRO_EXPAND_STRUCT_IMPL(...)\
    typedef struct {\
        PREPROCESSOR_IF(PREPROCESSOR_NAT_EQ(PREPROCESSOR_TUPLE_COUNT(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__))), 6))( PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(5)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__))))) )\
        PREPROCESSOR_TUPLE_FOR_EACH(ENTITY_STRUCT_MAKE_VAR, PREPROCESSOR_EMPTY, PREPROCESSOR_TUPLE_TAIL(__VA_ARGS__))\
    } PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__)))) /* entityName */


#define ENTITY_MACRO_EXPAND_INIT(breakExpr, entityNumber, fieldNumber, entityPtr, structObjectPointer, ...)\
    (entityNumber) = ENTITY_NUMBER_ERROR;\
    initEntity(&(entityNumber),\
               (PREPROCESSOR_TUPLE_FOR_EACH(ENTITY_STRUCT_COUNTER, PREPROCESSOR_PLUS, PREPROCESSOR_TUPLE_TAIL(__VA_ARGS__))),       /* (incrementSize1 + ... + incrementSizeN) */                                   \
               sizeof(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__))))),   /* sizeof(entityName)   */                                                      \
               PREPROCESSOR_GET_ARG(1)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__)))),           /* descr                */                                                      \
               PREPROCESSOR_GET_ARG(2)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__)))),           /* isCustomSpace        */                                                      \
               PREPROCESSOR_GET_ARG(3)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__)))),           /* isHeap               */                                                      \
               PREPROCESSOR_GET_ARG(4)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__)))));          /* arg                  */                                                      \
    \
    if((entityNumber) == ENTITY_NUMBER_ERROR) {\
        breakExpr;\
    }\
    \
    \
    (entityPtr) = getEntityPointer(entityNumber);\
    if((entityPtr) == NULL) {\
        breakExpr;\
    }\
    \
    PREPROCESSOR_TUPLE_FOR_EACH_PARAMETER(\
        (breakExpr, entityNumber, fieldNumber, entityPtr, structObjectPointer, PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(PREPROCESSOR_GET_ARG(0)(PREPROCESSOR_UNTUPLE(__VA_ARGS__))))), \
        ENTITY_STRUCT_INIT_FIELD, \
        PREPROCESSOR_EMPTY, \
        PREPROCESSOR_TUPLE_TAIL(__VA_ARGS__))



int entityMactoTest();

#endif /* C_ENTITY_FRAMEWORK_LIB_ENA */

#endif /* ENTITY_MACRO_H */

```

# OR:

```c
#define $POINTER(x) x
#define $STATIC_ARRAY(x) x
#define $CONST(x) x

//sizeof merge macro -----------------------------------------------------------------------------------------------
#define RAW_P_MERGE_OPERATION(op, sep, ...) \
 PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(RAW_P_MERGE_OPERATION_INNER(op, sep, ##__VA_ARGS__)))

#define RAW_P_MERGE_OPERATION_INNER(op, sep, cur_val, ...) \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $POINTER))( \
        RAW_P_MERGE_OPERATION_POINTER_INNER(op, sep, ##__VA_ARGS__),\
        PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $STATIC_ARRAY))(\
            RAW_P_MERGE_OPERATION_STATIC_ARRAY_INNER(op, sep, ##__VA_ARGS__),\
            PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $CONST))(\
                RAW_P_MERGE_OPERATION_CONST_INNER(op, sep, ##__VA_ARGS__),\
                op(cur_val)\
                RAW_P_MERGE_OPERATION_ELSE_INNER(op, sep, ##__VA_ARGS__)\
            )\
        )\
    )

#define _RAW_P_MERGE_OPERATION_INNER() RAW_P_MERGE_OPERATION_INNER

#define RAW_P_MERGE_OPERATION_ELSE_INNER(op, sep, ...)\
    PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))( \
      sep() PREPROCESSOR_DEFER5(_RAW_P_MERGE_OPERATION_INNER)()(op, sep, ##__VA_ARGS__) \
    )

#define RAW_P_MERGE_OPERATION_POINTER_INNER(op, sep, len, arr, ...)\
    len\
    RAW_P_MERGE_OPERATION_ELSE_INNER(op, sep, ##__VA_ARGS__)

#define RAW_P_MERGE_OPERATION_STATIC_ARRAY_INNER(op, sep, arr, ...)\
    op(arr)\
    RAW_P_MERGE_OPERATION_ELSE_INNER(op, sep, ##__VA_ARGS__)

#define RAW_P_MERGE_OPERATION_CONST_INNER(op, sep, val, type, ...)\
    op(type)\
    RAW_P_MERGE_OPERATION_ELSE_INNER(op, sep, ##__VA_ARGS__)


// write merge macro------------------------------------------------------------------------------------------------
#define RAW_P_MERGE_WRITE_OPERATION(foo, par1, op, cast, sep, ...) \
    PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(RAW_P_MERGE_WRITE_OPERATION_INNER(foo, par1, op, cast, sep, 0, ##__VA_ARGS__)))
#define RAW_P_MERGE_WRITE_OPERATION_INNER(foo, par1, op, cast, sep, count, cur_val, ...) \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $POINTER))( \
        RAW_P_MERGE_WRITE_OPERATION_POINTER_INNER(foo, par1, op, cast, sep, count, ##__VA_ARGS__),\
        PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $STATIC_ARRAY))( \
            RAW_P_MERGE_WRITE_OPERATION_STATIC_ARRAY_INNER(foo, par1, op, cast, sep, count, ##__VA_ARGS__),\
            PREPROCESSOR_IF_ELSE(PREPROCESSOR_EQUAL(cur_val, $CONST))(\
                RAW_P_MERGE_WRITE_OPERATION_CONST_INNER(foo, par1, op, cast, sep, count, ##__VA_ARGS__),\
                foo(par1, op(cur_val), op(cur_val), (cast)&cur_val) \
                RAW_P_MERGE_WRITE_OPERATION_ELSE(foo, par1, op, cast, sep, count, ##__VA_ARGS__)\
            )\
        )\
    )
#define _RAW_P_MERGE_WRITE_OPERATION_INNER() RAW_P_MERGE_WRITE_OPERATION_INNER


#define RAW_P_MERGE_WRITE_OPERATION_POINTER_INNER(foo, par1, op, cast, sep, count, len, arr, ...)\
        foo(par1, len, op(arr[0]), (cast)arr)\
        RAW_P_MERGE_WRITE_OPERATION_ELSE(foo, par1, op, cast, sep, count, ##__VA_ARGS__)

#define RAW_P_MERGE_WRITE_OPERATION_STATIC_ARRAY_INNER(foo, par1, op, cast, sep, count, arr, ...)\
        foo(par1, op(arr), op(arr[0]), (cast)arr)\
        RAW_P_MERGE_WRITE_OPERATION_ELSE(foo, par1, op, cast, sep, count, ##__VA_ARGS__)

#define RAW_P_MERGE_WRITE_OPERATION_CONST_INNER(foo, par1, op, cast, sep, count, val, type, ...)\
    type PREPROCESSOR_CONCAT(const_,count) = val;\
    foo(par1, op(type), op(type), (cast)&PREPROCESSOR_CONCAT(const_,count))\
    RAW_P_MERGE_WRITE_OPERATION_ELSE(foo, par1, op, cast, sep, count, ##__VA_ARGS__)


#define RAW_P_MERGE_WRITE_OPERATION_ELSE(foo, par1, op, cast, sep, count, ...)\
    PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))( \
        sep() PREPROCESSOR_DEFER5(_RAW_P_MERGE_WRITE_OPERATION_INNER)()(foo, par1, op, cast, sep, PREPROCESSOR_INC(count), ##__VA_ARGS__) \
    )


//-----------------------------------------------------------------------------------------------------------------
#define WRITE_PAYLOAD_MACRO(foo, par1, beforeExpr, afterExpr, ...)\
    do{\
        reg totalSize = RAW_P_MERGE_OPERATION(sizeof, PREPROCESSOR_PLUS, ##__VA_ARGS__);\
        beforeExpr;\
        RAW_P_MERGE_WRITE_OPERATION(foo, par1, sizeof, u8*, PREPROCESSOR_COMMA_POINT, ##__VA_ARGS__);\
        afterExpr;\
        (void)totalSize;\
    }while(0U)

//-----------------------------------------------------------------------------------------------------------------
#define READ_PAYLOAD_MACRO(foo, par1, beforeExpr, afterExpr, ...) WRITE_PAYLOAD_MACRO(foo, par1, beforeExpr, afterExpr, __VA_ARGS__)
```
