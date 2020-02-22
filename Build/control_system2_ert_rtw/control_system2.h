//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: control_system2.h
//
// Code generated for Simulink model 'control_system2'.
//
// Model version                  : 1.4
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 15:11:53 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_control_system2_h_
#define RTW_HEADER_control_system2_h_
#ifndef control_system2_COMMON_INCLUDES_
# define control_system2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // control_system2_COMMON_INCLUDES_

// Child system includes
#include "trajectory_planner2.h"
#include "controller2.h"
#include "thrust_allocation2.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetErrorStatusPointer
# define rtmGetErrorStatusPointer(rtm) ((const char_T **)(&((rtm)->errorStatus)))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM_control_system2_T RT_MODEL_control_system2_T;

// External inputs (root inport signals with default storage)
typedef struct {
  real_T time;                         // '<Root>/time '
  real_T endpoint[6];                  // '<Root>/endpoint '
  real_T x[12];                        // '<Root>/x'
} ExtU_control_system2_T;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T signals[6];                   // '<Root>/signals'
} ExtY_control_system2_T;

// Real-time Model Data Structure
struct tag_RTM_control_system2_T {
  const char_T * volatile errorStatus;
};

// Class declaration for model control_system2
class control_system2ModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU_control_system2_T control_system2_U;

  // External outputs
  ExtY_control_system2_T control_system2_Y;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  control_system2ModelClass();

  // Destructor
  ~control_system2ModelClass();

  // Real-Time Model get method
  RT_MODEL_control_system2_T * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL_control_system2_T control_system2_M;

  // model instance variable for '<Root>/Model'
  trajectory_planner2ModelClass ModelMDLOBJ1;

  // model instance variable for '<Root>/Model1'
  controller2ModelClass Model1MDLOBJ2;

  // model instance variable for '<Root>/Model2'
  thrust_allocation2ModelClass Model2MDLOBJ3;
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
//  '<Root>' : 'control_system2'

#endif                                 // RTW_HEADER_control_system2_h_

//
// File trailer for generated code.
//
// [EOF]
//
