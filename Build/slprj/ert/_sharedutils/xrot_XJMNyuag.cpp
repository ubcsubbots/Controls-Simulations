//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: xrot_XJMNyuag.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include "xrot_XJMNyuag.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
void xrot_XJMNyuag(real_T x[100], int32_T ix0, int32_T iy0, real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 10; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
