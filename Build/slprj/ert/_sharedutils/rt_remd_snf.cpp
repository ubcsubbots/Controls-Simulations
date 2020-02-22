//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: rt_remd_snf.cpp
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
#include <cfloat>
#include <cmath>
#include "rt_remd_snf.h"

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = std::ceil(u1);
    } else {
      u1_0 = std::floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = std::abs(u0 / u1);
      if (std::abs(u1_0 - std::floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }
  }

  return y;
}

//
// File trailer for generated code.
//
// [EOF]
//
