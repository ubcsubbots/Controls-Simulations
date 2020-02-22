//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller2.cpp
//
// Code generated for Simulink model 'controller2'.
//
// Model version                  : 1.13
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 15:11:21 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "controller2.h"

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

extern const real_T rtCP_pooled_xIp5xqWwZtfz[36];
extern const real_T rtCP_pooled_TFd8bf0TDh3x[36];

#define rtCP_Kd_Gain                   rtCP_pooled_xIp5xqWwZtfz  // Expression: Kd_mat
                                                                 //  Referenced by: '<Root>/Kd '

#define rtCP_Kp_Gain                   rtCP_pooled_TFd8bf0TDh3x  // Expression: Kp_mat
                                                                 //  Referenced by: '<Root>/Kp '


// Output and update for referenced model: 'controller2'
void controller2ModelClass::step(const real_T arg_eta_d[6], const real_T
  arg_eta_d_dot[6], const real_T arg_eta_d_dot_dot[6], const real_T arg_x[12],
  real_T arg_tau_[6])
{
  // local block i/o variables
  real_T rtb_eta_dot[6];
  real_T nu[6];
  real_T cpsi;
  real_T spsi;
  real_T sth_tmp;
  real_T cth_tmp;
  real_T sphi_tmp;
  real_T cphi_tmp;
  int8_T tmp[36];
  real_T cpsi_0[36];
  real_T arg_eta_d_0[6];
  real_T arg_eta_d_dot_0[6];
  real_T tmp_0[6];
  real_T tmp_1[6];
  real_T tmp_2[36];
  real_T tmp_3[6];
  real_T tmp_4[36];
  real_T tmp_5[36];
  int32_T i;
  int32_T i_0;
  real_T cpsi_tmp;
  real_T cpsi_tmp_0;
  int32_T cpsi_tmp_1;
  int32_T tmp_6;

  // MATLAB Function: '<Root>/C(nu)*nu + D(nu)*nu + g(eta)'
  nu[0] = arg_x[0];
  nu[1] = arg_x[1];
  nu[2] = arg_x[2];
  nu[3] = arg_x[3];
  nu[4] = arg_x[4];
  nu[5] = arg_x[5];

  // ModelReference: '<Root>/Model'
  ModelMDLOBJ1.step(&arg_x[0], &arg_x[6], &rtb_eta_dot[0]);

  // MATLAB Function: '<Root>/M*(J^-1(eta)*a_n)' incorporates:
  //   MATLAB Function: '<Root>/C(nu)*nu + D(nu)*nu + g(eta)'

  cphi_tmp = std::cos(arg_x[9]);
  sphi_tmp = std::sin(arg_x[9]);
  cth_tmp = std::cos(arg_x[10]);
  sth_tmp = std::sin(arg_x[10]);
  cpsi = std::cos(arg_x[11]);
  spsi = std::sin(arg_x[11]);
  tmp[0] = 100;
  tmp[6] = 0;
  tmp[12] = 0;
  tmp[18] = 0;
  tmp[24] = 0;
  tmp[30] = 0;
  tmp[1] = 0;
  tmp[7] = 100;
  tmp[13] = 0;
  tmp[19] = 0;
  tmp[25] = 0;
  tmp[31] = 0;
  tmp[2] = 0;
  tmp[8] = 0;
  tmp[14] = 100;
  tmp[20] = 0;
  tmp[26] = 0;
  tmp[32] = 0;
  tmp[3] = 0;
  tmp[9] = 0;
  tmp[15] = 0;
  tmp[21] = 10;
  tmp[27] = 0;
  tmp[33] = 0;
  tmp[4] = 0;
  tmp[10] = 0;
  tmp[16] = 0;
  tmp[22] = 0;
  tmp[28] = 10;
  tmp[34] = 0;
  tmp[5] = 0;
  tmp[11] = 0;
  tmp[17] = 0;
  tmp[23] = 0;
  tmp[29] = 0;
  tmp[35] = 10;
  cpsi_0[0] = cpsi * cth_tmp;
  cpsi_0[1] = cpsi * sth_tmp * sphi_tmp + -spsi * cphi_tmp;
  cpsi_tmp = cpsi * cphi_tmp;
  cpsi_0[2] = cpsi_tmp * sth_tmp + spsi * sphi_tmp;
  cpsi_0[6] = spsi * cth_tmp;
  cpsi_tmp_0 = sphi_tmp * sth_tmp;
  cpsi_0[7] = cpsi_tmp_0 * spsi + cpsi_tmp;
  cpsi_0[8] = sth_tmp * spsi * cphi_tmp + -cpsi * sphi_tmp;
  cpsi_0[12] = -sth_tmp;
  cpsi_0[13] = cth_tmp * sphi_tmp;
  cpsi_0[14] = cth_tmp * cphi_tmp;
  for (i = 0; i < 3; i++) {
    cpsi_0[6 * i + 3] = 0.0;
    cpsi_tmp_1 = 6 * (i + 3);
    cpsi_0[cpsi_tmp_1] = 0.0;
    cpsi_0[6 * i + 4] = 0.0;
    cpsi_0[cpsi_tmp_1 + 1] = 0.0;
    cpsi_0[6 * i + 5] = 0.0;
    cpsi_0[cpsi_tmp_1 + 2] = 0.0;
  }

  cpsi_0[21] = 1.0;
  cpsi_0[22] = cpsi_tmp_0 / cth_tmp;
  cpsi_0[23] = cphi_tmp * sth_tmp / cth_tmp;
  cpsi_0[27] = 0.0;
  cpsi_0[28] = cphi_tmp;
  cpsi_0[29] = -sphi_tmp;
  cpsi_0[33] = 0.0;
  cpsi_0[34] = sphi_tmp / cth_tmp;
  cpsi_0[35] = cphi_tmp / cth_tmp;
  for (i = 0; i < 6; i++) {
    // Sum: '<Root>/Sum'
    arg_eta_d_0[i] = arg_eta_d[i] - arg_x[i + 6];

    // Sum: '<Root>/Sum1'
    arg_eta_d_dot_0[i] = arg_eta_d_dot[i] - rtb_eta_dot[i];
  }

  for (i = 0; i < 6; i++) {
    // Gain: '<Root>/Kp '
    tmp_0[i] = 0.0;

    // Gain: '<Root>/Kd '
    tmp_1[i] = 0.0;
    for (cpsi_tmp_1 = 0; cpsi_tmp_1 < 6; cpsi_tmp_1++) {
      // MATLAB Function: '<Root>/M*(J^-1(eta)*a_n)' incorporates:
      //   Gain: '<Root>/Kd '
      //   Gain: '<Root>/Kp '

      tmp_6 = i + 6 * cpsi_tmp_1;
      tmp_2[tmp_6] = 0.0;
      for (i_0 = 0; i_0 < 6; i_0++) {
        tmp_2[tmp_6] += static_cast<real_T>(tmp[6 * i_0 + i]) * cpsi_0[6 *
          cpsi_tmp_1 + i_0];
      }

      // Gain: '<Root>/Kp '
      tmp_0[i] += rtCP_Kp_Gain[tmp_6] * arg_eta_d_0[cpsi_tmp_1];

      // Gain: '<Root>/Kd '
      tmp_1[i] += rtCP_Kd_Gain[tmp_6] * arg_eta_d_dot_0[cpsi_tmp_1];
    }

    // Sum: '<Root>/Sum2'
    tmp_3[i] = (tmp_0[i] + tmp_1[i]) + arg_eta_d_dot_dot[i];
  }

  // MATLAB Function: '<Root>/C(nu)*nu + D(nu)*nu + g(eta)'
  cpsi_0[0] = 0.0;
  cpsi_0[6] = 0.0;
  cpsi_0[12] = 0.0;
  cpsi_0[18] = 0.0;
  cpsi_0[24] = 100.0 * arg_x[2];
  cpsi_0[30] = -100.0 * arg_x[2];
  cpsi_0[1] = 0.0;
  cpsi_0[7] = 0.0;
  cpsi_0[13] = 0.0;
  cpsi_0[19] = -100.0 * arg_x[2];
  cpsi_0[25] = 0.0;
  cpsi_0[31] = 100.0 * arg_x[0];
  cpsi_0[2] = 0.0;
  cpsi_0[8] = 0.0;
  cpsi_0[14] = 0.0;
  cpsi_0[20] = 100.0 * arg_x[1];
  cpsi_0[26] = -100.0 * arg_x[0];
  cpsi_0[32] = 0.0;
  cpsi_0[3] = 0.0;
  cpsi_0[9] = 100.0 * arg_x[2];
  cpsi_0[15] = -100.0 * arg_x[1];
  cpsi_0[21] = 0.0;
  cpsi_0[27] = 10.0 * arg_x[5];
  cpsi_0[33] = -10.0 * arg_x[4];
  cpsi_0[4] = -100.0 * arg_x[2];
  cpsi_0[10] = 0.0;
  cpsi_0[16] = 100.0 * arg_x[0];
  cpsi_0[22] = -10.0 * arg_x[5];
  cpsi_0[28] = 0.0;
  cpsi_0[34] = 10.0 * arg_x[3];
  cpsi_0[5] = 100.0 * arg_x[1];
  cpsi_0[11] = -100.0 * arg_x[0];
  cpsi_0[17] = 0.0;
  cpsi_0[23] = 10.0 * arg_x[4];
  cpsi_0[29] = -10.0 * arg_x[3];
  cpsi_0[35] = 0.0;
  tmp[0] = 10;
  tmp[6] = 0;
  tmp[12] = 0;
  tmp[18] = 0;
  tmp[24] = 0;
  tmp[30] = 0;
  tmp[1] = 0;
  tmp[7] = 10;
  tmp[13] = 0;
  tmp[19] = 0;
  tmp[25] = 0;
  tmp[31] = 0;
  tmp[2] = 0;
  tmp[8] = 0;
  tmp[14] = 10;
  tmp[20] = 0;
  tmp[26] = 0;
  tmp[32] = 0;
  tmp[3] = 0;
  tmp[9] = 0;
  tmp[15] = 0;
  tmp[21] = 10;
  tmp[27] = 0;
  tmp[33] = 0;
  tmp[4] = 0;
  tmp[10] = 0;
  tmp[16] = 0;
  tmp[22] = 0;
  tmp[28] = 10;
  tmp[34] = 0;
  tmp[5] = 0;
  tmp[11] = 0;
  tmp[17] = 0;
  tmp[23] = 0;
  tmp[29] = 0;
  tmp[35] = 10;
  tmp_4[0] = 10.0 * std::abs(arg_x[0]);
  tmp_4[6] = 0.0;
  tmp_4[12] = 0.0;
  tmp_4[18] = 0.0;
  tmp_4[24] = 0.0;
  tmp_4[30] = 0.0;
  tmp_4[1] = 0.0;
  tmp_4[7] = 10.0 * std::abs(arg_x[1]);
  tmp_4[13] = 0.0;
  tmp_4[19] = 0.0;
  tmp_4[25] = 0.0;
  tmp_4[31] = 0.0;
  tmp_4[2] = 0.0;
  tmp_4[8] = 0.0;
  tmp_4[14] = 10.0 * std::abs(arg_x[2]);
  tmp_4[20] = 0.0;
  tmp_4[26] = 0.0;
  tmp_4[32] = 0.0;
  tmp_4[3] = 0.0;
  tmp_4[9] = 0.0;
  tmp_4[15] = 0.0;
  tmp_4[21] = 10.0 * std::abs(arg_x[3]);
  tmp_4[27] = 0.0;
  tmp_4[33] = 0.0;
  tmp_4[4] = 0.0;
  tmp_4[10] = 0.0;
  tmp_4[16] = 0.0;
  tmp_4[22] = 0.0;
  tmp_4[28] = 10.0 * std::abs(arg_x[4]);
  tmp_4[34] = 0.0;
  tmp_4[5] = 0.0;
  tmp_4[11] = 0.0;
  tmp_4[17] = 0.0;
  tmp_4[23] = 0.0;
  tmp_4[29] = 0.0;
  tmp_4[35] = 10.0 * std::abs(arg_x[5]);
  for (i = 0; i < 36; i++) {
    tmp_5[i] = static_cast<real_T>(tmp[i]) + tmp_4[i];
  }

  arg_eta_d_0[0] = -993753.0 * sth_tmp;
  arg_eta_d_0[1] = 993753.0 * cth_tmp * sphi_tmp;
  arg_eta_d_0[2] = 993753.0 * std::cos(arg_x[10]) * cphi_tmp;
  arg_eta_d_0[3] = -0.0 * cth_tmp * cphi_tmp + 0.0 * cth_tmp * sphi_tmp;
  arg_eta_d_0[4] = 0.0 * cth_tmp * cphi_tmp + 0.0 * sth_tmp;
  arg_eta_d_0[5] = -0.0 * cth_tmp * sphi_tmp - 0.0 * sth_tmp;
  for (i = 0; i < 6; i++) {
    tmp_0[i] = 0.0;
    tmp_1[i] = 0.0;

    // Sum: '<Root>/Sum4' incorporates:
    //   MATLAB Function: '<Root>/M*(J^-1(eta)*a_n)'

    cphi_tmp = 0.0;
    for (cpsi_tmp_1 = 0; cpsi_tmp_1 < 6; cpsi_tmp_1++) {
      tmp_6 = 6 * cpsi_tmp_1 + i;
      cphi_tmp += tmp_2[tmp_6] * tmp_3[cpsi_tmp_1];
      tmp_0[i] += cpsi_0[tmp_6] * nu[cpsi_tmp_1];
      tmp_1[i] += tmp_5[tmp_6] * nu[cpsi_tmp_1];
    }

    arg_tau_[i] = ((tmp_0[i] + tmp_1[i]) + arg_eta_d_0[i]) + cphi_tmp;

    // End of Sum: '<Root>/Sum4'
  }
}

// Model initialize function
void controller2ModelClass::initialize()
{
  // Model Initialize function for ModelReference Block: '<Root>/Model'

  // Set error status pointer for ModelReference Block: '<Root>/Model'
  ModelMDLOBJ1.setErrorStatusPointer(rtmGetErrorStatusPointer((&controller2_M)));
}

// Constructor
controller2ModelClass::controller2ModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
controller2ModelClass::~controller2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_controller2_T * controller2ModelClass::getRTM()
{
  return (&controller2_M);
}

// member function to setup error status pointer
void controller2ModelClass::setErrorStatusPointer(const char_T **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&controller2_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
