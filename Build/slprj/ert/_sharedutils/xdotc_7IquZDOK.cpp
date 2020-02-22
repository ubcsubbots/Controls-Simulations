//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xdotc_7IquZDOK.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include "xdotc_7IquZDOK.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
real_T xdotc_7IquZDOK(int32_T n, const real_T x[100], int32_T ix0, const real_T
                      y[100], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

//
// File trailer for generated code.
//
// [EOF]
//
