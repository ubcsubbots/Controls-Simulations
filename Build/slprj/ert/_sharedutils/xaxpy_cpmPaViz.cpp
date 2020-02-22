//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xaxpy_cpmPaViz.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include "xaxpy_cpmPaViz.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
void xaxpy_cpmPaViz(int32_T n, real_T a, const real_T x[10], int32_T ix0, real_T
                    y[100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
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
