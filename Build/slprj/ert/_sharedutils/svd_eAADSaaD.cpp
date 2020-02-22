//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: svd_eAADSaaD.cpp
//
// Code generated for Simulink model 'thrust_allocation2'.
//
// Model version                  : 1.3
// Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
// C/C++ source code generated on : Fri Feb 21 14:46:41 2020
//
#include "rtwtypes.h"
#include <cmath>
#include <cstring>
#include "rt_nonfinite.h"
#include "xaxpy_7155JtSF.h"
#include "xaxpy_cpmPaViz.h"
#include "xaxpy_irZdM5XF.h"
#include "xdotc_7IquZDOK.h"
#include "xnrm2_UbyzGcEw.h"
#include "xnrm2_qZ7KPglN.h"
#include "xrot_XJMNyuag.h"
#include "xrotg_IPICesPU.h"
#include "xscal_myTCeGM2.h"
#include "xswap_cwXDe7Ur.h"
#include "svd_eAADSaaD.h"

// Function for MATLAB Function: '<Root>/thrust-allocator'
void svd_eAADSaaD(const real_T A[100], real_T U[100], real_T s[10], real_T V[100])
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
    nrm = xnrm2_qZ7KPglN(10 - m, b_A, qq + 1);
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
        xaxpy_irZdM5XF(10 - m, -(xdotc_7IquZDOK(10 - m, b_A, qq + 1, b_A, qjj +
          1) / b_A[m + 10 * m]), qq + 1, b_A, qjj + 1);
      }

      e[qp1q] = b_A[qjj];
    }

    for (qq = m; qq + 1 < 11; qq++) {
      U[qq + 10 * m] = b_A[10 * m + qq];
    }

    if (m + 1 <= 8) {
      nrm = xnrm2_UbyzGcEw(9 - m, e, m + 2);
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
          xaxpy_7155JtSF(9 - m, e[qq], b_A, (m + 10 * qq) + 2, work, m + 2);
        }

        for (qq = m + 1; qq + 1 < 11; qq++) {
          xaxpy_cpmPaViz(9 - m, -e[qq] / e[m + 1], work, m + 2, b_A, (m + 10 *
            qq) + 2);
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
        xaxpy_irZdM5XF(10 - qp1q, -(xdotc_7IquZDOK(10 - qp1q, U, qq + 1, U, qjj)
          / U[qq]), qq + 1, U, qjj);
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
        xaxpy_irZdM5XF(9 - qq, -(xdotc_7IquZDOK(9 - qq, Vf, qp1q, Vf, qp1jj) /
          Vf[qp1q - 1]), qp1q, Vf, qp1jj);
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

      xscal_myTCeGM2(nrm, U, 10 * qq + 1);
    }

    if ((qq + 1 < 10) && (ztest != 0.0)) {
      rt = std::abs(ztest);
      nrm = rt / ztest;
      ztest = rt;
      b_s[qq + 1] *= nrm;
      xscal_myTCeGM2(nrm, Vf, 10 * (qq + 1) + 1);
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
        xrotg_IPICesPU(&b_s[qjj], &rt, &ztest, &sqds);
        if (qjj + 1 > qp1q + 1) {
          emm1 = e[qjj - 1];
          rt = emm1 * -sqds;
          e[qjj - 1] = emm1 * ztest;
        }

        xrot_XJMNyuag(Vf, 10 * qjj + 1, 10 * (m + 1) + 1, ztest, sqds);
      }
      break;

     case 2:
      rt = e[qp1q - 1];
      e[qp1q - 1] = 0.0;
      for (qjj = qp1q; qjj < m + 2; qjj++) {
        xrotg_IPICesPU(&b_s[qjj], &rt, &ztest, &sqds);
        rt = -sqds * e[qjj];
        e[qjj] *= ztest;
        xrot_XJMNyuag(U, 10 * qjj + 1, 10 * (qp1q - 1) + 1, ztest, sqds);
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
        xrotg_IPICesPU(&rt, &ztest, &sqds, &smm1);
        if (qjj > qp1q + 1) {
          e[qjj - 2] = rt;
        }

        emm1 = e[qjj - 1];
        ztest = b_s[qjj - 1];
        rt = ztest * sqds + emm1 * smm1;
        e[qjj - 1] = emm1 * sqds - ztest * smm1;
        ztest = smm1 * b_s[qjj];
        b_s[qjj] *= sqds;
        xrot_XJMNyuag(Vf, 10 * (qjj - 1) + 1, 10 * qjj + 1, sqds, smm1);
        xrotg_IPICesPU(&rt, &ztest, &sqds, &smm1);
        b_s[qjj - 1] = rt;
        rt = e[qjj - 1] * sqds + smm1 * b_s[qjj];
        b_s[qjj] = e[qjj - 1] * -smm1 + sqds * b_s[qjj];
        ztest = smm1 * e[qjj];
        e[qjj] *= sqds;
        xrot_XJMNyuag(U, 10 * (qjj - 1) + 1, 10 * qjj + 1, sqds, smm1);
      }

      e[m] = rt;
      qq++;
      break;

     default:
      if (b_s[qp1q] < 0.0) {
        b_s[qp1q] = -b_s[qp1q];
        xscal_myTCeGM2(-1.0, Vf, 10 * qp1q + 1);
      }

      qq = qp1q + 1;
      while ((qp1q + 1 < 10) && (b_s[qp1q] < b_s[qq])) {
        rt = b_s[qp1q];
        b_s[qp1q] = b_s[qq];
        b_s[qq] = rt;
        xswap_cwXDe7Ur(Vf, 10 * qp1q + 1, 10 * (qp1q + 1) + 1);
        xswap_cwXDe7Ur(U, 10 * qp1q + 1, 10 * (qp1q + 1) + 1);
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

//
// File trailer for generated code.
//
// [EOF]
//
