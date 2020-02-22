//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trajectory_planner2.cpp
//
// Code generated for Simulink model 'trajectory_planner2'.
//
// Model version                  : 1.9
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 15:11:05 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "trajectory_planner2.h"
#include "rt_powd_snf.h"

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

void trajectory_planner2ModelClass::trajectory_pla_SystemCore_setup
  (robotics_slcore_internal_bloc_T *obj)
{
  obj->isInitialized = 1;
  obj->TunablePropsChanged = false;
}

c_robotics_core_internal_code_T *trajectory_planner2ModelClass::
  NameValueParser_NameValueParser(c_robotics_core_internal_code_T *obj)
{
  return obj;
}

boolean_T trajectory_planner2ModelClass::traj_checkPolyForMultipleBreaks(const
  real_T breakMat[42])
{
  boolean_T hasMultipleBreaks;
  int32_T b_i;
  real_T y[7];
  boolean_T y_0;
  int32_T b_i_0;
  int32_T b_k;
  boolean_T exitg1;
  hasMultipleBreaks = false;
  for (b_i = 0; b_i < 5; b_i++) {
    b_i_0 = b_i + 1;
    for (b_k = 0; b_k < 7; b_k++) {
      y[b_k] = std::abs(breakMat[(6 * b_k + b_i_0) - 1] - breakMat[(6 * b_k +
        b_i) + 1]);
    }

    y_0 = false;
    b_k = 0;
    exitg1 = false;
    while ((!exitg1) && (b_k < 7)) {
      if (!(y[b_k] > 2.2204460492503131E-16)) {
        b_k++;
      } else {
        y_0 = true;
        exitg1 = true;
      }
    }

    if (y_0 || hasMultipleBreaks) {
      hasMultipleBreaks = true;
    }
  }

  return hasMultipleBreaks;
}

void trajectory_planner2ModelClass::trajec_processPolynomialResults(const real_T
  breakMat[42], const real_T coeffMat[108], boolean_T hasMultipleBreaks,
  k_cell_wrap_trajectory_planne_T breaksCell[6], l_cell_wrap_trajectory_planne_T
  coeffCell[6])
{
  real_T maxBreaksTime;
  real_T holdTime;
  real_T coefs_data[21];
  int32_T b_idx;
  int32_T k;
  real_T holdTime_0[3];
  int32_T i;
  boolean_T exitg1;
  if (!rtIsNaN(breakMat[36])) {
    b_idx = 1;
  } else {
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!rtIsNaN(breakMat[k + 35])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    maxBreaksTime = breakMat[36];
  } else {
    maxBreaksTime = breakMat[b_idx + 35];
    for (k = b_idx + 1; k < 7; k++) {
      holdTime = breakMat[k + 35];
      if (maxBreaksTime < holdTime) {
        maxBreaksTime = holdTime;
      }
    }
  }

  if (hasMultipleBreaks) {
    if (!rtIsNaN(breakMat[0])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[0];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[0].f1.size[0] = 1;
      breaksCell[0].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[0].f1.data[i] = breakMat[6 * i];
      }

      breaksCell[0].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[36] - breakMat[30];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[6 * k + 36 * i];
        }

        holdTime += coeffMat[36 * i + 30] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[6 * k + 36 * i];
        }
      }

      breaksCell[0].f1.size[0] = 1;
      breaksCell[0].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[0].f1.data[i] = breakMat[6 * i];
      }
    }

    coeffCell[0].f1.size[0] = b_idx;
    coeffCell[0].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[0].f1.data[i] = coefs_data[i];
    }

    if (!rtIsNaN(breakMat[1])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6 + 1])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[1];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6 + 1];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6 + 1;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[1].f1.size[0] = 1;
      breaksCell[1].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[1].f1.data[i] = breakMat[6 * i + 1];
      }

      breaksCell[1].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[37] - breakMat[31];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[(6 * k + 36 * i) + 1];
        }

        holdTime += coeffMat[36 * i + 31] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[(6 * k + 36 * i) + 1];
        }
      }

      breaksCell[1].f1.size[0] = 1;
      breaksCell[1].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[1].f1.data[i] = breakMat[6 * i + 1];
      }
    }

    coeffCell[1].f1.size[0] = b_idx;
    coeffCell[1].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[1].f1.data[i] = coefs_data[i];
    }

    if (!rtIsNaN(breakMat[2])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6 + 2])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[2];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6 + 2];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6 + 2;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[2].f1.size[0] = 1;
      breaksCell[2].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[2].f1.data[i] = breakMat[6 * i + 2];
      }

      breaksCell[2].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[38] - breakMat[32];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[(6 * k + 36 * i) + 2];
        }

        holdTime += coeffMat[36 * i + 32] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[(6 * k + 36 * i) + 2];
        }
      }

      breaksCell[2].f1.size[0] = 1;
      breaksCell[2].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[2].f1.data[i] = breakMat[6 * i + 2];
      }
    }

    coeffCell[2].f1.size[0] = b_idx;
    coeffCell[2].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[2].f1.data[i] = coefs_data[i];
    }

    if (!rtIsNaN(breakMat[3])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6 + 3])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[3];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6 + 3];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6 + 3;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[3].f1.size[0] = 1;
      breaksCell[3].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[3].f1.data[i] = breakMat[6 * i + 3];
      }

      breaksCell[3].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[39] - breakMat[33];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[(6 * k + 36 * i) + 3];
        }

        holdTime += coeffMat[36 * i + 33] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[(6 * k + 36 * i) + 3];
        }
      }

      breaksCell[3].f1.size[0] = 1;
      breaksCell[3].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[3].f1.data[i] = breakMat[6 * i + 3];
      }
    }

    coeffCell[3].f1.size[0] = b_idx;
    coeffCell[3].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[3].f1.data[i] = coefs_data[i];
    }

    if (!rtIsNaN(breakMat[4])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6 + 4])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[4];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6 + 4];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6 + 4;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[4].f1.size[0] = 1;
      breaksCell[4].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[4].f1.data[i] = breakMat[6 * i + 4];
      }

      breaksCell[4].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[40] - breakMat[34];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[(6 * k + 36 * i) + 4];
        }

        holdTime += coeffMat[36 * i + 34] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[(6 * k + 36 * i) + 4];
        }
      }

      breaksCell[4].f1.size[0] = 1;
      breaksCell[4].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[4].f1.data[i] = breakMat[6 * i + 4];
      }
    }

    coeffCell[4].f1.size[0] = b_idx;
    coeffCell[4].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[4].f1.data[i] = coefs_data[i];
    }

    if (!rtIsNaN(breakMat[5])) {
      b_idx = 1;
    } else {
      b_idx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k < 8)) {
        if (!rtIsNaN(breakMat[(k - 1) * 6 + 5])) {
          b_idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }

    if (b_idx == 0) {
      holdTime = breakMat[5];
    } else {
      holdTime = breakMat[(b_idx - 1) * 6 + 5];
      for (k = b_idx + 1; k < 8; k++) {
        i = (k - 1) * 6 + 5;
        if (holdTime < breakMat[i]) {
          holdTime = breakMat[i];
        }
      }
    }

    if (holdTime < maxBreaksTime) {
      breaksCell[5].f1.size[0] = 1;
      breaksCell[5].f1.size[1] = 8;
      for (i = 0; i < 7; i++) {
        breaksCell[5].f1.data[i] = breakMat[6 * i + 5];
      }

      breaksCell[5].f1.data[7] = maxBreaksTime;
      holdTime = breakMat[41] - breakMat[35];
      b_idx = 7;
      std::memset(&coefs_data[0], 0, 21U * sizeof(real_T));
      holdTime_0[0] = holdTime * holdTime;
      holdTime_0[1] = holdTime;
      holdTime_0[2] = 1.0;
      holdTime = 0.0;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 7 * i] = coeffMat[(6 * k + 36 * i) + 5];
        }

        holdTime += coeffMat[36 * i + 35] * holdTime_0[i];
      }

      coefs_data[20] = holdTime;
    } else {
      b_idx = 6;
      for (i = 0; i < 3; i++) {
        for (k = 0; k < 6; k++) {
          coefs_data[k + 6 * i] = coeffMat[(6 * k + 36 * i) + 5];
        }
      }

      breaksCell[5].f1.size[0] = 1;
      breaksCell[5].f1.size[1] = 7;
      for (i = 0; i < 7; i++) {
        breaksCell[5].f1.data[i] = breakMat[6 * i + 5];
      }
    }

    coeffCell[5].f1.size[0] = b_idx;
    coeffCell[5].f1.size[1] = 3;
    b_idx = b_idx * 3 - 1;
    for (i = 0; i <= b_idx; i++) {
      coeffCell[5].f1.data[i] = coefs_data[i];
    }
  } else {
    breaksCell[0].f1.size[0] = 1;
    breaksCell[0].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[0].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[0].f1.size[0] = 36;
    coeffCell[0].f1.size[1] = 3;
    std::memcpy(&coeffCell[0].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
    breaksCell[1].f1.size[0] = 1;
    breaksCell[1].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[1].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[1].f1.size[0] = 36;
    coeffCell[1].f1.size[1] = 3;
    std::memcpy(&coeffCell[1].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
    breaksCell[2].f1.size[0] = 1;
    breaksCell[2].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[2].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[2].f1.size[0] = 36;
    coeffCell[2].f1.size[1] = 3;
    std::memcpy(&coeffCell[2].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
    breaksCell[3].f1.size[0] = 1;
    breaksCell[3].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[3].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[3].f1.size[0] = 36;
    coeffCell[3].f1.size[1] = 3;
    std::memcpy(&coeffCell[3].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
    breaksCell[4].f1.size[0] = 1;
    breaksCell[4].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[4].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[4].f1.size[0] = 36;
    coeffCell[4].f1.size[1] = 3;
    std::memcpy(&coeffCell[4].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
    breaksCell[5].f1.size[0] = 1;
    breaksCell[5].f1.size[1] = 7;
    for (i = 0; i < 7; i++) {
      breaksCell[5].f1.data[i] = breakMat[6 * i];
    }

    coeffCell[5].f1.size[0] = 36;
    coeffCell[5].f1.size[1] = 3;
    std::memcpy(&coeffCell[5].f1.data[0], &coeffMat[0], 108U * sizeof(real_T));
  }
}

void trajectory_planner2ModelClass::trajectory_computeProfileParams(real_T i,
  real_T j, const real_T wayPoints[18], const real_T TFi_data[], real_T *vParam,
  real_T *aParam, real_T *tAParam, real_T *tFParam)
{
  real_T s0;
  real_T sF;
  int32_T deltaSign;
  int32_T s0_tmp;
  int32_T s0_tmp_0;
  s0_tmp = static_cast<int32_T>(i);
  s0_tmp_0 = ((static_cast<int32_T>(j) - 1) * 6 + s0_tmp) - 1;
  s0 = wayPoints[s0_tmp_0];
  s0_tmp = ((static_cast<int32_T>((j + 1.0)) - 1) * 6 + s0_tmp) - 1;
  sF = wayPoints[s0_tmp];
  deltaSign = 1;
  if (wayPoints[s0_tmp] < wayPoints[s0_tmp_0]) {
    s0 = wayPoints[s0_tmp];
    sF = wayPoints[s0_tmp_0];
    deltaSign = -1;
  }

  *tFParam = TFi_data[s0_tmp_0];
  *vParam = (sF - s0) * 1.5 / TFi_data[s0_tmp_0];
  *tAParam = (TFi_data[s0_tmp_0] * *vParam + (s0 - sF)) / *vParam;
  *aParam = *vParam / *tAParam;
  if (s0 == sF) {
    *aParam = 0.0;
    *vParam = 0.0;
    if (rtIsNaN(TFi_data[s0_tmp_0]) || (TFi_data[s0_tmp_0] == 0.0)) {
      *tFParam = 1.0;
    }

    *tAParam = *tFParam / 3.0;
  }

  *vParam *= static_cast<real_T>(deltaSign);
  *aParam *= static_cast<real_T>(deltaSign);
}

void trajectory_planner2ModelClass::trajectory_planner2_sum(const real_T x[12],
  real_T y[6])
{
  int32_T b_j;
  for (b_j = 0; b_j < 6; b_j++) {
    y[b_j] = x[b_j + 6] + x[b_j];
  }
}

void trajectory_planner2ModelClass::trajectory_planner2_linspace(real_T d2,
  real_T y[2])
{
  y[1] = d2;
  y[0] = 0.0;
}

void trajectory_planner2ModelClass::t_computeScalarLSPBCoefficients(real_T s0,
  real_T sF, real_T v, real_T a, real_T ta, real_T tf, real_T coefs[9], real_T
  breaks[4])
{
  real_T coefs_tmp;
  breaks[0] = 0.0;
  breaks[1] = ta;
  breaks[2] = tf - ta;
  breaks[3] = tf;
  std::memset(&coefs[0], 0, 9U * sizeof(real_T));
  if (v == 0.0) {
    coefs[6] = s0;
    coefs[7] = s0;
    coefs[8] = s0;
  } else {
    coefs[0] = a / 2.0;
    coefs[3] = 0.0;
    coefs[6] = s0;
    coefs[1] = 0.0;
    coefs[4] = v;
    coefs_tmp = a / 2.0 * (ta * ta);
    coefs[7] = coefs_tmp + s0;
    coefs[2] = -a / 2.0;
    coefs[5] = v;
    coefs[8] = (coefs_tmp + sF) - v * ta;
  }
}

void trajectory_planner2ModelClass::tr_addFlatSegmentsToPPFormParts(const real_T
  oldbreaks_data[], const int32_T oldbreaks_size[2], const real_T
  oldCoeffs_data[], const int32_T oldCoeffs_size[2], real_T dim, real_T
  newBreaks_data[], int32_T newBreaks_size[2], real_T newCoefs_data[], int32_T
  newCoefs_size[2])
{
  real_T breaksWithFlatStart_data[9];
  real_T coefsWithFlatStart_data[126];
  real_T valueAtStart_data[6];
  real_T newSegmentCoeffs_data[18];
  real_T holdPoint;
  real_T valueAtEnd_data[42];
  real_T newSegmentCoeffs_data_0[18];
  int32_T d;
  int32_T m;
  int32_T aoffset;
  int32_T b_i;
  int32_T c_i;
  real_T B[3];
  int32_T loop_ub;
  int32_T breaksWithFlatStart_size_idx_1;
  int32_T m_tmp;
  int32_T coefsWithFlatStart_size_idx_0_t;
  int32_T m_tmp_0;
  int32_T loop_ub_tmp;
  real_T holdPoint_tmp;
  B[0] = 0.0;
  B[1] = 0.0;
  B[2] = 1.0;
  m_tmp = static_cast<int32_T>(dim);
  m = m_tmp - 1;
  if (0 <= m) {
    std::memset(&valueAtStart_data[0], 0, (m + 1) * sizeof(real_T));
  }

  for (b_i = 0; b_i < 3; b_i++) {
    aoffset = b_i * m_tmp - 1;
    for (c_i = 0; c_i <= m; c_i++) {
      d = (aoffset + c_i) + 1;
      valueAtStart_data[c_i] += oldCoeffs_data[d / m_tmp * oldCoeffs_size[0] + d
        % m_tmp] * B[b_i];
    }
  }

  loop_ub_tmp = m_tmp * 3 - 1;
  if (0 <= loop_ub_tmp) {
    std::memset(&newSegmentCoeffs_data[0], 0, (loop_ub_tmp + 1) * sizeof(real_T));
  }

  for (d = 0; d < m_tmp; d++) {
    newSegmentCoeffs_data[d + (m_tmp << 1)] = valueAtStart_data[d];
  }

  coefsWithFlatStart_size_idx_0_t = static_cast<int32_T>((static_cast<real_T>
    (oldCoeffs_size[0]) + dim));
  loop_ub = coefsWithFlatStart_size_idx_0_t * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&coefsWithFlatStart_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  for (d = 0; d < 3; d++) {
    for (m = 0; m < m_tmp; m++) {
      coefsWithFlatStart_data[m + coefsWithFlatStart_size_idx_0_t * d] =
        newSegmentCoeffs_data[m_tmp * d + m];
    }
  }

  d = static_cast<int32_T>((dim + 1.0));
  loop_ub = oldCoeffs_size[0];
  for (m = 0; m < 3; m++) {
    for (breaksWithFlatStart_size_idx_1 = 0; breaksWithFlatStart_size_idx_1 <
         loop_ub; breaksWithFlatStart_size_idx_1++) {
      coefsWithFlatStart_data[((d + breaksWithFlatStart_size_idx_1) +
        coefsWithFlatStart_size_idx_0_t * m) - 1] =
        oldCoeffs_data[oldCoeffs_size[0] * m + breaksWithFlatStart_size_idx_1];
    }
  }

  breaksWithFlatStart_size_idx_1 = oldbreaks_size[1] + 1;
  loop_ub = oldbreaks_size[0] * oldbreaks_size[1] - 1;
  breaksWithFlatStart_data[0] = oldbreaks_data[0] - 1.0;
  if (0 <= loop_ub) {
    std::memcpy(&breaksWithFlatStart_data[1], &oldbreaks_data[0], (loop_ub + 1) *
                sizeof(real_T));
  }

  holdPoint_tmp = breaksWithFlatStart_data[breaksWithFlatStart_size_idx_1 - 1];
  holdPoint = holdPoint_tmp -
    breaksWithFlatStart_data[breaksWithFlatStart_size_idx_1 - 2];
  B[0] = rt_powd_snf(holdPoint, 2.0);
  B[1] = rt_powd_snf(holdPoint, 1.0);
  B[2] = rt_powd_snf(holdPoint, 0.0);
  holdPoint = (static_cast<real_T>(coefsWithFlatStart_size_idx_0_t) - dim) + 1.0;
  if (holdPoint > coefsWithFlatStart_size_idx_0_t) {
    loop_ub = 0;
    d = 0;
  } else {
    loop_ub = static_cast<int32_T>(holdPoint) - 1;
    d = coefsWithFlatStart_size_idx_0_t;
  }

  m_tmp_0 = d - loop_ub;
  m = m_tmp_0 - 1;
  if (0 <= m) {
    std::memset(&valueAtEnd_data[0], 0, (m + 1) * sizeof(real_T));
  }

  for (b_i = 0; b_i < 3; b_i++) {
    aoffset = (m + 1) * b_i - 1;
    for (c_i = 0; c_i <= m; c_i++) {
      d = (aoffset + c_i) + 1;
      valueAtEnd_data[c_i] += coefsWithFlatStart_data[(d % m_tmp_0 + loop_ub) +
        d / m_tmp_0 * coefsWithFlatStart_size_idx_0_t] * B[b_i];
    }
  }

  if (0 <= loop_ub_tmp) {
    std::memset(&newSegmentCoeffs_data_0[0], 0, (loop_ub_tmp + 1) * sizeof
                (real_T));
  }

  for (d = 0; d < m_tmp_0; d++) {
    newSegmentCoeffs_data_0[d + (m_tmp << 1)] = valueAtEnd_data[d];
  }

  loop_ub_tmp = static_cast<int32_T>((static_cast<real_T>
    (coefsWithFlatStart_size_idx_0_t) + dim));
  newCoefs_size[0] = loop_ub_tmp;
  newCoefs_size[1] = 3;
  loop_ub = loop_ub_tmp * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&newCoefs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  for (d = 0; d < 3; d++) {
    for (m = 0; m < coefsWithFlatStart_size_idx_0_t; m++) {
      newCoefs_data[m + loop_ub_tmp * d] =
        coefsWithFlatStart_data[coefsWithFlatStart_size_idx_0_t * d + m];
    }
  }

  for (d = 0; d < 3; d++) {
    for (m = 0; m < m_tmp; m++) {
      newCoefs_data[((coefsWithFlatStart_size_idx_0_t + (m + 1)) + loop_ub_tmp *
                     d) - 1] = newSegmentCoeffs_data_0[m_tmp * d + m];
    }
  }

  newBreaks_size[0] = 1;
  newBreaks_size[1] = breaksWithFlatStart_size_idx_1 + 1;
  if (0 <= breaksWithFlatStart_size_idx_1 - 1) {
    std::memcpy(&newBreaks_data[0], &breaksWithFlatStart_data[0],
                breaksWithFlatStart_size_idx_1 * sizeof(real_T));
  }

  newBreaks_data[breaksWithFlatStart_size_idx_1] = holdPoint_tmp + 1.0;
}

void trajectory_planner2ModelClass::trajectory_polyCoeffsDerivative(const real_T
  coeffs_data[], const int32_T coeffs_size[2], real_T dCoeffs_data[], int32_T
  dCoeffs_size[2])
{
  int32_T loop_ub;
  int32_T i;
  int32_T b_idx_0;
  b_idx_0 = coeffs_size[0];
  dCoeffs_size[0] = coeffs_size[0];
  dCoeffs_size[1] = 3;
  loop_ub = coeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&dCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  loop_ub = coeffs_size[0];
  for (i = 0; i < loop_ub; i++) {
    dCoeffs_data[i + b_idx_0] = 2.0 * coeffs_data[i];
  }

  loop_ub = coeffs_size[0];
  for (i = 0; i < loop_ub; i++) {
    dCoeffs_data[i + (b_idx_0 << 1)] = coeffs_data[i + coeffs_size[0]];
  }
}

int32_T trajectory_planner2ModelClass::trajectory_planner2_bsearch(const real_T
  x_data[], const int32_T x_size[2], real_T xi)
{
  int32_T n;
  int32_T low_ip1;
  int32_T high_i;
  int32_T mid_i;
  n = 1;
  low_ip1 = 1;
  high_i = x_size[1];
  while (high_i > low_ip1 + 1) {
    mid_i = (n >> 1) + (high_i >> 1);
    if (((n & 1) == 1) && ((high_i & 1) == 1)) {
      mid_i++;
    }

    if (xi >= x_data[mid_i - 1]) {
      n = mid_i;
      low_ip1 = mid_i;
    } else {
      high_i = mid_i;
    }
  }

  return n;
}

void trajectory_planner2ModelClass::trajectory_planner2_ppval(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], const real_T x[2], real_T v_data[], int32_T
  v_size[2])
{
  int32_T elementsPerPage;
  int32_T coefStride;
  int32_T ix;
  int32_T ip;
  int32_T icp;
  real_T xloc;
  int32_T c_j;
  int32_T v_data_tmp;
  elementsPerPage = pp_coefs_size[0] - 1;
  coefStride = (pp_breaks_size[1] - 1) * pp_coefs_size[0];
  v_size[0] = pp_coefs_size[0];
  v_size[1] = 2;
  if (pp_coefs_size[0] == 1) {
    if (rtIsNaN(x[0])) {
      v_data[0] = x[0];
    } else {
      ip = trajectory_planner2_bsearch(pp_breaks_data, pp_breaks_size, x[0]) - 1;
      xloc = x[0] - pp_breaks_data[ip];
      v_data[0] = (xloc * pp_coefs_data[ip] + pp_coefs_data[ip + coefStride]) *
        xloc + pp_coefs_data[(coefStride << 1) + ip];
    }

    if (rtIsNaN(x[1])) {
      v_data[1] = x[1];
    } else {
      ip = trajectory_planner2_bsearch(pp_breaks_data, pp_breaks_size, x[1]) - 1;
      xloc = x[1] - pp_breaks_data[ip];
      v_data[1] = (xloc * pp_coefs_data[ip] + pp_coefs_data[ip + coefStride]) *
        xloc + pp_coefs_data[(coefStride << 1) + ip];
    }
  } else {
    if (rtIsNaN(x[0])) {
      for (ip = 0; ip <= elementsPerPage; ip++) {
        v_data[ip] = x[0];
      }
    } else {
      ip = trajectory_planner2_bsearch(pp_breaks_data, pp_breaks_size, x[0]) - 1;
      icp = (elementsPerPage + 1) * ip;
      xloc = x[0] - pp_breaks_data[ip];
      ip = (icp + coefStride) - 1;
      for (c_j = 0; c_j <= elementsPerPage; c_j++) {
        v_data[c_j] = pp_coefs_data[icp + c_j];
        ix = c_j + 1;
        v_data[-1 + ix] = v_data[-1 + ix] * xloc + pp_coefs_data[ip + ix];
      }

      ip = ((coefStride << 1) + icp) - 1;
      for (icp = 0; icp <= elementsPerPage; icp++) {
        ix = icp + 1;
        v_data[-1 + ix] = v_data[-1 + ix] * xloc + pp_coefs_data[ip + ix];
      }
    }

    if (rtIsNaN(x[1])) {
      for (ip = 0; ip <= elementsPerPage; ip++) {
        v_data[(elementsPerPage + ip) + 1] = x[1];
      }
    } else {
      ip = trajectory_planner2_bsearch(pp_breaks_data, pp_breaks_size, x[1]) - 1;
      icp = (elementsPerPage + 1) * ip;
      xloc = x[1] - pp_breaks_data[ip];
      ip = (icp + coefStride) - 1;
      for (c_j = 0; c_j <= elementsPerPage; c_j++) {
        v_data[(elementsPerPage + c_j) + 1] = pp_coefs_data[icp + c_j];
        ix = c_j + 1;
        v_data_tmp = elementsPerPage + ix;
        v_data[v_data_tmp] = v_data[v_data_tmp] * xloc + pp_coefs_data[ip + ix];
      }

      ip = ((coefStride << 1) + icp) - 1;
      for (icp = 0; icp <= elementsPerPage; icp++) {
        ix = icp + 1;
        v_data_tmp = elementsPerPage + ix;
        v_data[v_data_tmp] = v_data[v_data_tmp] * xloc + pp_coefs_data[ip + ix];
      }
    }
  }
}

void trajectory_planner2ModelClass::t_generateTrajectoriesFromCoefs(const real_T
  breaks_data[], const int32_T breaks_size[2], const real_T coeffs_data[], const
  int32_T coeffs_size[2], real_T dim, const real_T t[2], real_T q_data[],
  int32_T q_size[2], real_T qd_data[], int32_T qd_size[2], real_T qdd_data[],
  int32_T qdd_size[2], real_T pp_breaks_data[], int32_T pp_breaks_size[2],
  real_T pp_coefs_data[], int32_T pp_coefs_size[3])
{
  real_T dCoeffs_data[144];
  real_T modBreaks_data[10];
  real_T modCoeffs_data[144];
  real_T modBreaks_data_0[10];
  real_T tmp_data[162];
  int32_T num[3];
  int32_T loop_ub;
  int32_T dCoeffs_size[2];
  int32_T modBreaks_size[2];
  int32_T modCoeffs_size[2];
  int32_T modBreaks_size_0[2];
  int32_T modBreaks_size_1[2];
  int32_T modBreaks_size_2[2];
  int32_T tmp_size[2];
  int32_T num_idx_1;
  int32_T num_idx_0_tmp;
  tr_addFlatSegmentsToPPFormParts(breaks_data, breaks_size, coeffs_data,
    coeffs_size, dim, modBreaks_data, modBreaks_size, modCoeffs_data,
    modCoeffs_size);
  trajectory_polyCoeffsDerivative(modCoeffs_data, modCoeffs_size, tmp_data,
    tmp_size);
  dCoeffs_size[0] = tmp_size[0];
  dCoeffs_size[1] = 3;
  loop_ub = tmp_size[0] * tmp_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&dCoeffs_data[0], &tmp_data[0], loop_ub * sizeof(real_T));
  }

  num_idx_0_tmp = static_cast<int32_T>(dim);
  num_idx_1 = modBreaks_size[1] - 1;
  pp_breaks_size[0] = 1;
  pp_breaks_size[1] = modBreaks_size[1];
  loop_ub = modBreaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&pp_breaks_data[0], &modBreaks_data[0], loop_ub * sizeof(real_T));
  }

  pp_coefs_size[0] = num_idx_0_tmp;
  pp_coefs_size[1] = num_idx_1;
  pp_coefs_size[2] = 3;
  loop_ub = num_idx_0_tmp * num_idx_1 * 3 - 1;
  if (0 <= loop_ub) {
    std::memcpy(&pp_coefs_data[0], &modCoeffs_data[0], (loop_ub + 1) * sizeof
                (real_T));
  }

  modBreaks_size_2[0] = 1;
  modBreaks_size_2[1] = modBreaks_size[1];
  loop_ub = modBreaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&modBreaks_data_0[0], &modBreaks_data[0], loop_ub * sizeof
                (real_T));
  }

  num[0] = num_idx_0_tmp;
  num[1] = num_idx_1;
  num[2] = 3;
  trajectory_planner2_ppval(modBreaks_data_0, modBreaks_size_2, modCoeffs_data,
    num, t, q_data, q_size);
  modBreaks_size_1[0] = 1;
  modBreaks_size_1[1] = modBreaks_size[1];
  loop_ub = modBreaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&modBreaks_data_0[0], &modBreaks_data[0], loop_ub * sizeof
                (real_T));
  }

  num[0] = num_idx_0_tmp;
  num[1] = modBreaks_size[1] - 1;
  num[2] = 3;
  trajectory_planner2_ppval(modBreaks_data_0, modBreaks_size_1, dCoeffs_data,
    num, t, qd_data, qd_size);
  trajectory_polyCoeffsDerivative(dCoeffs_data, dCoeffs_size, tmp_data, tmp_size);
  modBreaks_size_0[0] = 1;
  modBreaks_size_0[1] = modBreaks_size[1];
  loop_ub = modBreaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&modBreaks_data_0[0], &modBreaks_data[0], loop_ub * sizeof
                (real_T));
  }

  num[0] = num_idx_0_tmp;
  num[1] = modBreaks_size[1] - 1;
  num[2] = 3;
  trajectory_planner2_ppval(modBreaks_data_0, modBreaks_size_0, tmp_data, num, t,
    qdd_data, qdd_size);
}

void trajectory_planner2ModelClass::trajectory_planner2_trapveltraj(const real_T
  wayPoints[18], real_T varargin_2, real_T q[12], real_T qd[12], real_T qdd[12],
  real_T t[2], b_sFIF6B7xX8YpTZUzZY9pkT_traj_T ppCell_data[], int32_T
  *ppCell_size)
{
  c_robotics_core_internal_code_T parser;
  real_T tFi;
  real_T parameterMat[72];
  real_T coeffMat[108];
  real_T breakMat[42];
  boolean_T coefIndex[36];
  real_T lspbSegIndices_data[7];
  boolean_T hasMultipleBreaks;
  real_T rowSelection_data[6];
  k_cell_wrap_trajectory_planne_T breaksCell[6];
  real_T coefs[9];
  real_T breaks[4];
  real_T c_data[12];
  real_T d_data[12];
  int32_T b_j;
  int32_T f_data[7];
  int32_T k_data[6];
  int8_T o_data[36];
  real_T matrixInput_data[12];
  real_T varargin_1[6];
  int32_T nm1d2;
  int32_T k;
  real_T kd;
  int32_T n;
  int32_T c;
  int32_T b_k;
  real_T ndbl;
  real_T apnd;
  int32_T b_idx;
  int32_T i;
  int32_T b_size[2];
  int32_T c_size[2];
  int32_T d_size[2];
  real_T tFi_0;
  boolean_T exitg1;
  NameValueParser_NameValueParser(&parser);
  parser.ParsedResults.f3 = varargin_2;
  tFi = parser.ParsedResults.f3;
  for (n = 0; n < 12; n++) {
    matrixInput_data[n] = tFi;
    q[n] = 0.0;
    qd[n] = 0.0;
    qdd[n] = 0.0;
  }

  std::memset(&coeffMat[0], 0, 108U * sizeof(real_T));
  std::memset(&breakMat[0], 0, 42U * sizeof(real_T));
  for (b_idx = 0; b_idx < 6; b_idx++) {
    for (b_j = 0; b_j < 2; b_j++) {
      trajectory_computeProfileParams(static_cast<real_T>(b_idx) + 1.0,
        static_cast<real_T>(b_j) + 1.0, wayPoints, matrixInput_data, &tFi, &apnd,
        &kd, &ndbl);
      parameterMat[b_idx + 6 * b_j] = wayPoints[6 * b_j + b_idx];
      i = b_idx + 6 * b_j;
      parameterMat[i + 12] = wayPoints[(b_j + 1) * 6 + b_idx];
      parameterMat[i + 24] = tFi;
      i = b_idx + 6 * b_j;
      parameterMat[i + 36] = apnd;
      parameterMat[i + 48] = kd;
      parameterMat[i + 60] = ndbl;
      t_computeScalarLSPBCoefficients(wayPoints[b_idx + 6 * b_j],
        wayPoints[b_idx + 6 * (b_j + 1)], tFi, apnd, kd, ndbl, coefs, breaks);
      for (i = 0; i < 36; i++) {
        coefIndex[i] = false;
      }

      i = 3 * b_j * 6;
      tFi = (i + b_idx) + 1;
      kd = static_cast<real_T>(((i + b_idx) + 1)) + 12.0;
      if (kd < tFi) {
        i = 0;
      } else if (tFi == tFi) {
        nm1d2 = static_cast<int32_T>(std::floor((kd - tFi) / 6.0));
        i = nm1d2 + 1;
        for (n = 0; n <= nm1d2; n++) {
          lspbSegIndices_data[n] = 6.0 * static_cast<real_T>(n) + tFi;
        }
      } else {
        ndbl = std::floor((kd - tFi) / 6.0 + 0.5);
        apnd = ndbl * 6.0 + tFi;
        i = static_cast<int32_T>(apnd) - static_cast<int32_T>(kd);
        if (tFi > kd) {
          tFi_0 = tFi;
        } else {
          tFi_0 = kd;
        }

        if (std::abs(static_cast<real_T>(i)) < 4.4408920985006262E-16 * tFi_0) {
          ndbl++;
          apnd = kd;
        } else if (i > 0) {
          apnd = (ndbl - 1.0) * 6.0 + tFi;
        } else {
          ndbl++;
        }

        if (ndbl >= 0.0) {
          i = static_cast<int32_T>(ndbl);
        } else {
          i = 0;
        }

        n = i - 1;
        i = n + 1;
        if (n + 1 > 0) {
          lspbSegIndices_data[0] = tFi;
          if (n + 1 > 1) {
            lspbSegIndices_data[n] = apnd;
            nm1d2 = n / 2;
            c = nm1d2 - 2;
            for (b_k = 0; b_k <= c; b_k++) {
              k = b_k + 1;
              kd = static_cast<real_T>(k) * 6.0;
              lspbSegIndices_data[k] = tFi + kd;
              lspbSegIndices_data[n - k] = apnd - kd;
            }

            if (nm1d2 << 1 == n) {
              lspbSegIndices_data[nm1d2] = (tFi + apnd) / 2.0;
            } else {
              kd = static_cast<real_T>(nm1d2) * 6.0;
              lspbSegIndices_data[nm1d2] = tFi + kd;
              lspbSegIndices_data[nm1d2 + 1] = apnd - kd;
            }
          }
        }
      }

      nm1d2 = i - 1;
      for (n = 0; n <= nm1d2; n++) {
        f_data[n] = static_cast<int32_T>(lspbSegIndices_data[n]);
      }

      for (n = 0; n < i; n++) {
        coefIndex[f_data[n] - 1] = true;
      }

      n = 0;
      for (nm1d2 = 0; nm1d2 < 36; nm1d2++) {
        if (coefIndex[nm1d2]) {
          n++;
        }
      }

      i = n;
      n = 0;
      for (nm1d2 = 0; nm1d2 < 36; nm1d2++) {
        if (coefIndex[nm1d2]) {
          o_data[n] = static_cast<int8_T>((nm1d2 + 1));
          n++;
        }
      }

      for (n = 0; n < 3; n++) {
        for (nm1d2 = 0; nm1d2 < i; nm1d2++) {
          coeffMat[(o_data[nm1d2] + 36 * n) - 1] = coefs[i * n + nm1d2];
        }
      }

      n = (b_j + 1) * 3;
      apnd = breakMat[(n - 3) * 6 + b_idx];
      breakMat[b_idx + 6 * (n - 3)] = breaks[0] + apnd;
      breakMat[b_idx + 6 * (n - 2)] = breaks[1] + apnd;
      breakMat[b_idx + 6 * (n - 1)] = breaks[2] + apnd;
      breakMat[b_idx + 6 * n] = breaks[3] + apnd;
    }
  }

  hasMultipleBreaks = traj_checkPolyForMultipleBreaks(breakMat);
  trajec_processPolynomialResults(breakMat, coeffMat, hasMultipleBreaks,
    breaksCell, trajectory_planner2_DW.coeffsCell);
  trajectory_planner2_sum(&parameterMat[60], varargin_1);
  if (!rtIsNaN(varargin_1[0])) {
    b_idx = 1;
  } else {
    b_idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 7)) {
      if (!rtIsNaN(varargin_1[k - 1])) {
        b_idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }

  if (b_idx == 0) {
    tFi = varargin_1[0];
  } else {
    tFi = varargin_1[b_idx - 1];
    for (k = b_idx + 1; k < 7; k++) {
      apnd = varargin_1[k - 1];
      if (tFi < apnd) {
        tFi = apnd;
      }
    }
  }

  trajectory_planner2_linspace(tFi, t);
  if (hasMultipleBreaks) {
    apnd = 6.0;
    tFi = 1.0;
  } else {
    apnd = 1.0;
    tFi = 6.0;
  }

  b_idx = static_cast<int32_T>(apnd) - 1;
  *ppCell_size = static_cast<int32_T>(apnd);
  for (b_j = 0; b_j <= b_idx; b_j++) {
    if (hasMultipleBreaks) {
      i = 1;
      rowSelection_data[0] = static_cast<real_T>(b_j) + 1.0;
      apnd = static_cast<real_T>(b_j) + 1.0;
    } else {
      i = 6;
      for (n = 0; n < 6; n++) {
        rowSelection_data[n] = static_cast<real_T>(n) + 1.0;
      }

      apnd = 1.0;
    }

    t_generateTrajectoriesFromCoefs(breaksCell[static_cast<int32_T>(apnd) - 1].
      f1.data, breaksCell[static_cast<int32_T>(apnd) - 1].f1.size,
      trajectory_planner2_DW.coeffsCell[static_cast<int32_T>(apnd) - 1].f1.data,
      trajectory_planner2_DW.coeffsCell[static_cast<int32_T>(apnd) - 1].f1.size,
      tFi, t, matrixInput_data, b_size, c_data, c_size, d_data, d_size,
      ppCell_data[b_j].breaks.data, ppCell_data[b_j].breaks.size,
      ppCell_data[b_j].coefs.data, ppCell_data[b_j].coefs.size);
    for (n = 0; n < i; n++) {
      k_data[n] = static_cast<int32_T>(rowSelection_data[n]) - 1;
    }

    for (n = 0; n < i; n++) {
      q[k_data[n]] = matrixInput_data[n];
    }

    for (n = 0; n < i; n++) {
      q[k_data[n] + 6] = matrixInput_data[n + b_size[0]];
    }

    for (n = 0; n < i; n++) {
      k_data[n] = static_cast<int32_T>(rowSelection_data[n]) - 1;
    }

    for (n = 0; n < i; n++) {
      qd[k_data[n]] = c_data[n];
    }

    for (n = 0; n < i; n++) {
      qd[k_data[n] + 6] = c_data[n + c_size[0]];
    }

    for (n = 0; n < i; n++) {
      k_data[n] = static_cast<int32_T>(rowSelection_data[n]) - 1;
    }

    for (n = 0; n < i; n++) {
      qdd[k_data[n]] = d_data[n];
    }

    for (n = 0; n < i; n++) {
      qdd[k_data[n] + 6] = d_data[n + d_size[0]];
    }
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1DimFromP(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { true, false, false, false, false, false };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::trajectory_planner2_ppval_o(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  real_T x, real_T v_data[], int32_T *v_size)
{
  int32_T ip;
  real_T xloc;
  *v_size = 1;
  if (rtIsNaN(x)) {
    v_data[0] = x;
  } else {
    ip = trajectory_planner2_bsearch(pp_breaks_data, pp_breaks_size, x) - 1;
    xloc = x - pp_breaks_data[ip];
    v_data[0] = (pp_coefs_data[(ip + pp_breaks_size[1]) - 1] + xloc *
                 pp_coefs_data[ip]) * xloc + pp_coefs_data[((pp_breaks_size[1] -
      1) << 1) + ip];
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_generate1DTrajec(const real_T
  breaks_data[], const int32_T breaks_size[2], const real_T coefs_data[], const
  int32_T coefs_size[2], real_T t, real_T q_data[], int32_T *q_size, real_T
  qd_data[], int32_T *qd_size, real_T qdd_data[], int32_T *qdd_size)
{
  real_T dCoefs_data[162];
  real_T tmp_data[162];
  real_T breaks_data_0[10];
  int32_T loop_ub;
  int32_T dCoefs_size[2];
  int32_T breaks_size_0[2];
  int32_T breaks_size_1[2];
  int32_T breaks_size_2[2];
  trajectory_polyCoeffsDerivative(coefs_data, coefs_size, dCoefs_data,
    dCoefs_size);
  breaks_size_2[0] = 1;
  breaks_size_2[1] = breaks_size[1];
  loop_ub = breaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&breaks_data_0[0], &breaks_data[0], loop_ub * sizeof(real_T));
  }

  trajectory_planner2_ppval_o(breaks_data_0, breaks_size_2, coefs_data, t,
    q_data, q_size);
  breaks_size_1[0] = 1;
  breaks_size_1[1] = breaks_size[1];
  loop_ub = breaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&breaks_data_0[0], &breaks_data[0], loop_ub * sizeof(real_T));
  }

  trajectory_planner2_ppval_o(breaks_data_0, breaks_size_1, dCoefs_data, t,
    qd_data, qd_size);
  trajectory_polyCoeffsDerivative(dCoefs_data, dCoefs_size, tmp_data,
    breaks_size_2);
  breaks_size_0[0] = 1;
  breaks_size_0[1] = breaks_size[1];
  loop_ub = breaks_size[1];
  if (0 <= loop_ub - 1) {
    std::memcpy(&breaks_data_0[0], &breaks_data[0], loop_ub * sizeof(real_T));
  }

  trajectory_planner2_ppval_o(breaks_data_0, breaks_size_0, tmp_data, t,
    qdd_data, qdd_size);
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1DimFro_n(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { false, true, false, false, false, false };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1DimFr_nd(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { false, false, true, false, false, false };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1DimF_ndx(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { false, false, false, true, false, false };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1Dim_ndxq(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { false, false, false, false, true, false };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::TrapVelTrajSys_extract1Di_ndxqg(const real_T
  pp_breaks_data[], const int32_T pp_breaks_size[2], const real_T pp_coefs_data[],
  const int32_T pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2],
  real_T oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2])
{
  boolean_T coeffIndex_data[54];
  int32_T b_data[54];
  int32_T ntilerows;
  int32_T ibcol;
  int32_T b_itilerow;
  boolean_T a[6];
  int32_T i;
  static const boolean_T tmp[6] = { false, false, false, false, false, true };

  breaks_size[0] = 1;
  breaks_size[1] = pp_breaks_size[1];
  i = pp_breaks_size[1];
  if (0 <= i - 1) {
    std::memcpy(&breaks_data[0], &pp_breaks_data[0], i * sizeof(real_T));
  }

  for (i = 0; i < 6; i++) {
    a[i] = tmp[i];
  }

  ntilerows = pp_breaks_size[1] - 2;
  for (b_itilerow = 0; b_itilerow <= ntilerows; b_itilerow++) {
    ibcol = b_itilerow * 6 - 1;
    for (i = 0; i < 6; i++) {
      coeffIndex_data[(ibcol + i) + 1] = a[i];
    }
  }

  ntilerows = (pp_breaks_size[1] - 1) * 6 - 1;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_itilerow++;
    }
  }

  i = b_itilerow;
  b_itilerow = 0;
  for (ibcol = 0; ibcol <= ntilerows; ibcol++) {
    if (coeffIndex_data[ibcol]) {
      b_data[b_itilerow] = ibcol + 1;
      b_itilerow++;
    }
  }

  ntilerows = pp_coefs_size[0] * pp_coefs_size[1] * 3 / 3;
  oneDimCoeffs_size[0] = i;
  oneDimCoeffs_size[1] = 3;
  for (b_itilerow = 0; b_itilerow < 3; b_itilerow++) {
    for (ibcol = 0; ibcol < i; ibcol++) {
      oneDimCoeffs_data[ibcol + i * b_itilerow] = pp_coefs_data[(ntilerows *
        b_itilerow + b_data[ibcol]) - 1];
    }
  }
}

void trajectory_planner2ModelClass::traject_TrapVelTrajSys_stepImpl(real_T time,
  const real_T varargin_1[18], real_T varargin_2, real_T q[6], real_T qd[6],
  real_T qdd[6])
{
  real_T breaks_data[10];
  real_T oneDimCoeffs_data[162];
  real_T evalCoeffs_data[162];
  real_T unusedU8[12];
  real_T unusedU9[12];
  real_T unusedUa[12];
  real_T unusedUb[2];
  real_T b_data;
  real_T c_data;
  real_T d_data;
  real_T h_data;
  real_T i_data;
  real_T j_data;
  real_T n_data;
  real_T o_data;
  real_T p_data;
  real_T u_data;
  real_T v_data;
  real_T w_data;
  real_T bb_data;
  real_T cb_data;
  real_T db_data;
  real_T hb_data;
  real_T ib_data;
  real_T jb_data;
  int32_T loop_ub;
  int32_T breaks_size[2];
  int32_T oneDimCoeffs_size[2];
  int32_T evalCoeffs_size[2];
  int32_T b_size;
  int32_T oneDimCoeffs_size_tmp;
  trajectory_planner2_trapveltraj(varargin_1, varargin_2, unusedU8, unusedU9,
    unusedUa, unusedUb, trajectory_planner2_DW.trajPP.data,
    &trajectory_planner2_DW.trajPP.size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[0].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[0].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[0]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[0].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[0].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[0].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1DimFromP(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &d_data, &loop_ub, &c_data, &oneDimCoeffs_size_tmp,
    &b_data, &b_size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[1].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[1].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[1]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[1].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[1].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[1].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1DimFro_n(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &j_data, &loop_ub, &i_data, &oneDimCoeffs_size_tmp,
    &h_data, &b_size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[2].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[2].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[2]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[2].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[2].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[2].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1DimFr_nd(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &p_data, &loop_ub, &o_data, &oneDimCoeffs_size_tmp,
    &n_data, &b_size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[3].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[3].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[3]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[3].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[3].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[3].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1DimF_ndx(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &w_data, &loop_ub, &v_data, &oneDimCoeffs_size_tmp,
    &u_data, &b_size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[4].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[4].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[4]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[4].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[4].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[4].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1Dim_ndxq(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &db_data, &loop_ub, &cb_data, &oneDimCoeffs_size_tmp,
    &bb_data, &b_size);
  if (trajectory_planner2_DW.trajPP.size > 1) {
    breaks_size[0] = 1;
    breaks_size[1] = trajectory_planner2_DW.trajPP.data[5].breaks.size[1];
    loop_ub = trajectory_planner2_DW.trajPP.data[5].breaks.size[1];
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < loop_ub;
         oneDimCoeffs_size_tmp++) {
      breaks_data[oneDimCoeffs_size_tmp] = trajectory_planner2_DW.trajPP.data[5]
        .breaks.data[oneDimCoeffs_size_tmp];
    }

    oneDimCoeffs_size_tmp = trajectory_planner2_DW.trajPP.data[5].coefs.size[0] *
      trajectory_planner2_DW.trajPP.data[5].coefs.size[1] * 3 / 3;
    oneDimCoeffs_size[0] = oneDimCoeffs_size_tmp;
    loop_ub = oneDimCoeffs_size_tmp * 3 - 1;
    for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp <= loop_ub;
         oneDimCoeffs_size_tmp++) {
      oneDimCoeffs_data[oneDimCoeffs_size_tmp] =
        trajectory_planner2_DW.trajPP.data[5].coefs.data[oneDimCoeffs_size_tmp];
    }
  } else {
    TrapVelTrajSys_extract1Di_ndxqg(trajectory_planner2_DW.trajPP.data[0].
      breaks.data, trajectory_planner2_DW.trajPP.data[0].breaks.size,
      trajectory_planner2_DW.trajPP.data[0].coefs.data,
      trajectory_planner2_DW.trajPP.data[0].coefs.size, breaks_data, breaks_size,
      oneDimCoeffs_data, oneDimCoeffs_size);
  }

  evalCoeffs_size[0] = oneDimCoeffs_size[0];
  evalCoeffs_size[1] = 3;
  loop_ub = oneDimCoeffs_size[0] * 3 - 1;
  if (0 <= loop_ub) {
    std::memset(&evalCoeffs_data[0], 0, (loop_ub + 1) * sizeof(real_T));
  }

  if (1 > oneDimCoeffs_size[0]) {
    loop_ub = 0;
  } else {
    loop_ub = oneDimCoeffs_size[0];
  }

  for (oneDimCoeffs_size_tmp = 0; oneDimCoeffs_size_tmp < 3;
       oneDimCoeffs_size_tmp++) {
    for (b_size = 0; b_size < loop_ub; b_size++) {
      evalCoeffs_data[b_size + evalCoeffs_size[0] * oneDimCoeffs_size_tmp] =
        oneDimCoeffs_data[oneDimCoeffs_size[0] * oneDimCoeffs_size_tmp + b_size];
    }
  }

  TrapVelTrajSys_generate1DTrajec(breaks_data, breaks_size, evalCoeffs_data,
    evalCoeffs_size, time, &jb_data, &loop_ub, &ib_data, &oneDimCoeffs_size_tmp,
    &hb_data, &b_size);
  q[0] = d_data;
  q[1] = j_data;
  q[2] = p_data;
  q[3] = w_data;
  q[4] = db_data;
  q[5] = jb_data;
  qd[0] = c_data;
  qd[1] = i_data;
  qd[2] = o_data;
  qd[3] = v_data;
  qd[4] = cb_data;
  qd[5] = ib_data;
  qdd[0] = b_data;
  qdd[1] = h_data;
  qdd[2] = n_data;
  qdd[3] = u_data;
  qdd[4] = bb_data;
  qdd[5] = hb_data;
}

// Start for referenced model: 'trajectory_planner2'
void trajectory_planner2ModelClass::start(void)
{
  // Start for MATLABSystem: '<Root>/Trapezoidal Velocity Profile Trajectory'
  trajectory_planner2_DW.obj.EndTime[0] = 1.0;
  trajectory_planner2_DW.obj.EndTime[1] = 1.0;
  trajectory_planner2_DW.obj.isInitialized = 0;
  trajectory_planner2_DW.objisempty = true;
  trajectory_pla_SystemCore_setup(&trajectory_planner2_DW.obj);
}

// Output and update for referenced model: 'trajectory_planner2'
void trajectory_planner2ModelClass::step(real_T arg_time, const real_T
  arg_endpoint[6], real_T arg_eta_d[6], real_T arg_eta_d_dot[6], real_T
  arg_eta_d_dot_dot[6])
{
  real_T scale;
  real_T absxk;
  real_T t;
  real_T rtb_VectorConcatenate[18];
  real_T rtb_endtime;
  int32_T k;

  // MATLAB Function: '<Root>/MATLAB Function'
  rtb_endtime = 0.0;
  scale = 3.3121686421112381E-170;
  for (k = 0; k < 6; k++) {
    // SignalConversion generated from: '<Root>/Vector Concatenate'
    rtb_VectorConcatenate[k] = 0.0;

    // MATLAB Function: '<Root>/MATLAB Function'
    absxk = std::abs(arg_endpoint[k]);
    if (absxk > scale) {
      t = scale / absxk;
      rtb_endtime = rtb_endtime * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      rtb_endtime += t * t;
    }
  }

  // MATLAB Function: '<Root>/MATLAB Function' incorporates:
  //   Constant: '<Root>/avg_speed'

  rtb_endtime = scale * std::sqrt(rtb_endtime);
  rtb_endtime /= 2.0;
  if (rtb_endtime <= 0.0) {
    rtb_endtime = 1.0;
  }

  for (k = 0; k < 6; k++) {
    // SignalConversion generated from: '<Root>/Vector Concatenate'
    rtb_VectorConcatenate[k + 6] = arg_endpoint[k];

    // SignalConversion generated from: '<Root>/Vector Concatenate'
    rtb_VectorConcatenate[k + 12] = arg_endpoint[k];
  }

  // MATLABSystem: '<Root>/Trapezoidal Velocity Profile Trajectory'
  if (trajectory_planner2_DW.obj.TunablePropsChanged) {
    trajectory_planner2_DW.obj.TunablePropsChanged = false;
  }

  // Reshape: '<Root>/Reshape3' incorporates:
  //   MATLABSystem: '<Root>/Trapezoidal Velocity Profile Trajectory'
  //   Reshape: '<Root>/Reshape1'
  //   Reshape: '<Root>/Reshape2'

  traject_TrapVelTrajSys_stepImpl(arg_time, rtb_VectorConcatenate, rtb_endtime,
    arg_eta_d, arg_eta_d_dot, arg_eta_d_dot_dot);
}

// Model initialize function
void trajectory_planner2ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
trajectory_planner2ModelClass::trajectory_planner2ModelClass()
{
  // Currently there is no constructor body generated.
}

// Destructor
trajectory_planner2ModelClass::~trajectory_planner2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_trajectory_planner2_T * trajectory_planner2ModelClass::getRTM()
{
  return (&trajectory_planner2_M);
}

// member function to setup error status pointer
void trajectory_planner2ModelClass::setErrorStatusPointer(const char_T
  **rt_errorStatus)
{
  rtmSetErrorStatusPointer((&trajectory_planner2_M), rt_errorStatus);
}

//
// File trailer for generated code.
//
// [EOF]
//
