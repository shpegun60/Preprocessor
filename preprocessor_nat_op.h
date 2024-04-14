/*
 *	CREATED BY SHPEGUN60
 *
 *   DIGIT comparation macroces
 */

#ifndef __PREPROCESSOR_NAT_OP_H__
#define __PREPROCESSOR_NAT_OP_H__ 1

/*********************************************************************************************************************
 * DIGITS EQUALUATION MACRO
 *
 *      PREPROCESSOR_SIMPLE_EQUAL(10, 10)         // expands to 1
 *      PREPROCESSOR_SIMPLE_EQUAL(10, 11)         // expands to 0
 *      PREPROCESSOR_SIMPLE_EQUAL('c', 'c')       // expands to 1
 */
#define PREPROCESSOR_SIMPLE_EQUAL(a, b) PREPROCESSOR_SIMPLE_EQUAL_IMPL(a, b)
#define PREPROCESSOR_SIMPLE_EQUAL_IMPL(a, b) ((a) == (b))


/*********************************************************************************************************************
 * DIGITS MORE COMPARATION MACRO
 *
 *      PREPROCESSOR_MORE_THAN(10, 1)           // expands to 1
 *      PREPROCESSOR_MORE_THAN(10, 11)          // expands to 0
 *      PREPROCESSOR_MORE_THAN('c', 'c')        // expands to 0
 */

//>
#define PREPROCESSOR_MORE_THAN(a, b) PREPROCESSOR_MORE_THAN_IMPL(a, b)
#define PREPROCESSOR_MORE_THAN_IMPL(a, b) ((a) > (b))
//>=
#define PREPROCESSOR_MORE_OR_EQ_THAN(a, b) PREPROCESSOR_MORE_OR_EQ_THAN_IMPL(a, b)
#define PREPROCESSOR_MORE_OR_EQ_THAN_IMPL(a, b) ((a) >= (b))

/*********************************************************************************************************************
 * DIGITS LESS COMPARATION MACRO
 *
 *      PREPROCESSOR_LESS_THAN(10, 1)           // expands to 0
 *      PREPROCESSOR_LESS_THAN(10, 11)          // expands to 1
 *      PREPROCESSOR_LESS_THAN('c', 'c')        // expands to 0
 */

//<
#define PREPROCESSOR_LESS_THAN(a, b) PREPROCESSOR_LESS_THAN_IMPL(a, b)
#define PREPROCESSOR_LESS_THAN_IMPL(a, b) ((a) < (b))
//<=
#define PREPROCESSOR_LESS_OR_EQ_THAN(a, b) PREPROCESSOR_LESS_OR_EQ_THAN_IMPL(a, b)
#define PREPROCESSOR_LESS_OR_EQ_THAN_IMPL(a, b) ((a) <= (b))


/*********************************************************************************************************************
 * DIGITS MAX FINDER MACRO
 *
 *      PREPROCESSOR_MAX(10, 1)                 // expands to 10
 *      PREPROCESSOR_MAX(10, 11)                // expands to 11
 *      PREPROCESSOR_MAX('c', 'c')              // expands to 'c'
 */

#define PREPROCESSOR_MAX(a, b) PREPROCESSOR_MAX_IMPL(a, b)
#define PREPROCESSOR_MAX_IMPL(a, b) (PREPROCESSOR_MORE_THAN(a, b) ? (a) : (b))

#define PREPROCESSOR_MIN(a, b) PREPROCESSOR_MIN_IMPL(a, b)
#define PREPROCESSOR_MIN_IMPL(a, b) (PREPROCESSOR_LESS_THAN(a, b) ? (a) : (b))


#endif /* __PREPROCESSOR_NAT_OP_H__ */
