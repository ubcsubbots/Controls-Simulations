//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: sind_X3pRZNku.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include <cmath>
#include "rt_remd_snf.h"
#include "sind_X3pRZNku.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
void sind_X3pRZNku(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = std::abs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = std::abs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = std::sin(c_x);
      break;

     case 1:
      *x = std::cos(c_x);
      break;

     case -1:
      *x = -std::cos(c_x);
      break;

     default:
      *x = -std::sin(c_x);
      break;
    }
  }
}

//
// File trailer for generated code.
//
// [EOF]
//
