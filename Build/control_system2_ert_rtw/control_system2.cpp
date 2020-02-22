//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: control_system2.cpp
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
#include "control_system2.h"

// Model step function
void control_system2ModelClass::step()
{
  // local block i/o variables
  real_T rtb_Model_o1[6];
  real_T rtb_Model_o2[6];
  real_T rtb_Model_o3[6];
  real_T rtb_Ma_bCnunuDnunugeta[6];

  // ModelReference: '<Root>/Model' incorporates:
  //   Inport: '<Root>/endpoint '
  //   Inport: '<Root>/time '

  ModelMDLOBJ1.step(control_system2_U.time, &control_system2_U.endpoint[0],
                    &rtb_Model_o1[0], &rtb_Model_o2[0], &rtb_Model_o3[0]);

  // ModelReference: '<Root>/Model1' incorporates:
  //   Inport: '<Root>/x'

  Model1MDLOBJ2.step(&rtb_Model_o1[0], &rtb_Model_o2[0], &rtb_Model_o3[0],
                     &control_system2_U.x[0], &rtb_Ma_bCnunuDnunugeta[0]);

  // ModelReference: '<Root>/Model2' incorporates:
  //   Outport: '<Root>/signals'

  Model2MDLOBJ3.step(&rtb_Ma_bCnunuDnunugeta[0], &control_system2_Y.signals[0]);
}

// Model initialize function
void control_system2ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));

  // Model Initialize function for ModelReference Block: '<Root>/Model'

  // Set error status pointer for ModelReference Block: '<Root>/Model'
  ModelMDLOBJ1.setErrorStatusPointer(rtmGetErrorStatusPointer
    ((&control_system2_M)));
  ModelMDLOBJ1.initialize();

  // Model Initialize function for ModelReference Block: '<Root>/Model1'

  // Set error status pointer for ModelReference Block: '<Root>/Model1'
  Model1MDLOBJ2.setErrorStatusPointer(rtmGetErrorStatusPointer
    ((&control_system2_M)));
  Model1MDLOBJ2.initialize();

  // Model Initialize function for ModelReference Block: '<Root>/Model2'

  // Set error status pointer for ModelReference Block: '<Root>/Model2'
  Model2MDLOBJ3.setErrorStatusPointer(rtmGetErrorStatusPointer
    ((&control_system2_M)));
  Model2MDLOBJ3.initialize();

  // Start for ModelReference: '<Root>/Model' incorporates:
  //   Inport: '<Root>/endpoint '
  //   Inport: '<Root>/time '

  ModelMDLOBJ1.start();
}

// Constructor
control_system2ModelClass::control_system2ModelClass() : control_system2_M()
{
  // Currently there is no constructor body generated.
}

// Destructor
control_system2ModelClass::~control_system2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL_control_system2_T * control_system2ModelClass::getRTM()
{
  return (&control_system2_M);
}

//
// File trailer for generated code.
//
// [EOF]
//
