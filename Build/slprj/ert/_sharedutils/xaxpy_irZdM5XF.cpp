//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xaxpy_irZdM5XF.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include "xaxpy_irZdM5XF.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
void xaxpy_irZdM5XF(int32_T n, real_T a, int32_T ix0, real_T y[100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
