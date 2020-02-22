//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: frame_conversion2.cpp
//
// Code generated for Simulink model 'frame_conversion2'.
//
// Model version                  : 1.12
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 15:10:06 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "frame_conversion2.h"

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

// Output and update for referenced model: 'frame_conversion2'
void frame_conversion2ModelClass::step(const real_T arg_nu[6], const real_T
  arg_eta[6], real_T arg_eta_dot[6])
{
  real_T cphi;
  real_T sphi;
  real_T cth;
  real_T sth;
  real_T cpsi;
  real_T spsi;
  real_T cpsi_0[36];
  int32_T i;
  real_T cpsi_tmp;
  real_T cpsi_tmp_0;
  int32_T cpsi_tmp_1;

  // MATLAB Function: '<Root>/MATLAB Function'
  cphi = std::cos(arg_eta[3]);
  sphi = std::sin(arg_eta[3]);
  cth = std::cos(arg_eta[4]);
  sth = std::sin(arg_eta[4]);
  cpsi = std::cos(arg_eta[5]);
  spsi = std::sin(arg_eta[5]);
  cpsi_0[0] = cpsi * cth;
  cpsi_0[6] = cpsi * sth * sphi + -spsi * cphi;
  cpsi_tmp = cpsi * cphi;
  cpsi_0[12] = cpsi_tmp * sth + spsi * sphi;
  cpsi_0[1] = spsi * cth;
  cpsi_tmp_0 = sphi * sth;
  cpsi_0[7] = cpsi_tmp_0 * spsi + cpsi_tmp;
  cpsi_0[13] = sth * spsi * cphi + -cpsi * sphi;
  cpsi_0[2] = -sth;
  cpsi_0[8] = cth * sphi;
  cpsi_0[14] = cth * cphi;
  for (i = 0; i < 3; i++) {
    cpsi_tmp_1 = 6 * (i + 3);
    cpsi_0[cpsi_tmp_1] = 0.0;
    cpsi_0[6 * i + 3] = 0.0;
    cpsi_0[cpsi_tmp_1 + 1] = 0.0;
    cpsi_0[6 * i + 4] = 0.0;
    cpsi_0[cpsi_tmp_1 + 2] = 0.0;
    cpsi_0[6 * i + 5] = 0.0;
  }

  cpsi_0[21] = 1.0;
  cpsi_0[27] = cpsi_tmp_0 / cth;
  cpsi_0[33] = cphi * sth / cth;
  cpsi_0[22] = 0.0;
  cpsi_0[28] = cphi;
  cpsi_0[34] = -sphi;
  cpsi_0[23] = 0.0;
  cpsi_0[29] = sphi / cth;
  cpsi_0[35] = cphi / cth;
  for (i = 0; i < 6; i++) {
    arg_eta_dot[i] = 0.0;
    for (cpsi_tmp_1 = 0; cpsi_tmp_1 < 6; cpsi_tmp_1++) {
      arg_eta_dot[i] += cpsi_0[6 * cpsi_tmp_1 + i] * arg_nu[cpsi_tmp_1];
    }
  }

  // End of MATLAB Function: '<Root>/MATLAB Function'
}

// Constructor
frame_conversion2ModelClass::frame_conversion2ModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
frame_conversion2ModelClass::~frame_conversion2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_frame_conversion2_T * frame_conversion2ModelClass::getRTM()
{
  return (&frame_conversion2_M);
}

// member function to setup error status pointer
void frame_conversion2ModelClass::setErrorStatusPointer(const char_T
  **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&frame_conversion2_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
