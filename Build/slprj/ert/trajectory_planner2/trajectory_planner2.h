//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: trajectory_planner2.h
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
#ifndef RTW_HEADER_trajectory_planner2_h_
#define RTW_HEADER_trajectory_planner2_h_
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include <stddef.h>
#ifndef trajectory_planner2_COMMON_INCLUDES_
# define trajectory_planner2_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 // trajectory_planner2_COMMON_INCLUDES_

#include <stddef.h>
#include "rt_nonfinite.h"
#include "rtGetInf.h"

// Forward declaration for rtModel
typedef struct tag_RTM_trajectory_planner2_T RT_MODEL_trajectory_planner2_T;

#ifndef typedef_b_struct_T_trajectory_planner_T
#define typedef_b_struct_T_trajectory_planner_T

typedef struct {
  char_T Value;
} b_struct_T_trajectory_planner_T;

#endif                                 //typedef_b_struct_T_trajectory_planner_T

#ifndef struct_tag_s9EmFjryYMO2W0AIR0xRarC
#define struct_tag_s9EmFjryYMO2W0AIR0xRarC

struct tag_s9EmFjryYMO2W0AIR0xRarC
{
  uint32_T PeakVelocity;
  uint32_T Acceleration;
  uint32_T EndTime;
  uint32_T AccelTime;
};

#endif                                 //struct_tag_s9EmFjryYMO2W0AIR0xRarC

#ifndef typedef_s9EmFjryYMO2W0AIR0xRarC_traje_T
#define typedef_s9EmFjryYMO2W0AIR0xRarC_traje_T

typedef struct tag_s9EmFjryYMO2W0AIR0xRarC s9EmFjryYMO2W0AIR0xRarC_traje_T;

#endif                                 //typedef_s9EmFjryYMO2W0AIR0xRarC_traje_T

#ifndef struct_tag_ssCAWgYRBSGm3mTQp0eAePF
#define struct_tag_ssCAWgYRBSGm3mTQp0eAePF

struct tag_ssCAWgYRBSGm3mTQp0eAePF
{
  real_T PeakVelocity;
  real_T Acceleration;
  real_T EndTime;
  real_T AccelTime;
};

#endif                                 //struct_tag_ssCAWgYRBSGm3mTQp0eAePF

#ifndef typedef_ssCAWgYRBSGm3mTQp0eAePF_traje_T
#define typedef_ssCAWgYRBSGm3mTQp0eAePF_traje_T

typedef struct tag_ssCAWgYRBSGm3mTQp0eAePF ssCAWgYRBSGm3mTQp0eAePF_traje_T;

#endif                                 //typedef_ssCAWgYRBSGm3mTQp0eAePF_traje_T

#ifndef struct_emxArray_real_T_1x10
#define struct_emxArray_real_T_1x10

struct emxArray_real_T_1x10
{
  real_T data[10];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_1x10

#ifndef typedef_emxArray_real_T_1x10_trajecto_T
#define typedef_emxArray_real_T_1x10_trajecto_T

typedef struct emxArray_real_T_1x10 emxArray_real_T_1x10_trajecto_T;

#endif                                 //typedef_emxArray_real_T_1x10_trajecto_T

#ifndef struct_emxArray_real_T_6x9x3
#define struct_emxArray_real_T_6x9x3

struct emxArray_real_T_6x9x3
{
  real_T data[162];
  int32_T size[3];
};

#endif                                 //struct_emxArray_real_T_6x9x3

#ifndef typedef_emxArray_real_T_6x9x3_traject_T
#define typedef_emxArray_real_T_6x9x3_traject_T

typedef struct emxArray_real_T_6x9x3 emxArray_real_T_6x9x3_traject_T;

#endif                                 //typedef_emxArray_real_T_6x9x3_traject_T

#ifndef struct_sJX8BrdZKS31RX5klm6Y7gG_tag
#define struct_sJX8BrdZKS31RX5klm6Y7gG_tag

struct sJX8BrdZKS31RX5klm6Y7gG_tag
{
  emxArray_real_T_1x10_trajecto_T breaks;
  emxArray_real_T_6x9x3_traject_T coefs;
};

#endif                                 //struct_sJX8BrdZKS31RX5klm6Y7gG_tag

#ifndef typedef_b_sFIF6B7xX8YpTZUzZY9pkT_traj_T
#define typedef_b_sFIF6B7xX8YpTZUzZY9pkT_traj_T

typedef struct sJX8BrdZKS31RX5klm6Y7gG_tag b_sFIF6B7xX8YpTZUzZY9pkT_traj_T;

#endif                                 //typedef_b_sFIF6B7xX8YpTZUzZY9pkT_traj_T

#ifndef struct_emxArray_real_T_1x8
#define struct_emxArray_real_T_1x8

struct emxArray_real_T_1x8
{
  real_T data[8];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_1x8

#ifndef typedef_emxArray_real_T_1x8_trajector_T
#define typedef_emxArray_real_T_1x8_trajector_T

typedef struct emxArray_real_T_1x8 emxArray_real_T_1x8_trajector_T;

#endif                                 //typedef_emxArray_real_T_1x8_trajector_T

#ifndef struct_sFKCr2mh4cT9MeU1xTZQR7F_tag
#define struct_sFKCr2mh4cT9MeU1xTZQR7F_tag

struct sFKCr2mh4cT9MeU1xTZQR7F_tag
{
  emxArray_real_T_1x8_trajector_T f1;
};

#endif                                 //struct_sFKCr2mh4cT9MeU1xTZQR7F_tag

#ifndef typedef_k_cell_wrap_trajectory_planne_T
#define typedef_k_cell_wrap_trajectory_planne_T

typedef struct sFKCr2mh4cT9MeU1xTZQR7F_tag k_cell_wrap_trajectory_planne_T;

#endif                                 //typedef_k_cell_wrap_trajectory_planne_T

#ifndef struct_emxArray_real_T_36x3
#define struct_emxArray_real_T_36x3

struct emxArray_real_T_36x3
{
  real_T data[108];
  int32_T size[2];
};

#endif                                 //struct_emxArray_real_T_36x3

#ifndef typedef_emxArray_real_T_36x3_trajecto_T
#define typedef_emxArray_real_T_36x3_trajecto_T

typedef struct emxArray_real_T_36x3 emxArray_real_T_36x3_trajecto_T;

#endif                                 //typedef_emxArray_real_T_36x3_trajecto_T

#ifndef struct_sWZi4oRIY5ISoUGxOqLUMy_tag
#define struct_sWZi4oRIY5ISoUGxOqLUMy_tag

struct sWZi4oRIY5ISoUGxOqLUMy_tag
{
  emxArray_real_T_36x3_trajecto_T f1;
};

#endif                                 //struct_sWZi4oRIY5ISoUGxOqLUMy_tag

#ifndef typedef_l_cell_wrap_trajectory_planne_T
#define typedef_l_cell_wrap_trajectory_planne_T

typedef struct sWZi4oRIY5ISoUGxOqLUMy_tag l_cell_wrap_trajectory_planne_T;

#endif                                 //typedef_l_cell_wrap_trajectory_planne_T

#ifndef typedef_i_cell_trajectory_planner2_T
#define typedef_i_cell_trajectory_planner2_T

typedef struct {
  real_T f3;
} i_cell_trajectory_planner2_T;

#endif                                 //typedef_i_cell_trajectory_planner2_T

#ifndef typedef_c_robotics_core_internal_code_T
#define typedef_c_robotics_core_internal_code_T

typedef struct {
  i_cell_trajectory_planner2_T ParsedResults;
} c_robotics_core_internal_code_T;

#endif                                 //typedef_c_robotics_core_internal_code_T

#ifndef typedef_struct_T_trajectory_planner2_T
#define typedef_struct_T_trajectory_planner2_T

typedef struct {
  char_T Value[8];
} struct_T_trajectory_planner2_T;

#endif                                 //typedef_struct_T_trajectory_planner2_T

#ifndef struct_tag_so4pBuofLXIy3ixtLNBoZq
#define struct_tag_so4pBuofLXIy3ixtLNBoZq

struct tag_so4pBuofLXIy3ixtLNBoZq
{
  char_T PartialMatching[6];
};

#endif                                 //struct_tag_so4pBuofLXIy3ixtLNBoZq

#ifndef typedef_so4pBuofLXIy3ixtLNBoZq_trajec_T
#define typedef_so4pBuofLXIy3ixtLNBoZq_trajec_T

typedef struct tag_so4pBuofLXIy3ixtLNBoZq so4pBuofLXIy3ixtLNBoZq_trajec_T;

#endif                                 //typedef_so4pBuofLXIy3ixtLNBoZq_trajec_T

#ifndef typedef_c_cell_wrap_trajectory_planne_T
#define typedef_c_cell_wrap_trajectory_planne_T

typedef struct {
  uint32_T f1[8];
} c_cell_wrap_trajectory_planne_T;

#endif                                 //typedef_c_cell_wrap_trajectory_planne_T

#ifndef typedef_robotics_slcore_internal_bloc_T
#define typedef_robotics_slcore_internal_bloc_T

typedef struct {
  int32_T isInitialized;
  boolean_T TunablePropsChanged;
  c_cell_wrap_trajectory_planne_T inputVarSize[3];
  real_T EndTime[2];
} robotics_slcore_internal_bloc_T;

#endif                                 //typedef_robotics_slcore_internal_bloc_T

#ifndef struct_emxArray_sJX8BrdZKS31RX5klm6Y7g
#define struct_emxArray_sJX8BrdZKS31RX5klm6Y7g

struct emxArray_sJX8BrdZKS31RX5klm6Y7g
{
  b_sFIF6B7xX8YpTZUzZY9pkT_traj_T data[6];
  int32_T size;
};

#endif                                 //struct_emxArray_sJX8BrdZKS31RX5klm6Y7g

#ifndef typedef_emxArray_b_sFIF6B7xX8YpTZUzZY_T
#define typedef_emxArray_b_sFIF6B7xX8YpTZUzZY_T

typedef struct emxArray_sJX8BrdZKS31RX5klm6Y7g emxArray_b_sFIF6B7xX8YpTZUzZY_T;

#endif                                 //typedef_emxArray_b_sFIF6B7xX8YpTZUzZY_T

// Block signals and states (default storage) for model 'trajectory_planner2'
typedef struct {
  emxArray_b_sFIF6B7xX8YpTZUzZY_T trajPP;
  l_cell_wrap_trajectory_planne_T coeffsCell[6];
  robotics_slcore_internal_bloc_T obj;
                            // '<Root>/Trapezoidal Velocity Profile Trajectory'
  boolean_T objisempty;     // '<Root>/Trapezoidal Velocity Profile Trajectory'
} DW_trajectory_planner2_T;

// Real-time Model Data Structure
struct tag_RTM_trajectory_planner2_T {
  const char_T **errorStatus;
};

// Class declaration for model trajectory_planner2
class trajectory_planner2ModelClass {
  // public data and function members
 public:
  // model initialize function
  void initialize();

  // model step function
  void step(real_T arg_time, const real_T arg_endpoint[6], real_T arg_eta_d[6],
            real_T arg_eta_d_dot[6], real_T arg_eta_d_dot_dot[6]);

  // model start function
  void start();

  // Constructor
  trajectory_planner2ModelClass();

  // Destructor
  ~trajectory_planner2ModelClass();

  // Real-Time Model get method
  RT_MODEL_trajectory_planner2_T * getRTM();

  //member function to setup error status pointer
  void setErrorStatusPointer(const char_T **rt_errorStatus);

  // private data and function members
 private:
  // Block signals and states
  DW_trajectory_planner2_T trajectory_planner2_DW;

  // Real-Time Model
  RT_MODEL_trajectory_planner2_T trajectory_planner2_M;

  // private member function(s) for subsystem '<Root>/TmpModelReferenceSubsystem'
  void trajectory_pla_SystemCore_setup(robotics_slcore_internal_bloc_T *obj);
  c_robotics_core_internal_code_T *NameValueParser_NameValueParser
    (c_robotics_core_internal_code_T *obj);
  boolean_T traj_checkPolyForMultipleBreaks(const real_T breakMat[42]);
  void trajec_processPolynomialResults(const real_T breakMat[42], const real_T
    coeffMat[108], boolean_T hasMultipleBreaks, k_cell_wrap_trajectory_planne_T
    breaksCell[6], l_cell_wrap_trajectory_planne_T coeffCell[6]);
  void trajectory_computeProfileParams(real_T i, real_T j, const real_T
    wayPoints[18], const real_T TFi_data[], real_T *vParam, real_T *aParam,
    real_T *tAParam, real_T *tFParam);
  void trajectory_planner2_sum(const real_T x[12], real_T y[6]);
  void trajectory_planner2_linspace(real_T d2, real_T y[2]);
  void t_computeScalarLSPBCoefficients(real_T s0, real_T sF, real_T v, real_T a,
    real_T ta, real_T tf, real_T coefs[9], real_T breaks[4]);
  void tr_addFlatSegmentsToPPFormParts(const real_T oldbreaks_data[], const
    int32_T oldbreaks_size[2], const real_T oldCoeffs_data[], const int32_T
    oldCoeffs_size[2], real_T dim, real_T newBreaks_data[], int32_T
    newBreaks_size[2], real_T newCoefs_data[], int32_T newCoefs_size[2]);
  void trajectory_polyCoeffsDerivative(const real_T coeffs_data[], const int32_T
    coeffs_size[2], real_T dCoeffs_data[], int32_T dCoeffs_size[2]);
  int32_T trajectory_planner2_bsearch(const real_T x_data[], const int32_T
    x_size[2], real_T xi);
  void trajectory_planner2_ppval(const real_T pp_breaks_data[], const int32_T
    pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], const real_T x[2], real_T v_data[], int32_T v_size[2]);
  void t_generateTrajectoriesFromCoefs(const real_T breaks_data[], const int32_T
    breaks_size[2], const real_T coeffs_data[], const int32_T coeffs_size[2],
    real_T dim, const real_T t[2], real_T q_data[], int32_T q_size[2], real_T
    qd_data[], int32_T qd_size[2], real_T qdd_data[], int32_T qdd_size[2],
    real_T pp_breaks_data[], int32_T pp_breaks_size[2], real_T pp_coefs_data[],
    int32_T pp_coefs_size[3]);
  void trajectory_planner2_trapveltraj(const real_T wayPoints[18], real_T
    varargin_2, real_T q[12], real_T qd[12], real_T qdd[12], real_T t[2],
    b_sFIF6B7xX8YpTZUzZY9pkT_traj_T ppCell_data[], int32_T *ppCell_size);
  void TrapVelTrajSys_extract1DimFromP(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void trajectory_planner2_ppval_o(const real_T pp_breaks_data[], const int32_T
    pp_breaks_size[2], const real_T pp_coefs_data[], real_T x, real_T v_data[],
    int32_T *v_size);
  void TrapVelTrajSys_generate1DTrajec(const real_T breaks_data[], const int32_T
    breaks_size[2], const real_T coefs_data[], const int32_T coefs_size[2],
    real_T t, real_T q_data[], int32_T *q_size, real_T qd_data[], int32_T
    *qd_size, real_T qdd_data[], int32_T *qdd_size);
  void TrapVelTrajSys_extract1DimFro_n(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void TrapVelTrajSys_extract1DimFr_nd(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void TrapVelTrajSys_extract1DimF_ndx(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void TrapVelTrajSys_extract1Dim_ndxq(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void TrapVelTrajSys_extract1Di_ndxqg(const real_T pp_breaks_data[], const
    int32_T pp_breaks_size[2], const real_T pp_coefs_data[], const int32_T
    pp_coefs_size[3], real_T breaks_data[], int32_T breaks_size[2], real_T
    oneDimCoeffs_data[], int32_T oneDimCoeffs_size[2]);
  void traject_TrapVelTrajSys_stepImpl(real_T time, const real_T varargin_1[18],
    real_T varargin_2, real_T q[6], real_T qd[6], real_T qdd[6]);
};

//-
//  These blocks were eliminated from the model due to optimizations:
//
//  Block '<Root>/Reshape' : Reshape block reduction


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
//  '<Root>' : 'trajectory_planner2'
//  '<S1>'   : 'trajectory_planner2/MATLAB Function'

#endif                                 // RTW_HEADER_trajectory_planner2_h_

//
// File trailer for generated code.
//
// [EOF]
//
