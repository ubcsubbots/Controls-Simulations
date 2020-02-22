//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: thrust_allocation2.h
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.0
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:40:42 2020
//
// Target selection: ert.tlc
// Embedded hardware selection: Intel->x86-64 (Windows64)
// Code generation objectives:
//    1. Execution efficiency
//    2. RAM efficiency
// Validation result: Not run
//
#ifndef RTW_HEADER_thrust_allocation2_h_
#define RTW_HEADER_thrust_allocation2_h_
#include "rtwtypes.h"
#include <stddef.h>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <math.h>
#ifndef thrust_allocation2_COMMON_INCLUDES_
# define thrust_allocation2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 // thrust_allocation2_COMMON_INCLUDES_

// Macros for accessing real-time model data structure
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

// Forward declaration for rtModel
typedef struct tag_RTM RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_struct_LRrGrd8qubFR55llqE8teD_
#define DEFINED_TYPEDEF_FOR_struct_LRrGrd8qubFR55llqE8teD_

typedef struct {
  real_T m;
  real_T V;
  real_T W;
  real_T B;
  real_T xg;
  real_T yg;
  real_T zg;
  real_T xb;
  real_T yb;
  real_T zb;
  real_T Ixx;
  real_T Iyy;
  real_T Izz;
  real_T Xu;
  real_T Yv;
  real_T Zw;
  real_T Kp;
  real_T Kq;
  real_T Nr;
  real_T Xuu;
  real_T Yvv;
  real_T Zww;
  real_T Kpp;
  real_T Kqq;
  real_T Nrr;
  real_T alpha;
  real_T L1x;
  real_T L1y;
  real_T L2x;
  real_T L2y;
  real_T L3x;
  real_T L4x;
  real_T L5x;
  real_T L6x;
} struct_LRrGrd8qubFR55llqE8teD;

#endif

// External inputs (root inport signals with default storage)
typedef struct {
  real_T tau[6];                       // '<Root>/tau '
} ExtU;

// External outputs (root outports fed by signals with default storage)
typedef struct {
  real_T signals[6];                   // '<Root>/signals '
} ExtY;

// Real-time Model Data Structure
struct tag_RTM {
  const char_T * volatile errorStatus;
};

// Class declaration for model thrust_allocation2
class thrust_allocation2ModelClass {
  // public data and function members
 public:
  // External inputs
  ExtU rtU;

  // External outputs
  ExtY rtY;

  // model initialize function
  void initialize();

  // model step function
  void step();

  // Constructor
  thrust_allocation2ModelClass();

  // Destructor
  ~thrust_allocation2ModelClass();

  // Real-Time Model get method
  RT_MODEL * getRTM();

  // private data and function members
 private:
  // Real-Time Model
  RT_MODEL rtM;

  // private member function(s) for subsystem '<Root>'
  void cosd(real_T *x);
  void sind(real_T *x);
  real_T xnrm2(int32_T n, const real_T x[100], int32_T ix0);
  real_T xnrm2_e(int32_T n, const real_T x[10], int32_T ix0);
  void xaxpy_er(int32_T n, real_T a, const real_T x[10], int32_T ix0, real_T y
                [100], int32_T iy0);
  void xaxpy_e(int32_T n, real_T a, const real_T x[100], int32_T ix0, real_T y
               [10], int32_T iy0);
  real_T xdotc(int32_T n, const real_T x[100], int32_T ix0, const real_T y[100],
               int32_T iy0);
  void xaxpy(int32_T n, real_T a, int32_T ix0, real_T y[100], int32_T iy0);
  void xscal(real_T a, real_T x[100], int32_T ix0);
  void xswap(real_T x[100], int32_T ix0, int32_T iy0);
  void xrotg(real_T *a, real_T *b, real_T *c, real_T *s);
  void xrot(real_T x[100], int32_T ix0, int32_T iy0, real_T c, real_T s);
  void svd(const real_T A[100], real_T U[100], real_T s[10], real_T V[100]);
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
//  '<Root>' : 'thrust_allocation2'
//  '<S1>'   : 'thrust_allocation2/thrust-allocator'

#endif                                 // RTW_HEADER_thrust_allocation2_h_

//
// File trailer for generated code.
//
// [EOF]
//
