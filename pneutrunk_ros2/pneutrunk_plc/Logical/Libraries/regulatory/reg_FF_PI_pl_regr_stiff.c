/*
 * reg_FF_PI_pl_regr_stiff.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "reg_FF_PI_pl_regr_stiff".
 *
 * Model version              : 1.154
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Jun 26 09:10:26 2023
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "reg_FF_PI_pl_regr_stiff.h"
#include "reg_FF_PI_pl_regr_stiff_private.h"

/* Forward declaration for local functions */
static real32_T reg_FF_PI_pl_regr_stiff_norm(const real32_T x[4], struct FF_PID_r_t* inst);

/* Function for MATLAB Function: '<S4>/requested alfa 2 deltaz1' */
static real32_T reg_FF_PI_pl_regr_stiff_norm(const real32_T x[4], struct FF_PID_r_t* inst)
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

/* Model step function */
void reg_FF_PI_pl_regr_stiff_step(RT_MODEL_reg_FF_PI_pl_regr_st_T *const
  reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst)
{
  B_reg_FF_PI_pl_regr_stiff_T *reg_FF_PI_pl_regr_stiff_B =
    reg_FF_PI_pl_regr_stiff_M->blockIO;
  DW_reg_FF_PI_pl_regr_stiff_T *reg_FF_PI_pl_regr_stiff_DW =
    reg_FF_PI_pl_regr_stiff_M->dwork;
  real_T rtb_MultiportSwitch[48];
  real_T rtb_MultiportSwitch1[48];
  real_T rtb_MultiportSwitch2[48];
  real_T Blue0_tmp[4];
  real_T Yellow0_tmp[4];
  real_T A1;
  real_T A2;
  real_T A3;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum_d;
  real_T rtb_Switch1;
  int32_T Tz23_tmp;
  int32_T Tz23_tmp_tmp;
  int32_T i;
  int32_T i_0;
  real32_T AlphaY_0[16];
  real32_T HTransform[16];
  real32_T HTransform_tmp_2[16];
  real32_T Tz23_0[16];
  real32_T tmp[8];
  real32_T rtb_MultiportSwitch_0[6];
  real32_T tmp_0[6];
  real32_T Blue0_tmp_0[4];
  real32_T Green0_tmp_tmp_0[4];
  real32_T Yellow0_tmp_0[4];
  real32_T AlphaX;
  real32_T AlphaY;
  real32_T HTransform_tmp;
  real32_T rtb_Blue_real;
  real32_T rtb_Blue_ref;
  real32_T rtb_Green_ref;
  real32_T rtb_MultiportSwitch2_0;
  real32_T rtb_MultiportSwitch_1;
  real32_T rtb_MultiportSwitch_2;
  real32_T rtb_MultiportSwitch_3;
  real32_T rtb_MultiportSwitch_4;
  real32_T rtb_MultiportSwitch_5;
  real32_T rtb_MultiportSwitch_6;
  real32_T rtb_Yellow_real;
  real32_T rtb_Yellow_ref;
  real32_T tmp_1;
  real32_T tmp_2;
  int8_T Tz23[16];
  int8_T Green0_tmp_tmp[4];
  int8_T HTransform_tmp_0[4];
  int8_T HTransform_tmp_1[4];

  /* S-Function (bur_in): '<Root>/Input15' */
  reg_FF_PI_pl_regr_stiff_B->Input15 = inst->stiffness_ff;

  /* S-Function (bur_in): '<Root>/Input1' */
  reg_FF_PI_pl_regr_stiff_B->Input1 = inst->ref_alfa_x;

  /* S-Function (bur_in): '<Root>/Input2' */
  reg_FF_PI_pl_regr_stiff_B->Input2 = inst->ref_alfa_y;

  /* S-Function (bur_in): '<Root>/Input3' */
  reg_FF_PI_pl_regr_stiff_B->Input3 = inst->real_alfa_x;

  /* S-Function (bur_in): '<Root>/Input4' */
  reg_FF_PI_pl_regr_stiff_B->Input4 = inst->real_alfa_y;

  /* S-Function (bur_in): '<Root>/Input16' */
  reg_FF_PI_pl_regr_stiff_B->Input16 = inst->poradie_vlnovcov;

  /* MATLAB Function: '<S4>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  AlphaX = reg_FF_PI_pl_regr_stiff_B->Input1 * 3.14159274F / 180.0F;
  AlphaY = -reg_FF_PI_pl_regr_stiff_B->Input2 * 3.14159274F / 180.0F;
  Tz23[2] = 0;
  Tz23[6] = 0;
  Tz23[10] = 1;
  Tz23[14] = 80;
  HTransform_tmp = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  rtb_Blue_real = sinf(AlphaX);
  AlphaX = cosf(AlphaX);
  AlphaY_0[0] = AlphaY;
  AlphaY_0[4] = 0.0F;
  AlphaY_0[8] = HTransform_tmp;
  AlphaY_0[12] = 0.0F;
  AlphaY_0[2] = -HTransform_tmp;
  AlphaY_0[6] = 0.0F;
  AlphaY_0[10] = AlphaY;
  AlphaY_0[14] = 0.0F;
  Tz23[0] = 1;
  Tz23[1] = 0;
  Tz23[3] = 0;
  HTransform_tmp_1[0] = 1;
  AlphaY_0[1] = 0.0F;
  AlphaY_0[3] = 0.0F;
  HTransform_tmp_0[0] = 0;
  Tz23[4] = 0;
  Tz23[5] = 1;
  Tz23[7] = 0;
  HTransform_tmp_1[1] = 0;
  AlphaY_0[5] = 1.0F;
  AlphaY_0[7] = 0.0F;
  HTransform_tmp_0[1] = 0;
  Tz23[8] = 0;
  Tz23[9] = 0;
  Tz23[11] = 0;
  HTransform_tmp_1[2] = 0;
  AlphaY_0[9] = 0.0F;
  AlphaY_0[11] = 0.0F;
  HTransform_tmp_0[2] = 0;
  Tz23[12] = 0;
  Tz23[13] = 0;
  Tz23[15] = 1;
  HTransform_tmp_1[3] = 0;
  AlphaY_0[13] = 0.0F;
  AlphaY_0[15] = 1.0F;
  HTransform_tmp_0[3] = 1;
  HTransform_tmp_2[1] = 0.0F;
  HTransform_tmp_2[5] = AlphaX;
  HTransform_tmp_2[9] = -rtb_Blue_real;
  HTransform_tmp_2[13] = 0.0F;
  HTransform_tmp_2[2] = 0.0F;
  HTransform_tmp_2[6] = rtb_Blue_real;
  HTransform_tmp_2[10] = AlphaX;
  HTransform_tmp_2[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      Tz23_0[Tz23_tmp] = 0.0F;
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp] * (real32_T)Tz23[i];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 1] * (real32_T)Tz23[i + 4];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 2] * (real32_T)Tz23[i + 8];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 3] * (real32_T)Tz23[i + 12];
    }

    Tz23_tmp_tmp = i << 2;
    HTransform_tmp_2[Tz23_tmp_tmp] = HTransform_tmp_1[i];
    HTransform_tmp_2[Tz23_tmp_tmp + 3] = HTransform_tmp_0[i];
  }

  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 3] * Tz23_0[i + 12];
    }

    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 3] * AlphaY_0[i + 12];
    }
  }

  Green0_tmp_tmp[0] = 107;
  Green0_tmp_tmp[1] = 0;
  Green0_tmp_tmp[2] = 0;
  Green0_tmp_tmp[3] = 1;
  Yellow0_tmp[0] = -53.5;
  Yellow0_tmp[1] = 92.664718204934928;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -53.5;
  Blue0_tmp[1] = -92.664718204934928;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  switch ((int32_T)reg_FF_PI_pl_regr_stiff_B->Input16) {
   case 1:
    for (i = 0; i < 4; i++) {
      HTransform_tmp = HTransform[i + 12];
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + HTransform_tmp);
      AlphaY = HTransform[i + 4];
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * -92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * 92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    break;

   case 2:
    for (i = 0; i < 4; i++) {
      HTransform_tmp = HTransform[i + 12];
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + HTransform_tmp);
      AlphaY = HTransform[i + 4];
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * 92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * -92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    break;

   case 3:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      HTransform_tmp = HTransform[i + 12];
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * -92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * 92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + HTransform_tmp);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    break;

   case 4:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 12];
      HTransform_tmp = HTransform[i + 4];
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform_tmp * -92.6647186F
        + HTransform[i] * -53.5F) + AlphaY);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + AlphaY);
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((HTransform_tmp *
        92.6647186F + HTransform[i] * -53.5F) + AlphaY);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    break;

   case 5:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 12];
      HTransform_tmp = HTransform[i + 4];
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((HTransform_tmp *
        92.6647186F + HTransform[i] * -53.5F) + AlphaY);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + AlphaY);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform_tmp * -92.6647186F
        + HTransform[i] * -53.5F) + AlphaY);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    break;

   default:
    for (i = 0; i < 4; i++) {
      AlphaY = HTransform[i + 4];
      HTransform_tmp = HTransform[i + 12];
      Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - ((AlphaY * 92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((AlphaY * -92.6647186F +
        HTransform[i] * -53.5F) + HTransform_tmp);
      Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] *
        107.0F + HTransform_tmp);
    }

    rtb_Green_ref = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
    rtb_Blue_ref = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
    rtb_Yellow_ref = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
    break;
  }

  AlphaX = reg_FF_PI_pl_regr_stiff_B->Input3 * 3.14159274F / 180.0F;
  AlphaY = -reg_FF_PI_pl_regr_stiff_B->Input4 * 3.14159274F / 180.0F;
  HTransform_tmp = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  rtb_Blue_real = sinf(AlphaX);
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
  HTransform_tmp_2[1] = 0.0F;
  HTransform_tmp_2[5] = AlphaX;
  HTransform_tmp_2[9] = -rtb_Blue_real;
  HTransform_tmp_2[13] = 0.0F;
  HTransform_tmp_2[2] = 0.0F;
  HTransform_tmp_2[6] = rtb_Blue_real;
  HTransform_tmp_2[10] = AlphaX;
  HTransform_tmp_2[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      Tz23_0[Tz23_tmp] = 0.0F;
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp] * (real32_T)Tz23[i];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 1] * (real32_T)Tz23[i + 4];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 2] * (real32_T)Tz23[i + 8];
      Tz23_0[Tz23_tmp] += AlphaY_0[Tz23_tmp_tmp + 3] * (real32_T)Tz23[i + 12];
    }

    Tz23_tmp_tmp = i << 2;
    HTransform_tmp_2[Tz23_tmp_tmp] = HTransform_tmp_1[i];
    HTransform_tmp_2[Tz23_tmp_tmp + 3] = HTransform_tmp_0[i];
  }

  Yellow0_tmp[0] = -53.5;
  Yellow0_tmp[1] = 92.664718204934928;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -53.5;
  Blue0_tmp[1] = -92.664718204934928;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_2[Tz23_tmp_tmp + 3] * Tz23_0[i + 12];
    }

    AlphaY = 0.0F;
    HTransform_tmp = 0.0F;
    rtb_Blue_real = 0.0F;
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 3] * AlphaY_0[i + 12];
      AlphaY += HTransform[Tz23_tmp] * (real32_T)Green0_tmp_tmp[i_0];
      HTransform_tmp += HTransform[Tz23_tmp] * (real32_T)Blue0_tmp[i_0];
      rtb_Blue_real += HTransform[Tz23_tmp] * (real32_T)Yellow0_tmp[i_0];
    }

    Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - AlphaY;
    Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - HTransform_tmp;
    Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - rtb_Blue_real;
  }

  HTransform_tmp = reg_FF_PI_pl_regr_stiff_norm(Green0_tmp_tmp_0, inst);
  AlphaX = HTransform_tmp;
  AlphaY = reg_FF_PI_pl_regr_stiff_norm(Blue0_tmp_0, inst);
  rtb_Blue_real = AlphaY;
  rtb_Yellow_real = reg_FF_PI_pl_regr_stiff_norm(Yellow0_tmp_0, inst);
  switch ((int32_T)reg_FF_PI_pl_regr_stiff_B->Input16) {
   case 1:
    break;

   case 2:
    rtb_Blue_real = rtb_Yellow_real;
    rtb_Yellow_real = AlphaY;
    break;

   case 3:
    AlphaX = AlphaY;
    rtb_Blue_real = rtb_Yellow_real;
    rtb_Yellow_real = HTransform_tmp;
    break;

   case 4:
    rtb_Green_ref = AlphaY;
    rtb_Blue_ref = HTransform_tmp;
    rtb_Yellow_ref = rtb_Yellow_real;
    break;

   case 5:
    AlphaX = rtb_Yellow_real;
    rtb_Blue_real = HTransform_tmp;
    rtb_Yellow_real = AlphaY;
    break;

   default:
    AlphaX = rtb_Yellow_real;
    rtb_Yellow_real = HTransform_tmp;
    break;
  }

  /* End of MATLAB Function: '<S4>/requested alfa 2 deltaz1' */

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S10>/cylinder height'
   *  Constant: '<S8>/cylinder height'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain3'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S8>/Sum'
   */
  A2 = (0.001F * rtb_Blue_real - 0.16) - (0.001F * rtb_Blue_ref - 0.16);

  /* S-Function (bur_in): '<Root>/Input11' */
  reg_FF_PI_pl_regr_stiff_B->Input11 = inst->P_parameter;

  /* S-Function (bur_in): '<Root>/Input5' */
  reg_FF_PI_pl_regr_stiff_B->Input5 = inst->reset_PID_blue;

  /* DiscreteIntegrator: '<S144>/Integrator' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input5 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input13' */
  reg_FF_PI_pl_regr_stiff_B->Input13 = inst->D_parameter;

  /* DiscreteIntegrator: '<S139>/Filter' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input5 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input14' */
  reg_FF_PI_pl_regr_stiff_B->Input14 = inst->N_parameter;

  /* Product: '<S147>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S139>/Filter'
   *  Product: '<S138>/DProd Out'
   *  Sum: '<S139>/SumD'
   */
  A1 = (A2 * reg_FF_PI_pl_regr_stiff_B->Input13 -
        reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE) *
    reg_FF_PI_pl_regr_stiff_B->Input14;

  /* Switch: '<Root>/Switch2' */
  if (reg_FF_PI_pl_regr_stiff_B->Input5 > 0.0F) {
    /* Sum: '<S154>/Sum' incorporates:
     *  DiscreteIntegrator: '<S144>/Integrator'
     *  Product: '<S149>/PProd Out'
     */
    A3 = (A2 * reg_FF_PI_pl_regr_stiff_B->Input11 +
          reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE) + A1;

    /* Switch: '<S152>/Switch2' incorporates:
     *  Constant: '<S2>/max_sat'
     *  Constant: '<S2>/min_sat'
     *  RelationalOperator: '<S152>/LowerRelop1'
     *  RelationalOperator: '<S152>/UpperRelop'
     *  Sum: '<S2>/Sum3'
     *  Sum: '<S2>/Sum4'
     *  Switch: '<S152>/Switch'
     */
    if (A3 > 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      rtb_Switch1 = 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    } else if (A3 < 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      /* Switch: '<S152>/Switch' incorporates:
       *  Constant: '<S2>/min_sat'
       *  Sum: '<S2>/Sum4'
       */
      rtb_Switch1 = 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    } else {
      rtb_Switch1 = A3;
    }

    /* End of Switch: '<S152>/Switch2' */
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* S-Function (bur_in): '<Root>/Input17' */
  reg_FF_PI_pl_regr_stiff_B->Input17 = inst->platform_ID;

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   */
  switch ((int32_T)reg_FF_PI_pl_regr_stiff_B->Input17) {
   case 1:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant2_Value[i];
    }
    break;

   case 3:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant4_Value[i];
    }
    break;

   case 4:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled3[i];
    }
    break;

   case 5:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled3[i];
    }
    break;

   default:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled3[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* MultiPortSwitch: '<S1>/Multiport Switch1' incorporates:
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant8'
   *  Constant: '<S1>/Constant9'
   */
  switch ((int32_T)reg_FF_PI_pl_regr_stiff_B->Input17) {
   case 1:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant1_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant8_Value[i];
    }
    break;

   case 3:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant9_Value[i];
    }
    break;

   case 4:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled1[i];
    }
    break;

   case 5:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled1[i];
    }
    break;

   default:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch1[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled1[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch1' */

  /* MultiPortSwitch: '<S1>/Multiport Switch2' incorporates:
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant14'
   *  Constant: '<S1>/Constant15'
   *  Constant: '<S1>/Constant16'
   *  Constant: '<S1>/Constant17'
   *  Constant: '<S1>/Constant3'
   */
  switch ((int32_T)reg_FF_PI_pl_regr_stiff_B->Input17) {
   case 1:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] = reg_FF_PI_pl_regr_stiff_ConstP.Constant3_Value[i];
    }
    break;

   case 2:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] =
        reg_FF_PI_pl_regr_stiff_ConstP.Constant13_Value[i];
    }
    break;

   case 3:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] =
        reg_FF_PI_pl_regr_stiff_ConstP.Constant14_Value[i];
    }
    break;

   case 4:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled2[i];
    }
    break;

   case 5:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled2[i];
    }
    break;

   default:
    for (i = 0; i < 48; i++) {
      rtb_MultiportSwitch2[i] = reg_FF_PI_pl_regr_stiff_ConstP.pooled2[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch2' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  MultiPortSwitch: '<S1>/Multiport Switch'
   */
  AlphaY = powf(reg_FF_PI_pl_regr_stiff_B->Input15, 7.0F);
  tmp[0] = AlphaY;
  HTransform_tmp = powf(reg_FF_PI_pl_regr_stiff_B->Input15, 6.0F);
  tmp[1] = HTransform_tmp;
  rtb_Blue_real = powf(reg_FF_PI_pl_regr_stiff_B->Input15, 5.0F);
  tmp[2] = rtb_Blue_real;
  rtb_Blue_ref = powf(reg_FF_PI_pl_regr_stiff_B->Input15, 4.0F);
  tmp[3] = rtb_Blue_ref;
  tmp_1 = powf(reg_FF_PI_pl_regr_stiff_B->Input15, 3.0F);
  tmp[4] = tmp_1;
  tmp_2 = reg_FF_PI_pl_regr_stiff_B->Input15 *
    reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_1 += (real32_T)rtb_MultiportSwitch[6 * i] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_2 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_2 += (real32_T)rtb_MultiportSwitch[6 * i + 1] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_3 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_3 += (real32_T)rtb_MultiportSwitch[6 * i + 2] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_4 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_4 += (real32_T)rtb_MultiportSwitch[6 * i + 3] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_5 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_5 += (real32_T)rtb_MultiportSwitch[6 * i + 4] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_6 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_6 += (real32_T)rtb_MultiportSwitch[6 * i + 5] * tmp[i];
  }

  rtb_MultiportSwitch_0[0] = rtb_MultiportSwitch_1;
  rtb_MultiportSwitch_0[1] = rtb_MultiportSwitch_2;
  rtb_MultiportSwitch_0[2] = rtb_MultiportSwitch_3;
  rtb_MultiportSwitch_0[3] = rtb_MultiportSwitch_4;
  rtb_MultiportSwitch_0[4] = rtb_MultiportSwitch_5;
  rtb_MultiportSwitch_0[5] = rtb_MultiportSwitch_6;
  tmp_0[0] = 1.0F;
  tmp_0[1] = reg_FF_PI_pl_regr_stiff_B->Input1;
  tmp_0[2] = reg_FF_PI_pl_regr_stiff_B->Input2;
  rtb_MultiportSwitch_2 = reg_FF_PI_pl_regr_stiff_B->Input1 *
    reg_FF_PI_pl_regr_stiff_B->Input1;
  tmp_0[3] = rtb_MultiportSwitch_2;
  rtb_MultiportSwitch_3 = reg_FF_PI_pl_regr_stiff_B->Input1 *
    reg_FF_PI_pl_regr_stiff_B->Input2;
  tmp_0[4] = rtb_MultiportSwitch_3;
  rtb_MultiportSwitch_4 = reg_FF_PI_pl_regr_stiff_B->Input2 *
    reg_FF_PI_pl_regr_stiff_B->Input2;
  tmp_0[5] = rtb_MultiportSwitch_4;
  rtb_MultiportSwitch_1 = 0.0F;
  for (i = 0; i < 6; i++) {
    rtb_MultiportSwitch_1 += rtb_MultiportSwitch_0[i] * tmp_0[i];
  }

  /* Sum: '<Root>/Sum' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  reg_FF_PI_pl_regr_stiff_B->Sum = (real32_T)(rtb_Switch1 +
    rtb_MultiportSwitch_1);

  /* S-Function (bur_out): '<Root>/Output1' */
  inst->Blue_tab = reg_FF_PI_pl_regr_stiff_B->Sum;

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<S11>/cylinder height'
   *  Constant: '<S13>/cylinder height'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain4'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S13>/Sum'
   */
  rtb_Sum2 = (0.001F * AlphaX - 0.16) - (0.001F * rtb_Green_ref - 0.16);

  /* S-Function (bur_in): '<Root>/Input7' */
  reg_FF_PI_pl_regr_stiff_B->Input7 = inst->reset_PID_green;

  /* DiscreteIntegrator: '<S95>/Integrator' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input7 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_o = 0.0;
  }

  /* DiscreteIntegrator: '<S90>/Filter' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input7 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_f = 0.0;
  }

  /* Product: '<S98>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Product: '<S89>/DProd Out'
   *  Sum: '<S90>/SumD'
   */
  A3 = (rtb_Sum2 * reg_FF_PI_pl_regr_stiff_B->Input13 -
        reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_f) *
    reg_FF_PI_pl_regr_stiff_B->Input14;

  /* Switch: '<Root>/Switch' */
  if (reg_FF_PI_pl_regr_stiff_B->Input7 > 0.0F) {
    /* Sum: '<S105>/Sum' incorporates:
     *  DiscreteIntegrator: '<S95>/Integrator'
     *  Product: '<S100>/PProd Out'
     */
    rtb_Sum_d = (rtb_Sum2 * reg_FF_PI_pl_regr_stiff_B->Input11 +
                 reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_o) + A3;

    /* Switch: '<S103>/Switch2' incorporates:
     *  Constant: '<S2>/max_sat'
     *  Constant: '<S2>/min_sat'
     *  RelationalOperator: '<S103>/LowerRelop1'
     *  RelationalOperator: '<S103>/UpperRelop'
     *  Sum: '<S2>/Sum3'
     *  Sum: '<S2>/Sum4'
     *  Switch: '<S103>/Switch'
     */
    if (rtb_Sum_d > 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      rtb_Switch1 = 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    } else if (rtb_Sum_d < 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      /* Switch: '<S103>/Switch' incorporates:
       *  Constant: '<S2>/min_sat'
       *  Sum: '<S2>/Sum4'
       */
      rtb_Switch1 = 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    } else {
      rtb_Switch1 = rtb_Sum_d;
    }

    /* End of Switch: '<S103>/Switch2' */
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  MultiPortSwitch: '<S1>/Multiport Switch2'
   */
  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  AlphaX = 0.0F;
  for (i = 0; i < 8; i++) {
    AlphaX += (real32_T)rtb_MultiportSwitch2[6 * i] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_Green_ref = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_Green_ref += (real32_T)rtb_MultiportSwitch2[6 * i + 1] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_1 += (real32_T)rtb_MultiportSwitch2[6 * i + 2] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_5 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_5 += (real32_T)rtb_MultiportSwitch2[6 * i + 3] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_6 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_6 += (real32_T)rtb_MultiportSwitch2[6 * i + 4] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch2_0 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch2_0 += (real32_T)rtb_MultiportSwitch2[6 * i + 5] * tmp[i];
  }

  rtb_MultiportSwitch_0[0] = AlphaX;
  rtb_MultiportSwitch_0[1] = rtb_Green_ref;
  rtb_MultiportSwitch_0[2] = rtb_MultiportSwitch_1;
  rtb_MultiportSwitch_0[3] = rtb_MultiportSwitch_5;
  rtb_MultiportSwitch_0[4] = rtb_MultiportSwitch_6;
  rtb_MultiportSwitch_0[5] = rtb_MultiportSwitch2_0;
  tmp_0[0] = 1.0F;
  tmp_0[1] = reg_FF_PI_pl_regr_stiff_B->Input1;
  tmp_0[2] = reg_FF_PI_pl_regr_stiff_B->Input2;
  tmp_0[3] = rtb_MultiportSwitch_2;
  tmp_0[4] = rtb_MultiportSwitch_3;
  tmp_0[5] = rtb_MultiportSwitch_4;
  AlphaX = 0.0F;
  for (i = 0; i < 6; i++) {
    AlphaX += rtb_MultiportSwitch_0[i] * tmp_0[i];
  }

  /* Sum: '<Root>/Sum2' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  reg_FF_PI_pl_regr_stiff_B->Sum2 = (real32_T)(rtb_Switch1 + AlphaX);

  /* S-Function (bur_out): '<Root>/Output2' */
  inst->Yellow_tab = reg_FF_PI_pl_regr_stiff_B->Sum2;

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S12>/cylinder height'
   *  Constant: '<S9>/cylinder height'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain5'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sum1 = (0.001F * rtb_Yellow_real - 0.16) - (0.001F * rtb_Yellow_ref - 0.16);

  /* S-Function (bur_in): '<Root>/Input6' */
  reg_FF_PI_pl_regr_stiff_B->Input6 = inst->reset_PID_yellow;

  /* DiscreteIntegrator: '<S46>/Integrator' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input6 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_i = 0.0;
  }

  /* DiscreteIntegrator: '<S41>/Filter' */
  if ((reg_FF_PI_pl_regr_stiff_B->Input6 <= 0.0F) &&
      (reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h == 1)) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_a = 0.0;
  }

  /* Product: '<S49>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S41>/Filter'
   *  Product: '<S40>/DProd Out'
   *  Sum: '<S41>/SumD'
   */
  rtb_Sum_d = (rtb_Sum1 * reg_FF_PI_pl_regr_stiff_B->Input13 -
               reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_a) *
    reg_FF_PI_pl_regr_stiff_B->Input14;

  /* Switch: '<Root>/Switch1' */
  if (reg_FF_PI_pl_regr_stiff_B->Input6 > 0.0F) {
    /* Sum: '<S56>/Sum' incorporates:
     *  DiscreteIntegrator: '<S46>/Integrator'
     *  Product: '<S51>/PProd Out'
     */
    rtb_Switch1 = (rtb_Sum1 * reg_FF_PI_pl_regr_stiff_B->Input11 +
                   reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_i) + rtb_Sum_d;

    /* Switch: '<S54>/Switch2' incorporates:
     *  Constant: '<S2>/max_sat'
     *  Constant: '<S2>/min_sat'
     *  RelationalOperator: '<S54>/LowerRelop1'
     *  RelationalOperator: '<S54>/UpperRelop'
     *  Sum: '<S2>/Sum3'
     *  Sum: '<S2>/Sum4'
     *  Switch: '<S54>/Switch'
     */
    if (rtb_Switch1 > 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      rtb_Switch1 = 5.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    } else if (rtb_Switch1 < 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15) {
      /* Switch: '<S54>/Switch' incorporates:
       *  Constant: '<S2>/min_sat'
       *  Sum: '<S2>/Sum4'
       */
      rtb_Switch1 = 0.0 - reg_FF_PI_pl_regr_stiff_B->Input15;
    }

    /* End of Switch: '<S54>/Switch2' */
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* MATLAB Function: '<S1>/MATLAB Function' incorporates:
   *  MultiPortSwitch: '<S1>/Multiport Switch1'
   */
  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_Yellow_ref = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_Yellow_ref += (real32_T)rtb_MultiportSwitch1[6 * i] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_Yellow_real = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_Yellow_real += (real32_T)rtb_MultiportSwitch1[6 * i + 1] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  AlphaX = 0.0F;
  for (i = 0; i < 8; i++) {
    AlphaX += (real32_T)rtb_MultiportSwitch1[6 * i + 2] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_Green_ref = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_Green_ref += (real32_T)rtb_MultiportSwitch1[6 * i + 3] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  rtb_MultiportSwitch_1 = 0.0F;
  for (i = 0; i < 8; i++) {
    rtb_MultiportSwitch_1 += (real32_T)rtb_MultiportSwitch1[6 * i + 4] * tmp[i];
  }

  tmp[0] = AlphaY;
  tmp[1] = HTransform_tmp;
  tmp[2] = rtb_Blue_real;
  tmp[3] = rtb_Blue_ref;
  tmp[4] = tmp_1;
  tmp[5] = tmp_2;
  tmp[6] = reg_FF_PI_pl_regr_stiff_B->Input15;
  tmp[7] = 1.0F;
  AlphaY = 0.0F;
  for (i = 0; i < 8; i++) {
    AlphaY += (real32_T)rtb_MultiportSwitch1[6 * i + 5] * tmp[i];
  }

  rtb_MultiportSwitch_0[0] = rtb_Yellow_ref;
  rtb_MultiportSwitch_0[1] = rtb_Yellow_real;
  rtb_MultiportSwitch_0[2] = AlphaX;
  rtb_MultiportSwitch_0[3] = rtb_Green_ref;
  rtb_MultiportSwitch_0[4] = rtb_MultiportSwitch_1;
  rtb_MultiportSwitch_0[5] = AlphaY;
  tmp_0[0] = 1.0F;
  tmp_0[1] = reg_FF_PI_pl_regr_stiff_B->Input1;
  tmp_0[2] = reg_FF_PI_pl_regr_stiff_B->Input2;
  tmp_0[3] = rtb_MultiportSwitch_2;
  tmp_0[4] = rtb_MultiportSwitch_3;
  tmp_0[5] = rtb_MultiportSwitch_4;
  rtb_Yellow_ref = 0.0F;
  for (i = 0; i < 6; i++) {
    rtb_Yellow_ref += rtb_MultiportSwitch_0[i] * tmp_0[i];
  }

  /* Sum: '<Root>/Sum1' incorporates:
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  reg_FF_PI_pl_regr_stiff_B->Sum1 = (real32_T)(rtb_Switch1 + rtb_Yellow_ref);

  /* S-Function (bur_out): '<Root>/Output4' */
  inst->Green_tab = reg_FF_PI_pl_regr_stiff_B->Sum1;

  /* S-Function (bur_in): '<Root>/Input10' */
  reg_FF_PI_pl_regr_stiff_B->Input10 = inst->tlak3;

  /* S-Function (bur_in): '<Root>/Input12' */
  reg_FF_PI_pl_regr_stiff_B->Input12 = inst->I_parameter;

  /* S-Function (bur_in): '<Root>/Input8' */
  reg_FF_PI_pl_regr_stiff_B->Input8 = inst->tlak1;

  /* S-Function (bur_in): '<Root>/Input9' */
  reg_FF_PI_pl_regr_stiff_B->Input9 = inst->tlak2;

  /* Product: '<S43>/IProd Out' */
  rtb_Switch1 = rtb_Sum1 * reg_FF_PI_pl_regr_stiff_B->Input12;

  /* Product: '<S92>/IProd Out' */
  rtb_Sum2 *= reg_FF_PI_pl_regr_stiff_B->Input12;

  /* Product: '<S141>/IProd Out' */
  A2 *= reg_FF_PI_pl_regr_stiff_B->Input12;

  /* Update for DiscreteIntegrator: '<S144>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE += 0.002 * A2;
  if (reg_FF_PI_pl_regr_stiff_B->Input5 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input5 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input5 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S144>/Integrator' */

  /* Update for DiscreteIntegrator: '<S139>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE += 0.002 * A1;
  if (reg_FF_PI_pl_regr_stiff_B->Input5 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input5 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input5 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S139>/Filter' */

  /* Update for DiscreteIntegrator: '<S95>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_o += 0.002 * rtb_Sum2;
  if (reg_FF_PI_pl_regr_stiff_B->Input7 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input7 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input7 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S95>/Integrator' */

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_f += 0.002 * A3;
  if (reg_FF_PI_pl_regr_stiff_B->Input7 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input7 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input7 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S90>/Filter' */

  /* Update for DiscreteIntegrator: '<S46>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_i += 0.002 * rtb_Switch1;
  if (reg_FF_PI_pl_regr_stiff_B->Input6 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input6 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input6 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S46>/Integrator' */

  /* Update for DiscreteIntegrator: '<S41>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_a += 0.002 * rtb_Sum_d;
  if (reg_FF_PI_pl_regr_stiff_B->Input6 > 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h = 1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input6 < 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h = -1;
  } else if (reg_FF_PI_pl_regr_stiff_B->Input6 == 0.0F) {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h = 0;
  } else {
    reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S41>/Filter' */
}

/* Model initialize function */
void reg_FF_PI_pl_regr_stiff_initialize(RT_MODEL_reg_FF_PI_pl_regr_st_T *const
  reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst)
{
  DW_reg_FF_PI_pl_regr_stiff_T *reg_FF_PI_pl_regr_stiff_DW =
    reg_FF_PI_pl_regr_stiff_M->dwork;

  /* InitializeConditions for DiscreteIntegrator: '<S144>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S139>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_o = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_l = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S90>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_f = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_i = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Integrator_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Filter' */
  reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_a = 0.0;
  reg_FF_PI_pl_regr_stiff_DW->Filter_PrevResetState_h = 2;
}

/* Model terminate function */
void reg_FF_PI_pl_regr_stiff_terminate(RT_MODEL_reg_FF_PI_pl_regr_st_T
  * reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst)
{}

/* Model data allocation function */
void reg_FF_PI_pl_regr_stiff_initializeMemory(RT_MODEL_reg_FF_PI_pl_regr_st_T* const reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t * inst)
{  /* states (dwork) */  {  }  {    B_reg_FF_PI_pl_regr_stiff_T *reg_FF_PI_pl_regr_stiff_B =      reg_FF_PI_pl_regr_stiff_M->blockIO;    DW_reg_FF_PI_pl_regr_stiff_T *reg_FF_PI_pl_regr_stiff_DW =      reg_FF_PI_pl_regr_stiff_M->dwork;    /* block I/O */    {      reg_FF_PI_pl_regr_stiff_B->Input15 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input1 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input2 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input3 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input4 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input16 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input11 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input5 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input13 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input14 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input17 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Sum = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input7 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Sum2 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input6 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Sum1 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input10 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input12 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input8 = 0.0F;      reg_FF_PI_pl_regr_stiff_B->Input9 = 0.0F;    }    /* states (dwork) */    (void) memset((void *)reg_FF_PI_pl_regr_stiff_DW, 0,                  sizeof(DW_reg_FF_PI_pl_regr_stiff_T));    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE = 0.0;    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE = 0.0;    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_o = 0.0;    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_f = 0.0;    reg_FF_PI_pl_regr_stiff_DW->Integrator_DSTATE_i = 0.0;    reg_FF_PI_pl_regr_stiff_DW->Filter_DSTATE_a = 0.0;  }}
