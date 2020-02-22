//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: thrust_allocation2.cpp
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
#include "thrust_allocation2.h"
#define NumBitsPerChar                 8U

extern real_T rt_remd_snf(real_T u0, real_T u1);
extern "C" {
  static real_T rtGetNaN(void);
  static real32_T rtGetNaNF(void);
}                                      // extern "C"
  extern "C"
{
  extern real_T rtInf;
  extern real_T rtMinusInf;
  extern real_T rtNaN;
  extern real32_T rtInfF;
  extern real32_T rtMinusInfF;
  extern real32_T rtNaNF;
  static void rt_InitInfAndNaN(size_t realSize);
  static boolean_T rtIsInf(real_T value);
  static boolean_T rtIsInfF(real32_T value);
  static boolean_T rtIsNaN(real_T value);
  static boolean_T rtIsNaNF(real32_T value);
  typedef struct {
    struct {
      uint32_T wordH;
      uint32_T wordL;
    } words;
  } BigEndianIEEEDouble;

  typedef struct {
    struct {
      uint32_T wordL;
      uint32_T wordH;
    } words;
  } LittleEndianIEEEDouble;

  typedef struct {
    union {
      real32_T wordLreal;
      uint32_T wordLuint;
    } wordL;
  } IEEESingle;
}                                      // extern "C"

extern "C" {
  real_T rtInf;
  real_T rtMinusInf;
  real_T rtNaN;
  real32_T rtInfF;
  real32_T rtMinusInfF;
  real32_T rtNaNF;
}
  extern "C"
{
  static real_T rtGetInf(void);
  static real32_T rtGetInfF(void);
  static real_T rtGetMinusInf(void);
  static real32_T rtGetMinusInfF(void);
}                                      // extern "C"

extern "C" {
  //
  // Initialize rtNaN needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetNaN(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T nan = 0.0;
    if (bitsPerReal == 32U) {
      nan = rtGetNaNF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF80000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      nan = tmpVal.fltVal;
    }

    return nan;
  }

  //
  // Initialize rtNaNF needed by the generated code.
  // NaN is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetNaNF(void)
  {
    IEEESingle nanF = { { 0 } };

    nanF.wordL.wordLuint = 0xFFC00000U;
    return nanF.wordL.wordLreal;
  }
}
  extern "C"
{
  //
  // Initialize the rtInf, rtMinusInf, and rtNaN needed by the
  // generated code. NaN is initialized as non-signaling. Assumes IEEE.
  //
  static void rt_InitInfAndNaN(size_t realSize)
  {
    (void) (realSize);
    rtNaN = rtGetNaN();
    rtNaNF = rtGetNaNF();
    rtInf = rtGetInf();
    rtInfF = rtGetInfF();
    rtMinusInf = rtGetMinusInf();
    rtMinusInfF = rtGetMinusInfF();
  }

  // Test if value is infinite
  static boolean_T rtIsInf(real_T value)
  {
    return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
  }

  // Test if single-precision value is infinite
  static boolean_T rtIsInfF(real32_T value)
  {
    return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
  }

  // Test if value is not a number
  static boolean_T rtIsNaN(real_T value)
  {
    boolean_T result = (boolean_T) 0;
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    if (bitsPerReal == 32U) {
      result = rtIsNaNF((real32_T)value);
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.fltVal = value;
      result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) ==
                           0x7FF00000 &&
                           ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                            (tmpVal.bitVal.words.wordL != 0) ));
    }

    return result;
  }

  // Test if single-precision value is not a number
  static boolean_T rtIsNaNF(real32_T value)
  {
    IEEESingle tmp;
    tmp.wordL.wordLreal = value;
    return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                       (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
  }
}

extern "C" {
  //
  // Initialize rtInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T inf = 0.0;
    if (bitsPerReal == 32U) {
      inf = rtGetInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0x7FF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      inf = tmpVal.fltVal;
    }

    return inf;
  }

  //
  // Initialize rtInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetInfF(void)
  {
    IEEESingle infF;
    infF.wordL.wordLuint = 0x7F800000U;
    return infF.wordL.wordLreal;
  }

  //
  // Initialize rtMinusInf needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real_T rtGetMinusInf(void)
  {
    size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
    real_T minf = 0.0;
    if (bitsPerReal == 32U) {
      minf = rtGetMinusInfF();
    } else {
      union {
        LittleEndianIEEEDouble bitVal;
        real_T fltVal;
      } tmpVal;

      tmpVal.bitVal.words.wordH = 0xFFF00000U;
      tmpVal.bitVal.words.wordL = 0x00000000U;
      minf = tmpVal.fltVal;
    }

    return minf;
  }

  //
  // Initialize rtMinusInfF needed by the generated code.
  // Inf is initialized as non-signaling. Assumes IEEE.
  //
  static real32_T rtGetMinusInfF(void)
  {
    IEEESingle minfF;
    minfF.wordL.wordLuint = 0xFF800000U;
    return minfF.wordL.wordLreal;
  }
}
  real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T u1_0;
  if (rtIsNaN(u0) || rtIsNaN(u1) || rtIsInf(u0)) {
    y = (rtNaN);
  } else if (rtIsInf(u1)) {
    y = u0;
  } else {
    if (u1 < 0.0) {
      u1_0 = std::ceil(u1);
    } else {
      u1_0 = std::floor(u1);
    }

    if ((u1 != 0.0) && (u1 != u1_0)) {
      u1_0 = std::abs(u0 / u1);
      if (std::abs(u1_0 - std::floor(u1_0 + 0.5)) <= DBL_EPSILON * u1_0) {
        y = 0.0 * u0;
      } else {
        y = std::fmod(u0, u1);
      }
    } else {
      y = std::fmod(u0, u1);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::cosd(real_T *x)
{
  int8_T n;
  real_T b_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    absx = std::abs(b_x);
    if (absx > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      absx = std::abs(b_x);
    }

    if (absx <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (b_x > 0.0) {
        b_x = (b_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        b_x = (b_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = (b_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      b_x = (b_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = std::cos(b_x);
      break;

     case 1:
      *x = -std::sin(b_x);
      break;

     case -1:
      *x = std::sin(b_x);
      break;

     default:
      *x = -std::cos(b_x);
      break;
    }
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::sind(real_T *x)
{
  int8_T n;
  real_T c_x;
  real_T absx;
  if (rtIsInf(*x) || rtIsNaN(*x)) {
    *x = (rtNaN);
  } else {
    c_x = rt_remd_snf(*x, 360.0);
    absx = std::abs(c_x);
    if (absx > 180.0) {
      if (c_x > 0.0) {
        c_x -= 360.0;
      } else {
        c_x += 360.0;
      }

      absx = std::abs(c_x);
    }

    if (absx <= 45.0) {
      c_x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (c_x > 0.0) {
        c_x = (c_x - 90.0) * 0.017453292519943295;
        n = 1;
      } else {
        c_x = (c_x + 90.0) * 0.017453292519943295;
        n = -1;
      }
    } else if (c_x > 0.0) {
      c_x = (c_x - 180.0) * 0.017453292519943295;
      n = 2;
    } else {
      c_x = (c_x + 180.0) * 0.017453292519943295;
      n = -2;
    }

    switch (n) {
     case 0:
      *x = std::sin(c_x);
      break;

     case 1:
      *x = std::cos(c_x);
      break;

     case -1:
      *x = -std::cos(c_x);
      break;

     default:
      *x = -std::sin(c_x);
      break;
    }
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
real_T thrust_allocation2ModelClass::xnrm2(int32_T n, const real_T x[100],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
real_T thrust_allocation2ModelClass::xnrm2_e(int32_T n, const real_T x[10],
  int32_T ix0)
{
  real_T y;
  real_T scale;
  int32_T kend;
  real_T absxk;
  real_T t;
  int32_T k;
  y = 0.0;
  if (n >= 1) {
    if (n == 1) {
      y = std::abs(x[ix0 - 1]);
    } else {
      scale = 3.3121686421112381E-170;
      kend = (ix0 + n) - 1;
      for (k = ix0; k <= kend; k++) {
        absxk = std::abs(x[k - 1]);
        if (absxk > scale) {
          t = scale / absxk;
          y = y * t * t + 1.0;
          scale = absxk;
        } else {
          t = absxk / scale;
          y += t * t;
        }
      }

      y = scale * std::sqrt(y);
    }
  }

  return y;
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xaxpy_er(int32_T n, real_T a, const real_T x
  [10], int32_T ix0, real_T y[100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xaxpy_e(int32_T n, real_T a, const real_T x
  [100], int32_T ix0, real_T y[10], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * x[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
real_T thrust_allocation2ModelClass::xdotc(int32_T n, const real_T x[100],
  int32_T ix0, const real_T y[100], int32_T iy0)
{
  real_T d;
  int32_T ix;
  int32_T iy;
  int32_T k;
  d = 0.0;
  if (n >= 1) {
    ix = ix0;
    iy = iy0;
    for (k = 0; k < n; k++) {
      d += x[ix - 1] * y[iy - 1];
      ix++;
      iy++;
    }
  }

  return d;
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xaxpy(int32_T n, real_T a, int32_T ix0,
  real_T y[100], int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  int32_T k;
  if ((n >= 1) && (!(a == 0.0))) {
    ix = ix0 - 1;
    iy = iy0 - 1;
    for (k = 0; k < n; k++) {
      y[iy] += a * y[ix];
      ix++;
      iy++;
    }
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xscal(real_T a, real_T x[100], int32_T ix0)
{
  int32_T k;
  for (k = ix0; k <= ix0 + 9; k++) {
    x[k - 1] *= a;
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xswap(real_T x[100], int32_T ix0, int32_T iy0)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 10; k++) {
    temp = x[ix];
    x[ix] = x[iy];
    x[iy] = temp;
    ix++;
    iy++;
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xrotg(real_T *a, real_T *b, real_T *c, real_T
  *s)
{
  real_T roe;
  real_T absa;
  real_T absb;
  real_T scale;
  real_T ads;
  real_T bds;
  roe = *b;
  absa = std::abs(*a);
  absb = std::abs(*b);
  if (absa > absb) {
    roe = *a;
  }

  scale = absa + absb;
  if (scale == 0.0) {
    *s = 0.0;
    *c = 1.0;
    *b = 0.0;
  } else {
    ads = absa / scale;
    bds = absb / scale;
    scale *= std::sqrt(ads * ads + bds * bds);
    if (roe < 0.0) {
      scale = -scale;
    }

    *c = *a / scale;
    *s = *b / scale;
    if (absa > absb) {
      *b = *s;
    } else if (*c != 0.0) {
      *b = 1.0 / *c;
    } else {
      *b = 1.0;
    }
  }

  *a = scale;
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::xrot(real_T x[100], int32_T ix0, int32_T iy0,
  real_T c, real_T s)
{
  int32_T ix;
  int32_T iy;
  real_T temp;
  int32_T k;
  ix = ix0 - 1;
  iy = iy0 - 1;
  for (k = 0; k < 10; k++) {
    temp = c * x[ix] + s * x[iy];
    x[iy] = c * x[iy] - s * x[ix];
    x[ix] = temp;
    iy++;
    ix++;
  }
}

// Function for MATLAB Function: '<Root>/thrust-allocator'
void thrust_allocation2ModelClass::svd(const real_T A[100], real_T U[100],
  real_T s[10], real_T V[100])
{
  real_T b_A[100];
  real_T b_s[10];
  real_T e[10];
  real_T work[10];
  real_T Vf[100];
  int32_T qq;
  boolean_T apply_transform;
  real_T nrm;
  int32_T qjj;
  int32_T qp1jj;
  int32_T m;
  int32_T qp1q;
  real_T rt;
  real_T ztest;
  real_T smm1;
  real_T emm1;
  real_T sqds;
  real_T shift;
  int32_T k_ii;
  int32_T exitg1;
  boolean_T exitg2;
  std::memcpy(&b_A[0], &A[0], 100U * sizeof(real_T));
  std::memset(&b_s[0], 0, 10U * sizeof(real_T));
  std::memset(&e[0], 0, 10U * sizeof(real_T));
  std::memset(&work[0], 0, 10U * sizeof(real_T));
  std::memset(&U[0], 0, 100U * sizeof(real_T));
  std::memset(&Vf[0], 0, 100U * sizeof(real_T));
  for (m = 0; m < 9; m++) {
    qq = 10 * m + m;
    apply_transform = false;
    nrm = xnrm2(10 - m, b_A, qq + 1);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq] < 0.0) {
        b_s[m] = -nrm;
      } else {
        b_s[m] = nrm;
      }

      if (std::abs(b_s[m]) >= 1.0020841800044864E-292) {
        nrm = 1.0 / b_s[m];
        qp1q = (qq - m) + 10;
        for (qjj = qq; qjj < qp1q; qjj++) {
          b_A[qjj] *= nrm;
        }
      } else {
        qp1q = (qq - m) + 10;
        for (qjj = qq; qjj < qp1q; qjj++) {
          b_A[qjj] /= b_s[m];
        }
      }

      b_A[qq]++;
      b_s[m] = -b_s[m];
    } else {
      b_s[m] = 0.0;
    }

    for (qp1q = m + 1; qp1q + 1 < 11; qp1q++) {
      qjj = 10 * qp1q + m;
      if (apply_transform) {
        xaxpy(10 - m, -(xdotc(10 - m, b_A, qq + 1, b_A, qjj + 1) / b_A[m + 10 *
                        m]), qq + 1, b_A, qjj + 1);
      }

      e[qp1q] = b_A[qjj];
    }

    for (qq = m; qq + 1 < 11; qq++) {
      U[qq + 10 * m] = b_A[10 * m + qq];
    }

    if (m + 1 <= 8) {
      nrm = xnrm2_e(9 - m, e, m + 2);
      if (nrm == 0.0) {
        e[m] = 0.0;
      } else {
        if (e[m + 1] < 0.0) {
          e[m] = -nrm;
        } else {
          e[m] = nrm;
        }

        nrm = e[m];
        if (std::abs(e[m]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[m];
          for (qq = m + 1; qq < 10; qq++) {
            e[qq] *= nrm;
          }
        } else {
          for (qq = m + 1; qq < 10; qq++) {
            e[qq] /= nrm;
          }
        }

        e[m + 1]++;
        e[m] = -e[m];
        for (qq = m + 1; qq + 1 < 11; qq++) {
          work[qq] = 0.0;
        }

        for (qq = m + 1; qq + 1 < 11; qq++) {
          xaxpy_e(9 - m, e[qq], b_A, (m + 10 * qq) + 2, work, m + 2);
        }

        for (qq = m + 1; qq + 1 < 11; qq++) {
          xaxpy_er(9 - m, -e[qq] / e[m + 1], work, m + 2, b_A, (m + 10 * qq) + 2);
        }
      }

      for (qq = m + 1; qq + 1 < 11; qq++) {
        Vf[qq + 10 * m] = e[qq];
      }
    }
  }

  m = 8;
  b_s[9] = b_A[99];
  e[8] = b_A[98];
  e[9] = 0.0;
  std::memset(&U[90], 0, 10U * sizeof(real_T));
  U[99] = 1.0;
  for (qp1q = 8; qp1q >= 0; qp1q--) {
    qq = 10 * qp1q + qp1q;
    if (b_s[qp1q] != 0.0) {
      for (qp1jj = qp1q + 1; qp1jj + 1 < 11; qp1jj++) {
        qjj = (10 * qp1jj + qp1q) + 1;
        xaxpy(10 - qp1q, -(xdotc(10 - qp1q, U, qq + 1, U, qjj) / U[qq]), qq + 1,
              U, qjj);
      }

      for (qjj = qp1q; qjj + 1 < 11; qjj++) {
        qp1jj = 10 * qp1q + qjj;
        U[qp1jj] = -U[qp1jj];
      }

      U[qq]++;
      for (qq = 0; qq < qp1q; qq++) {
        U[qq + 10 * qp1q] = 0.0;
      }
    } else {
      std::memset(&U[qp1q * 10], 0, 10U * sizeof(real_T));
      U[qq] = 1.0;
    }
  }

  for (qq = 9; qq >= 0; qq--) {
    if ((qq + 1 <= 8) && (e[qq] != 0.0)) {
      qp1q = (10 * qq + qq) + 2;
      for (qjj = qq + 1; qjj + 1 < 11; qjj++) {
        qp1jj = (10 * qjj + qq) + 2;
        xaxpy(9 - qq, -(xdotc(9 - qq, Vf, qp1q, Vf, qp1jj) / Vf[qp1q - 1]), qp1q,
              Vf, qp1jj);
      }
    }

    std::memset(&Vf[qq * 10], 0, 10U * sizeof(real_T));
    Vf[qq + 10 * qq] = 1.0;
  }

  for (qq = 0; qq < 10; qq++) {
    ztest = e[qq];
    if (b_s[qq] != 0.0) {
      rt = std::abs(b_s[qq]);
      nrm = b_s[qq] / rt;
      b_s[qq] = rt;
      if (qq + 1 < 10) {
        ztest = e[qq] / nrm;
      }

      xscal(nrm, U, 10 * qq + 1);
    }

    if ((qq + 1 < 10) && (ztest != 0.0)) {
      rt = std::abs(ztest);
      nrm = rt / ztest;
      ztest = rt;
      b_s[qq + 1] *= nrm;
      xscal(nrm, Vf, 10 * (qq + 1) + 1);
    }

    e[qq] = ztest;
  }

  qq = 0;
  nrm = 0.0;
  for (qp1q = 0; qp1q < 10; qp1q++) {
    ztest = std::abs(b_s[qp1q]);
    rt = std::abs(e[qp1q]);
    if ((ztest > rt) || rtIsNaN(rt)) {
      rt = ztest;
    }

    if ((!(nrm > rt)) && (!rtIsNaN(rt))) {
      nrm = rt;
    }
  }

  while ((m + 2 > 0) && (qq < 75)) {
    qp1jj = m + 1;
    do {
      exitg1 = 0;
      qp1q = qp1jj;
      if (qp1jj == 0) {
        exitg1 = 1;
      } else {
        rt = std::abs(e[qp1jj - 1]);
        if (rt <= (std::abs(b_s[qp1jj - 1]) + std::abs(b_s[qp1jj])) *
            2.2204460492503131E-16) {
          e[qp1jj - 1] = 0.0;
          exitg1 = 1;
        } else if ((rt <= 1.0020841800044864E-292) || ((qq > 20) && (rt <=
                     2.2204460492503131E-16 * nrm))) {
          e[qp1jj - 1] = 0.0;
          exitg1 = 1;
        } else {
          qp1jj--;
        }
      }
    } while (exitg1 == 0);

    if (m + 1 == qp1jj) {
      qp1jj = 4;
    } else {
      qjj = m + 2;
      k_ii = m + 2;
      exitg2 = false;
      while ((!exitg2) && (k_ii >= qp1jj)) {
        qjj = k_ii;
        if (k_ii == qp1jj) {
          exitg2 = true;
        } else {
          rt = 0.0;
          if (k_ii < m + 2) {
            rt = std::abs(e[k_ii - 1]);
          }

          if (k_ii > qp1jj + 1) {
            rt += std::abs(e[k_ii - 2]);
          }

          ztest = std::abs(b_s[k_ii - 1]);
          if ((ztest <= 2.2204460492503131E-16 * rt) || (ztest <=
               1.0020841800044864E-292)) {
            b_s[k_ii - 1] = 0.0;
            exitg2 = true;
          } else {
            k_ii--;
          }
        }
      }

      if (qjj == qp1jj) {
        qp1jj = 3;
      } else if (m + 2 == qjj) {
        qp1jj = 1;
      } else {
        qp1jj = 2;
        qp1q = qjj;
      }
    }

    switch (qp1jj) {
     case 1:
      rt = e[m];
      e[m] = 0.0;
      for (qjj = m; qjj + 1 >= qp1q + 1; qjj--) {
        xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        if (qjj + 1 > qp1q + 1) {
          emm1 = e[qjj - 1];
          rt = emm1 * -sqds;
          e[qjj - 1] = emm1 * ztest;
        }

        xrot(Vf, 10 * qjj + 1, 10 * (m + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[qp1q - 1];
      e[qp1q - 1] = 0.0;
      for (qjj = qp1q; qjj < m + 2; qjj++) {
        xrotg(&b_s[qjj], &rt, &ztest, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        xrot(U, 10 * qjj + 1, 10 * (qp1q - 1) + 1, ztest, sqds);
      }
      break;

     case 3:
      sqds = b_s[m + 1];
      ztest = std::abs(sqds);
      rt = std::abs(b_s[m]);
      if ((ztest > rt) || rtIsNaN(rt)) {
        rt = ztest;
      }

      ztest = std::abs(e[m]);
      if ((rt > ztest) || rtIsNaN(ztest)) {
        ztest = rt;
      }

      rt = std::abs(b_s[qp1q]);
      if ((ztest > rt) || rtIsNaN(rt)) {
        rt = ztest;
      }

      ztest = std::abs(e[qp1q]);
      if ((rt > ztest) || rtIsNaN(ztest)) {
        ztest = rt;
      }

      rt = sqds / ztest;
      smm1 = b_s[m] / ztest;
      emm1 = e[m] / ztest;
      sqds = b_s[qp1q] / ztest;
      smm1 = ((smm1 + rt) * (smm1 - rt) + emm1 * emm1) / 2.0;
      emm1 *= rt;
      emm1 *= emm1;
      if ((smm1 != 0.0) || (emm1 != 0.0)) {
        shift = std::sqrt(smm1 * smm1 + emm1);
        if (smm1 < 0.0) {
          shift = -shift;
        }

        shift = emm1 / (smm1 + shift);
      } else {
        shift = 0.0;
      }

      rt = (sqds + rt) * (sqds - rt) + shift;
      ztest = e[qp1q] / ztest * sqds;
      for (qjj = qp1q + 1; qjj <= m + 1; qjj++) {
        xrotg(&rt, &ztest, &sqds, &smm1);
        if (qjj > qp1q + 1) {
          e[qjj - 2] = rt;
        }

        emm1 = e[qjj - 1];
        ztest = b_s[qjj - 1];
        rt = ztest * sqds + emm1 * smm1;
        e[qjj - 1] = emm1 * sqds - ztest * smm1;
        ztest = smm1 * b_s[qjj];
        b_s[qjj] *= sqds;
        xrot(Vf, 10 * (qjj - 1) + 1, 10 * qjj + 1, sqds, smm1);
        xrotg(&rt, &ztest, &sqds, &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        xrot(U, 10 * (qjj - 1) + 1, 10 * qjj + 1, sqds, smm1);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[qp1q] < 0.0) {
        b_s[qp1q] = -b_s[qp1q];
        xscal(-1.0, Vf, 10 * qp1q + 1);
      }

      qq = qp1q + 1;
      while ((qp1q + 1 < 10) && (b_s[qp1q] < b_s[qq])) {
        rt = b_s[qp1q];
        b_s[qp1q] = b_s[qq];
        b_s[qq] = rt;
        xswap(Vf, 10 * qp1q + 1, 10 * (qp1q + 1) + 1);
        xswap(U, 10 * qp1q + 1, 10 * (qp1q + 1) + 1);
        qp1q = qq;
        qq++;
      }

      qq = 0;
      m--;
      break;
    }
  }

  for (m = 0; m < 10; m++) {
    s[m] = b_s[m];
    std::memcpy(&V[m * 10], &Vf[m * 10], 10U * sizeof(real_T));
  }
}

// Model step function
void thrust_allocation2ModelClass::step()
{
  real_T A[100];
  real_T u[10];
  real_T X_0[100];
  real_T V[100];
  int32_T vcol;
  real_T U[100];
  int32_T j;
  boolean_T p;
  real_T absx;
  int32_T ar;
  int32_T ia;
  int32_T b;
  int32_T ib;
  int32_T b_ic;
  real_T g;
  real_T h;
  real_T i;
  real_T l;
  real_T m;
  real_T n;
  real_T o;
  real_T tmp[10];
  int32_T r;
  static const int8_T c[10] = { -1, 0, -1, 0, 1, 0, 1, 0, 0, 0 };

  static const int8_T d[10] = { 0, -1, 0, 1, 0, -1, 0, 1, 0, 0 };

  static const int8_T e[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 1, 1 };

  // MATLAB Function: '<Root>/thrust-allocator' incorporates:
  //   Inport: '<Root>/tau '

  absx = 45.0;
  cosd(&absx);
  g = 45.0;
  sind(&g);
  h = 45.0;
  cosd(&h);
  i = 45.0;
  sind(&i);
  l = 45.0;
  cosd(&l);
  m = 45.0;
  sind(&m);
  n = 45.0;
  cosd(&n);
  o = 45.0;
  sind(&o);
  A[3] = 0.0;
  A[13] = 0.0;
  A[23] = 0.0;
  A[33] = 0.0;
  A[43] = 0.0;
  A[53] = 0.0;
  A[63] = 0.0;
  A[73] = 0.0;
  A[83] = -8.744;
  A[93] = 8.239;
  for (r = 0; r < 10; r++) {
    A[10 * r] = c[r];
    A[10 * r + 1] = d[r];
    A[10 * r + 2] = e[r];
    A[10 * r + 4] = 0.0;
  }

  A[5] = 6.5640707185674305;
  A[15] = 8.6178224976873175;
  A[25] = -6.5640707185674305;
  A[35] = -8.6178224976873175;
  A[45] = -6.5640707185674305;
  A[55] = -8.6178224976873175;
  A[65] = 6.5640707185674305;
  A[75] = 8.6178224976873175;
  A[85] = 0.0;
  A[95] = 0.0;
  A[6] = 1.0 / absx;
  A[16] = -1.0 / g;
  A[26] = 0.0;
  A[36] = 0.0;
  A[46] = 0.0;
  A[56] = 0.0;
  A[66] = 0.0;
  A[76] = 0.0;
  A[86] = 0.0;
  A[96] = 0.0;
  A[7] = 0.0;
  A[17] = 0.0;
  A[27] = 1.0 / h;
  A[37] = -1.0 / i;
  A[47] = 0.0;
  A[57] = 0.0;
  A[67] = 0.0;
  A[77] = 0.0;
  A[87] = 0.0;
  A[97] = 0.0;
  A[8] = 0.0;
  A[18] = 0.0;
  A[28] = 0.0;
  A[38] = 0.0;
  A[48] = 1.0 / l;
  A[58] = -1.0 / m;
  A[68] = 0.0;
  A[78] = 0.0;
  A[88] = 0.0;
  A[98] = 0.0;
  A[9] = 0.0;
  A[19] = 0.0;
  A[29] = 0.0;
  A[39] = 0.0;
  A[49] = 0.0;
  A[59] = 0.0;
  A[69] = 1.0 / n;
  A[79] = -1.0 / o;
  A[89] = 0.0;
  A[99] = 0.0;
  p = true;
  for (r = 0; r < 100; r++) {
    X_0[r] = 0.0;
    p = (p && ((!rtIsInf(A[r])) && (!rtIsNaN(A[r]))));
  }

  if (!p) {
    for (r = 0; r < 100; r++) {
      X_0[r] = (rtNaN);
    }
  } else {
    svd(A, U, u, V);
    absx = std::abs(u[0]);
    if ((!rtIsInf(absx)) && (!rtIsNaN(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = std::ldexp(1.0, vcol - 53);
      }
    } else {
      absx = (rtNaN);
    }

    absx *= 10.0;
    r = -1;
    vcol = 0;
    while ((vcol < 10) && (u[vcol] > absx)) {
      r++;
      vcol++;
    }

    if (r + 1 > 0) {
      vcol = 0;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / u[j];
        for (ar = vcol; ar < vcol + 10; ar++) {
          V[ar] *= absx;
        }

        vcol += 10;
      }

      for (vcol = 0; vcol <= 91; vcol += 10) {
        for (j = vcol; j < vcol + 10; j++) {
          X_0[j] = 0.0;
        }
      }

      vcol = 0;
      for (j = 0; j <= 91; j += 10) {
        ar = -1;
        vcol++;
        b = 10 * r + vcol;
        for (ib = vcol; ib <= b; ib += 10) {
          ia = ar;
          for (b_ic = j; b_ic < j + 10; b_ic++) {
            ia++;
            X_0[b_ic] += U[ib - 1] * V[ia];
          }

          ar += 10;
        }
      }
    }
  }

  for (r = 0; r < 6; r++) {
    tmp[r] = rtU.tau[r];
  }

  tmp[6] = 0.0;
  tmp[7] = 0.0;
  tmp[8] = 0.0;
  tmp[9] = 0.0;
  for (r = 0; r < 10; r++) {
    u[r] = 0.0;
    for (vcol = 0; vcol < 10; vcol++) {
      u[r] += X_0[10 * vcol + r] * tmp[vcol];
    }
  }

  // Outport: '<Root>/signals ' incorporates:
  //   MATLAB Function: '<Root>/thrust-allocator'

  rtY.signals[0] = std::sqrt(u[0] * u[0] + u[1] * u[1]);
  rtY.signals[1] = std::sqrt(u[2] * u[2] + u[3] * u[3]);
  rtY.signals[2] = std::sqrt(u[4] * u[4] + u[5] * u[5]);
  rtY.signals[3] = std::sqrt(u[6] * u[6] + u[7] * u[7]);
  rtY.signals[4] = u[8];
  rtY.signals[5] = u[9];
}

// Model initialize function
void thrust_allocation2ModelClass::initialize()
{
  // Registration code

  // initialize non-finites
  rt_InitInfAndNaN(sizeof(real_T));
}

// Constructor
thrust_allocation2ModelClass::thrust_allocation2ModelClass() : rtM()
{
  // Currently there is no constructor body generated.
}

// Destructor
thrust_allocation2ModelClass::~thrust_allocation2ModelClass()
{
  // Currently there is no destructor body generated.
}

// Real-Time Model get method
RT_MODEL * thrust_allocation2ModelClass::getRTM()
{
  return (&rtM);
}

//
// File trailer for generated code.
//
// [EOF]
//
