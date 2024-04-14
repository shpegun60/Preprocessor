/*
 *	CREATED BY SHPEGUN60
 *
 *  PREPROCESSOR - a library that allows you to summon the devil or other evil spirits in the programming language C99 or later, and no joke, it allows you to use preprocessor metaprogramming in C
 *
 *  Supporeted Compilers:
 *      MSVC: After Visual Studio 2019 verion 16.6;	Compiler version after--> msvc v19.26, 
 *             you must add /Zc:preprocessor to your compilation flags. Instruction: https://learn.microsoft.com/en-us/cpp/build/reference/zc-preprocessor?view=msvc-170
 *      GCC: All compilers supported
 *      Clang: All compilers supported
 *
 *  Supported C standards:
 *      All after GNU/ISO C99
 */

#ifndef __PREPROCESSOR_H__
#define __PREPROCESSOR_H__ 1

/* -- Headers -- */

#include "preprocessor_arguments.h"
#include "preprocessor_arithmetic.h"
#include "preprocessor_base.h"
#include "preprocessor_boolean.h"
#include "preprocessor_char_eq.h"
#include "preprocessor_comparison.h"
#include "preprocessor_complement.h"
#include "preprocessor_concatenation.h"
#include "preprocessor_cycle.h"
#include "preprocessor_detection.h"
#include "preprocessor_div.h"
#include "preprocessor_ctx.h"
#include "preprocessor_if.h"
#include "preprocessor_keyword_eq.h"
#include "preprocessor_logical.h"
#include "preprocessor_map.h"
#include "preprocessor_nat_eq.h"
#include "preprocessor_nat_op.h"
#include "preprocessor_serial.h"
#include "preprocessor_stringify.h"
#include "preprocessor_symbol.h"
#include "preprocessor_template.h"
#include "preprocessor_tuple.h"
#include "preprocessor_type_eq.h"
#include "preprocessor_unused.h"


#if defined(_MSC_VER)
#   define STRINGIZE_HELPER(x) #x
#   define STRINGIZE(x) STRINGIZE_HELPER(x)
#   define WARNING(desc) message(__FILE__ "(" STRINGIZE(__LINE__) ") : Warning: " #desc)
#
#   if (_MSC_VER < 1926)
#       error do not supported MSVC compiler, supports only after Visual Studio 2019 verion 16.6 and compiler version after--> msvc v19.26
#   else
#       pragma WARNING("_MSC_VER: User must add /Zc:preprocessor to compilation flags see https://devblogs.microsoft.com/cppblog/announcing-full-support-for-a-c-c-conformant-preprocessor-in-msvc/")
#   endif /* (_MSC_VER < 1926) */
#
#endif /* defined(_MSC_VER) */



#endif /* __PREPROCESSOR_H__ */
