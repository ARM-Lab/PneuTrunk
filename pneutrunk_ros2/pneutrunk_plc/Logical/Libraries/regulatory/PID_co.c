/*
 * PID_co.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "PID_co".
 *
 * Model version              : 1.9
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Mon Sep 26 14:43:58 2022
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "PID_co.h"
#include "PID_co_private.h"

/* Forward declaration for local functions */
static real32_T PID_co_norm(const real32_T x[4], struct PID_c* inst);

/* Function for MATLAB Function: '<S2>/requested alfa 2 deltaz1' */
static real32_T PID_co_norm(const real32_T x[4], struct PID_c* inst)
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
void PID_co_step(RT_MODEL_PID_co_T *const PID_co_M, struct PID_c* inst)
{
  B_PID_co_T *PID_co_B = PID_co_M->blockIO;
  DW_PID_co_T *PID_co_DW = PID_co_M->dwork;
  real_T Tz23[16];
  real_T Blue0_tmp[4];
  real_T Yellow0_tmp[4];
  real_T A1;
  real_T A2;
  real_T A3;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum_j;
  real_T u0;
  int32_T Tz23_tmp;
  int32_T Tz23_tmp_tmp;
  int32_T i;
  int32_T i_0;
  real32_T AlphaY_0[16];
  real32_T HTransform[16];
  real32_T HTransform_tmp_3[16];
  real32_T Tz23_0[16];
  real32_T Blue0_tmp_0[4];
  real32_T Green0_tmp_tmp_0[4];
  real32_T Yellow0_tmp_0[4];
  real32_T Yellow0_tmp_1[4];
  real32_T AlphaX;
  real32_T AlphaY;
  real32_T HTransform_tmp;
  real32_T HTransform_tmp_0;
  int8_T Green0_tmp_tmp[4];
  int8_T HTransform_tmp_1[4];
  int8_T HTransform_tmp_2[4];

  /* S-Function (bur_in): '<Root>/Input1' */
  PID_co_B->Input1 = inst->ref_alfa_x;

  /* S-Function (bur_in): '<Root>/Input2' */
  PID_co_B->Input2 = inst->ref_alfa_y;

  /* S-Function (bur_in): '<Root>/Input3' */
  PID_co_B->Input3 = inst->real_alfa_x;

  /* S-Function (bur_in): '<Root>/Input4' */
  PID_co_B->Input4 = inst->real_alfa_y;

  /* MATLAB Function: '<S2>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S2>/Constant1'
   */
  AlphaX = PID_co_B->Input1 * 3.14159274F / 180.0F;
  AlphaY = -PID_co_B->Input2 * 3.14159274F / 180.0F;
  Tz23[2] = 0.0;
  Tz23[6] = 0.0;
  Tz23[10] = 1.0;
  Tz23[14] = 57.5;
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
  HTransform_tmp_2[0] = 1;
  AlphaY_0[1] = 0.0F;
  AlphaY_0[3] = 0.0F;
  HTransform_tmp_1[0] = 0;
  Tz23[4] = 0.0;
  Tz23[5] = 1.0;
  Tz23[7] = 0.0;
  HTransform_tmp_2[1] = 0;
  AlphaY_0[5] = 1.0F;
  AlphaY_0[7] = 0.0F;
  HTransform_tmp_1[1] = 0;
  Tz23[8] = 0.0;
  Tz23[9] = 0.0;
  Tz23[11] = 0.0;
  HTransform_tmp_2[2] = 0;
  AlphaY_0[9] = 0.0F;
  AlphaY_0[11] = 0.0F;
  HTransform_tmp_1[2] = 0;
  Tz23[12] = 0.0;
  Tz23[13] = 0.0;
  Tz23[15] = 1.0;
  HTransform_tmp_2[3] = 0;
  AlphaY_0[13] = 0.0F;
  AlphaY_0[15] = 1.0F;
  HTransform_tmp_1[3] = 1;
  HTransform_tmp_3[1] = 0.0F;
  HTransform_tmp_3[5] = AlphaX;
  HTransform_tmp_3[9] = -HTransform_tmp_0;
  HTransform_tmp_3[13] = 0.0F;
  HTransform_tmp_3[2] = 0.0F;
  HTransform_tmp_3[6] = HTransform_tmp_0;
  HTransform_tmp_3[10] = AlphaX;
  HTransform_tmp_3[14] = 0.0F;
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
    HTransform_tmp_3[Tz23_tmp_tmp] = HTransform_tmp_2[i];
    HTransform_tmp_3[Tz23_tmp_tmp + 3] = HTransform_tmp_1[i];
  }

  Green0_tmp_tmp[0] = 85;
  Green0_tmp_tmp[1] = 0;
  Green0_tmp_tmp[2] = 0;
  Green0_tmp_tmp[3] = 1;
  Yellow0_tmp[0] = -42.5;
  Yellow0_tmp[1] = 73.612159321677282;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -42.5;
  Blue0_tmp[1] = -73.612159321677282;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 3] * Tz23_0[i + 12];
    }

    AlphaX = 0.0F;
    AlphaY = 0.0F;
    HTransform_tmp = 0.0F;
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 3] * AlphaY_0[i + 12];
      AlphaX += HTransform[Tz23_tmp] * (real32_T)Green0_tmp_tmp[i_0];
      AlphaY += HTransform[Tz23_tmp] * (real32_T)Yellow0_tmp[i_0];
      HTransform_tmp += HTransform[Tz23_tmp] * (real32_T)Blue0_tmp[i_0];
    }

    Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - AlphaX;
    Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - AlphaY;
    Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - HTransform_tmp;
  }

  AlphaX = PID_co_B->Input3 * 3.14159274F / 180.0F;
  AlphaY = -PID_co_B->Input4 * 3.14159274F / 180.0F;
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
  HTransform_tmp_3[1] = 0.0F;
  HTransform_tmp_3[5] = AlphaX;
  HTransform_tmp_3[9] = -HTransform_tmp_0;
  HTransform_tmp_3[13] = 0.0F;
  HTransform_tmp_3[2] = 0.0F;
  HTransform_tmp_3[6] = HTransform_tmp_0;
  HTransform_tmp_3[10] = AlphaX;
  HTransform_tmp_3[14] = 0.0F;
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
    HTransform_tmp_3[Tz23_tmp_tmp] = HTransform_tmp_2[i];
    HTransform_tmp_3[Tz23_tmp_tmp + 3] = HTransform_tmp_1[i];
  }

  Yellow0_tmp[0] = -42.5;
  Yellow0_tmp[1] = 73.612159321677282;
  Yellow0_tmp[2] = 0.0;
  Yellow0_tmp[3] = 1.0;
  Blue0_tmp[0] = -42.5;
  Blue0_tmp[1] = -73.612159321677282;
  Blue0_tmp[2] = 0.0;
  Blue0_tmp[3] = 1.0;
  for (i = 0; i < 4; i++) {
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_3[Tz23_tmp_tmp + 3] * Tz23_0[i + 12];
    }

    AlphaX = 0.0F;
    for (i_0 = 0; i_0 < 4; i_0++) {
      Tz23_tmp_tmp = i_0 << 2;
      Tz23_tmp = i + Tz23_tmp_tmp;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[Tz23_tmp_tmp + 3] * AlphaY_0[i + 12];
      AlphaX += HTransform[Tz23_tmp] * (real32_T)Yellow0_tmp[i_0];
    }

    Yellow0_tmp_1[i] = (real32_T)Yellow0_tmp[i] - AlphaX;
  }

  /* Sum: '<S1>/Sum' incorporates:
   *  Constant: '<S6>/cylinder height'
   *  Constant: '<S8>/cylinder height'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain3'
   *  MATLAB Function: '<S2>/requested alfa 2 deltaz1'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S8>/Sum'
   */
  rtb_Sum_j = (0.001F * PID_co_norm(Yellow0_tmp_1, inst) - 0.115) - (0.001F *
    PID_co_norm(Yellow0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input11' */
  PID_co_B->Input11 = inst->P_parameter;

  /* S-Function (bur_in): '<Root>/Input5' */
  PID_co_B->Input5 = inst->reset_PID_blue;

  /* DiscreteIntegrator: '<S140>/Integrator' */
  if ((PID_co_B->Input5 <= 0.0F) && (PID_co_DW->Integrator_PrevResetState == 1))
  {
    PID_co_DW->Integrator_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input13' */
  PID_co_B->Input13 = inst->D_parameter;

  /* DiscreteIntegrator: '<S135>/Filter' */
  if ((PID_co_B->Input5 <= 0.0F) && (PID_co_DW->Filter_PrevResetState == 1)) {
    PID_co_DW->Filter_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input14' */
  PID_co_B->Input14 = inst->N_parameter;

  /* Product: '<S143>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S135>/Filter'
   *  Product: '<S134>/DProd Out'
   *  Sum: '<S135>/SumD'
   */
  A1 = (rtb_Sum_j * PID_co_B->Input13 - PID_co_DW->Filter_DSTATE) *
    PID_co_B->Input14;

  /* Switch: '<Root>/Switch2' */
  if (PID_co_B->Input5 > 0.0F) {
    /* Sum: '<S149>/Sum' incorporates:
     *  DiscreteIntegrator: '<S140>/Integrator'
     *  Product: '<S145>/PProd Out'
     */
    u0 = (rtb_Sum_j * PID_co_B->Input11 + PID_co_DW->Integrator_DSTATE) + A1;

    /* Saturate: '<S147>/Saturation' */
    if (u0 > 2.0) {
      /* Switch: '<Root>/Switch2' */
      PID_co_B->Switch2 = 2.0F;
    } else if (u0 < -3.0) {
      /* Switch: '<Root>/Switch2' */
      PID_co_B->Switch2 = -3.0F;
    } else {
      /* Switch: '<Root>/Switch2' */
      PID_co_B->Switch2 = (real32_T)u0;
    }

    /* End of Saturate: '<S147>/Saturation' */
  } else {
    /* Switch: '<Root>/Switch2' */
    PID_co_B->Switch2 = 0.0F;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* S-Function (bur_out): '<Root>/Output1' */
  inst->Blue_tab = PID_co_B->Switch2;

  /* MATLAB Function: '<S2>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Yellow0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform[i + 4] *
      -73.6121597F + HTransform[i] * -42.5F) + HTransform[i + 12]);
  }

  /* Sum: '<S1>/Sum1' incorporates:
   *  Constant: '<S10>/cylinder height'
   *  Constant: '<S7>/cylinder height'
   *  Gain: '<S2>/Gain2'
   *  Gain: '<S2>/Gain5'
   *  MATLAB Function: '<S2>/requested alfa 2 deltaz1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S7>/Sum'
   */
  rtb_Sum1 = (0.001F * PID_co_norm(Yellow0_tmp_0, inst) - 0.115) - (0.001F *
    PID_co_norm(Blue0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input6' */
  PID_co_B->Input6 = inst->reset_PID_yellow;

  /* DiscreteIntegrator: '<S44>/Integrator' */
  if ((PID_co_B->Input6 <= 0.0F) && (PID_co_DW->Integrator_PrevResetState_m == 1))
  {
    PID_co_DW->Integrator_DSTATE_f = 0.0;
  }

  /* DiscreteIntegrator: '<S39>/Filter' */
  if ((PID_co_B->Input6 <= 0.0F) && (PID_co_DW->Filter_PrevResetState_e == 1)) {
    PID_co_DW->Filter_DSTATE_j = 0.0;
  }

  /* Product: '<S47>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S39>/Filter'
   *  Product: '<S38>/DProd Out'
   *  Sum: '<S39>/SumD'
   */
  A2 = (rtb_Sum1 * PID_co_B->Input13 - PID_co_DW->Filter_DSTATE_j) *
    PID_co_B->Input14;

  /* Switch: '<Root>/Switch1' */
  if (PID_co_B->Input6 > 0.0F) {
    /* Sum: '<S53>/Sum' incorporates:
     *  DiscreteIntegrator: '<S44>/Integrator'
     *  Product: '<S49>/PProd Out'
     */
    u0 = (rtb_Sum1 * PID_co_B->Input11 + PID_co_DW->Integrator_DSTATE_f) + A2;

    /* Saturate: '<S51>/Saturation' */
    if (u0 > 2.0) {
      /* Switch: '<Root>/Switch1' */
      PID_co_B->Switch1 = 2.0F;
    } else if (u0 < -3.0) {
      /* Switch: '<Root>/Switch1' */
      PID_co_B->Switch1 = -3.0F;
    } else {
      /* Switch: '<Root>/Switch1' */
      PID_co_B->Switch1 = (real32_T)u0;
    }

    /* End of Saturate: '<S51>/Saturation' */
  } else {
    /* Switch: '<Root>/Switch1' */
    PID_co_B->Switch1 = 0.0F;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* S-Function (bur_out): '<Root>/Output2' */
  inst->Yellow_tab = PID_co_B->Switch1;

  /* MATLAB Function: '<S2>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Blue0_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] * 85.0F +
      HTransform[i + 12]);
  }

  /* Sum: '<S1>/Sum2' incorporates:
   *  Constant: '<S11>/cylinder height'
   *  Constant: '<S9>/cylinder height'
   *  Gain: '<S2>/Gain1'
   *  Gain: '<S2>/Gain4'
   *  MATLAB Function: '<S2>/requested alfa 2 deltaz1'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sum2 = (0.001F * PID_co_norm(Blue0_tmp_0, inst) - 0.115) - (0.001F * PID_co_norm
    (Green0_tmp_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input7' */
  PID_co_B->Input7 = inst->reset_PID_green;

  /* DiscreteIntegrator: '<S92>/Integrator' */
  if ((PID_co_B->Input7 <= 0.0F) && (PID_co_DW->Integrator_PrevResetState_l == 1))
  {
    PID_co_DW->Integrator_DSTATE_h = 0.0;
  }

  /* DiscreteIntegrator: '<S87>/Filter' */
  if ((PID_co_B->Input7 <= 0.0F) && (PID_co_DW->Filter_PrevResetState_k == 1)) {
    PID_co_DW->Filter_DSTATE_m = 0.0;
  }

  /* Product: '<S95>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S87>/Filter'
   *  Product: '<S86>/DProd Out'
   *  Sum: '<S87>/SumD'
   */
  A3 = (rtb_Sum2 * PID_co_B->Input13 - PID_co_DW->Filter_DSTATE_m) *
    PID_co_B->Input14;

  /* Switch: '<Root>/Switch' */
  if (PID_co_B->Input7 > 0.0F) {
    /* Sum: '<S101>/Sum' incorporates:
     *  DiscreteIntegrator: '<S92>/Integrator'
     *  Product: '<S97>/PProd Out'
     */
    u0 = (rtb_Sum2 * PID_co_B->Input11 + PID_co_DW->Integrator_DSTATE_h) + A3;

    /* Saturate: '<S99>/Saturation' */
    if (u0 > 2.0) {
      /* Switch: '<Root>/Switch' */
      PID_co_B->Switch = 2.0F;
    } else if (u0 < -3.0) {
      /* Switch: '<Root>/Switch' */
      PID_co_B->Switch = -3.0F;
    } else {
      /* Switch: '<Root>/Switch' */
      PID_co_B->Switch = (real32_T)u0;
    }

    /* End of Saturate: '<S99>/Saturation' */
  } else {
    /* Switch: '<Root>/Switch' */
    PID_co_B->Switch = 0.0F;
  }

  /* End of Switch: '<Root>/Switch' */

  /* S-Function (bur_out): '<Root>/Output4' */
  inst->Green_tab = PID_co_B->Switch;

  /* S-Function (bur_in): '<Root>/Input12' */
  PID_co_B->Input12 = inst->I_parameter;

  /* Product: '<S41>/IProd Out' */
  rtb_Sum1 *= PID_co_B->Input12;

  /* Product: '<S89>/IProd Out' */
  rtb_Sum2 *= PID_co_B->Input12;

  /* Product: '<S137>/IProd Out' */
  rtb_Sum_j *= PID_co_B->Input12;

  /* Update for DiscreteIntegrator: '<S140>/Integrator' */
  PID_co_DW->Integrator_DSTATE += 0.002 * rtb_Sum_j;
  if (PID_co_B->Input5 > 0.0F) {
    PID_co_DW->Integrator_PrevResetState = 1;
  } else if (PID_co_B->Input5 < 0.0F) {
    PID_co_DW->Integrator_PrevResetState = -1;
  } else if (PID_co_B->Input5 == 0.0F) {
    PID_co_DW->Integrator_PrevResetState = 0;
  } else {
    PID_co_DW->Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S140>/Integrator' */

  /* Update for DiscreteIntegrator: '<S135>/Filter' */
  PID_co_DW->Filter_DSTATE += 0.002 * A1;
  if (PID_co_B->Input5 > 0.0F) {
    PID_co_DW->Filter_PrevResetState = 1;
  } else if (PID_co_B->Input5 < 0.0F) {
    PID_co_DW->Filter_PrevResetState = -1;
  } else if (PID_co_B->Input5 == 0.0F) {
    PID_co_DW->Filter_PrevResetState = 0;
  } else {
    PID_co_DW->Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S135>/Filter' */

  /* Update for DiscreteIntegrator: '<S44>/Integrator' */
  PID_co_DW->Integrator_DSTATE_f += 0.002 * rtb_Sum1;
  if (PID_co_B->Input6 > 0.0F) {
    PID_co_DW->Integrator_PrevResetState_m = 1;
  } else if (PID_co_B->Input6 < 0.0F) {
    PID_co_DW->Integrator_PrevResetState_m = -1;
  } else if (PID_co_B->Input6 == 0.0F) {
    PID_co_DW->Integrator_PrevResetState_m = 0;
  } else {
    PID_co_DW->Integrator_PrevResetState_m = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S44>/Integrator' */

  /* Update for DiscreteIntegrator: '<S39>/Filter' */
  PID_co_DW->Filter_DSTATE_j += 0.002 * A2;
  if (PID_co_B->Input6 > 0.0F) {
    PID_co_DW->Filter_PrevResetState_e = 1;
  } else if (PID_co_B->Input6 < 0.0F) {
    PID_co_DW->Filter_PrevResetState_e = -1;
  } else if (PID_co_B->Input6 == 0.0F) {
    PID_co_DW->Filter_PrevResetState_e = 0;
  } else {
    PID_co_DW->Filter_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S39>/Filter' */

  /* Update for DiscreteIntegrator: '<S92>/Integrator' */
  PID_co_DW->Integrator_DSTATE_h += 0.002 * rtb_Sum2;
  if (PID_co_B->Input7 > 0.0F) {
    PID_co_DW->Integrator_PrevResetState_l = 1;
  } else if (PID_co_B->Input7 < 0.0F) {
    PID_co_DW->Integrator_PrevResetState_l = -1;
  } else if (PID_co_B->Input7 == 0.0F) {
    PID_co_DW->Integrator_PrevResetState_l = 0;
  } else {
    PID_co_DW->Integrator_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S92>/Integrator' */

  /* Update for DiscreteIntegrator: '<S87>/Filter' */
  PID_co_DW->Filter_DSTATE_m += 0.002 * A3;
  if (PID_co_B->Input7 > 0.0F) {
    PID_co_DW->Filter_PrevResetState_k = 1;
  } else if (PID_co_B->Input7 < 0.0F) {
    PID_co_DW->Filter_PrevResetState_k = -1;
  } else if (PID_co_B->Input7 == 0.0F) {
    PID_co_DW->Filter_PrevResetState_k = 0;
  } else {
    PID_co_DW->Filter_PrevResetState_k = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S87>/Filter' */
}

/* Model initialize function */
void PID_co_initialize(RT_MODEL_PID_co_T *const PID_co_M, struct PID_c* inst)
{
  DW_PID_co_T *PID_co_DW = PID_co_M->dwork;

  /* InitializeConditions for DiscreteIntegrator: '<S140>/Integrator' */
  PID_co_DW->Integrator_DSTATE = 0.0;
  PID_co_DW->Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S135>/Filter' */
  PID_co_DW->Filter_DSTATE = 0.0;
  PID_co_DW->Filter_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S44>/Integrator' */
  PID_co_DW->Integrator_DSTATE_f = 0.0;
  PID_co_DW->Integrator_PrevResetState_m = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S39>/Filter' */
  PID_co_DW->Filter_DSTATE_j = 0.0;
  PID_co_DW->Filter_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S92>/Integrator' */
  PID_co_DW->Integrator_DSTATE_h = 0.0;
  PID_co_DW->Integrator_PrevResetState_l = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S87>/Filter' */
  PID_co_DW->Filter_DSTATE_m = 0.0;
  PID_co_DW->Filter_PrevResetState_k = 2;
}

/* Model terminate function */
void PID_co_terminate(RT_MODEL_PID_co_T * PID_co_M, struct PID_c* inst)
{}

/* Model data allocation function */
void PID_co_initializeMemory(RT_MODEL_PID_co_T* const PID_co_M, struct PID_c * inst)
{  /* states (dwork) */  {  }  {    B_PID_co_T *PID_co_B = PID_co_M->blockIO;    DW_PID_co_T *PID_co_DW = PID_co_M->dwork;    /* block I/O */    {      PID_co_B->Input1 = 0.0F;      PID_co_B->Input2 = 0.0F;      PID_co_B->Input3 = 0.0F;      PID_co_B->Input4 = 0.0F;      PID_co_B->Input11 = 0.0F;      PID_co_B->Input5 = 0.0F;      PID_co_B->Input13 = 0.0F;      PID_co_B->Input14 = 0.0F;      PID_co_B->Switch2 = 0.0F;      PID_co_B->Input6 = 0.0F;      PID_co_B->Switch1 = 0.0F;      PID_co_B->Input7 = 0.0F;      PID_co_B->Switch = 0.0F;      PID_co_B->Input12 = 0.0F;    }    /* states (dwork) */    (void) memset((void *)PID_co_DW, 0,                  sizeof(DW_PID_co_T));    PID_co_DW->Integrator_DSTATE = 0.0;    PID_co_DW->Filter_DSTATE = 0.0;    PID_co_DW->Integrator_DSTATE_f = 0.0;    PID_co_DW->Filter_DSTATE_j = 0.0;    PID_co_DW->Integrator_DSTATE_h = 0.0;    PID_co_DW->Filter_DSTATE_m = 0.0;  }}
