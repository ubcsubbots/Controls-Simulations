//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trajectory_planner.cpp
//
// Code generated for Simulink model 'trajectory_planner'.
//
// Model version                  : 1.9
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Fri Feb  7 15:17:40 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "trajectory_planner.h"

// Output and update for referenced model: 'trajectory_planner'
void trajectory_plannerModelClass::step(real_T arg_cmd_, real_T arg_time_,
  real_T *arg_x_d, real_T *arg_x_dot_d, real_T *arg_x_dot_dot_d_)
{
  // Inport: '<Root>/cmd '
  *arg_x_dot_d = arg_cmd_;

  // SignalConversion: '<Root>/TmpSignal ConversionAtx_dInport1'
  *arg_x_d = *arg_x_dot_d;

  // Inport: '<Root>/time '
  *arg_x_dot_dot_d_ = arg_time_;
}

// Constructor
trajectory_plannerModelClass::trajectory_plannerModelClass()
{
}

// Destructor
trajectory_plannerModelClass::~trajectory_plannerModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
