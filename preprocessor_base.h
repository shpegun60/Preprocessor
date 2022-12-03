/*
 *	CREATED BY SHPEGUN60
 *
 *  PREPROCESSOR BASE MACRO
 */

#ifndef __PREPROCESSOR_BASE_H__
#define __PREPROCESSOR_BASE_H__ 1

#include "preprocessor_symbol.h"


/************************************************************************************************************************************************************
 * PREPROCESSOR EXPAND
 */
#define PREPROCESSOR_EXPAND(...) __VA_ARGS__

/************************************************************************************************************************************************************
 * PREPROCESSOR DEBUG EXPRESSIONS
 */

#define PREPROCESSOR_MACRO_DEBUG(...) _MACRO_DEBUG(_MACRO_DEBUG(__VA_ARGS__))
#define _MACRO_DEBUG(...) PREPROCESSOR_EXPAND(#__VA_ARGS__)


/************************************************************************************************************************************************************
 * Force the pre-processor to expand the macro a large number of times. Usage:
 *
 *   PREPROCESSOR_EVAL(expression)
 *
 * This is useful when you have a macro which evaluates to a valid macro
 * expression which is not subsequently expanded in the same pass. A contrived,
 * but easy to understand, example of such a macro follows. Note that though
 * this example is contrived, this behaviour is abused to implement bounded
 * recursion in macros such as FOR.
 *
 *   #define A(x) x+1
 *   #define PREPROCESSOR_EMPTY
 *   #define NOT_QUITE_RIGHT(x) A PREPROCESSOR_EMPTY (x)
 *   NOT_QUITE_RIGHT(999)
 *
 * Here's what happens inside the C preprocessor:
 *
 * 1. It sees a macro "NOT_QUITE_RIGHT" and performs a single macro expansion
 *    pass on its arguments. Since the argument is "999" and this isn't a macro,
 *    this is a boring step resulting in no change.
 * 2. The NOT_QUITE_RIGHT macro is substituted for its definition giving "A
 *    PREPROCESSOR_EMPTY() (x)".
 * 3. The expander moves from left-to-right trying to expand the macro:
 *    The first token, A, cannot be expanded since there are no brackets
 *    immediately following it. The second token EMPTY(), however, can be
 *    expanded (recursively in this manner) and is replaced with "".
 * 4. Expansion continues from the start of the substituted test (which in this
 *    case is just empty), and sees "(999)" but since no macro name is present,
 *    nothing is done. This results in a final expansion of "A (999)".
 *
 * Unfortunately, this doesn't quite meet expectations since you may expect that
 * "A (999)" would have been expanded into "999+1". Unfortunately this requires
 * a second expansion pass but luckily we can force the macro processor to make
 * more passes by abusing the first step of macro expansion: the preprocessor
 * expands arguments in their own pass. If we define a macro which does nothing
 * except produce its arguments e.g.:
 *
 *   #define PASS_THROUGH(...) __VA_ARGS__
 *
 * We can now do "PASS_THROUGH(NOT_QUITE_RIGHT(999))" causing "NOT_QUITE_RIGHT" to be
 * expanded to "A (999)", as described above, when the arguments are expanded.
 * Now when the body of PASS_THROUGH is expanded, "A (999)" gets expanded to
 * "999+1".
 *
 * The PREPROCESSOR_EVAL defined below is essentially equivalent to a large nesting of
 * "PASS_THROUGH(PASS_THROUGH(PASS_THROUGH(...))" which results in the
 * preprocessor making a large number of expansion passes over the given
 * expression.
 */
//#define PREPROCESSOR_EVAL(...) EVAL1024(__VA_ARGS__)
//#define PREPROCESSOR_EVAL1024(...) EVAL512(EVAL512(__VA_ARGS__))
//#define PREPROCESSOR_EVAL512(...) EVAL256(EVAL256(__VA_ARGS__))
//#define PREPROCESSOR_EVAL256(...) EVAL128(EVAL128(__VA_ARGS__))
//#define PREPROCESSOR_EVAL128(...) EVAL64(EVAL64(__VA_ARGS__))
//#define PREPROCESSOR_EVAL64(...) EVAL32(EVAL32(__VA_ARGS__))
//#define PREPROCESSOR_EVAL32(...) EVAL16(EVAL16(__VA_ARGS__))
//#define PREPROCESSOR_EVAL16(...) EVAL8(EVAL8(__VA_ARGS__))
//#define PREPROCESSOR_EVAL8(...) EVAL4(EVAL4(__VA_ARGS__))
//#define PREPROCESSOR_EVAL4(...) EVAL2(EVAL2(__VA_ARGS__))
//#define PREPROCESSOR_EVAL2(...) EVAL1(EVAL1(__VA_ARGS__))
//#define PREPROCESSOR_EVAL1(...) __VA_ARGS__

#define PREPROCESSOR_EVAL0(...) __VA_ARGS__
#define PREPROCESSOR_EVAL1(...) PREPROCESSOR_EVAL0(PREPROCESSOR_EVAL0(PREPROCESSOR_EVAL0(__VA_ARGS__)))
#define PREPROCESSOR_EVAL2(...) PREPROCESSOR_EVAL1(PREPROCESSOR_EVAL1(PREPROCESSOR_EVAL1(__VA_ARGS__)))
#define PREPROCESSOR_EVAL3(...) PREPROCESSOR_EVAL2(PREPROCESSOR_EVAL2(PREPROCESSOR_EVAL2(__VA_ARGS__)))
#define PREPROCESSOR_EVAL4(...) PREPROCESSOR_EVAL3(PREPROCESSOR_EVAL3(PREPROCESSOR_EVAL3(__VA_ARGS__)))
#define PREPROCESSOR_EVAL5(...) PREPROCESSOR_EVAL4(PREPROCESSOR_EVAL4(PREPROCESSOR_EVAL4(__VA_ARGS__)))

#ifdef _MSC_VER
    // MSVC needs more evaluations
    #define PREPROCESSOR_EVAL6(...) PREPROCESSOR_EVAL5(PREPROCESSOR_EVAL5(PREPROCESSOR_EVAL5(__VA_ARGS__)))
    #define PREPROCESSOR_EVAL(...)  PREPROCESSOR_EVAL6(PREPROCESSOR_EVAL6(__VA_ARGS__))
#else
    #define PREPROCESSOR_EVAL(...)  PREPROCESSOR_EVAL5(__VA_ARGS__)
#endif /* _MSC_VER */


/************************************************************************************************************************************************************
 * Causes a function-style macro to require an additional pass to be expanded.
 *
 * This is useful, for example, when trying to implement recursion since the
 * recursive step must not be expanded in a single pass as the pre-processor
 * will catch it and prevent it.
 *
 * Usage:
 *
 *   PREPROCESSOR_DEFER1(IN_NEXT_PASS)(args, to, the, macro)
 *
 * How it works:
 *
 * 1. When PREPROCESSOR_DEFER1 is expanded, first its arguments are expanded which are
 *    simply IN_NEXT_PASS. Since this is a function-style macro and it has no
 *    arguments, nothing will happen.
 * 2. The body of PREPROCESSOR_DEFER1 will now be expanded resulting in PREPROCESSOR_EMPTY() being
 *    deleted. This results in "IN_NEXT_PASS (args, to, the macro)". Note that
 *    since the macro expander has already passed IN_NEXT_PASS by the time it
 *    expands PREPROCESSOR_EMPTY() and so it won't spot that the brackets which remain can be
 *    applied to IN_NEXT_PASS.
 * 3. At this point the macro expansion completes. If one more pass is made,
 *    IN_NEXT_PASS(args, to, the, macro) will be expanded as desired.
 */
#define PREPROCESSOR_DEFER1(...) __VA_ARGS__ PREPROCESSOR_EMPTY()

/************************************************************************************************************************************************************
 * As with PREPROCESSOR_DEFER1 except here n additional passes are required for PREPROCESSOR_DEFERn.
 *
 * The mechanism is analogous.
 *
 * Note that there doesn't appear to be a way of combining DEFERn macros in
 * order to achieve exponentially increasing defers e.g. as is done by PREPROCESSOR_EVAL.
 */
#define PREPROCESSOR_DEFER2(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()
#define PREPROCESSOR_DEFER3(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()
#define PREPROCESSOR_DEFER4(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()
#define PREPROCESSOR_DEFER5(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()
#define PREPROCESSOR_DEFER6(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()
#define PREPROCESSOR_DEFER7(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()
#define PREPROCESSOR_DEFER8(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()
#define PREPROCESSOR_DEFER9(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()
#define PREPROCESSOR_DEFER10(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()
#define PREPROCESSOR_DEFER11(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()
#define PREPROCESSOR_DEFER12(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()
#define PREPROCESSOR_DEFER13(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER14(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER15(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER16(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER17(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER18(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER19(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()()()()()
#define PREPROCESSOR_DEFER20(...) __VA_ARGS__ PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY PREPROCESSOR_EMPTY()()()()()()()()()()()()()()()()()()()()



#endif /* __PREPROCESSOR_BASE_H__ */
