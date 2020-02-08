//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trajectory_planner.h
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
#ifndef RTW_HEADER_trajectory_planner_h_
#define RTW_HEADER_trajectory_planner_h_
#include <string.h>
#include <stddef.h>
#ifndef trajectory_planner_COMMON_INCLUDES_
# define trajectory_planner_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // trajectory_planner_COMMON_INCLUDES_

#include <stddef.h>

// Class declaration for model trajectory_planner
class trajectory_plannerModelClass {
  // public data and function members
 public:
  // model step function
  void step(real_T arg_cmd_, real_T arg_time_, real_T *arg_x_d, real_T
            *arg_x_dot_d, real_T *arg_x_dot_dot_d_);

  // Constructor
  trajectory_plannerModelClass();

  // Destructor
  ~trajectory_plannerModelClass();

  // private data and function members
 private:
};

//-
//  The generated code includes comments that allow you to trace directly
//  back to the appropriate location in the model.  The basic format
//  is <system>/block_name, where system is the system number (uniquely
//  assigned by Simulink) and block_name is the name of the block.
//
//  Use the MATLAB hilite_system command to trace the generated code back
//  to the model.  For example,
//
//  hilite_system('<S3>')    - opens system 3
//  hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
//
//  Here is the system hierarchy for this model
//
//  '<Root>' : 'trajectory_planner'

#endif                                 // RTW_HEADER_trajectory_planner_h_

//
// File trailer for generated code.
//
// [EOF]
//
