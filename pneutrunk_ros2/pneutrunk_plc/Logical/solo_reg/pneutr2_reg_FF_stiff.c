/*
 * pneutr2_reg_FF_stiff.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pneutr2_reg_FF_stiff".
 *
 * Model version              : 4.30
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Thu Feb 15 10:44:02 2024
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pneutr2_reg_FF_stiff.h"
#include "rtwtypes.h"
#include "pneutr2_reg_FF_stiff_private.h"
#include <math.h>
#include <string.h>
#include "rt_nonfinite.h"

/* Block signals (default storage) */
B_pneutr2_reg_FF_stiff_T pneutr2_reg_FF_stiff_B;

/* Block states (default storage) */
DW_pneutr2_reg_FF_stiff_T pneutr2_reg_FF_stiff_DW;

/* Real-time model */
static RT_MODEL_pneutr2_reg_FF_stiff_T pneutr2_reg_FF_stiff_M_;
RT_MODEL_pneutr2_reg_FF_stiff_T *const pneutr2_reg_FF_stiff_M =
  &pneutr2_reg_FF_stiff_M_;

/* Forward declaration for local functions */
static real32_T pneutr2_reg_FF_stiff_norm(const real32_T x[4]);
real32_T look1_tf_binlcpw(real_T u0, const real_T bp0[], const real32_T table[],
  uint32_T maxIndex)
{
  real_T frac;
  real32_T yL_0d0;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0.0;
  } else if (u0 < bp0[maxIndex]) {
    uint32_T bpIdx;
    uint32_T iRght;

    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = 1.0;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'portable wrapping'
   */
  yL_0d0 = table[iLeft];
  return (real32_T)((table[iLeft + 1U] - yL_0d0) * frac) + yL_0d0;
}

/*
 * Output and update for atomic system:
 *    '<Root>/ID1'
 *    '<Root>/ID2'
 *    '<Root>/ID3'
 *    '<Root>/ID4'
 *    '<Root>/ID5'
 *    '<Root>/ID6'
 *    '<Root>/ID7'
 */
void pneutr2_reg_FF_stiff_ID1(real32_T rtu_poz_u_x, real32_T rtu_poz_u_y, const
  real_T rtu_coef_1blue[48], const real_T rtu_coef_2green[48], const real_T
  rtu_coef_3yellow[48], real32_T rtu_tuhost, B_ID1_pneutr2_reg_FF_stiff_T
  *localB)
{
  int32_T i;
  real32_T tmp[8];
  real32_T rtu_coef_1blue_0[6];
  real32_T tmp_0[6];
  real32_T rtu_coef_1blue_1;
  real32_T rtu_coef_1blue_2;
  real32_T rtu_coef_1blue_3;
  real32_T rtu_coef_1blue_4;
  real32_T rtu_coef_1blue_5;
  real32_T rtu_coef_1blue_6;
  real32_T rtu_coef_2green_0;
  real32_T rtu_coef_2green_1;
  real32_T rtu_coef_2green_2;
  real32_T rtu_coef_3yellow_0;
  real32_T tmp_1;
  real32_T tmp_2;
  real32_T tmp_3;
  real32_T tmp_4;
  real32_T tmp_5;
  rtu_coef_3yellow_0 = powf(rtu_tuhost, 7.0F);
  tmp[0] = rtu_coef_3yellow_0;
  tmp_1 = powf(rtu_tuhost, 6.0F);
  tmp[1] = tmp_1;
  tmp_2 = powf(rtu_tuhost, 5.0F);
  tmp[2] = tmp_2;
  tmp_3 = powf(rtu_tuhost, 4.0F);
  tmp[3] = tmp_3;
  tmp_4 = powf(rtu_tuhost, 3.0F);
  tmp[4] = tmp_4;
  tmp_5 = rtu_tuhost * rtu_tuhost;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_1 += (real32_T)rtu_coef_1blue[6 * i] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_2 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_2 += (real32_T)rtu_coef_1blue[6 * i + 1] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_3 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_3 += (real32_T)rtu_coef_1blue[6 * i + 2] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_4 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_4 += (real32_T)rtu_coef_1blue[6 * i + 3] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_5 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_5 += (real32_T)rtu_coef_1blue[6 * i + 4] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_6 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_6 += (real32_T)rtu_coef_1blue[6 * i + 5] * tmp[i];
  }

  rtu_coef_1blue_0[0] = rtu_coef_1blue_1;
  rtu_coef_1blue_0[1] = rtu_coef_1blue_2;
  rtu_coef_1blue_0[2] = rtu_coef_1blue_3;
  rtu_coef_1blue_0[3] = rtu_coef_1blue_4;
  rtu_coef_1blue_0[4] = rtu_coef_1blue_5;
  rtu_coef_1blue_0[5] = rtu_coef_1blue_6;
  tmp_0[0] = 1.0F;
  tmp_0[1] = rtu_poz_u_x;
  tmp_0[2] = rtu_poz_u_y;
  rtu_coef_1blue_2 = rtu_poz_u_x * rtu_poz_u_x;
  tmp_0[3] = rtu_coef_1blue_2;
  rtu_coef_1blue_3 = rtu_poz_u_x * rtu_poz_u_y;
  tmp_0[4] = rtu_coef_1blue_3;
  rtu_coef_1blue_4 = rtu_poz_u_y * rtu_poz_u_y;
  tmp_0[5] = rtu_coef_1blue_4;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 6; i++) {
    rtu_coef_1blue_1 += rtu_coef_1blue_0[i] * tmp_0[i];
  }

  localB->tlak1 = rtu_coef_1blue_1;
  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_1 += (real32_T)rtu_coef_2green[6 * i] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_5 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_5 += (real32_T)rtu_coef_2green[6 * i + 1] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_6 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_6 += (real32_T)rtu_coef_2green[6 * i + 2] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_2green_0 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_2green_0 += (real32_T)rtu_coef_2green[6 * i + 3] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_2green_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_2green_1 += (real32_T)rtu_coef_2green[6 * i + 4] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_2green_2 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_2green_2 += (real32_T)rtu_coef_2green[6 * i + 5] * tmp[i];
  }

  rtu_coef_1blue_0[0] = rtu_coef_1blue_1;
  rtu_coef_1blue_0[1] = rtu_coef_1blue_5;
  rtu_coef_1blue_0[2] = rtu_coef_1blue_6;
  rtu_coef_1blue_0[3] = rtu_coef_2green_0;
  rtu_coef_1blue_0[4] = rtu_coef_2green_1;
  rtu_coef_1blue_0[5] = rtu_coef_2green_2;
  tmp_0[0] = 1.0F;
  tmp_0[1] = rtu_poz_u_x;
  tmp_0[2] = rtu_poz_u_y;
  tmp_0[3] = rtu_coef_1blue_2;
  tmp_0[4] = rtu_coef_1blue_3;
  tmp_0[5] = rtu_coef_1blue_4;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 6; i++) {
    rtu_coef_1blue_1 += rtu_coef_1blue_0[i] * tmp_0[i];
  }

  localB->tlak2 = rtu_coef_1blue_1;
  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_1 += (real32_T)rtu_coef_3yellow[6 * i] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_5 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_5 += (real32_T)rtu_coef_3yellow[6 * i + 1] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_1blue_6 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_1blue_6 += (real32_T)rtu_coef_3yellow[6 * i + 2] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_2green_0 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_2green_0 += (real32_T)rtu_coef_3yellow[6 * i + 3] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_2green_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_2green_1 += (real32_T)rtu_coef_3yellow[6 * i + 4] * tmp[i];
  }

  tmp[0] = rtu_coef_3yellow_0;
  tmp[1] = tmp_1;
  tmp[2] = tmp_2;
  tmp[3] = tmp_3;
  tmp[4] = tmp_4;
  tmp[5] = tmp_5;
  tmp[6] = rtu_tuhost;
  tmp[7] = 1.0F;
  rtu_coef_3yellow_0 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtu_coef_3yellow_0 += (real32_T)rtu_coef_3yellow[6 * i + 5] * tmp[i];
  }

  rtu_coef_1blue_0[0] = rtu_coef_1blue_1;
  rtu_coef_1blue_0[1] = rtu_coef_1blue_5;
  rtu_coef_1blue_0[2] = rtu_coef_1blue_6;
  rtu_coef_1blue_0[3] = rtu_coef_2green_0;
  rtu_coef_1blue_0[4] = rtu_coef_2green_1;
  rtu_coef_1blue_0[5] = rtu_coef_3yellow_0;
  tmp_0[0] = 1.0F;
  tmp_0[1] = rtu_poz_u_x;
  tmp_0[2] = rtu_poz_u_y;
  tmp_0[3] = rtu_coef_1blue_2;
  tmp_0[4] = rtu_coef_1blue_3;
  tmp_0[5] = rtu_coef_1blue_4;
  rtu_coef_1blue_1 = 0.0F;
  for (i = 0; i < 6; i++) {
    rtu_coef_1blue_1 += rtu_coef_1blue_0[i] * tmp_0[i];
  }

  localB->tlak3 = rtu_coef_1blue_1;
}

/* Function for MATLAB Function: '<S37>/requested alfa 2 deltaz1' */
static real32_T pneutr2_reg_FF_stiff_norm(const real32_T x[4])
{
  real32_T absxk;
  real32_T scale;
  real32_T t;
  real32_T y;
  scale = 1.29246971E-26F;
  absxk = fabsf(x[0]);
  if (absxk > 1.29246971E-26F) {
    y = 1.0F;
    scale = absxk;
  } else {
    t = absxk / 1.29246971E-26F;
    y = t * t;
  }

  absxk = fabsf(x[1]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabsf(x[2]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  absxk = fabsf(x[3]);
  if (absxk > scale) {
    t = scale / absxk;
    y = y * t * t + 1.0F;
    scale = absxk;
  } else {
    t = absxk / scale;
    y += t * t;
  }

  return scale * sqrtf(y);
}

/*
 * Output and update for atomic system:
 *    '<S37>/requested alfa 2 deltaz1'
 *    '<S196>/requested alfa 2 deltaz1'
 *    '<S365>/requested alfa 2 deltaz1'
 *    '<S528>/requested alfa 2 deltaz1'
 *    '<S688>/requested alfa 2 deltaz1'
 *    '<S848>/requested alfa 2 deltaz1'
 *    '<S1007>/requested alfa 2 deltaz1'
 */
void pneutr2_r_requestedalfa2deltaz1(real32_T rtu_AlphaX_ref, real32_T
  rtu_AlphaY_ref, real32_T rtu_AlphaX_real, real32_T rtu_AlphaY_real, real_T
  rtu_A, real_T rtu_B, real32_T rtu_poradie, B_requestedalfa2deltaz1_pneut_T
  *localB)
{
  real_T Tz23[16];
  real_T Blue0_tmp[4];
  real_T Green0_tmp_tmp[4];
  real_T Yellow0_tmp[4];
  real_T A1;
  real_T A2_tmp;
  real_T A3_tmp;
  int32_T AlphaY_tmp_tmp;
  int32_T Blue10_tmp;
  int32_T i;
  real32_T AlphaY_0[16];
  real32_T Blue10_0[16];
  real32_T HTransform[16];
  real32_T Tz23_0[16];
  real32_T Blue0_tmp_0[4];
  real32_T Blue10[4];
  real32_T Green0_tmp_tmp_0[4];
  real32_T Green10[4];
  real32_T Yellow0_tmp_0[4];
  real32_T Yellow10[4];
  real32_T AlphaX;
  real32_T AlphaY;
  real32_T Blue10_1;
  real32_T Green10_0;
  real32_T HTransform_tmp;
  real32_T HTransform_tmp_0;
  real32_T Tz23_1;
  real32_T Yellow10_0;
  AlphaX = rtu_AlphaX_ref * 3.14159274F / 180.0F;
  AlphaY = -rtu_AlphaY_ref * 3.14159274F / 180.0F;
  A1 = rtu_A / 2.0;
  A2_tmp = 1.7320508075688772 * A1 / 2.0;
  A3_tmp = A1 / 2.0;
  Tz23[2] = 0.0;
  Tz23[6] = 0.0;
  Tz23[10] = 1.0;
  Tz23[14] = rtu_B / 2.0;
  HTransform_tmp = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  HTransform_tmp_0 = sinf(AlphaX);
  AlphaX = cosf(AlphaX);
  AlphaY_0[0] = AlphaY;
  AlphaY_0[4] = 0.0F;
  AlphaY_0[8] = HTransform_tmp;
  AlphaY_0[12] = 0.0F;
  AlphaY_0[2] = -HTransform_tmp;
  AlphaY_0[6] = 0.0F;
  AlphaY_0[10] = AlphaY;
  AlphaY_0[14] = 0.0F;
  Tz23[0] = 1.0;
  Tz23[1] = 0.0;
  Tz23[3] = 0.0;
  Green10[0] = 0.0F;
  Blue10[0] = 1.0F;
  AlphaY_0[1] = 0.0F;
  AlphaY_0[3] = 0.0F;
  Tz23[4] = 0.0;
  Tz23[5] = 1.0;
  Tz23[7] = 0.0;
  Green10[1] = 0.0F;
  Blue10[1] = 0.0F;
  AlphaY_0[5] = 1.0F;
  AlphaY_0[7] = 0.0F;
  Tz23[8] = 0.0;
  Tz23[9] = 0.0;
  Tz23[11] = 0.0;
  Green10[2] = 0.0F;
  Blue10[2] = 0.0F;
  AlphaY_0[9] = 0.0F;
  AlphaY_0[11] = 0.0F;
  Tz23[12] = 0.0;
  Tz23[13] = 0.0;
  Tz23[15] = 1.0;
  Green10[3] = 1.0F;
  Blue10[3] = 0.0F;
  AlphaY_0[13] = 0.0F;
  AlphaY_0[15] = 1.0F;
  Blue10_0[1] = 0.0F;
  Blue10_0[5] = AlphaX;
  Blue10_0[9] = -HTransform_tmp_0;
  Blue10_0[13] = 0.0F;
  Blue10_0[2] = 0.0F;
  Blue10_0[6] = HTransform_tmp_0;
  Blue10_0[10] = AlphaX;
  Blue10_0[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    AlphaY_tmp_tmp = i << 2;
    AlphaY = AlphaY_0[AlphaY_tmp_tmp + 1];
    AlphaX = AlphaY_0[AlphaY_tmp_tmp];
    HTransform_tmp = AlphaY_0[AlphaY_tmp_tmp + 2];
    HTransform_tmp_0 = AlphaY_0[AlphaY_tmp_tmp + 3];
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      Tz23_0[Blue10_tmp + AlphaY_tmp_tmp] = (((real32_T)Tz23[Blue10_tmp + 4] *
        AlphaY + AlphaX * (real32_T)Tz23[Blue10_tmp]) + (real32_T)
        Tz23[Blue10_tmp + 8] * HTransform_tmp) + (real32_T)Tz23[Blue10_tmp + 12]
        * HTransform_tmp_0;
    }

    Blue10_0[AlphaY_tmp_tmp] = Blue10[i];
    Blue10_0[AlphaY_tmp_tmp + 3] = Green10[i];
  }

  for (i = 0; i < 4; i++) {
    AlphaX = Tz23_0[i + 4];
    HTransform_tmp = Tz23_0[i];
    HTransform_tmp_0 = Tz23_0[i + 8];
    Tz23_1 = Tz23_0[i + 12];
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      AlphaY_tmp_tmp = Blue10_tmp << 2;
      AlphaY_0[i + AlphaY_tmp_tmp] = ((Blue10_0[AlphaY_tmp_tmp + 1] * AlphaX +
        Blue10_0[AlphaY_tmp_tmp] * HTransform_tmp) + Blue10_0[AlphaY_tmp_tmp + 2]
        * HTransform_tmp_0) + Blue10_0[AlphaY_tmp_tmp + 3] * Tz23_1;
    }

    AlphaX = AlphaY_0[i + 4];
    HTransform_tmp = AlphaY_0[i];
    HTransform_tmp_0 = AlphaY_0[i + 8];
    Tz23_1 = AlphaY_0[i + 12];
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      AlphaY_tmp_tmp = Blue10_tmp << 2;
      HTransform[i + AlphaY_tmp_tmp] = (((real32_T)Tz23[AlphaY_tmp_tmp + 1] *
        AlphaX + (real32_T)Tz23[AlphaY_tmp_tmp] * HTransform_tmp) + (real32_T)
        Tz23[AlphaY_tmp_tmp + 2] * HTransform_tmp_0) + (real32_T)
        Tz23[AlphaY_tmp_tmp + 3] * Tz23_1;
    }
  }

  Green0_tmp_tmp[0] = A1;
  Green0_tmp_tmp[1] = 0.0;
  Green0_tmp_tmp[2] = 0.0;
  Green0_tmp_tmp[3] = 1.0;
  Yellow0_tmp[0] = -A3_tmp;
  Yellow0_tmp[1] = A2_tmp;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -A3_tmp;
  Blue0_tmp[1] = -A2_tmp;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  switch ((int32_T)rtu_poradie) {
   case 1:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i];
      AlphaX = HTransform[i + 12];
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaY * (real32_T)A1
        + AlphaX);
      HTransform_tmp = HTransform[i + 4];
      HTransform_tmp_0 = AlphaY * (real32_T)-A3_tmp;
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform_tmp * (real32_T)
        -A2_tmp + HTransform_tmp_0) + AlphaX);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((HTransform_tmp * (real32_T)
        A2_tmp + HTransform_tmp_0) + AlphaX);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    break;

   case 2:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i];
      AlphaX = HTransform[i + 12];
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaY * (real32_T)A1
        + AlphaX);
      HTransform_tmp = HTransform[i + 4];
      HTransform_tmp_0 = AlphaY * (real32_T)-A3_tmp;
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((HTransform_tmp * (real32_T)
        A2_tmp + HTransform_tmp_0) + AlphaX);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform_tmp * (real32_T)
        -A2_tmp + HTransform_tmp_0) + AlphaX);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    break;

   case 3:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      AlphaX = HTransform[i];
      HTransform_tmp = HTransform[i + 12];
      HTransform_tmp_0 = AlphaX * (real32_T)-A3_tmp;
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * (real32_T)-A2_tmp +
        HTransform_tmp_0) + HTransform_tmp);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * (real32_T)A2_tmp
        + HTransform_tmp_0) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaX * (real32_T)A1
        + HTransform_tmp);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    break;

   case 4:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      AlphaX = HTransform[i];
      HTransform_tmp = HTransform[i + 12];
      HTransform_tmp_0 = AlphaX * (real32_T)-A3_tmp;
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * (real32_T)-A2_tmp +
        HTransform_tmp_0) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaX * (real32_T)A1
        + HTransform_tmp);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * (real32_T)A2_tmp
        + HTransform_tmp_0) + HTransform_tmp);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    break;

   case 5:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      AlphaX = HTransform[i];
      HTransform_tmp = HTransform[i + 12];
      HTransform_tmp_0 = AlphaX * (real32_T)-A3_tmp;
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * (real32_T)A2_tmp
        + HTransform_tmp_0) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaX * (real32_T)A1
        + HTransform_tmp);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * (real32_T)-A2_tmp +
        HTransform_tmp_0) + HTransform_tmp);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    break;

   default:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      AlphaX = HTransform[i];
      HTransform_tmp = HTransform[i + 12];
      HTransform_tmp_0 = AlphaX * (real32_T)-A3_tmp;
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * (real32_T)A2_tmp
        + HTransform_tmp_0) + HTransform_tmp);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * (real32_T)-A2_tmp +
        HTransform_tmp_0) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (AlphaX * (real32_T)A1
        + HTransform_tmp);
    }

    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    break;
  }

  AlphaX = rtu_AlphaX_real * 3.14159274F / 180.0F;
  AlphaY = -rtu_AlphaY_real * 3.14159274F / 180.0F;
  HTransform_tmp = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  HTransform_tmp_0 = sinf(AlphaX);
  AlphaX = cosf(AlphaX);
  AlphaY_0[0] = AlphaY;
  AlphaY_0[4] = 0.0F;
  AlphaY_0[8] = HTransform_tmp;
  AlphaY_0[12] = 0.0F;
  AlphaY_0[2] = -HTransform_tmp;
  AlphaY_0[6] = 0.0F;
  AlphaY_0[10] = AlphaY;
  AlphaY_0[14] = 0.0F;
  AlphaY_0[1] = 0.0F;
  AlphaY_0[3] = 0.0F;
  AlphaY_0[5] = 1.0F;
  AlphaY_0[7] = 0.0F;
  AlphaY_0[9] = 0.0F;
  AlphaY_0[11] = 0.0F;
  AlphaY_0[13] = 0.0F;
  AlphaY_0[15] = 1.0F;
  Blue10_0[1] = 0.0F;
  Blue10_0[5] = AlphaX;
  Blue10_0[9] = -HTransform_tmp_0;
  Blue10_0[13] = 0.0F;
  Blue10_0[2] = 0.0F;
  Blue10_0[6] = HTransform_tmp_0;
  Blue10_0[10] = AlphaX;
  Blue10_0[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    AlphaY_tmp_tmp = i << 2;
    AlphaY = AlphaY_0[AlphaY_tmp_tmp + 1];
    AlphaX = AlphaY_0[AlphaY_tmp_tmp];
    HTransform_tmp = AlphaY_0[AlphaY_tmp_tmp + 2];
    HTransform_tmp_0 = AlphaY_0[AlphaY_tmp_tmp + 3];
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      Tz23_0[Blue10_tmp + AlphaY_tmp_tmp] = (((real32_T)Tz23[Blue10_tmp + 4] *
        AlphaY + AlphaX * (real32_T)Tz23[Blue10_tmp]) + (real32_T)
        Tz23[Blue10_tmp + 8] * HTransform_tmp) + (real32_T)Tz23[Blue10_tmp + 12]
        * HTransform_tmp_0;
    }

    Blue10_tmp = i << 2;
    Blue10_0[Blue10_tmp] = Blue10[i];
    Blue10_0[Blue10_tmp + 3] = Green10[i];
  }

  Yellow0_tmp[0] = -A3_tmp;
  Yellow0_tmp[1] = A2_tmp;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -A3_tmp;
  Blue0_tmp[1] = -A2_tmp;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  for (i = 0; i < 4; i++) {
    AlphaX = Tz23_0[i + 4];
    HTransform_tmp = Tz23_0[i];
    HTransform_tmp_0 = Tz23_0[i + 8];
    Tz23_1 = Tz23_0[i + 12];
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      AlphaY_tmp_tmp = Blue10_tmp << 2;
      AlphaY_0[i + AlphaY_tmp_tmp] = ((Blue10_0[AlphaY_tmp_tmp + 1] * AlphaX +
        Blue10_0[AlphaY_tmp_tmp] * HTransform_tmp) + Blue10_0[AlphaY_tmp_tmp + 2]
        * HTransform_tmp_0) + Blue10_0[AlphaY_tmp_tmp + 3] * Tz23_1;
    }

    AlphaX = AlphaY_0[i + 4];
    HTransform_tmp = AlphaY_0[i];
    HTransform_tmp_0 = AlphaY_0[i + 8];
    Tz23_1 = AlphaY_0[i + 12];
    Green10_0 = 0.0F;
    Yellow10_0 = 0.0F;
    Blue10_1 = 0.0F;
    for (Blue10_tmp = 0; Blue10_tmp < 4; Blue10_tmp++) {
      AlphaY_tmp_tmp = Blue10_tmp << 2;
      AlphaY = (((real32_T)Tz23[AlphaY_tmp_tmp + 1] * AlphaX + (real32_T)
                 Tz23[AlphaY_tmp_tmp] * HTransform_tmp) + (real32_T)
                Tz23[AlphaY_tmp_tmp + 2] * HTransform_tmp_0) + (real32_T)
        Tz23[AlphaY_tmp_tmp + 3] * Tz23_1;
      Green10_0 += AlphaY * (real32_T)Green0_tmp_tmp[Blue10_tmp];
      Yellow10_0 += AlphaY * (real32_T)Yellow0_tmp[Blue10_tmp];
      Blue10_1 += AlphaY * (real32_T)Blue0_tmp[Blue10_tmp];
    }

    Blue10[i] = Blue10_1;
    Yellow10[i] = Yellow10_0;
    Green10[i] = Green10_0;
    Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - Green10_0;
    Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - Blue10_1;
    Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - Yellow10_0;
  }

  localB->Green_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
  localB->Blue_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
  localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
  switch ((int32_T)rtu_poradie) {
   case 1:
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Green_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Blue_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    break;

   case 2:
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Green_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Blue_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    break;

   case 3:
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Green_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Blue_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    break;

   case 4:
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Green_ref = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Blue_ref = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Yellow_ref = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    break;

   case 5:
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Green_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Blue_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    break;

   default:
    Yellow0_tmp_0[0] = (real32_T)-A3_tmp - Yellow10[0];
    Yellow0_tmp_0[1] = (real32_T)A2_tmp - Yellow10[1];
    Yellow0_tmp_0[2] = 0.0F - Yellow10[2];
    Yellow0_tmp_0[3] = 1.0F - Yellow10[3];
    localB->Green_real = pneutr2_reg_FF_stiff_norm(Yellow0_tmp_0);
    Blue0_tmp_0[0] = (real32_T)-A3_tmp - Blue10[0];
    Blue0_tmp_0[1] = (real32_T)-A2_tmp - Blue10[1];
    Blue0_tmp_0[2] = 0.0F - Blue10[2];
    Blue0_tmp_0[3] = 1.0F - Blue10[3];
    localB->Blue_real = pneutr2_reg_FF_stiff_norm(Blue0_tmp_0);
    Green0_tmp_tmp_0[0] = (real32_T)A1 - Green10[0];
    Green0_tmp_tmp_0[1] = 0.0F - Green10[1];
    Green0_tmp_tmp_0[2] = 0.0F - Green10[2];
    Green0_tmp_tmp_0[3] = 1.0F - Green10[3];
    localB->Yellow_real = pneutr2_reg_FF_stiff_norm(Green0_tmp_tmp_0);
    break;
  }
}

/*
 * Output and update for atomic system:
 *    '<S10>/MATLAB Function'
 *    '<S11>/MATLAB Function'
 *    '<S12>/MATLAB Function'
 *    '<S13>/MATLAB Function'
 *    '<S14>/MATLAB Function'
 *    '<S15>/MATLAB Function'
 *    '<S16>/MATLAB Function'
 *    '<S17>/MATLAB Function'
 *    '<S18>/MATLAB Function'
 *    '<S19>/MATLAB Function'
 *    ...
 */
void pneutr2_reg_FF_s_MATLABFunction(real_T rtu_in, real_T rtu_previous_in,
  real_T rtu_step, real_T rtu_pocet_stepov, real_T rtu_last_in, real_T
  rtu_neupravujuci_uhol, B_MATLABFunction_pneutr2_reg__T *localB)
{
  real_T last_in;
  real_T step_count;
  last_in = rtu_last_in;
  if (fabs(rtu_previous_in - rtu_in) < rtu_neupravujuci_uhol) {
    step_count = rtu_step + 1.0;
    if (rtu_step + 1.0 >= rtu_pocet_stepov) {
      step_count = rtu_pocet_stepov;
      last_in = rtu_in;
    }

    localB->out = (rtu_in - last_in) * (step_count / rtu_pocet_stepov) + last_in;
    localB->last_out = last_in;
  } else {
    localB->out = rtu_last_in;
    step_count = 0.0;
    localB->last_out = rtu_last_in;
  }

  localB->step_count = step_count;
}

/* Model output function */
static void pneutr2_reg_FF_stiff_output(void)
{
  real_T rtb_Sum;
  real_T rtb_Sum4;
  real_T rtb_Sum4_b;
  real_T rtb_Sum4_hu;
  real_T rtb_Sum4_l;
  real_T rtb_Sum4_o;
  real_T rtb_Sum_ai;
  real_T rtb_Sum_az;
  real_T rtb_Sum_c;
  real_T rtb_Sum_ce;
  real_T rtb_Sum_ek;
  real_T rtb_Sum_iu;
  real_T rtb_Sum_jv;
  real_T rtb_Sum_l;
  real_T rtb_Sum_lj;
  real_T rtb_Sum_lr;
  real_T rtb_Switch2_i;
  real_T rtb_Switch_ju;
  real_T rtb_Switch_l1;
  real_T rtb_Switch_mc;
  real32_T rtb_MathFunction;
  real32_T rtb_MathFunction_h;
  real32_T rtb_MathFunction_o;
  real32_T rtb_Sum8;

  /* S-Function (bur_in): '<Root>/Input15' */
  pneutr2_reg_FF_stiff_B.Input15 = stiffness_ff;

  /* Sum: '<S8>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   */
  rtb_Switch2_i = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input1' */
  pneutr2_reg_FF_stiff_B.Input1 = ref_alfa_x_ID1;

  /* S-Function (bur_in): '<Root>/Input2' */
  pneutr2_reg_FF_stiff_B.Input2 = ref_alfa_y_ID1;

  /* S-Function (bur_in): '<Root>/Input8' */
  pneutr2_reg_FF_stiff_B.Input8 = act_alfa_x_ID1;

  /* S-Function (bur_in): '<Root>/Input14' */
  pneutr2_reg_FF_stiff_B.Input14 = act_alfa_y_ID1;

  /* S-Function (bur_in): '<Root>/Input18' */
  pneutr2_reg_FF_stiff_B.Input18 = poradie_ID1;

  /* MATLAB Function: '<S37>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S37>/Constant'
   *  Constant: '<S37>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input1,
    pneutr2_reg_FF_stiff_B.Input2, pneutr2_reg_FF_stiff_B.Input8,
    pneutr2_reg_FF_stiff_B.Input14, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input18,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1);

  /* Sum: '<S38>/Sum6' */
  rtb_Sum8 = pneutr2_reg_FF_stiff_B.Input8 - pneutr2_reg_FF_stiff_B.Input1;

  /* Math: '<S38>/Math Function' */
  rtb_MathFunction = rtb_Sum8 * rtb_Sum8;

  /* Sum: '<S38>/Sum7' */
  rtb_Sum8 = pneutr2_reg_FF_stiff_B.Input14 - pneutr2_reg_FF_stiff_B.Input2;

  /* S-Function (bur_in): '<Root>/Input47' */
  pneutr2_reg_FF_stiff_B.Input47 = pripustna_odchylka_naklonenia;

  /* Sum: '<S38>/Sum8' incorporates:
   *  Math: '<S38>/Math Function1'
   *  Sqrt: '<S38>/Sqrt'
   *  Sum: '<S38>/Sum5'
   */
  rtb_Sum8 = sqrtf(rtb_Sum8 * rtb_Sum8 + rtb_MathFunction) -
    pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S38>/Switch' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S42>/cylinder height'
   *  Constant: '<S44>/cylinder height'
   *  Gain: '<S37>/Gain'
   *  Gain: '<S37>/Gain3'
   *  Sum: '<S42>/Sum'
   *  Sum: '<S44>/Sum'
   *  Sum: '<S8>/Sum'
   */
  if (rtb_Sum8 >= 0.0F) {
    rtb_Switch_l1 = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Blue_real -
                     0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Blue_ref - 0.16);
  } else {
    rtb_Switch_l1 = 0.0;
  }

  /* End of Switch: '<S38>/Switch' */

  /* S-Function (bur_in): '<Root>/Input17' */
  pneutr2_reg_FF_stiff_B.Input17 = RESET_ID1;

  /* DiscreteIntegrator: '<S178>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE = 0.0;
  }

  /* DiscreteIntegrator: '<S173>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE = 0.0;
  }

  /* End of DiscreteIntegrator: '<S173>/Filter' */

  /* Product: '<S181>/NProd Out' incorporates:
   *  Constant: '<S8>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut = 0.0;

  /* Sum: '<S188>/Sum' incorporates:
   *  DiscreteIntegrator: '<S178>/Integrator'
   */
  rtb_Sum = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE +
    pneutr2_reg_FF_stiff_B.NProdOut;

  /* Switch: '<S186>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Constant: '<S8>/min_sat'
   *  RelationalOperator: '<S186>/LowerRelop1'
   *  RelationalOperator: '<S186>/UpperRelop'
   *  Sum: '<S8>/Sum3'
   *  Sum: '<S8>/Sum4'
   *  Switch: '<S186>/Switch'
   */
  if (rtb_Sum > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S186>/Switch' incorporates:
     *  Constant: '<S8>/min_sat'
     *  Sum: '<S8>/Sum4'
     */
    rtb_Sum = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S186>/Switch2' */

  /* MATLAB Function: '<Root>/ID1' incorporates:
   *  Constant: '<Root>/Constant'
   *  Constant: '<Root>/Constant1'
   *  Constant: '<Root>/Constant3'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input1,
    pneutr2_reg_FF_stiff_B.Input2, pneutr2_reg_FF_stiff_ConstP.Constant_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant1_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant3_Value, pneutr2_reg_FF_stiff_B.Input15,
    &pneutr2_reg_FF_stiff_B.sf_ID1);

  /* Gain: '<S32>/Gain1' incorporates:
   *  Sum: '<Root>/Sum'
   */
  pneutr2_reg_FF_stiff_B.Gain1 = (real32_T)(rtb_Sum +
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak1);

  /* S-Function (bur_in): '<Root>/Input45' */
  pneutr2_reg_FF_stiff_B.Input45 = cas_trajektorie;

  /* S-Function (bur_in): '<Root>/Input46' */
  pneutr2_reg_FF_stiff_B.Input46 = hranica_upravy_traj;

  /* MATLAB Function: '<S32>/MATLAB Function' incorporates:
   *  Gain: '<S32>/Gain2'
   *  Gain: '<S32>/Gain3'
   *  UnitDelay: '<S32>/Unit Delay'
   *  UnitDelay: '<S32>/Unit Delay1'
   *  UnitDelay: '<S32>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a);

  /* Gain: '<S32>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6 = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.out;

  /* S-Function (bur_out): '<Root>/Output1' */
  Blue_tab_ID1 = pneutr2_reg_FF_stiff_B.Gain6;

  /* Sum: '<S29>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input10' */
  pneutr2_reg_FF_stiff_B.Input10 = ref_alfa_x_ID4;

  /* S-Function (bur_in): '<Root>/Input12' */
  pneutr2_reg_FF_stiff_B.Input12 = ref_alfa_y_ID4;

  /* S-Function (bur_in): '<Root>/Input33' */
  pneutr2_reg_FF_stiff_B.Input33 = act_alfa_x_ID4;

  /* S-Function (bur_in): '<Root>/Input29' */
  pneutr2_reg_FF_stiff_B.Input29 = act_alfa_y_ID4;

  /* S-Function (bur_in): '<Root>/Input32' */
  pneutr2_reg_FF_stiff_B.Input32 = poradie_ID4;

  /* MATLAB Function: '<S848>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S848>/Constant'
   *  Constant: '<S848>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input10,
    pneutr2_reg_FF_stiff_B.Input12, pneutr2_reg_FF_stiff_B.Input33,
    pneutr2_reg_FF_stiff_B.Input29, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input32,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a);

  /* Sum: '<S849>/Sum6' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input33 -
    pneutr2_reg_FF_stiff_B.Input10;

  /* Math: '<S849>/Math Function' */
  rtb_MathFunction_o = rtb_MathFunction * rtb_MathFunction;

  /* Sum: '<S849>/Sum7' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input29 -
    pneutr2_reg_FF_stiff_B.Input12;

  /* Sum: '<S849>/Sum8' incorporates:
   *  Math: '<S849>/Math Function1'
   *  Sqrt: '<S849>/Sqrt'
   *  Sum: '<S849>/Sum5'
   */
  rtb_MathFunction = sqrtf(rtb_MathFunction * rtb_MathFunction +
    rtb_MathFunction_o) - pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S849>/Switch' incorporates:
   *  Constant: '<S849>/Constant'
   *  Constant: '<S853>/cylinder height'
   *  Constant: '<S855>/cylinder height'
   *  Gain: '<S848>/Gain'
   *  Gain: '<S848>/Gain3'
   *  Sum: '<S29>/Sum'
   *  Sum: '<S853>/Sum'
   *  Sum: '<S855>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Switch_mc = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Blue_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Blue_ref - 0.16);
  } else {
    rtb_Switch_mc = 0.0;
  }

  /* End of Switch: '<S849>/Switch' */

  /* S-Function (bur_in): '<Root>/Input31' */
  pneutr2_reg_FF_stiff_B.Input31 = RESET_ID4;

  /* DiscreteIntegrator: '<S989>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_p = 0.0;
  }

  /* DiscreteIntegrator: '<S984>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_h = 0.0;
  }

  /* End of DiscreteIntegrator: '<S984>/Filter' */

  /* Product: '<S992>/NProd Out' incorporates:
   *  Constant: '<S29>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_h = 0.0;

  /* Sum: '<S999>/Sum' incorporates:
   *  DiscreteIntegrator: '<S989>/Integrator'
   */
  rtb_Sum_az = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_p +
    pneutr2_reg_FF_stiff_B.NProdOut_h;

  /* Switch: '<S997>/Switch2' incorporates:
   *  Constant: '<S29>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S997>/LowerRelop1'
   *  RelationalOperator: '<S997>/UpperRelop'
   *  Sum: '<S29>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S997>/Switch'
   */
  if (rtb_Sum_az > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_az = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_az < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S997>/Switch' incorporates:
     *  Constant: '<S29>/min_sat'
     *  Sum: '<S29>/Sum4'
     */
    rtb_Sum_az = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S997>/Switch2' */

  /* MATLAB Function: '<Root>/ID4' incorporates:
   *  Constant: '<Root>/Constant10'
   *  Constant: '<Root>/Constant15'
   *  Constant: '<Root>/Constant5'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input10,
    pneutr2_reg_FF_stiff_B.Input12, pneutr2_reg_FF_stiff_ConstP.Constant5_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant10_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant15_Value, pneutr2_reg_FF_stiff_B.Input15,
    &pneutr2_reg_FF_stiff_B.sf_ID4);

  /* Gain: '<S22>/Gain1' incorporates:
   *  Sum: '<Root>/Sum9'
   */
  pneutr2_reg_FF_stiff_B.Gain1_d = (real32_T)(rtb_Sum_az +
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak1);

  /* MATLAB Function: '<S22>/MATLAB Function' incorporates:
   *  Gain: '<S22>/Gain2'
   *  Gain: '<S22>/Gain3'
   *  UnitDelay: '<S22>/Unit Delay'
   *  UnitDelay: '<S22>/Unit Delay1'
   *  UnitDelay: '<S22>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_d,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_i,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_k,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m);

  /* Gain: '<S22>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_d = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.out;

  /* S-Function (bur_out): '<Root>/Output10' */
  Blue_tab_ID4 = pneutr2_reg_FF_stiff_B.Gain6_d;

  /* Switch: '<S849>/Switch2' incorporates:
   *  Constant: '<S849>/Constant'
   *  Constant: '<S856>/cylinder height'
   *  Constant: '<S858>/cylinder height'
   *  Gain: '<S848>/Gain1'
   *  Gain: '<S848>/Gain4'
   *  Sum: '<S29>/Sum2'
   *  Sum: '<S856>/Sum'
   *  Sum: '<S858>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_az = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Green_real -
                  0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Green_ref - 0.16);
  } else {
    rtb_Sum_az = 0.0;
  }

  /* End of Switch: '<S849>/Switch2' */

  /* DiscreteIntegrator: '<S940>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_m = 0.0;
  }

  /* DiscreteIntegrator: '<S935>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a = 0.0;
  }

  /* End of DiscreteIntegrator: '<S935>/Filter' */

  /* Product: '<S943>/NProd Out' incorporates:
   *  Constant: '<S29>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_o = 0.0;

  /* Sum: '<S950>/Sum' incorporates:
   *  DiscreteIntegrator: '<S940>/Integrator'
   */
  rtb_Sum_ai = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_m +
    pneutr2_reg_FF_stiff_B.NProdOut_o;

  /* Switch: '<S948>/Switch2' incorporates:
   *  Constant: '<S29>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S948>/LowerRelop1'
   *  RelationalOperator: '<S948>/UpperRelop'
   *  Sum: '<S29>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S948>/Switch'
   */
  if (rtb_Sum_ai > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_ai = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_ai < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S948>/Switch' incorporates:
     *  Constant: '<S29>/min_sat'
     *  Sum: '<S29>/Sum4'
     */
    rtb_Sum_ai = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S948>/Switch2' */

  /* Gain: '<S24>/Gain1' incorporates:
   *  Sum: '<Root>/Sum11'
   */
  pneutr2_reg_FF_stiff_B.Gain1_l = (real32_T)(rtb_Sum_ai +
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak3);

  /* MATLAB Function: '<S24>/MATLAB Function' incorporates:
   *  Gain: '<S24>/Gain2'
   *  Gain: '<S24>/Gain3'
   *  UnitDelay: '<S24>/Unit Delay'
   *  UnitDelay: '<S24>/Unit Delay1'
   *  UnitDelay: '<S24>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_l,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_l,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_n,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g);

  /* Gain: '<S24>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_l = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.out;

  /* S-Function (bur_out): '<Root>/Output11' */
  Yellow_tab_ID4 = pneutr2_reg_FF_stiff_B.Gain6_l;

  /* Sum: '<S30>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum_ai = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input11' */
  pneutr2_reg_FF_stiff_B.Input11 = ref_alfa_x_ID5;

  /* S-Function (bur_in): '<Root>/Input13' */
  pneutr2_reg_FF_stiff_B.Input13 = ref_alfa_y_ID5;

  /* S-Function (bur_in): '<Root>/Input37' */
  pneutr2_reg_FF_stiff_B.Input37 = act_alfa_x_ID5;

  /* S-Function (bur_in): '<Root>/Input34' */
  pneutr2_reg_FF_stiff_B.Input34 = act_alfa_y_ID5;

  /* S-Function (bur_in): '<Root>/Input38' */
  pneutr2_reg_FF_stiff_B.Input38 = poradie_ID5;

  /* MATLAB Function: '<S1007>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S1007>/Constant'
   *  Constant: '<S1007>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input11,
    pneutr2_reg_FF_stiff_B.Input13, pneutr2_reg_FF_stiff_B.Input37,
    pneutr2_reg_FF_stiff_B.Input34, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input38,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j);

  /* Sum: '<S1008>/Sum6' */
  rtb_MathFunction_o = pneutr2_reg_FF_stiff_B.Input37 -
    pneutr2_reg_FF_stiff_B.Input11;

  /* Math: '<S1008>/Math Function' */
  rtb_MathFunction_h = rtb_MathFunction_o * rtb_MathFunction_o;

  /* Sum: '<S1008>/Sum7' */
  rtb_MathFunction_o = pneutr2_reg_FF_stiff_B.Input34 -
    pneutr2_reg_FF_stiff_B.Input13;

  /* Sum: '<S1008>/Sum8' incorporates:
   *  Math: '<S1008>/Math Function1'
   *  Sqrt: '<S1008>/Sqrt'
   *  Sum: '<S1008>/Sum5'
   */
  rtb_MathFunction_o = sqrtf(rtb_MathFunction_o * rtb_MathFunction_o +
    rtb_MathFunction_h) - pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S1008>/Switch' incorporates:
   *  Constant: '<S1008>/Constant'
   *  Constant: '<S1012>/cylinder height'
   *  Constant: '<S1014>/cylinder height'
   *  Gain: '<S1007>/Gain'
   *  Gain: '<S1007>/Gain3'
   *  Sum: '<S1012>/Sum'
   *  Sum: '<S1014>/Sum'
   *  Sum: '<S30>/Sum'
   */
  if (rtb_MathFunction_o >= 0.0F) {
    rtb_Switch_ju = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Blue_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Blue_ref - 0.16);
  } else {
    rtb_Switch_ju = 0.0;
  }

  /* End of Switch: '<S1008>/Switch' */

  /* S-Function (bur_in): '<Root>/Input36' */
  pneutr2_reg_FF_stiff_B.Input36 = RESET_ID5;

  /* DiscreteIntegrator: '<S1148>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_b = 0.0;
  }

  /* DiscreteIntegrator: '<S1143>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hm = 0.0;
  }

  /* End of DiscreteIntegrator: '<S1143>/Filter' */

  /* Product: '<S1151>/NProd Out' incorporates:
   *  Constant: '<S30>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_a = 0.0;

  /* Sum: '<S1158>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1148>/Integrator'
   */
  rtb_Sum_lj = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_b +
    pneutr2_reg_FF_stiff_B.NProdOut_a;

  /* Switch: '<S1156>/Switch2' incorporates:
   *  Constant: '<S30>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S1156>/LowerRelop1'
   *  RelationalOperator: '<S1156>/UpperRelop'
   *  Sum: '<S30>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S1156>/Switch'
   */
  if (rtb_Sum_lj > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_lj = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_lj < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S1156>/Switch' incorporates:
     *  Constant: '<S30>/min_sat'
     *  Sum: '<S30>/Sum4'
     */
    rtb_Sum_lj = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S1156>/Switch2' */

  /* MATLAB Function: '<Root>/ID5' incorporates:
   *  Constant: '<Root>/Constant11'
   *  Constant: '<Root>/Constant16'
   *  Constant: '<Root>/Constant6'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input11,
    pneutr2_reg_FF_stiff_B.Input13, pneutr2_reg_FF_stiff_ConstP.Constant6_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant11_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant16_Value, pneutr2_reg_FF_stiff_B.Input15,
    &pneutr2_reg_FF_stiff_B.sf_ID5);

  /* Gain: '<S12>/Gain1' incorporates:
   *  Sum: '<Root>/Sum14'
   */
  pneutr2_reg_FF_stiff_B.Gain1_c = (real32_T)(rtb_Sum_lj +
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak1);

  /* MATLAB Function: '<S12>/MATLAB Function' incorporates:
   *  Gain: '<S12>/Gain2'
   *  Gain: '<S12>/Gain3'
   *  UnitDelay: '<S12>/Unit Delay'
   *  UnitDelay: '<S12>/Unit Delay1'
   *  UnitDelay: '<S12>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_c,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lr,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_e, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_g,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p);

  /* Gain: '<S12>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_j = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.out;

  /* S-Function (bur_out): '<Root>/Output12' */
  Blue_tab_ID5 = pneutr2_reg_FF_stiff_B.Gain6_j;

  /* Switch: '<S849>/Switch1' incorporates:
   *  Constant: '<S849>/Constant'
   *  Constant: '<S854>/cylinder height'
   *  Constant: '<S857>/cylinder height'
   *  Gain: '<S848>/Gain2'
   *  Gain: '<S848>/Gain5'
   *  Sum: '<S29>/Sum1'
   *  Sum: '<S854>/Sum'
   *  Sum: '<S857>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_lj = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Yellow_real
                  - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Yellow_ref - 0.16);
  } else {
    rtb_Sum_lj = 0.0;
  }

  /* End of Switch: '<S849>/Switch1' */

  /* DiscreteIntegrator: '<S891>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_h = 0.0;
  }

  /* DiscreteIntegrator: '<S886>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input31 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input31 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hx = 0.0;
  }

  /* End of DiscreteIntegrator: '<S886>/Filter' */

  /* Product: '<S894>/NProd Out' incorporates:
   *  Constant: '<S29>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_k = 0.0;

  /* Sum: '<S901>/Sum' incorporates:
   *  DiscreteIntegrator: '<S891>/Integrator'
   */
  rtb_Sum_jv = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_h +
    pneutr2_reg_FF_stiff_B.NProdOut_k;

  /* Switch: '<S899>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S899>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_jv <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S899>/Switch' incorporates:
     *  Constant: '<S29>/min_sat'
     *  RelationalOperator: '<S899>/UpperRelop'
     *  Sum: '<S29>/Sum4'
     */
    if (rtb_Sum_jv < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum = rtb_Sum_jv;
    }

    /* End of Switch: '<S899>/Switch' */
  }

  /* End of Switch: '<S899>/Switch2' */

  /* Gain: '<S23>/Gain1' incorporates:
   *  Sum: '<Root>/Sum10'
   */
  pneutr2_reg_FF_stiff_B.Gain1_a = (real32_T)(rtb_Sum +
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak2);

  /* MATLAB Function: '<S23>/MATLAB Function' incorporates:
   *  Gain: '<S23>/Gain2'
   *  Gain: '<S23>/Gain3'
   *  UnitDelay: '<S23>/Unit Delay'
   *  UnitDelay: '<S23>/Unit Delay1'
   *  UnitDelay: '<S23>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_a,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_n,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_a,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw);

  /* Gain: '<S23>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_p = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.out;

  /* S-Function (bur_out): '<Root>/Output13' */
  Green_tab_ID4 = pneutr2_reg_FF_stiff_B.Gain6_p;

  /* Switch: '<S1008>/Switch2' incorporates:
   *  Constant: '<S1008>/Constant'
   *  Constant: '<S1015>/cylinder height'
   *  Constant: '<S1017>/cylinder height'
   *  Gain: '<S1007>/Gain1'
   *  Gain: '<S1007>/Gain4'
   *  Sum: '<S1015>/Sum'
   *  Sum: '<S1017>/Sum'
   *  Sum: '<S30>/Sum2'
   */
  if (rtb_MathFunction_o >= 0.0F) {
    rtb_Sum = (0.001F *
               pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Green_real -
               0.16) - (0.001F *
                        pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Green_ref
                        - 0.16);
  } else {
    rtb_Sum = 0.0;
  }

  /* End of Switch: '<S1008>/Switch2' */

  /* DiscreteIntegrator: '<S1099>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_l = 0.0;
  }

  /* DiscreteIntegrator: '<S1094>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a4 = 0.0;
  }

  /* End of DiscreteIntegrator: '<S1094>/Filter' */

  /* Product: '<S1102>/NProd Out' incorporates:
   *  Constant: '<S30>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_e = 0.0;

  /* Sum: '<S1109>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1099>/Integrator'
   */
  rtb_Sum4_l = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_l +
    pneutr2_reg_FF_stiff_B.NProdOut_e;

  /* Switch: '<S1107>/Switch2' incorporates:
   *  Constant: '<S30>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S1107>/LowerRelop1'
   *  RelationalOperator: '<S1107>/UpperRelop'
   *  Sum: '<S30>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S1107>/Switch'
   */
  if (rtb_Sum4_l > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum4_l = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum4_l < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S1107>/Switch' incorporates:
     *  Constant: '<S30>/min_sat'
     *  Sum: '<S30>/Sum4'
     */
    rtb_Sum4_l = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S1107>/Switch2' */

  /* Gain: '<S14>/Gain1' incorporates:
   *  Sum: '<Root>/Sum13'
   */
  pneutr2_reg_FF_stiff_B.Gain1_k = (real32_T)(rtb_Sum4_l +
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak3);

  /* MATLAB Function: '<S14>/MATLAB Function' incorporates:
   *  Gain: '<S14>/Gain2'
   *  Gain: '<S14>/Gain3'
   *  UnitDelay: '<S14>/Unit Delay'
   *  UnitDelay: '<S14>/Unit Delay1'
   *  UnitDelay: '<S14>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_k,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_m,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_m, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l);

  /* Gain: '<S14>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_g = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.out;

  /* S-Function (bur_out): '<Root>/Output14' */
  Yellow_tab_ID5 = pneutr2_reg_FF_stiff_B.Gain6_g;

  /* Switch: '<S1008>/Switch1' incorporates:
   *  Constant: '<S1008>/Constant'
   *  Constant: '<S1013>/cylinder height'
   *  Constant: '<S1016>/cylinder height'
   *  Gain: '<S1007>/Gain2'
   *  Gain: '<S1007>/Gain5'
   *  Sum: '<S1013>/Sum'
   *  Sum: '<S1016>/Sum'
   *  Sum: '<S30>/Sum1'
   */
  if (rtb_MathFunction_o >= 0.0F) {
    rtb_Sum4_l = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Yellow_real
                  - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Yellow_ref - 0.16);
  } else {
    rtb_Sum4_l = 0.0;
  }

  /* End of Switch: '<S1008>/Switch1' */

  /* DiscreteIntegrator: '<S1050>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_a = 0.0;
  }

  /* DiscreteIntegrator: '<S1045>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input36 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input36 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_c = 0.0;
  }

  /* End of DiscreteIntegrator: '<S1045>/Filter' */

  /* Product: '<S1053>/NProd Out' incorporates:
   *  Constant: '<S30>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_f = 0.0;

  /* Sum: '<S1060>/Sum' incorporates:
   *  DiscreteIntegrator: '<S1050>/Integrator'
   */
  rtb_Sum_jv = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_a +
    pneutr2_reg_FF_stiff_B.NProdOut_f;

  /* Switch: '<S1058>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S1058>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_jv <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S1058>/Switch' incorporates:
     *  Constant: '<S30>/min_sat'
     *  RelationalOperator: '<S1058>/UpperRelop'
     *  Sum: '<S30>/Sum4'
     */
    if (rtb_Sum_jv < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum_ai = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum_ai = rtb_Sum_jv;
    }

    /* End of Switch: '<S1058>/Switch' */
  }

  /* End of Switch: '<S1058>/Switch2' */

  /* Gain: '<S13>/Gain1' incorporates:
   *  Sum: '<Root>/Sum12'
   */
  pneutr2_reg_FF_stiff_B.Gain1_kh = (real32_T)(rtb_Sum_ai +
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak2);

  /* MATLAB Function: '<S13>/MATLAB Function' incorporates:
   *  Gain: '<S13>/Gain2'
   *  Gain: '<S13>/Gain3'
   *  UnitDelay: '<S13>/Unit Delay'
   *  UnitDelay: '<S13>/Unit Delay1'
   *  UnitDelay: '<S13>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_kh,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_g,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a5, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p4,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c);

  /* Gain: '<S13>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_i = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.out;

  /* S-Function (bur_out): '<Root>/Output15' */
  Green_tab_ID5 = pneutr2_reg_FF_stiff_B.Gain6_i;

  /* Sum: '<S20>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum_ai = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input7' */
  pneutr2_reg_FF_stiff_B.Input7 = ref_alfa_x_ID6;

  /* S-Function (bur_in): '<Root>/Input9' */
  pneutr2_reg_FF_stiff_B.Input9 = ref_alfa_y_ID6;

  /* S-Function (bur_in): '<Root>/Input43' */
  pneutr2_reg_FF_stiff_B.Input43 = act_alfa_x_ID6;

  /* S-Function (bur_in): '<Root>/Input39' */
  pneutr2_reg_FF_stiff_B.Input39 = act_alfa_y_ID6;

  /* S-Function (bur_in): '<Root>/Input42' */
  pneutr2_reg_FF_stiff_B.Input42 = poradie_ID6;

  /* MATLAB Function: '<S365>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S365>/Constant'
   *  Constant: '<S365>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input7,
    pneutr2_reg_FF_stiff_B.Input9, pneutr2_reg_FF_stiff_B.Input43,
    pneutr2_reg_FF_stiff_B.Input39, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input42,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n);

  /* Sum: '<S366>/Sum6' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input43 -
    pneutr2_reg_FF_stiff_B.Input7;

  /* Math: '<S366>/Math Function' */
  rtb_MathFunction_o = rtb_MathFunction * rtb_MathFunction;

  /* Sum: '<S366>/Sum7' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input39 -
    pneutr2_reg_FF_stiff_B.Input9;

  /* Sum: '<S366>/Sum8' incorporates:
   *  Math: '<S366>/Math Function1'
   *  Sqrt: '<S366>/Sqrt'
   *  Sum: '<S366>/Sum5'
   */
  rtb_MathFunction = sqrtf(rtb_MathFunction * rtb_MathFunction +
    rtb_MathFunction_o) - pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S366>/Switch' incorporates:
   *  Constant: '<S366>/Constant'
   *  Constant: '<S370>/cylinder height'
   *  Constant: '<S372>/cylinder height'
   *  Gain: '<S365>/Gain'
   *  Gain: '<S365>/Gain3'
   *  Sum: '<S20>/Sum'
   *  Sum: '<S370>/Sum'
   *  Sum: '<S372>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum4_hu = (0.001F *
                   pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Blue_real -
                   0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Blue_ref - 0.16);
  } else {
    rtb_Sum4_hu = 0.0;
  }

  /* End of Switch: '<S366>/Switch' */

  /* S-Function (bur_in): '<Root>/Input41' */
  pneutr2_reg_FF_stiff_B.Input41 = RESET_ID6;

  /* DiscreteIntegrator: '<S506>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_lu = 0.0;
  }

  /* DiscreteIntegrator: '<S501>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_p = 0.0;
  }

  /* End of DiscreteIntegrator: '<S501>/Filter' */

  /* Product: '<S509>/NProd Out' incorporates:
   *  Constant: '<S20>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_ay = 0.0;

  /* Sum: '<S516>/Sum' incorporates:
   *  DiscreteIntegrator: '<S506>/Integrator'
   */
  rtb_Sum_jv = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_lu +
    pneutr2_reg_FF_stiff_B.NProdOut_ay;

  /* Switch: '<S514>/Switch2' incorporates:
   *  Constant: '<S20>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S514>/LowerRelop1'
   *  RelationalOperator: '<S514>/UpperRelop'
   *  Sum: '<S20>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S514>/Switch'
   */
  if (rtb_Sum_jv > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_jv = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_jv < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S514>/Switch' incorporates:
     *  Constant: '<S20>/min_sat'
     *  Sum: '<S20>/Sum4'
     */
    rtb_Sum_jv = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S514>/Switch2' */

  /* MATLAB Function: '<Root>/ID6' incorporates:
   *  Constant: '<Root>/Constant12'
   *  Constant: '<Root>/Constant17'
   *  Constant: '<Root>/Constant7'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input7,
    pneutr2_reg_FF_stiff_B.Input9, pneutr2_reg_FF_stiff_ConstP.pooled3,
    pneutr2_reg_FF_stiff_ConstP.pooled1, pneutr2_reg_FF_stiff_ConstP.pooled2,
    pneutr2_reg_FF_stiff_B.Input15, &pneutr2_reg_FF_stiff_B.sf_ID6);

  /* Gain: '<S18>/Gain1' incorporates:
   *  Sum: '<Root>/Sum17'
   */
  pneutr2_reg_FF_stiff_B.Gain1_e = (real32_T)(rtb_Sum_jv +
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak1);

  /* MATLAB Function: '<S18>/MATLAB Function' incorporates:
   *  Gain: '<S18>/Gain2'
   *  Gain: '<S18>/Gain3'
   *  UnitDelay: '<S18>/Unit Delay'
   *  UnitDelay: '<S18>/Unit Delay1'
   *  UnitDelay: '<S18>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_e,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_b,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kl,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h);

  /* Gain: '<S18>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_po = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.out;

  /* S-Function (bur_out): '<Root>/Output16' */
  Blue_tab_ID6 = pneutr2_reg_FF_stiff_B.Gain6_po;

  /* Switch: '<S366>/Switch2' incorporates:
   *  Constant: '<S366>/Constant'
   *  Constant: '<S373>/cylinder height'
   *  Constant: '<S375>/cylinder height'
   *  Gain: '<S365>/Gain1'
   *  Gain: '<S365>/Gain4'
   *  Sum: '<S20>/Sum2'
   *  Sum: '<S373>/Sum'
   *  Sum: '<S375>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_jv = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Green_real -
                  0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Green_ref - 0.16);
  } else {
    rtb_Sum_jv = 0.0;
  }

  /* End of Switch: '<S366>/Switch2' */

  /* DiscreteIntegrator: '<S457>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_bw = 0.0;
  }

  /* DiscreteIntegrator: '<S452>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_pq = 0.0;
  }

  /* End of DiscreteIntegrator: '<S452>/Filter' */

  /* Product: '<S460>/NProd Out' incorporates:
   *  Constant: '<S20>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_n = 0.0;

  /* Sum: '<S467>/Sum' incorporates:
   *  DiscreteIntegrator: '<S457>/Integrator'
   */
  rtb_Sum_lr = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_bw +
    pneutr2_reg_FF_stiff_B.NProdOut_n;

  /* Switch: '<S465>/Switch2' incorporates:
   *  Constant: '<S20>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S465>/LowerRelop1'
   *  RelationalOperator: '<S465>/UpperRelop'
   *  Sum: '<S20>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S465>/Switch'
   */
  if (rtb_Sum_lr > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_lr = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_lr < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S465>/Switch' incorporates:
     *  Constant: '<S20>/min_sat'
     *  Sum: '<S20>/Sum4'
     */
    rtb_Sum_lr = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S465>/Switch2' */

  /* Gain: '<S21>/Gain1' incorporates:
   *  Sum: '<Root>/Sum16'
   */
  pneutr2_reg_FF_stiff_B.Gain1_k0 = (real32_T)(rtb_Sum_lr +
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak3);

  /* MATLAB Function: '<S21>/MATLAB Function' incorporates:
   *  Gain: '<S21>/Gain2'
   *  Gain: '<S21>/Gain3'
   *  UnitDelay: '<S21>/Unit Delay'
   *  UnitDelay: '<S21>/Unit Delay1'
   *  UnitDelay: '<S21>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_k0,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g1, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_m,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm);

  /* Gain: '<S21>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_n = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.out;

  /* S-Function (bur_out): '<Root>/Output17' */
  Yellow_tab_ID6 = pneutr2_reg_FF_stiff_B.Gain6_n;

  /* Switch: '<S366>/Switch1' incorporates:
   *  Constant: '<S366>/Constant'
   *  Constant: '<S371>/cylinder height'
   *  Constant: '<S374>/cylinder height'
   *  Gain: '<S365>/Gain2'
   *  Gain: '<S365>/Gain5'
   *  Sum: '<S20>/Sum1'
   *  Sum: '<S371>/Sum'
   *  Sum: '<S374>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_lr = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Yellow_real
                  - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Yellow_ref - 0.16);
  } else {
    rtb_Sum_lr = 0.0;
  }

  /* End of Switch: '<S366>/Switch1' */

  /* DiscreteIntegrator: '<S408>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_pa = 0.0;
  }

  /* DiscreteIntegrator: '<S403>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input41 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input41 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_k = 0.0;
  }

  /* End of DiscreteIntegrator: '<S403>/Filter' */

  /* Product: '<S411>/NProd Out' incorporates:
   *  Constant: '<S20>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_ol = 0.0;

  /* Sum: '<S418>/Sum' incorporates:
   *  DiscreteIntegrator: '<S408>/Integrator'
   */
  rtb_Sum_l = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_pa +
    pneutr2_reg_FF_stiff_B.NProdOut_ol;

  /* Switch: '<S416>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S416>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_l <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S416>/Switch' incorporates:
     *  Constant: '<S20>/min_sat'
     *  RelationalOperator: '<S416>/UpperRelop'
     *  Sum: '<S20>/Sum4'
     */
    if (rtb_Sum_l < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum_ai = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum_ai = rtb_Sum_l;
    }

    /* End of Switch: '<S416>/Switch' */
  }

  /* End of Switch: '<S416>/Switch2' */

  /* Gain: '<S19>/Gain1' incorporates:
   *  Sum: '<Root>/Sum15'
   */
  pneutr2_reg_FF_stiff_B.Gain1_b = (real32_T)(rtb_Sum_ai +
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak2);

  /* MATLAB Function: '<S19>/MATLAB Function' incorporates:
   *  Gain: '<S19>/Gain2'
   *  Gain: '<S19>/Gain3'
   *  UnitDelay: '<S19>/Unit Delay'
   *  UnitDelay: '<S19>/Unit Delay1'
   *  UnitDelay: '<S19>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_b,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_le,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_i, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_ny,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n);

  /* Gain: '<S19>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_e = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.out;

  /* S-Function (bur_out): '<Root>/Output18' */
  Green_tab_ID6 = pneutr2_reg_FF_stiff_B.Gain6_e;

  /* Switch: '<S38>/Switch2' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S45>/cylinder height'
   *  Constant: '<S47>/cylinder height'
   *  Gain: '<S37>/Gain1'
   *  Gain: '<S37>/Gain4'
   *  Sum: '<S45>/Sum'
   *  Sum: '<S47>/Sum'
   *  Sum: '<S8>/Sum2'
   */
  if (rtb_Sum8 >= 0.0F) {
    rtb_Sum_ai = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Green_real -
                  0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Green_ref - 0.16);
  } else {
    rtb_Sum_ai = 0.0;
  }

  /* End of Switch: '<S38>/Switch2' */

  /* DiscreteIntegrator: '<S129>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_o = 0.0;
  }

  /* DiscreteIntegrator: '<S124>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kg = 0.0;
  }

  /* End of DiscreteIntegrator: '<S124>/Filter' */

  /* Product: '<S132>/NProd Out' incorporates:
   *  Constant: '<S8>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_m = 0.0;

  /* Sum: '<S139>/Sum' incorporates:
   *  DiscreteIntegrator: '<S129>/Integrator'
   */
  rtb_Sum4_b = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_o +
    pneutr2_reg_FF_stiff_B.NProdOut_m;

  /* Switch: '<S137>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Constant: '<S8>/min_sat'
   *  RelationalOperator: '<S137>/LowerRelop1'
   *  RelationalOperator: '<S137>/UpperRelop'
   *  Sum: '<S8>/Sum3'
   *  Sum: '<S8>/Sum4'
   *  Switch: '<S137>/Switch'
   */
  if (rtb_Sum4_b > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum4_b = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum4_b < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S137>/Switch' incorporates:
     *  Constant: '<S8>/min_sat'
     *  Sum: '<S8>/Sum4'
     */
    rtb_Sum4_b = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S137>/Switch2' */

  /* Gain: '<S34>/Gain1' incorporates:
   *  Sum: '<Root>/Sum2'
   */
  pneutr2_reg_FF_stiff_B.Gain1_g = (real32_T)(rtb_Sum4_b +
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak3);

  /* MATLAB Function: '<S34>/MATLAB Function' incorporates:
   *  Gain: '<S34>/Gain2'
   *  Gain: '<S34>/Gain3'
   *  UnitDelay: '<S34>/Unit Delay'
   *  UnitDelay: '<S34>/Unit Delay1'
   *  UnitDelay: '<S34>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_g,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_f,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k2, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je);

  /* Gain: '<S34>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_a = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.out;

  /* S-Function (bur_out): '<Root>/Output2' */
  Yellow_tab_ID1 = pneutr2_reg_FF_stiff_B.Gain6_a;

  /* Sum: '<S27>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum4_b = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input53' */
  pneutr2_reg_FF_stiff_B.Input53 = ref_alfa_x_ID7;

  /* S-Function (bur_in): '<Root>/Input54' */
  pneutr2_reg_FF_stiff_B.Input54 = ref_alfa_y_ID7;

  /* S-Function (bur_in): '<Root>/Input52' */
  pneutr2_reg_FF_stiff_B.Input52 = act_alfa_x_ID7;

  /* S-Function (bur_in): '<Root>/Input48' */
  pneutr2_reg_FF_stiff_B.Input48 = act_alfa_y_ID7;

  /* S-Function (bur_in): '<Root>/Input51' */
  pneutr2_reg_FF_stiff_B.Input51 = poradie_ID7;

  /* MATLAB Function: '<S688>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S688>/Constant'
   *  Constant: '<S688>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input53,
    pneutr2_reg_FF_stiff_B.Input54, pneutr2_reg_FF_stiff_B.Input52,
    pneutr2_reg_FF_stiff_B.Input48, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input51,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b);

  /* Sum: '<S689>/Sum6' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input52 -
    pneutr2_reg_FF_stiff_B.Input53;

  /* Math: '<S689>/Math Function' */
  rtb_MathFunction_o = rtb_MathFunction * rtb_MathFunction;

  /* Sum: '<S689>/Sum7' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input48 -
    pneutr2_reg_FF_stiff_B.Input54;

  /* Sum: '<S689>/Sum8' incorporates:
   *  Math: '<S689>/Math Function1'
   *  Sqrt: '<S689>/Sqrt'
   *  Sum: '<S689>/Sum5'
   */
  rtb_MathFunction = sqrtf(rtb_MathFunction * rtb_MathFunction +
    rtb_MathFunction_o) - pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S689>/Switch' incorporates:
   *  Constant: '<S689>/Constant'
   *  Constant: '<S693>/cylinder height'
   *  Constant: '<S695>/cylinder height'
   *  Gain: '<S688>/Gain'
   *  Gain: '<S688>/Gain3'
   *  Sum: '<S27>/Sum'
   *  Sum: '<S693>/Sum'
   *  Sum: '<S695>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_l = (0.001F *
                 pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Blue_real -
                 0.16) - (0.001F *
                          pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Blue_ref
                          - 0.16);
  } else {
    rtb_Sum_l = 0.0;
  }

  /* End of Switch: '<S689>/Switch' */

  /* S-Function (bur_in): '<Root>/Input50' */
  pneutr2_reg_FF_stiff_B.Input50 = RESET_ID7;

  /* DiscreteIntegrator: '<S829>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ah = 0.0;
  }

  /* DiscreteIntegrator: '<S824>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_d = 0.0;
  }

  /* End of DiscreteIntegrator: '<S824>/Filter' */

  /* Product: '<S832>/NProd Out' incorporates:
   *  Constant: '<S27>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_b = 0.0;

  /* Sum: '<S839>/Sum' incorporates:
   *  DiscreteIntegrator: '<S829>/Integrator'
   */
  rtb_Sum_ce = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ah +
    pneutr2_reg_FF_stiff_B.NProdOut_b;

  /* Switch: '<S837>/Switch2' incorporates:
   *  Constant: '<S27>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S837>/LowerRelop1'
   *  RelationalOperator: '<S837>/UpperRelop'
   *  Sum: '<S27>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S837>/Switch'
   */
  if (rtb_Sum_ce > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_ce = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_ce < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S837>/Switch' incorporates:
     *  Constant: '<S27>/min_sat'
     *  Sum: '<S27>/Sum4'
     */
    rtb_Sum_ce = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S837>/Switch2' */

  /* MATLAB Function: '<Root>/ID7' incorporates:
   *  Constant: '<Root>/Constant18'
   *  Constant: '<Root>/Constant19'
   *  Constant: '<Root>/Constant20'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input53,
    pneutr2_reg_FF_stiff_B.Input54, pneutr2_reg_FF_stiff_ConstP.pooled3,
    pneutr2_reg_FF_stiff_ConstP.pooled1, pneutr2_reg_FF_stiff_ConstP.pooled2,
    pneutr2_reg_FF_stiff_B.Input15, &pneutr2_reg_FF_stiff_B.sf_ID7);

  /* Gain: '<S31>/Gain1' incorporates:
   *  Sum: '<Root>/Sum20'
   */
  pneutr2_reg_FF_stiff_B.Gain1_o = (real32_T)(rtb_Sum_ce +
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak1);

  /* MATLAB Function: '<S31>/MATLAB Function' incorporates:
   *  Gain: '<S31>/Gain2'
   *  Gain: '<S31>/Gain3'
   *  UnitDelay: '<S31>/Unit Delay'
   *  UnitDelay: '<S31>/Unit Delay1'
   *  UnitDelay: '<S31>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_o,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_ie,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ep, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mm,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd);

  /* Gain: '<S31>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_h = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.out;

  /* S-Function (bur_out): '<Root>/Output20' */
  Blue_tab_ID7 = pneutr2_reg_FF_stiff_B.Gain6_h;

  /* Switch: '<S689>/Switch2' incorporates:
   *  Constant: '<S689>/Constant'
   *  Constant: '<S696>/cylinder height'
   *  Constant: '<S698>/cylinder height'
   *  Gain: '<S688>/Gain1'
   *  Gain: '<S688>/Gain4'
   *  Sum: '<S27>/Sum2'
   *  Sum: '<S696>/Sum'
   *  Sum: '<S698>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_ce = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Green_real -
                  0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Green_ref - 0.16);
  } else {
    rtb_Sum_ce = 0.0;
  }

  /* End of Switch: '<S689>/Switch2' */

  /* DiscreteIntegrator: '<S780>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_j = 0.0;
  }

  /* DiscreteIntegrator: '<S775>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_ku = 0.0;
  }

  /* End of DiscreteIntegrator: '<S775>/Filter' */

  /* Product: '<S783>/NProd Out' incorporates:
   *  Constant: '<S27>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_nr = 0.0;

  /* Sum: '<S790>/Sum' incorporates:
   *  DiscreteIntegrator: '<S780>/Integrator'
   */
  rtb_Sum_iu = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_j +
    pneutr2_reg_FF_stiff_B.NProdOut_nr;

  /* Switch: '<S788>/Switch2' incorporates:
   *  Constant: '<S27>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S788>/LowerRelop1'
   *  RelationalOperator: '<S788>/UpperRelop'
   *  Sum: '<S27>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S788>/Switch'
   */
  if (rtb_Sum_iu > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_iu = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_iu < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S788>/Switch' incorporates:
     *  Constant: '<S27>/min_sat'
     *  Sum: '<S27>/Sum4'
     */
    rtb_Sum_iu = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S788>/Switch2' */

  /* Gain: '<S28>/Gain1' incorporates:
   *  Sum: '<Root>/Sum19'
   */
  pneutr2_reg_FF_stiff_B.Gain1_j = (real32_T)(rtb_Sum_iu +
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak3);

  /* MATLAB Function: '<S28>/MATLAB Function' incorporates:
   *  Gain: '<S28>/Gain2'
   *  Gain: '<S28>/Gain3'
   *  UnitDelay: '<S28>/Unit Delay'
   *  UnitDelay: '<S28>/Unit Delay1'
   *  UnitDelay: '<S28>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_j,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_h,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_n, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jk,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz);

  /* Gain: '<S28>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_f = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.out;

  /* S-Function (bur_out): '<Root>/Output21' */
  Yellow_tab_ID7 = pneutr2_reg_FF_stiff_B.Gain6_f;

  /* Switch: '<S689>/Switch1' incorporates:
   *  Constant: '<S689>/Constant'
   *  Constant: '<S694>/cylinder height'
   *  Constant: '<S697>/cylinder height'
   *  Gain: '<S688>/Gain2'
   *  Gain: '<S688>/Gain5'
   *  Sum: '<S27>/Sum1'
   *  Sum: '<S694>/Sum'
   *  Sum: '<S697>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum_iu = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Yellow_real
                  - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Yellow_ref - 0.16);
  } else {
    rtb_Sum_iu = 0.0;
  }

  /* End of Switch: '<S689>/Switch1' */

  /* DiscreteIntegrator: '<S731>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_aj = 0.0;
  }

  /* DiscreteIntegrator: '<S726>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input50 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input50 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_f = 0.0;
  }

  /* End of DiscreteIntegrator: '<S726>/Filter' */

  /* Product: '<S734>/NProd Out' incorporates:
   *  Constant: '<S27>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_kv = 0.0;

  /* Sum: '<S741>/Sum' incorporates:
   *  DiscreteIntegrator: '<S731>/Integrator'
   */
  rtb_Sum_c = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_aj +
    pneutr2_reg_FF_stiff_B.NProdOut_kv;

  /* Switch: '<S739>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S739>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_c <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S739>/Switch' incorporates:
     *  Constant: '<S27>/min_sat'
     *  RelationalOperator: '<S739>/UpperRelop'
     *  Sum: '<S27>/Sum4'
     */
    if (rtb_Sum_c < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum4_b = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum4_b = rtb_Sum_c;
    }

    /* End of Switch: '<S739>/Switch' */
  }

  /* End of Switch: '<S739>/Switch2' */

  /* Gain: '<S26>/Gain1' incorporates:
   *  Sum: '<Root>/Sum18'
   */
  pneutr2_reg_FF_stiff_B.Gain1_gu = (real32_T)(rtb_Sum4_b +
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak2);

  /* MATLAB Function: '<S26>/MATLAB Function' incorporates:
   *  Gain: '<S26>/Gain2'
   *  Gain: '<S26>/Gain3'
   *  UnitDelay: '<S26>/Unit Delay'
   *  UnitDelay: '<S26>/Unit Delay1'
   *  UnitDelay: '<S26>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_gu,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lg,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_mp, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_o,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j);

  /* Gain: '<S26>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_b = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.out;

  /* S-Function (bur_out): '<Root>/Output22' */
  Green_tab_ID7 = pneutr2_reg_FF_stiff_B.Gain6_b;

  /* Sum: '<S9>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum4_b = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input3' */
  pneutr2_reg_FF_stiff_B.Input3 = ref_alfa_x_ID2;

  /* S-Function (bur_in): '<Root>/Input5' */
  pneutr2_reg_FF_stiff_B.Input5 = ref_alfa_y_ID2;

  /* S-Function (bur_in): '<Root>/Input23' */
  pneutr2_reg_FF_stiff_B.Input23 = act_alfa_x_ID2;

  /* S-Function (bur_in): '<Root>/Input19' */
  pneutr2_reg_FF_stiff_B.Input19 = act_alfa_y_ID2;

  /* S-Function (bur_in): '<Root>/Input22' */
  pneutr2_reg_FF_stiff_B.Input22 = poradie_ID2;

  /* MATLAB Function: '<S196>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S196>/Constant'
   *  Constant: '<S196>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input3,
    pneutr2_reg_FF_stiff_B.Input5, pneutr2_reg_FF_stiff_B.Input23,
    pneutr2_reg_FF_stiff_B.Input19, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input22,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g);

  /* Sum: '<S197>/Sum6' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input23 -
    pneutr2_reg_FF_stiff_B.Input3;

  /* Math: '<S197>/Math Function' */
  rtb_MathFunction_o = rtb_MathFunction * rtb_MathFunction;

  /* Sum: '<S197>/Sum7' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input19 -
    pneutr2_reg_FF_stiff_B.Input5;

  /* Sum: '<S197>/Sum8' incorporates:
   *  Math: '<S197>/Math Function1'
   *  Sqrt: '<S197>/Sqrt'
   *  Sum: '<S197>/Sum5'
   */
  rtb_MathFunction = sqrtf(rtb_MathFunction * rtb_MathFunction +
    rtb_MathFunction_o) - pneutr2_reg_FF_stiff_B.Input47;

  /* Switch: '<S197>/Switch' incorporates:
   *  Constant: '<S197>/Constant'
   *  Constant: '<S201>/cylinder height'
   *  Constant: '<S203>/cylinder height'
   *  Gain: '<S196>/Gain'
   *  Gain: '<S196>/Gain3'
   *  Sum: '<S201>/Sum'
   *  Sum: '<S203>/Sum'
   *  Sum: '<S9>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum4_o = (0.001F *
                  pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Blue_real -
                  0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Blue_ref - 0.16);
  } else {
    rtb_Sum4_o = 0.0;
  }

  /* End of Switch: '<S197>/Switch' */

  /* S-Function (bur_in): '<Root>/Input21' */
  pneutr2_reg_FF_stiff_B.Input21 = RESET_ID2;

  /* DiscreteIntegrator: '<S337>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_al = 0.0;
  }

  /* DiscreteIntegrator: '<S332>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kue = 0.0;
  }

  /* End of DiscreteIntegrator: '<S332>/Filter' */

  /* Product: '<S340>/NProd Out' incorporates:
   *  Constant: '<S9>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_nw = 0.0;

  /* Sum: '<S347>/Sum' incorporates:
   *  DiscreteIntegrator: '<S337>/Integrator'
   */
  rtb_Sum_c = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_al +
    pneutr2_reg_FF_stiff_B.NProdOut_nw;

  /* Switch: '<S345>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Constant: '<S9>/min_sat'
   *  RelationalOperator: '<S345>/LowerRelop1'
   *  RelationalOperator: '<S345>/UpperRelop'
   *  Sum: '<S8>/Sum3'
   *  Sum: '<S9>/Sum4'
   *  Switch: '<S345>/Switch'
   */
  if (rtb_Sum_c > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_c = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_c < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S345>/Switch' incorporates:
     *  Constant: '<S9>/min_sat'
     *  Sum: '<S9>/Sum4'
     */
    rtb_Sum_c = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S345>/Switch2' */

  /* MATLAB Function: '<Root>/ID2' incorporates:
   *  Constant: '<Root>/Constant13'
   *  Constant: '<Root>/Constant2'
   *  Constant: '<Root>/Constant8'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input3,
    pneutr2_reg_FF_stiff_B.Input5, pneutr2_reg_FF_stiff_ConstP.Constant2_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant8_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant13_Value, pneutr2_reg_FF_stiff_B.Input15,
    &pneutr2_reg_FF_stiff_B.sf_ID2);

  /* Gain: '<S35>/Gain1' incorporates:
   *  Sum: '<Root>/Sum3'
   */
  pneutr2_reg_FF_stiff_B.Gain1_p = (real32_T)(rtb_Sum_c +
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak1);

  /* MATLAB Function: '<S35>/MATLAB Function' incorporates:
   *  Gain: '<S35>/Gain2'
   *  Gain: '<S35>/Gain3'
   *  UnitDelay: '<S35>/Unit Delay'
   *  UnitDelay: '<S35>/Unit Delay1'
   *  UnitDelay: '<S35>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_p,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_a,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_l, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jw,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f);

  /* Gain: '<S35>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_lc = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.out;

  /* S-Function (bur_out): '<Root>/Output3' */
  Blue_tab_ID2 = pneutr2_reg_FF_stiff_B.Gain6_lc;

  /* Switch: '<S38>/Switch1' incorporates:
   *  Constant: '<S38>/Constant'
   *  Constant: '<S43>/cylinder height'
   *  Constant: '<S46>/cylinder height'
   *  Gain: '<S37>/Gain2'
   *  Gain: '<S37>/Gain5'
   *  Sum: '<S43>/Sum'
   *  Sum: '<S46>/Sum'
   *  Sum: '<S8>/Sum1'
   */
  if (rtb_Sum8 >= 0.0F) {
    rtb_Sum_c = (0.001F *
                 pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Yellow_real -
                 0.16) - (0.001F *
                          pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Yellow_ref
                          - 0.16);
  } else {
    rtb_Sum_c = 0.0;
  }

  /* End of Switch: '<S38>/Switch1' */

  /* DiscreteIntegrator: '<S80>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_f = 0.0;
  }

  /* DiscreteIntegrator: '<S75>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input17 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input17 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_m = 0.0;
  }

  /* End of DiscreteIntegrator: '<S75>/Filter' */

  /* Product: '<S83>/NProd Out' incorporates:
   *  Constant: '<S8>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_fl = 0.0;

  /* Sum: '<S90>/Sum' incorporates:
   *  DiscreteIntegrator: '<S80>/Integrator'
   */
  rtb_Sum_ek = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_f +
    pneutr2_reg_FF_stiff_B.NProdOut_fl;

  /* Switch: '<S88>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S88>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_ek <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S88>/Switch' incorporates:
     *  Constant: '<S8>/min_sat'
     *  RelationalOperator: '<S88>/UpperRelop'
     *  Sum: '<S8>/Sum4'
     */
    if (rtb_Sum_ek < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Switch2_i = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Switch2_i = rtb_Sum_ek;
    }

    /* End of Switch: '<S88>/Switch' */
  }

  /* End of Switch: '<S88>/Switch2' */

  /* Gain: '<S33>/Gain1' incorporates:
   *  Sum: '<Root>/Sum1'
   */
  pneutr2_reg_FF_stiff_B.Gain1_h = (real32_T)(rtb_Switch2_i +
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak2);

  /* MATLAB Function: '<S33>/MATLAB Function' incorporates:
   *  Gain: '<S33>/Gain2'
   *  Gain: '<S33>/Gain3'
   *  UnitDelay: '<S33>/Unit Delay'
   *  UnitDelay: '<S33>/Unit Delay1'
   *  UnitDelay: '<S33>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_h,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_j,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ly, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_l,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i);

  /* Gain: '<S33>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_js = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.out;

  /* S-Function (bur_out): '<Root>/Output4' */
  Green_tab_ID1 = pneutr2_reg_FF_stiff_B.Gain6_js;

  /* Switch: '<S197>/Switch2' incorporates:
   *  Constant: '<S197>/Constant'
   *  Constant: '<S204>/cylinder height'
   *  Constant: '<S206>/cylinder height'
   *  Gain: '<S196>/Gain1'
   *  Gain: '<S196>/Gain4'
   *  Sum: '<S204>/Sum'
   *  Sum: '<S206>/Sum'
   *  Sum: '<S9>/Sum2'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Switch2_i = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Green_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Green_ref - 0.16);
  } else {
    rtb_Switch2_i = 0.0;
  }

  /* End of Switch: '<S197>/Switch2' */

  /* DiscreteIntegrator: '<S288>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_e = 0.0;
  }

  /* DiscreteIntegrator: '<S283>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_o = 0.0;
  }

  /* End of DiscreteIntegrator: '<S283>/Filter' */

  /* Product: '<S291>/NProd Out' incorporates:
   *  Constant: '<S9>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_p = 0.0;

  /* Sum: '<S298>/Sum' incorporates:
   *  DiscreteIntegrator: '<S288>/Integrator'
   */
  rtb_Sum4 = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_e +
    pneutr2_reg_FF_stiff_B.NProdOut_p;

  /* Switch: '<S296>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Constant: '<S9>/min_sat'
   *  RelationalOperator: '<S296>/LowerRelop1'
   *  RelationalOperator: '<S296>/UpperRelop'
   *  Sum: '<S8>/Sum3'
   *  Sum: '<S9>/Sum4'
   *  Switch: '<S296>/Switch'
   */
  if (rtb_Sum4 > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum4 = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum4 < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S296>/Switch' incorporates:
     *  Constant: '<S9>/min_sat'
     *  Sum: '<S9>/Sum4'
     */
    rtb_Sum4 = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S296>/Switch2' */

  /* Gain: '<S11>/Gain1' incorporates:
   *  Sum: '<Root>/Sum5'
   */
  pneutr2_reg_FF_stiff_B.Gain1_hr = (real32_T)(rtb_Sum4 +
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak3);

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  Gain: '<S11>/Gain2'
   *  Gain: '<S11>/Gain3'
   *  UnitDelay: '<S11>/Unit Delay'
   *  UnitDelay: '<S11>/Unit Delay1'
   *  UnitDelay: '<S11>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_hr,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_gr,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_na, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kh,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e);

  /* Gain: '<S11>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_i3 = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.out;

  /* S-Function (bur_out): '<Root>/Output5' */
  Yellow_tab_ID2 = pneutr2_reg_FF_stiff_B.Gain6_i3;

  /* Switch: '<S197>/Switch1' incorporates:
   *  Constant: '<S197>/Constant'
   *  Constant: '<S202>/cylinder height'
   *  Constant: '<S205>/cylinder height'
   *  Gain: '<S196>/Gain2'
   *  Gain: '<S196>/Gain5'
   *  Sum: '<S202>/Sum'
   *  Sum: '<S205>/Sum'
   *  Sum: '<S9>/Sum1'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Sum4 = (0.001F *
                pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Yellow_real -
                0.16) - (0.001F *
                         pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Yellow_ref
                         - 0.16);
  } else {
    rtb_Sum4 = 0.0;
  }

  /* End of Switch: '<S197>/Switch1' */

  /* DiscreteIntegrator: '<S239>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_hg = 0.0;
  }

  /* DiscreteIntegrator: '<S234>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input21 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input21 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_e = 0.0;
  }

  /* End of DiscreteIntegrator: '<S234>/Filter' */

  /* Product: '<S242>/NProd Out' incorporates:
   *  Constant: '<S9>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_mg = 0.0;

  /* Sum: '<S249>/Sum' incorporates:
   *  DiscreteIntegrator: '<S239>/Integrator'
   */
  rtb_Sum_ek = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_hg +
    pneutr2_reg_FF_stiff_B.NProdOut_mg;

  /* Switch: '<S247>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S247>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_ek <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S247>/Switch' incorporates:
     *  Constant: '<S9>/min_sat'
     *  RelationalOperator: '<S247>/UpperRelop'
     *  Sum: '<S9>/Sum4'
     */
    if (rtb_Sum_ek < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum4_b = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum4_b = rtb_Sum_ek;
    }

    /* End of Switch: '<S247>/Switch' */
  }

  /* End of Switch: '<S247>/Switch2' */

  /* Gain: '<S10>/Gain1' incorporates:
   *  Sum: '<Root>/Sum4'
   */
  pneutr2_reg_FF_stiff_B.Gain1_dw = (real32_T)(rtb_Sum4_b +
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak2);

  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  Gain: '<S10>/Gain2'
   *  Gain: '<S10>/Gain3'
   *  UnitDelay: '<S10>/Unit Delay'
   *  UnitDelay: '<S10>/Unit Delay1'
   *  UnitDelay: '<S10>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_dw,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_nj,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_d, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mz,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction);

  /* Gain: '<S10>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_bw = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.out;

  /* S-Function (bur_out): '<Root>/Output6' */
  Green_tab_ID2 = pneutr2_reg_FF_stiff_B.Gain6_bw;

  /* Sum: '<S25>/Sum3' incorporates:
   *  Constant: '<S8>/max_sat'
   *  Sum: '<S8>/Sum3'
   */
  rtb_Sum4_b = 5.0 - pneutr2_reg_FF_stiff_B.Input15;

  /* S-Function (bur_in): '<Root>/Input4' */
  pneutr2_reg_FF_stiff_B.Input4 = ref_alfa_x_ID3;

  /* S-Function (bur_in): '<Root>/Input6' */
  pneutr2_reg_FF_stiff_B.Input6 = ref_alfa_y_ID3;

  /* S-Function (bur_in): '<Root>/Input28' */
  pneutr2_reg_FF_stiff_B.Input28 = act_alfa_x_ID3;

  /* S-Function (bur_in): '<Root>/Input24' */
  pneutr2_reg_FF_stiff_B.Input24 = act_alfa_y_ID3;

  /* S-Function (bur_in): '<Root>/Input27' */
  pneutr2_reg_FF_stiff_B.Input27 = poradie_ID3;

  /* MATLAB Function: '<S528>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S528>/Constant'
   *  Constant: '<S528>/Constant1'
   */
  pneutr2_r_requestedalfa2deltaz1(pneutr2_reg_FF_stiff_B.Input4,
    pneutr2_reg_FF_stiff_B.Input6, pneutr2_reg_FF_stiff_B.Input28,
    pneutr2_reg_FF_stiff_B.Input24, 214.0, 160.0, pneutr2_reg_FF_stiff_B.Input27,
    &pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d);

  /* Sum: '<S529>/Sum6' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input28 -
    pneutr2_reg_FF_stiff_B.Input4;

  /* Math: '<S529>/Math Function' */
  rtb_Sum8 = rtb_MathFunction * rtb_MathFunction;

  /* Sum: '<S529>/Sum7' */
  rtb_MathFunction = pneutr2_reg_FF_stiff_B.Input24 -
    pneutr2_reg_FF_stiff_B.Input6;

  /* Sum: '<S529>/Sum8' incorporates:
   *  Math: '<S529>/Math Function1'
   *  Sqrt: '<S529>/Sqrt'
   *  Sum: '<S529>/Sum5'
   */
  rtb_MathFunction = sqrtf(rtb_MathFunction * rtb_MathFunction + rtb_Sum8) -
    pneutr2_reg_FF_stiff_B.Input47;

  /* S-Function (bur_in): '<Root>/Input26' */
  pneutr2_reg_FF_stiff_B.Input26 = RESET_ID3;

  /* DiscreteIntegrator: '<S669>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_mr = 0.0;
  }

  /* DiscreteIntegrator: '<S664>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_g = 0.0;
  }

  /* End of DiscreteIntegrator: '<S664>/Filter' */

  /* Product: '<S672>/NProd Out' incorporates:
   *  Constant: '<S25>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_l = 0.0;

  /* Sum: '<S679>/Sum' incorporates:
   *  DiscreteIntegrator: '<S669>/Integrator'
   */
  rtb_Sum_ek = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_mr +
    pneutr2_reg_FF_stiff_B.NProdOut_l;

  /* Switch: '<S677>/Switch2' incorporates:
   *  Constant: '<S25>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S677>/LowerRelop1'
   *  RelationalOperator: '<S677>/UpperRelop'
   *  Sum: '<S25>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S677>/Switch'
   */
  if (rtb_Sum_ek > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_ek = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_ek < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S677>/Switch' incorporates:
     *  Constant: '<S25>/min_sat'
     *  Sum: '<S25>/Sum4'
     */
    rtb_Sum_ek = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S677>/Switch2' */

  /* MATLAB Function: '<Root>/ID3' incorporates:
   *  Constant: '<Root>/Constant14'
   *  Constant: '<Root>/Constant4'
   *  Constant: '<Root>/Constant9'
   */
  pneutr2_reg_FF_stiff_ID1(pneutr2_reg_FF_stiff_B.Input4,
    pneutr2_reg_FF_stiff_B.Input6, pneutr2_reg_FF_stiff_ConstP.Constant4_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant9_Value,
    pneutr2_reg_FF_stiff_ConstP.Constant14_Value, pneutr2_reg_FF_stiff_B.Input15,
    &pneutr2_reg_FF_stiff_B.sf_ID3);

  /* Gain: '<S15>/Gain1' incorporates:
   *  Sum: '<Root>/Sum6'
   */
  pneutr2_reg_FF_stiff_B.Gain1_li = (real32_T)(rtb_Sum_ek +
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak1);

  /* MATLAB Function: '<S15>/MATLAB Function' incorporates:
   *  Gain: '<S15>/Gain2'
   *  Gain: '<S15>/Gain3'
   *  UnitDelay: '<S15>/Unit Delay'
   *  UnitDelay: '<S15>/Unit Delay1'
   *  UnitDelay: '<S15>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_li,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fe,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_iu, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_au,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k);

  /* Gain: '<S15>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_a2 = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.out;

  /* S-Function (bur_out): '<Root>/Output7' */
  Blue_tab_ID3 = pneutr2_reg_FF_stiff_B.Gain6_a2;

  /* DiscreteIntegrator: '<S620>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_i = 0.0;
  }

  /* DiscreteIntegrator: '<S615>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_dc = 0.0;
  }

  /* End of DiscreteIntegrator: '<S615>/Filter' */

  /* Product: '<S623>/NProd Out' incorporates:
   *  Constant: '<S25>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_oh = 0.0;

  /* Sum: '<S630>/Sum' incorporates:
   *  DiscreteIntegrator: '<S620>/Integrator'
   */
  rtb_Sum_ek = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_i +
    pneutr2_reg_FF_stiff_B.NProdOut_oh;

  /* Switch: '<S628>/Switch2' incorporates:
   *  Constant: '<S25>/min_sat'
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S628>/LowerRelop1'
   *  RelationalOperator: '<S628>/UpperRelop'
   *  Sum: '<S25>/Sum4'
   *  Sum: '<S8>/Sum3'
   *  Switch: '<S628>/Switch'
   */
  if (rtb_Sum_ek > 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    rtb_Sum_ek = 5.0 - pneutr2_reg_FF_stiff_B.Input15;
  } else if (rtb_Sum_ek < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S628>/Switch' incorporates:
     *  Constant: '<S25>/min_sat'
     *  Sum: '<S25>/Sum4'
     */
    rtb_Sum_ek = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
  }

  /* End of Switch: '<S628>/Switch2' */

  /* Gain: '<S17>/Gain1' incorporates:
   *  Sum: '<Root>/Sum8'
   */
  pneutr2_reg_FF_stiff_B.Gain1_hd = (real32_T)(rtb_Sum_ek +
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak3);

  /* MATLAB Function: '<S17>/MATLAB Function' incorporates:
   *  Gain: '<S17>/Gain2'
   *  Gain: '<S17>/Gain3'
   *  UnitDelay: '<S17>/Unit Delay'
   *  UnitDelay: '<S17>/Unit Delay1'
   *  UnitDelay: '<S17>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_hd,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fg,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j5, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j1,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d);

  /* Gain: '<S17>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_db = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.out;

  /* S-Function (bur_out): '<Root>/Output8' */
  Yellow_tab_ID3 = pneutr2_reg_FF_stiff_B.Gain6_db;

  /* DiscreteIntegrator: '<S571>/Integrator' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc == 1))) {
    pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ln = 0.0;
  }

  /* DiscreteIntegrator: '<S566>/Filter' */
  if (((pneutr2_reg_FF_stiff_B.Input26 > 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd <= 0)) ||
      ((pneutr2_reg_FF_stiff_B.Input26 <= 0.0F) &&
       (pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd == 1))) {
    pneutr2_reg_FF_stiff_DW.Filter_DSTATE_i = 0.0;
  }

  /* End of DiscreteIntegrator: '<S566>/Filter' */

  /* Product: '<S574>/NProd Out' incorporates:
   *  Constant: '<S25>/N'
   */
  pneutr2_reg_FF_stiff_B.NProdOut_d = 0.0;

  /* Sum: '<S581>/Sum' incorporates:
   *  DiscreteIntegrator: '<S571>/Integrator'
   */
  rtb_Sum_ek = pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ln +
    pneutr2_reg_FF_stiff_B.NProdOut_d;

  /* Switch: '<S579>/Switch2' incorporates:
   *  Constant: '<S8>/max_sat'
   *  RelationalOperator: '<S579>/LowerRelop1'
   *  Sum: '<S8>/Sum3'
   */
  if (rtb_Sum_ek <= 5.0 - pneutr2_reg_FF_stiff_B.Input15) {
    /* Switch: '<S579>/Switch' incorporates:
     *  Constant: '<S25>/min_sat'
     *  RelationalOperator: '<S579>/UpperRelop'
     *  Sum: '<S25>/Sum4'
     */
    if (rtb_Sum_ek < 0.0 - pneutr2_reg_FF_stiff_B.Input15) {
      rtb_Sum4_b = 0.0 - pneutr2_reg_FF_stiff_B.Input15;
    } else {
      rtb_Sum4_b = rtb_Sum_ek;
    }

    /* End of Switch: '<S579>/Switch' */
  }

  /* End of Switch: '<S579>/Switch2' */

  /* Gain: '<S16>/Gain1' incorporates:
   *  Sum: '<Root>/Sum7'
   */
  pneutr2_reg_FF_stiff_B.Gain1_ax = (real32_T)(rtb_Sum4_b +
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak2);

  /* MATLAB Function: '<S16>/MATLAB Function' incorporates:
   *  Gain: '<S16>/Gain2'
   *  Gain: '<S16>/Gain3'
   *  UnitDelay: '<S16>/Unit Delay'
   *  UnitDelay: '<S16>/Unit Delay1'
   *  UnitDelay: '<S16>/Unit Delay3'
   */
  pneutr2_reg_FF_s_MATLABFunction(pneutr2_reg_FF_stiff_B.Gain1_ax,
    pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d5,
    pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_c, (real_T)
    pneutr2_reg_FF_stiff_B.Input45, pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_c,
    (real_T)pneutr2_reg_FF_stiff_B.Input46,
    &pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b);

  /* Gain: '<S16>/Gain6' */
  pneutr2_reg_FF_stiff_B.Gain6_m = (real32_T)
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.out;

  /* S-Function (bur_out): '<Root>/Output9' */
  Green_tab_ID3 = pneutr2_reg_FF_stiff_B.Gain6_m;

  /* S-Function (bur_in): '<Root>/Input16' */
  pneutr2_reg_FF_stiff_B.Input16 = I_konstanta_ID1;

  /* S-Function (bur_in): '<Root>/Input20' */
  pneutr2_reg_FF_stiff_B.Input20 = I_konstanta_ID2;

  /* S-Function (bur_in): '<Root>/Input25' */
  pneutr2_reg_FF_stiff_B.Input25 = I_konstanta_ID3;

  /* S-Function (bur_in): '<Root>/Input30' */
  pneutr2_reg_FF_stiff_B.Input30 = I_konstanta_ID4;

  /* S-Function (bur_in): '<Root>/Input35' */
  pneutr2_reg_FF_stiff_B.Input35 = I_konstanta_ID5;

  /* S-Function (bur_in): '<Root>/Input40' */
  pneutr2_reg_FF_stiff_B.Input40 = I_konstanta_ID6;

  /* S-Function (bur_in): '<Root>/Input49' */
  pneutr2_reg_FF_stiff_B.Input49 = I_konstanta_ID7;

  /* Product: '<S77>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut = rtb_Sum_c * pneutr2_reg_FF_stiff_B.Input16;

  /* Product: '<S126>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_h = rtb_Sum_ai *
    pneutr2_reg_FF_stiff_B.Input16;

  /* Product: '<S175>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_k = rtb_Switch_l1 *
    pneutr2_reg_FF_stiff_B.Input16;

  /* Product: '<S236>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_a = rtb_Sum4 * pneutr2_reg_FF_stiff_B.Input20;

  /* Product: '<S285>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_kt = rtb_Switch2_i *
    pneutr2_reg_FF_stiff_B.Input20;

  /* Product: '<S334>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_b = rtb_Sum4_o *
    pneutr2_reg_FF_stiff_B.Input20;

  /* Product: '<S405>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_f = rtb_Sum_lr *
    pneutr2_reg_FF_stiff_B.Input40;

  /* Product: '<S454>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_kp = rtb_Sum_jv *
    pneutr2_reg_FF_stiff_B.Input40;

  /* Product: '<S503>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_fx = rtb_Sum4_hu *
    pneutr2_reg_FF_stiff_B.Input40;

  /* Switch: '<S529>/Switch1' incorporates:
   *  Constant: '<S529>/Constant'
   *  Constant: '<S534>/cylinder height'
   *  Constant: '<S537>/cylinder height'
   *  Gain: '<S528>/Gain2'
   *  Gain: '<S528>/Gain5'
   *  Sum: '<S25>/Sum1'
   *  Sum: '<S534>/Sum'
   *  Sum: '<S537>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Switch2_i = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Yellow_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Yellow_ref - 0.16);
  } else {
    rtb_Switch2_i = 0.0;
  }

  /* Product: '<S568>/IProd Out' incorporates:
   *  Switch: '<S529>/Switch1'
   */
  pneutr2_reg_FF_stiff_B.IProdOut_kg = rtb_Switch2_i *
    pneutr2_reg_FF_stiff_B.Input25;

  /* Switch: '<S529>/Switch2' incorporates:
   *  Constant: '<S529>/Constant'
   *  Constant: '<S536>/cylinder height'
   *  Constant: '<S538>/cylinder height'
   *  Gain: '<S528>/Gain1'
   *  Gain: '<S528>/Gain4'
   *  Sum: '<S25>/Sum2'
   *  Sum: '<S536>/Sum'
   *  Sum: '<S538>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Switch2_i = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Green_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Green_ref - 0.16);
  } else {
    rtb_Switch2_i = 0.0;
  }

  /* Product: '<S617>/IProd Out' incorporates:
   *  Switch: '<S529>/Switch2'
   */
  pneutr2_reg_FF_stiff_B.IProdOut_c = rtb_Switch2_i *
    pneutr2_reg_FF_stiff_B.Input25;

  /* Switch: '<S529>/Switch' incorporates:
   *  Constant: '<S529>/Constant'
   *  Constant: '<S533>/cylinder height'
   *  Constant: '<S535>/cylinder height'
   *  Gain: '<S528>/Gain'
   *  Gain: '<S528>/Gain3'
   *  Sum: '<S25>/Sum'
   *  Sum: '<S533>/Sum'
   *  Sum: '<S535>/Sum'
   */
  if (rtb_MathFunction >= 0.0F) {
    rtb_Switch2_i = (0.001F *
                     pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Blue_real
                     - 0.16) - (0.001F *
      pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Blue_ref - 0.16);
  } else {
    rtb_Switch2_i = 0.0;
  }

  /* Product: '<S666>/IProd Out' incorporates:
   *  Switch: '<S529>/Switch'
   */
  pneutr2_reg_FF_stiff_B.IProdOut_d = rtb_Switch2_i *
    pneutr2_reg_FF_stiff_B.Input25;

  /* Product: '<S728>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_az = rtb_Sum_iu *
    pneutr2_reg_FF_stiff_B.Input49;

  /* Product: '<S777>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_fl = rtb_Sum_ce *
    pneutr2_reg_FF_stiff_B.Input49;

  /* Product: '<S826>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_g = rtb_Sum_l * pneutr2_reg_FF_stiff_B.Input49;

  /* Product: '<S888>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_h1 = rtb_Sum_lj *
    pneutr2_reg_FF_stiff_B.Input30;

  /* Product: '<S937>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_p = rtb_Sum_az *
    pneutr2_reg_FF_stiff_B.Input30;

  /* Product: '<S986>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_i = rtb_Switch_mc *
    pneutr2_reg_FF_stiff_B.Input30;

  /* Product: '<S1047>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_al = rtb_Sum4_l *
    pneutr2_reg_FF_stiff_B.Input35;

  /* Product: '<S1096>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_j = rtb_Sum * pneutr2_reg_FF_stiff_B.Input35;

  /* Product: '<S1145>/IProd Out' */
  pneutr2_reg_FF_stiff_B.IProdOut_n = rtb_Switch_ju *
    pneutr2_reg_FF_stiff_B.Input35;

  /* S-Function (bur_in): '<Root>/Input44' */
  pneutr2_reg_FF_stiff_B.Input44 = ref_linearny_posun;

  /* Lookup_n-D: '<S36>/z2pressure' incorporates:
   *  Constant: '<S36>/Constant18'
   *  Sum: '<S36>/Sum18'
   */
  pneutr2_reg_FF_stiff_B.z2pressure = look1_tf_binlcpw
    (pneutr2_reg_FF_stiff_B.Input44 + 118.39,
     pneutr2_reg_FF_stiff_ConstP.z2pressure_bp01Data,
     pneutr2_reg_FF_stiff_ConstP.z2pressure_tableData, 6U);

  /* S-Function (bur_out): '<Root>/Output19' */
  lin_pressure = pneutr2_reg_FF_stiff_B.z2pressure;
}

/* Model update function */
static void pneutr2_reg_FF_stiff_update(void)
{
  /* Update for DiscreteIntegrator: '<S178>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_k;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S178>/Integrator' */

  /* Update for DiscreteIntegrator: '<S173>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S173>/Filter' */

  /* Update for UnitDelay: '<S32>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE = pneutr2_reg_FF_stiff_B.Gain1;

  /* Update for UnitDelay: '<S32>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.step_count;

  /* Update for UnitDelay: '<S32>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.last_out;

  /* Update for DiscreteIntegrator: '<S989>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_p += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_i;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S989>/Integrator' */

  /* Update for DiscreteIntegrator: '<S984>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_h += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_h;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S984>/Filter' */

  /* Update for UnitDelay: '<S22>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_i = pneutr2_reg_FF_stiff_B.Gain1_d;

  /* Update for UnitDelay: '<S22>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.step_count;

  /* Update for UnitDelay: '<S22>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_k =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.last_out;

  /* Update for DiscreteIntegrator: '<S940>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_m += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_p;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S940>/Integrator' */

  /* Update for DiscreteIntegrator: '<S935>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_o;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S935>/Filter' */

  /* Update for UnitDelay: '<S24>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_l = pneutr2_reg_FF_stiff_B.Gain1_l;

  /* Update for UnitDelay: '<S24>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.step_count;

  /* Update for UnitDelay: '<S24>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_n =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.last_out;

  /* Update for DiscreteIntegrator: '<S1148>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_b += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_n;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1148>/Integrator' */

  /* Update for DiscreteIntegrator: '<S1143>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hm += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_a;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1143>/Filter' */

  /* Update for UnitDelay: '<S12>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lr = pneutr2_reg_FF_stiff_B.Gain1_c;

  /* Update for UnitDelay: '<S12>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_e =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.step_count;

  /* Update for UnitDelay: '<S12>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_g =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.last_out;

  /* Update for DiscreteIntegrator: '<S891>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_h += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_h1;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S891>/Integrator' */

  /* Update for DiscreteIntegrator: '<S886>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hx += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_k;
  if (pneutr2_reg_FF_stiff_B.Input31 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input31 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S886>/Filter' */

  /* Update for UnitDelay: '<S23>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_n = pneutr2_reg_FF_stiff_B.Gain1_a;

  /* Update for UnitDelay: '<S23>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.step_count;

  /* Update for UnitDelay: '<S23>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_a =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.last_out;

  /* Update for DiscreteIntegrator: '<S1099>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_l += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_j;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1099>/Integrator' */

  /* Update for DiscreteIntegrator: '<S1094>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a4 += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_e;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1094>/Filter' */

  /* Update for UnitDelay: '<S14>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_m = pneutr2_reg_FF_stiff_B.Gain1_k;

  /* Update for UnitDelay: '<S14>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_m =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.step_count;

  /* Update for UnitDelay: '<S14>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.last_out;

  /* Update for DiscreteIntegrator: '<S1050>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_a += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_al;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1050>/Integrator' */

  /* Update for DiscreteIntegrator: '<S1045>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_c += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_f;
  if (pneutr2_reg_FF_stiff_B.Input36 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input36 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S1045>/Filter' */

  /* Update for UnitDelay: '<S13>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_g = pneutr2_reg_FF_stiff_B.Gain1_kh;

  /* Update for UnitDelay: '<S13>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a5 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.step_count;

  /* Update for UnitDelay: '<S13>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p4 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.last_out;

  /* Update for DiscreteIntegrator: '<S506>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_lu += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_fx;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S506>/Integrator' */

  /* Update for DiscreteIntegrator: '<S501>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_p += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_ay;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S501>/Filter' */

  /* Update for UnitDelay: '<S18>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_b = pneutr2_reg_FF_stiff_B.Gain1_e;

  /* Update for UnitDelay: '<S18>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.step_count;

  /* Update for UnitDelay: '<S18>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kl =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.last_out;

  /* Update for DiscreteIntegrator: '<S457>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_bw += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_kp;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S457>/Integrator' */

  /* Update for DiscreteIntegrator: '<S452>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_pq += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_n;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S452>/Filter' */

  /* Update for UnitDelay: '<S21>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d = pneutr2_reg_FF_stiff_B.Gain1_k0;

  /* Update for UnitDelay: '<S21>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g1 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.step_count;

  /* Update for UnitDelay: '<S21>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_m =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.last_out;

  /* Update for DiscreteIntegrator: '<S408>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_pa += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_f;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S408>/Integrator' */

  /* Update for DiscreteIntegrator: '<S403>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_k += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_ol;
  if (pneutr2_reg_FF_stiff_B.Input41 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input41 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S403>/Filter' */

  /* Update for UnitDelay: '<S19>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_le = pneutr2_reg_FF_stiff_B.Gain1_b;

  /* Update for UnitDelay: '<S19>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_i =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.step_count;

  /* Update for UnitDelay: '<S19>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_ny =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.last_out;

  /* Update for DiscreteIntegrator: '<S129>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_o += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_h;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S129>/Integrator' */

  /* Update for DiscreteIntegrator: '<S124>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kg += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_m;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S124>/Filter' */

  /* Update for UnitDelay: '<S34>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_f = pneutr2_reg_FF_stiff_B.Gain1_g;

  /* Update for UnitDelay: '<S34>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k2 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.step_count;

  /* Update for UnitDelay: '<S34>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.last_out;

  /* Update for DiscreteIntegrator: '<S829>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ah += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_g;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S829>/Integrator' */

  /* Update for DiscreteIntegrator: '<S824>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_d += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_b;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S824>/Filter' */

  /* Update for UnitDelay: '<S31>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_ie = pneutr2_reg_FF_stiff_B.Gain1_o;

  /* Update for UnitDelay: '<S31>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ep =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.step_count;

  /* Update for UnitDelay: '<S31>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mm =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.last_out;

  /* Update for DiscreteIntegrator: '<S780>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_j += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_fl;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S780>/Integrator' */

  /* Update for DiscreteIntegrator: '<S775>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_ku += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_nr;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S775>/Filter' */

  /* Update for UnitDelay: '<S28>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_h = pneutr2_reg_FF_stiff_B.Gain1_j;

  /* Update for UnitDelay: '<S28>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_n =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.step_count;

  /* Update for UnitDelay: '<S28>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jk =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.last_out;

  /* Update for DiscreteIntegrator: '<S731>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_aj += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_az;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S731>/Integrator' */

  /* Update for DiscreteIntegrator: '<S726>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_f += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_kv;
  if (pneutr2_reg_FF_stiff_B.Input50 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input50 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S726>/Filter' */

  /* Update for UnitDelay: '<S26>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lg = pneutr2_reg_FF_stiff_B.Gain1_gu;

  /* Update for UnitDelay: '<S26>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_mp =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.step_count;

  /* Update for UnitDelay: '<S26>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_o =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.last_out;

  /* Update for DiscreteIntegrator: '<S337>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_al += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_b;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S337>/Integrator' */

  /* Update for DiscreteIntegrator: '<S332>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kue += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_nw;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S332>/Filter' */

  /* Update for UnitDelay: '<S35>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_a = pneutr2_reg_FF_stiff_B.Gain1_p;

  /* Update for UnitDelay: '<S35>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_l =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.step_count;

  /* Update for UnitDelay: '<S35>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jw =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.last_out;

  /* Update for DiscreteIntegrator: '<S80>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_f += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S80>/Integrator' */

  /* Update for DiscreteIntegrator: '<S75>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_m += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_fl;
  if (pneutr2_reg_FF_stiff_B.Input17 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input17 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S75>/Filter' */

  /* Update for UnitDelay: '<S33>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_j = pneutr2_reg_FF_stiff_B.Gain1_h;

  /* Update for UnitDelay: '<S33>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ly =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.step_count;

  /* Update for UnitDelay: '<S33>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_l =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.last_out;

  /* Update for DiscreteIntegrator: '<S288>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_e += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_kt;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S288>/Integrator' */

  /* Update for DiscreteIntegrator: '<S283>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_o += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_p;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S283>/Filter' */

  /* Update for UnitDelay: '<S11>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_gr = pneutr2_reg_FF_stiff_B.Gain1_hr;

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_na =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.step_count;

  /* Update for UnitDelay: '<S11>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kh =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.last_out;

  /* Update for DiscreteIntegrator: '<S239>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_hg += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_a;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S239>/Integrator' */

  /* Update for DiscreteIntegrator: '<S234>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_e += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_mg;
  if (pneutr2_reg_FF_stiff_B.Input21 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input21 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S234>/Filter' */

  /* Update for UnitDelay: '<S10>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_nj = pneutr2_reg_FF_stiff_B.Gain1_dw;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_d =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.step_count;

  /* Update for UnitDelay: '<S10>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mz =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.last_out;

  /* Update for DiscreteIntegrator: '<S669>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_mr += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_d;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S669>/Integrator' */

  /* Update for DiscreteIntegrator: '<S664>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_g += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_l;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S664>/Filter' */

  /* Update for UnitDelay: '<S15>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fe = pneutr2_reg_FF_stiff_B.Gain1_li;

  /* Update for UnitDelay: '<S15>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_iu =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.step_count;

  /* Update for UnitDelay: '<S15>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_au =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.last_out;

  /* Update for DiscreteIntegrator: '<S620>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_i += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_c;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S620>/Integrator' */

  /* Update for DiscreteIntegrator: '<S615>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_dc += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_oh;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S615>/Filter' */

  /* Update for UnitDelay: '<S17>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fg = pneutr2_reg_FF_stiff_B.Gain1_hd;

  /* Update for UnitDelay: '<S17>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j5 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.step_count;

  /* Update for UnitDelay: '<S17>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j1 =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.last_out;

  /* Update for DiscreteIntegrator: '<S571>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ln += 0.016 *
    pneutr2_reg_FF_stiff_B.IProdOut_kg;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S571>/Integrator' */

  /* Update for DiscreteIntegrator: '<S566>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_i += 0.016 *
    pneutr2_reg_FF_stiff_B.NProdOut_d;
  if (pneutr2_reg_FF_stiff_B.Input26 > 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd = 1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 < 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd = -1;
  } else if (pneutr2_reg_FF_stiff_B.Input26 == 0.0F) {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd = 0;
  } else {
    pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S566>/Filter' */

  /* Update for UnitDelay: '<S16>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d5 = pneutr2_reg_FF_stiff_B.Gain1_ax;

  /* Update for UnitDelay: '<S16>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_c =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.step_count;

  /* Update for UnitDelay: '<S16>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_c =
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.last_out;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++pneutr2_reg_FF_stiff_M->Timing.clockTick0)) {
    ++pneutr2_reg_FF_stiff_M->Timing.clockTickH0;
  }

  pneutr2_reg_FF_stiff_M->Timing.t[0] =
    pneutr2_reg_FF_stiff_M->Timing.clockTick0 *
    pneutr2_reg_FF_stiff_M->Timing.stepSize0 +
    pneutr2_reg_FF_stiff_M->Timing.clockTickH0 *
    pneutr2_reg_FF_stiff_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
static void pneutr2_reg_FF_stiff_initialize(void)
{
  /* InitializeConditions for DiscreteIntegrator: '<S178>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S173>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState = 2;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE = 0.0;

  /* InitializeConditions for UnitDelay: '<S32>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S989>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_p = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_o = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S984>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_h = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_n = 2;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_i = 0.0;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g = 0.0;

  /* InitializeConditions for UnitDelay: '<S22>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_k = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S940>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_c = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S935>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_m = 2;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_l = 0.0;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a = 0.0;

  /* InitializeConditions for UnitDelay: '<S24>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_n = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S1148>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_b = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_on = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S1143>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hm = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_p = 2;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lr = 0.0;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_e = 0.0;

  /* InitializeConditions for UnitDelay: '<S12>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_g = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S891>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_h = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S886>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hx = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e = 2;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_n = 0.0;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j = 0.0;

  /* InitializeConditions for UnitDelay: '<S23>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_a = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S1099>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_l = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_i = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S1094>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a4 = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_g = 2;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_m = 0.0;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_m = 0.0;

  /* InitializeConditions for UnitDelay: '<S14>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S1050>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S1045>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_c = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_nf = 2;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_g = 0.0;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a5 = 0.0;

  /* InitializeConditions for UnitDelay: '<S13>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p4 = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S506>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_lu = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h1 = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S501>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_p = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_f = 2;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_b = 0.0;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k = 0.0;

  /* InitializeConditions for UnitDelay: '<S18>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kl = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S457>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_bw = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_j3 = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S452>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_pq = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_em = 2;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d = 0.0;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g1 = 0.0;

  /* InitializeConditions for UnitDelay: '<S21>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_m = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S408>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_pa = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_f = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S403>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_k = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_c = 2;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_le = 0.0;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_i = 0.0;

  /* InitializeConditions for UnitDelay: '<S19>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_ny = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S129>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_o = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_n = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S124>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kg = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_a = 2;

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_f = 0.0;

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k2 = 0.0;

  /* InitializeConditions for UnitDelay: '<S34>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S829>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ah = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_h3 = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S824>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_d = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_en = 2;

  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_ie = 0.0;

  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ep = 0.0;

  /* InitializeConditions for UnitDelay: '<S31>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mm = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S780>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_j = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_nv = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S775>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_ku = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e0 = 2;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_h = 0.0;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_n = 0.0;

  /* InitializeConditions for UnitDelay: '<S28>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jk = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S731>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_aj = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_na = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S726>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_f = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_h = 2;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lg = 0.0;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_mp = 0.0;

  /* InitializeConditions for UnitDelay: '<S26>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_o = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S337>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_al = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_l = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S332>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kue = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_mc = 2;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_a = 0.0;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_l = 0.0;

  /* InitializeConditions for UnitDelay: '<S35>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jw = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S80>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_f = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_il = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S75>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_hd = 2;

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_j = 0.0;

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ly = 0.0;

  /* InitializeConditions for UnitDelay: '<S33>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_l = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S288>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_e = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_p = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S283>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_o = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_gb = 2;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_gr = 0.0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_na = 0.0;

  /* InitializeConditions for UnitDelay: '<S11>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kh = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S239>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_hg = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S234>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_e = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_e4 = 2;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_nj = 0.0;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_d = 0.0;

  /* InitializeConditions for UnitDelay: '<S10>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mz = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S669>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_mr = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_b = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S664>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_g = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_b = 2;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fe = 0.0;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_iu = 0.0;

  /* InitializeConditions for UnitDelay: '<S15>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_au = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S620>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_bi = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S615>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_dc = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_k = 2;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fg = 0.0;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j5 = 0.0;

  /* InitializeConditions for UnitDelay: '<S17>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j1 = 0.0;

  /* InitializeConditions for DiscreteIntegrator: '<S571>/Integrator' */
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ln = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_PrevResetState_jc = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S566>/Filter' */
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_PrevResetState_cd = 2;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay1' */
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d5 = 0.0;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay' */
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_c = 0.0;

  /* InitializeConditions for UnitDelay: '<S16>/Unit Delay3' */
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_c = 0.0;
}

/* Model terminate function */
static void pneutr2_reg_FF_stiff_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pneutr2_reg_FF_stiff_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pneutr2_reg_FF_stiff_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  pneutr2_reg_FF_stiff_initialize();
}

void MdlTerminate(void)
{
  pneutr2_reg_FF_stiff_terminate();
}

/* Registration function */
RT_MODEL_pneutr2_reg_FF_stiff_T *pneutr2_reg_FF_stiff(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pneutr2_reg_FF_stiff_M, 0,
                sizeof(RT_MODEL_pneutr2_reg_FF_stiff_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pneutr2_reg_FF_stiff_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "pneutr2_reg_FF_stiff_M points to
       static memory which is guaranteed to be non-NULL" */
    pneutr2_reg_FF_stiff_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pneutr2_reg_FF_stiff_M->Timing.sampleTimes =
      (&pneutr2_reg_FF_stiff_M->Timing.sampleTimesArray[0]);
    pneutr2_reg_FF_stiff_M->Timing.offsetTimes =
      (&pneutr2_reg_FF_stiff_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pneutr2_reg_FF_stiff_M->Timing.sampleTimes[0] = (0.016);

    /* task offsets */
    pneutr2_reg_FF_stiff_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(pneutr2_reg_FF_stiff_M, &pneutr2_reg_FF_stiff_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pneutr2_reg_FF_stiff_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    pneutr2_reg_FF_stiff_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pneutr2_reg_FF_stiff_M, -1);
  pneutr2_reg_FF_stiff_M->Timing.stepSize0 = 0.016;
  pneutr2_reg_FF_stiff_M->solverInfoPtr = (&pneutr2_reg_FF_stiff_M->solverInfo);
  pneutr2_reg_FF_stiff_M->Timing.stepSize = (0.016);
  rtsiSetFixedStepSize(&pneutr2_reg_FF_stiff_M->solverInfo, 0.016);
  rtsiSetSolverMode(&pneutr2_reg_FF_stiff_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pneutr2_reg_FF_stiff_M->blockIO = ((void *) &pneutr2_reg_FF_stiff_B);

  {
    pneutr2_reg_FF_stiff_B.NProdOut = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1 = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_h = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_d = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_o = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_l = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_a = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_c = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_k = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_a = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_e = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_k = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_f = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_kh = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_ay = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_e = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_n = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_k0 = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_ol = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_b = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_m = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_g = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_b = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_o = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_nr = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_j = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_kv = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_gu = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_nw = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_p = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_fl = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_h = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_p = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_hr = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_mg = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_dw = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_l = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_li = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_oh = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_hd = 0.0;
    pneutr2_reg_FF_stiff_B.NProdOut_d = 0.0;
    pneutr2_reg_FF_stiff_B.Gain1_ax = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_h = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_k = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_a = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_kt = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_b = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_f = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_kp = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_fx = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_kg = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_c = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_d = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_az = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_fl = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_g = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_h1 = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_p = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_i = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_al = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_j = 0.0;
    pneutr2_reg_FF_stiff_B.IProdOut_n = 0.0;
    pneutr2_reg_FF_stiff_B.Input15 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input1 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input2 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input8 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input14 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input18 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input47 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input17 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input45 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input46 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input10 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input12 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input33 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input29 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input32 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input31 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_d = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_l = 0.0F;
    pneutr2_reg_FF_stiff_B.Input11 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input13 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input37 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input34 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input38 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input36 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_j = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_p = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_g = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_i = 0.0F;
    pneutr2_reg_FF_stiff_B.Input7 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input9 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input43 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input39 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input42 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input41 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_po = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_n = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_e = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_a = 0.0F;
    pneutr2_reg_FF_stiff_B.Input53 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input54 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input52 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input48 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input51 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input50 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_h = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_f = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_b = 0.0F;
    pneutr2_reg_FF_stiff_B.Input3 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input5 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input23 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input19 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input22 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input21 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_lc = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_js = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_i3 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_bw = 0.0F;
    pneutr2_reg_FF_stiff_B.Input4 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input6 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input28 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input24 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input27 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input26 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_a2 = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_db = 0.0F;
    pneutr2_reg_FF_stiff_B.Gain6_m = 0.0F;
    pneutr2_reg_FF_stiff_B.Input16 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input20 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input25 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input30 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input35 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input40 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input49 = 0.0F;
    pneutr2_reg_FF_stiff_B.Input44 = 0.0F;
    pneutr2_reg_FF_stiff_B.z2pressure = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_f.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_je.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_i.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_a.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_cd.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_j.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_a.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_gz.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_b.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_j.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_d.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_g.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pw.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_m.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_pm.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_n.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_n.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_h.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_d.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_b.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_k.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_l.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_c.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_p.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction_e.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.step_count = 0.0;
    pneutr2_reg_FF_stiff_B.sf_MATLABFunction.last_out = 0.0;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1_g.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Blue_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Green_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Yellow_real = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Blue_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Green_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_requestedalfa2deltaz1.Yellow_ref = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID7.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID6.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID5.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID4.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID3.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID2.tlak3 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak1 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak2 = 0.0F;
    pneutr2_reg_FF_stiff_B.sf_ID1.tlak3 = 0.0F;
  }

  /* states (dwork) */
  pneutr2_reg_FF_stiff_M->dwork = ((void *) &pneutr2_reg_FF_stiff_DW);
  (void) memset((void *)&pneutr2_reg_FF_stiff_DW, 0,
                sizeof(DW_pneutr2_reg_FF_stiff_T));
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_p = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_h = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_k = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_l = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_n = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_b = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hm = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lr = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_e = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_g = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_h = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_hx = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_n = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_l = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_a4 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_c = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_g = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_a5 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_p4 = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_lu = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_p = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_b = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kl = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_bw = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_pq = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_g1 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_pa = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_k = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_le = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_ny = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_o = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kg = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_f = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_k2 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ah = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_d = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_ie = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ep = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mm = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_j = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_ku = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_h = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_n = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jk = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_aj = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_f = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_lg = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_mp = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_o = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_al = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_kue = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_a = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_l = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_jw = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_f = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_m = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_j = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_ly = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_l = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_e = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_o = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_gr = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_na = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_kh = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_hg = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_e = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_nj = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_d = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_mz = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_mr = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_g = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fe = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_iu = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_au = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_dc = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_fg = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_j5 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_j1 = 0.0;
  pneutr2_reg_FF_stiff_DW.Integrator_DSTATE_ln = 0.0;
  pneutr2_reg_FF_stiff_DW.Filter_DSTATE_i = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay1_DSTATE_d5 = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay_DSTATE_c = 0.0;
  pneutr2_reg_FF_stiff_DW.UnitDelay3_DSTATE_c = 0.0;

  /* Initialize Sizes */
  pneutr2_reg_FF_stiff_M->Sizes.numContStates = (0);/* Number of continuous states */
  pneutr2_reg_FF_stiff_M->Sizes.numY = (0);/* Number of model outputs */
  pneutr2_reg_FF_stiff_M->Sizes.numU = (0);/* Number of model inputs */
  pneutr2_reg_FF_stiff_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pneutr2_reg_FF_stiff_M->Sizes.numSampTimes = (1);/* Number of sample times */
  pneutr2_reg_FF_stiff_M->Sizes.numBlocks = (888);/* Number of blocks */
  pneutr2_reg_FF_stiff_M->Sizes.numBlockIO = (265);/* Number of block outputs */
  return pneutr2_reg_FF_stiff_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
