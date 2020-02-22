//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: thrust_allocation2.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.7
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 15:10:33 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "thrust_allocation2.h"
#include "cosd_REZfihlV.h"
#include "sind_X3pRZNku.h"
#include "svd_eAADSaaD.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        (*((rtm)->errorStatus))
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   (*((rtm)->errorStatus) = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) (rtm)->errorStatus
#endif

#ifndef rtmSetErrorStatusPointer
# define rtmSetErrorStatusPointer(rtm, val) ((rtm)->errorStatus = (val))
#endif

// Output and update for referenced model: 'thrust_allocation2'
void thrust_allocation2ModelClass::step(const real_T arg_tau_[6], real_T
  arg_signals_[6])
{
  real_T A[100];
  real_T u[10];
  real_T X[100];
  real_T V[100];
  int32_T vcol;
  real_T U[100];
  int32_T j;
  boolean_T p;
  real_T absx;
  int32_T ar;
  int32_T ia;
  int32_T b;
  int32_T ib;
  int32_T b_ic;
  real_T g;
  real_T h;
  real_T i;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T arg_tau__0[10];
  int32_T r;
  static const int8_T c[10] = { -1, 0, -1, 0, 1, 0, 1, 0, 0, 0 };

  static const int8_T d[10] = { 0, -1, 0, 1, 0, -1, 0, 1, 0, 0 };

  static const int8_T e[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };

  // MATLAB Function: '<Root>/thrust-allocator'
  absx = 45.0;
  cosd_REZfihlV(&absx);
  g = 45.0;
  sind_X3pRZNku(&g);
  h = 45.0;
  cosd_REZfihlV(&h);
  i = 45.0;
  sind_X3pRZNku(&i);
  l = 45.0;
  cosd_REZfihlV(&l);
  m = 45.0;
  sind_X3pRZNku(&m);
  n = 45.0;
  cosd_REZfihlV(&n);
  o = 45.0;
  sind_X3pRZNku(&o);
  A[3] = 0.0;
  A[13] = 0.0;
  A[23] = 0.0;
  A[33] = 0.0;
  A[43] = 0.0;
  A[53] = 0.0;
  A[63] = 0.0;
  A[73] = 0.0;
  A[83] = -8.744;
  A[93] = 8.239;
  for (r = 0; r < 10; r++) {
    A[10 * r] = c[r];
    A[10 * r + 1] = d[r];
    A[10 * r + 2] = e[r];
    A[10 * r + 4] = 0.0;
  }

  A[5] = 6.5640707185674305;
  A[15] = 8.6178224976873175;
  A[25] = -6.5640707185674305;
  A[35] = -8.6178224976873175;
  A[45] = -6.5640707185674305;
  A[55] = -8.6178224976873175;
  A[65] = 6.5640707185674305;
  A[75] = 8.6178224976873175;
  A[85] = 0.0;
  A[95] = 0.0;
  A[6] = 1.0 / absx;
  A[16] = -1.0 / g;
  A[26] = 0.0;
  A[36] = 0.0;
  A[46] = 0.0;
  A[56] = 0.0;
  A[66] = 0.0;
  A[76] = 0.0;
  A[86] = 0.0;
  A[96] = 0.0;
  A[7] = 0.0;
  A[17] = 0.0;
  A[27] = 1.0 / h;
  A[37] = -1.0 / i;
  A[47] = 0.0;
  A[57] = 0.0;
  A[67] = 0.0;
  A[77] = 0.0;
  A[87] = 0.0;
  A[97] = 0.0;
  A[8] = 0.0;
  A[18] = 0.0;
  A[28] = 0.0;
  A[38] = 0.0;
  A[48] = 1.0 / l;
  A[58] = -1.0 / m;
  A[68] = 0.0;
  A[78] = 0.0;
  A[88] = 0.0;
  A[98] = 0.0;
  A[9] = 0.0;
  A[19] = 0.0;
  A[29] = 0.0;
  A[39] = 0.0;
  A[49] = 0.0;
  A[59] = 0.0;
  A[69] = 1.0 / n;
  A[79] = -1.0 / o;
  A[89] = 0.0;
  A[99] = 0.0;
  p = true;
  for (r = 0; r < 100; r++) {
    X[r] = 0.0;
    p = (p && ((!rtIsInf(A[r])) && (!rtIsNaN(A[r]))));
  }

  if (!p) {
    for (r = 0; r < 100; r++) {
      X[r] = (rtNaN);
    }
  } else {
    svd_eAADSaaD(A, U, u, V);
    absx = std::abs(u[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = std::ldexp(1.0, vcol - 53);
      }
    } else {
      absx = (rtNaN);
    }

    absx *= 10.0;
    r = -1;
    vcol = 0;
    while ((vcol < 10) && (u[vcol] > absx)) {
      r++;
      vcol++;
    }

    if (r + 1 > 0) {
      vcol = 0;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / u[j];
        for (ar = vcol; ar < vcol + 10; ar++) {
          V[ar] *= absx;
        }

        vcol += 10;
      }

      for (vcol = 0; vcol <= 91; vcol += 10) {
        for (j = vcol; j < vcol + 10; j++) {
          X[j] = 0.0;
        }
      }

      vcol = 0;
      for (j = 0; j <= 91; j += 10) {
        ar = -1;
        vcol++;
        b = 10 * r + vcol;
        for (ib = vcol; ib <= b; ib += 10) {
          ia = ar;
          for (b_ic = j; b_ic < j + 10; b_ic++) {
            ia++;
            X[b_ic] += U[ib - 1] * V[ia];
          }

          ar += 10;
        }
      }
    }
  }

  for (r = 0; r < 6; r++) {
    arg_tau__0[r] = arg_tau_[r];
  }

  arg_tau__0[6] = 0.0;
  arg_tau__0[7] = 0.0;
  arg_tau__0[8] = 0.0;
  arg_tau__0[9] = 0.0;
  for (r = 0; r < 10; r++) {
    u[r] = 0.0;
    for (vcol = 0; vcol < 10; vcol++) {
      u[r] += X[10 * vcol + r] * arg_tau__0[vcol];
    }
  }

  arg_signals_[0] = std::sqrt(u[0] * u[0] + u[1] * u[1]);
  arg_signals_[1] = std::sqrt(u[2] * u[2] + u[3] * u[3]);
  arg_signals_[2] = std::sqrt(u[4] * u[4] + u[5] * u[5]);
  arg_signals_[3] = std::sqrt(u[6] * u[6] + u[7] * u[7]);
  arg_signals_[4] = u[8];
  arg_signals_[5] = u[9];

  // End of MATLAB Function: '<Root>/thrust-allocator'
}

// Model initialize function
void thrust_allocation2ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
thrust_allocation2ModelClass::thrust_allocation2ModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
thrust_allocation2ModelClass::~thrust_allocation2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_thrust_allocation2_T * thrust_allocation2ModelClass::getRTM()
{
  return (&thrust_allocation2_M);
}

// member function to setup error status pointer
void thrust_allocation2ModelClass::setErrorStatusPointer(const char_T
  **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&thrust_allocation2_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
