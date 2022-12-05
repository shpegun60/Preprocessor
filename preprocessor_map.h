/*
 *	CREATED BY SHPEGUN60
 *
 *  MAP MACROCES
 */

#ifndef __PREPROCESSOR_MAP_H__
#define __PREPROCESSOR_MAP_H__ 1

#include "preprocessor_base.h"
#include "preprocessor_arguments.h"
#include "preprocessor_if.h"
#include "preprocessor_concatenation.h"
#include "preprocessor_boolean.h"


/************************************************************************************************************************************************************
 * Macro map/list comprehension. Usage:
 *
 *   PREPROCESSOR_MAP(op, sep, ...)
 *
 * Produces a 'sep()' - separated list of the result of op(arg) for each arg.
 *
 * Example Usage:
 *
 *   #define MAKE_HAPPY(x) happy_##x
 *   PREPROCESSOR_MAP(MAKE_HAPPY, PREPROCESSOR_COMMA, 1, 2, 3)
 *
 * Which expands to:
 *
 *    happy_1 , happy_2 , happy_3
 *
 * How it works:
 *
 * 1. The PREPROCESSOR_MAP macro simply maps the inner PREPROCESSOR_MAP_INNER function in an PREPROCESSOR_EVAL which
 *    forces it to be expanded a large number of times, thus enabling many steps
 *    of iteration (see step 6).
 * 2. The PREPROCESSOR_MAP_INNER macro is substituted for its body.
 * 3. In the body, op(cur_val) is substituted giving the value for this
 *    iteration.
 * 4. The IF macro expands according to whether further iterations are required.
 *    This expansion either produces _IF_0 or _IF_1.
 * 5. Since the IF is followed by a set of brackets containing the "if true"
 *    clause, these become the argument to _IF_0 or _IF_1. At this point, the
 *    macro in the brackets will be expanded giving the separator followed by
 *    _PREPROCESSOR_MAP_INNER PREPROCESSOR_EMPTY()()(op, sep, __VA_ARGS__).
 * 5. If the IF was not taken, the above will simply be discarded and everything
 *    stops. If the IF is taken, The expression is then processed a second time
 *    yielding "_PREPROCESSOR_MAP_INNER()(op, sep, __VA_ARGS__)". Note that this call looks
 *    very similar to the  essentially the same as the original call except the
 *    first argument has been dropped.
 * 6. At this point expansion of PREPROCESSOR_MAP_INNER will terminate. However, since we can
 *    force more rounds of expansion using EVAL1. In the argument-expansion pass
 *    of the EVAL1, _PREPROCESSOR_MAP_INNER() is expanded to PREPROCESSOR_MAP_INNER which is then expanded
 *    using the arguments which follow it as in step 2-5. This is followed by a
 *    second expansion pass as the substitution of EVAL1() is expanded executing
 *    2-5 a second time. This results in up to two iterations occurring. Using
 *    many nested EVAL1 macros, i.e. the very-deeply-nested EVAL macro, will in
 *    this manner produce further iterations, hence the outer MAP macro doing
 *    this for us.
 *
 * Important tricks used:
 *
 * * If we directly produce "PREPROCESSOR_MAP_INNER" in an expansion of PREPROCESSOR_MAP_INNER, a special
 *   case in the preprocessor will prevent it being expanded in the future, even
 *   if we EVAL.  As a result, the PREPROCESSOR_MAP_INNER macro carefully only expands to
 *   something containing "_PREPROCESSOR_MAP_INNER()" which requires a further expansion step
 *   to invoke _PREPROCESSOR_MAP_INNER and thus implementing the recursion.
 * * To prevent _PREPROCESSOR_MAP_INNER being expanded within the macro we must first defer its
 *   expansion during its initial pass as an argument to _IF_0 or _IF_1. We must
 *   then defer its expansion a second time as part of the body of the _IF_0. As
 *   a result hence the DEFER2.
 * * _PREPROCESSOR_MAP_INNER seemingly gets away with producing itself because it actually only
 *   produces PREPROCESSOR_MAP_INNER. It just happens that when _PREPROCESSOR_MAP_INNER() is expanded in
 *   this case it is followed by some arguments which get consumed by PREPROCESSOR_MAP_INNER
 *   and produce a _PREPROCESSOR_MAP_INNER.  As such, the macro expander never marks
 *   _PREPROCESSOR_MAP_INNER as expanding to itself and thus it will still be expanded in
 *   future productions of itself.
 */
#define PREPROCESSOR_MAP(op, sep, ...) \
   PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_INNER(op, sep, __VA_ARGS__)))

#define PREPROCESSOR_MAP_INNER(op, sep, cur_val, ...)                                   \
  op(cur_val)                                                                           \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(                            \
    sep() PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_INNER)()(op, sep, ##__VA_ARGS__)        \
  )
#define _PREPROCESSOR_MAP_INNER() PREPROCESSOR_MAP_INNER



// the same as PREPROCESSOR_MAP but contains some user parameter
#define PREPROCESSOR_MAP_PARAMETER(par, op, sep, ...) \
   PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_PARAMETER_INNER(par, op, sep, __VA_ARGS__)))

#define PREPROCESSOR_MAP_PARAMETER_INNER(par, op, sep, cur_val, ...)                                    \
  op(par, cur_val)                                                                                      \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(                                            \
    sep() PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_PARAMETER_INNER)()(par, op, sep, ##__VA_ARGS__)         \
  )
#define _PREPROCESSOR_MAP_PARAMETER_INNER() PREPROCESSOR_MAP_PARAMETER_INNER



/************************************************************************************************************************************************************
 * PREPROCESSOR MAP FOR MERGING NAMES TO ONE NAME
 * Example Usage:
 *      PREPROCESSOR_MAP_ALL_TO_ONE(sum,__,int, float, double) // __ - is separator
 *
 * Which expands to:
 *      sum__int__float__double
 */

#define PREPROCESSOR_MAP_ALL_TO_ONE(op, sep, ...) \
   PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (PREPROCESSOR_EVAL(PREPROCESSOR_MAP_ALL_TO_ONE_INNER(op, sep, __VA_ARGS__)))

#define PREPROCESSOR_MAP_ALL_TO_ONE_INNER(op, sep, cur_val, ...)                                                                        \
    PREPROCESSOR_IF_ELSE(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (                                                                    \
        PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_ALL_TO_ONE_INNER)()(PREPROCESSOR_CONCAT3(op, sep, cur_val), sep, __VA_ARGS__),            \
        PREPROCESSOR_CONCAT3(op, sep, cur_val)                                                                                          \
    )
#define _PREPROCESSOR_MAP_ALL_TO_ONE_INNER() PREPROCESSOR_MAP_ALL_TO_ONE_INNER


/************************************************************************************************************************************************************
 * This is a variant of the MAP macro which also includes as an argument to the
 * operation a valid C variable name which is different for each iteration.
 *
 * Usage:
 *   PREPROCESSOR_MAP_WITH_ID(op, sep, ...)
 *
 * Where op is a macro op(val, id) which takes a list value and an ID. This ID
 * will simply be a unary number using the digit "I", that is, I, II, III, IIII,
 * and so on.
 *
 * Example:
 *
 *   #define MAKE_STATIC_VAR(type, name) static type name;
 *   PREPROCESSOR_MAP_WITH_ID(MAKE_STATIC_VAR, PREPROCESSOR_COMMA_POINT, int, int, int, bool, char)
 *
 * Which expands to:
 *
 *   static int I; static int II; static int III; static bool IIII; static char IIIII;
 *
 * The mechanism is analogous to the MAP macro.
 */
#define PREPROCESSOR_MAP_WITH_ID(op, sep, ...) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_WITH_ID_INNER(op, sep, I, ##__VA_ARGS__)))

#define PREPROCESSOR_MAP_WITH_ID_INNER(op, sep, id, cur_val, ...)                                                       \
  op(cur_val, id)                                                                                                       \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (                                                           \
    sep() PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_WITH_ID_INNER)()(op, sep, PREPROCESSOR_CONCAT(id, I), ##__VA_ARGS__)    \
  )
#define _PREPROCESSOR_MAP_WITH_ID_INNER() PREPROCESSOR_MAP_WITH_ID_INNER


/************************************************************************************************************************************************************
 * This is a variant of the MAP macro which iterates over pairs rather than
 * singletons.
 *
 * Usage:
 *   PREPROCESSOR_MAP_PAIRS(op, sep, ...)
 *
 * Where op is a macro op(val_1, val_2) which takes two list values.
 *
 * Example:
 *
 *   #define MAKE_STATIC_VAR(type, name) static type name;
 *   PREPROCESSOR_MAP_PAIRS(MAKE_STATIC_VAR, PREPROCESSOR_EMPTY, char, my_char, int, my_int)
 *
 * Which expands to:
 *
 *   static char my_char; static int my_int;
 *
 * The mechanism is analogous to the MAP macro.
 */
#define PREPROCESSOR_MAP_PAIRS(op, sep, ...) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_PAIRS_INNER(op, sep, __VA_ARGS__)))

#define PREPROCESSOR_MAP_PAIRS_INNER(op, sep, cur_val_1, cur_val_2, ...)                    \
  op(cur_val_1, cur_val_2)                                                                  \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__)) (                               \
    sep() PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_PAIRS_INNER)()(op, sep, __VA_ARGS__)        \
  )
#define _PREPROCESSOR_MAP_PAIRS_INNER() PREPROCESSOR_MAP_PAIRS_INNER



/************************************************************************************************************************************************************
 * This is a variant of the MAP macro which iterates over a two-element sliding
 * window.
 *
 * Usage:
 *   PREPROCESSOR_MAP_SLIDE(op, last_op, sep, ...)
 *
 * Where op is a macro op(val_1, val_2) which takes the two list values
 * currently in the window. last_op is a macro taking a single value which is
 * called for the last argument.
 *
 * Example:
 *
 *   #define SIMON_SAYS_OP(simon, next) PREPROCESSOR_IF(PREPROCESSOR_NOT(simon()))(next)
 *   #define SIMON_SAYS_LAST_OP(val) last_but_not_least_##val
 *   #define SIMON_SAYS() 0
 *
 *   PREPROCESSOR_MAP_SLIDE(SIMON_SAYS_OP, SIMON_SAYS_LAST_OP, PREPROCESSOR_EMPTY, wiggle, SIMON_SAYS, dance, move, SIMON_SAYS, boogie, stop)
 *
 * Which expands to:
 *
 *   dance boogie last_but_not_least_stop
 *
 * The mechanism is analogous to the MAP macro.
 */
#define PREPROCESSOR_MAP_SLIDE(op, last_op, sep, ...) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(PREPROCESSOR_EVAL(PREPROCESSOR_MAP_SLIDE_INNER(op, last_op, sep, __VA_ARGS__)))

#define PREPROCESSOR_MAP_SLIDE_INNER(op, last_op, sep, cur_val, ...) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))(op(cur_val, PREPROCESSOR_ARGS_GET_0(__VA_ARGS__))) \
  PREPROCESSOR_IF(PREPROCESSOR_NOT(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))) (last_op(cur_val)) \
  PREPROCESSOR_IF(PREPROCESSOR_ARGS_NOT_EMPTY(__VA_ARGS__))( \
    sep() PREPROCESSOR_DEFER2(_PREPROCESSOR_MAP_SLIDE_INNER)()(op, last_op, sep, __VA_ARGS__) \
  )
#define _PREPROCESSOR_MAP_SLIDE_INNER() PREPROCESSOR_MAP_SLIDE_INNER


/************************************************************************************************************************************************************
 * Strip any excess commas from a set of arguments.
 */
#define PREPROCESSOR_REMOVE_TRAILING_COMMAS(...) \
    PREPROCESSOR_MAP(PREPROCESSOR_PASS, PREPROCESSOR_COMMA, __VA_ARGS__)



#endif /* __PREPROCESSOR_MAP_H__ */
