//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: controller.cpp
//
// Code generated for Simulink model 'controller'.
//
// Model version                  : 1.8
// Simulink Coder version         : 8.13 (R2017b) 24-Jul-2017
// C/C++ source code generated on : Fri Feb  7 15:17:31 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#include "controller.h"

// Output and update for referenced model: 'controller'
void controllerModelClass::step(real_T arg_x_d, real_T arg_x_dot_d, real_T
  arg_x_dot_dot_d_, real_T arg_x, real_T arg_x_dot_, real_T arg_x_dot_dot_,
  real_T *arg_tau_)
{
  // Inport: '<Root>/x_d'
  *arg_tau_ = arg_x_d;
  (void)arg_x_dot_d;
  (void)arg_x_dot_dot_d_;
  (void)arg_x;
  (void)arg_x_dot_;
  (void)arg_x_dot_dot_;
}

// Constructor
controllerModelClass::controllerModelClass()
{
}

// Destructor
controllerModelClass::~controllerModelClass()
{
  // Currently there is no destructor body generated.
}

//
// File trailer for generated code.
//
// [EOF]
//
