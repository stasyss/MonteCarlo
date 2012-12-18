/*
 * sixhump.cpp
 *
 * Code generation for function 'sixhump'
 *
 * C source code generated on: Sun Dec 16 11:59:32 2012
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "sixhump.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
real_T sixhump(/*const*/ real_T x[2])
{
  return (((4.0 - 2.1 * x[0] * x[0]) + x[0] * x[0] * x[0] * x[0] / 3.0) * x[0] *
          x[0] + x[0] * x[1]) + (-4.0 + 4.0 * x[1] * x[1]) * x[1] * x[1];
}

/* End of code generation (sixhump.cpp) */
