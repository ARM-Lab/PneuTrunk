/*
 * regulator_FF_PI_plane_regress.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "regulator_FF_PI_plane_regress".
 *
 * Model version              : 1.105
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr 12 13:40:31 2022
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "regulator_FF_PI_plane_regress.h"
#include "regulator_FF_PI_plane_regress_private.h"

/* Forward declaration for local functions */
static real32_T regulator_FF_PI_plane_regr_norm(const real32_T x[4], struct FF_PID_r* inst);

/* Function for MATLAB Function: '<S4>/requested alfa 2 deltaz1' */
static real32_T regulator_FF_PI_plane_regr_norm(const real32_T x[4], struct FF_PID_r* inst)
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
void regulator_FF_PI_plane_regress_step(RT_MODEL_regulator_FF_PI_plan_T *const
  regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst)
{
  B_regulator_FF_PI_plane_regre_T *regulator_FF_PI_plane_regress_B =
    regulator_FF_PI_plane_regres_M->blockIO;
  DW_regulator_FF_PI_plane_regr_T *regulator_FF_PI_plane_regres_DW =
    regulator_FF_PI_plane_regres_M->dwork;
  real_T Tz23[16];
  real_T Blue0_tmp[4];
  real_T Yellow0_tmp[4];
  real_T A1;
  real_T A2;
  real_T A3;
  real_T rtb_Sum1;
  real_T rtb_Sum2;
  real_T rtb_Sum_p;
  real_T rtb_Switch1;
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
  regulator_FF_PI_plane_regress_B->Input1 = inst->ref_alfa_x;

  /* S-Function (bur_in): '<Root>/Input2' */
  regulator_FF_PI_plane_regress_B->Input2 = inst->ref_alfa_y;

  /* S-Function (bur_in): '<Root>/Input3' */
  regulator_FF_PI_plane_regress_B->Input3 = inst->real_alfa_x;

  /* S-Function (bur_in): '<Root>/Input4' */
  regulator_FF_PI_plane_regress_B->Input4 = inst->real_alfa_y;

  /* MATLAB Function: '<S4>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S4>/Constant1'
   */
  AlphaX = regulator_FF_PI_plane_regress_B->Input1 * 3.14159274F / 180.0F;
  AlphaY = -regulator_FF_PI_plane_regress_B->Input2 * 3.14159274F / 180.0F;
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

  AlphaX = regulator_FF_PI_plane_regress_B->Input3 * 3.14159274F / 180.0F;
  AlphaY = -regulator_FF_PI_plane_regress_B->Input4 * 3.14159274F / 180.0F;
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

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S10>/cylinder height'
   *  Constant: '<S8>/cylinder height'
   *  Gain: '<S4>/Gain'
   *  Gain: '<S4>/Gain3'
   *  MATLAB Function: '<S4>/requested alfa 2 deltaz1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S8>/Sum'
   */
  rtb_Sum_p = (0.001F * regulator_FF_PI_plane_regr_norm(Yellow0_tmp_1, inst) - 0.115)
    - (0.001F * regulator_FF_PI_plane_regr_norm(Yellow0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input11' */
  regulator_FF_PI_plane_regress_B->Input11 = inst->P_parameter;

  /* S-Function (bur_in): '<Root>/Input5' */
  regulator_FF_PI_plane_regress_B->Input5 = inst->reset_PID_blue;

  /* DiscreteIntegrator: '<S142>/Integrator' */
  if ((regulator_FF_PI_plane_regress_B->Input5 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState == 1)) {
    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input13' */
  regulator_FF_PI_plane_regress_B->Input13 = inst->D_parameter;

  /* DiscreteIntegrator: '<S137>/Filter' */
  if ((regulator_FF_PI_plane_regress_B->Input5 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Filter_PrevResetState == 1)) {
    regulator_FF_PI_plane_regres_DW->Filter_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input14' */
  regulator_FF_PI_plane_regress_B->Input14 = inst->N_parameter;

  /* Product: '<S145>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S137>/Filter'
   *  Product: '<S136>/DProd Out'
   *  Sum: '<S137>/SumD'
   */
  A1 = (rtb_Sum_p * regulator_FF_PI_plane_regress_B->Input13 -
        regulator_FF_PI_plane_regres_DW->Filter_DSTATE) *
    regulator_FF_PI_plane_regress_B->Input14;

  /* Switch: '<Root>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S142>/Integrator'
   *  Product: '<S147>/PProd Out'
   *  Sum: '<S151>/Sum'
   */
  if (regulator_FF_PI_plane_regress_B->Input5 > 0.0F) {
    rtb_Switch1 = (rtb_Sum_p * regulator_FF_PI_plane_regress_B->Input11 +
                   regulator_FF_PI_plane_regres_DW->Integrator_DSTATE) + A1;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* MATLAB Function: '<S1>/MATLAB Function' */
  AlphaX = regulator_FF_PI_plane_regress_B->Input2 *
    regulator_FF_PI_plane_regress_B->Input2;

  /* Sum: '<Root>/Sum' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant10'
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant9'
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  regulator_FF_PI_plane_regress_B->Sum = (real32_T)(((((-0.124224707F *
    regulator_FF_PI_plane_regress_B->Input1 + 2.64781308F) + -0.00357809151F *
    regulator_FF_PI_plane_regress_B->Input2) + 0.000199967442F *
    regulator_FF_PI_plane_regress_B->Input1 *
    regulator_FF_PI_plane_regress_B->Input2) + AlphaX * -0.000922495266F) +
    rtb_Switch1);

  /* S-Function (bur_out): '<Root>/Output1' */
  inst->Blue_tab = regulator_FF_PI_plane_regress_B->Sum;

  /* MATLAB Function: '<S4>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Yellow0_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] * 85.0F +
      HTransform[i + 12]);
  }

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<S11>/cylinder height'
   *  Constant: '<S13>/cylinder height'
   *  Gain: '<S4>/Gain1'
   *  Gain: '<S4>/Gain4'
   *  MATLAB Function: '<S4>/requested alfa 2 deltaz1'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S13>/Sum'
   */
  rtb_Sum2 = (0.001F * regulator_FF_PI_plane_regr_norm(Yellow0_tmp_0, inst) - 0.115) -
    (0.001F * regulator_FF_PI_plane_regr_norm(Green0_tmp_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input7' */
  regulator_FF_PI_plane_regress_B->Input7 = inst->reset_PID_green;

  /* DiscreteIntegrator: '<S94>/Integrator' */
  if ((regulator_FF_PI_plane_regress_B->Input7 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l == 1)) {
    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_o = 0.0;
  }

  /* DiscreteIntegrator: '<S89>/Filter' */
  if ((regulator_FF_PI_plane_regress_B->Input7 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e == 1)) {
    regulator_FF_PI_plane_regres_DW->Filter_DSTATE_f = 0.0;
  }

  /* Product: '<S97>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S89>/Filter'
   *  Product: '<S88>/DProd Out'
   *  Sum: '<S89>/SumD'
   */
  A2 = (rtb_Sum2 * regulator_FF_PI_plane_regress_B->Input13 -
        regulator_FF_PI_plane_regres_DW->Filter_DSTATE_f) *
    regulator_FF_PI_plane_regress_B->Input14;

  /* Switch: '<Root>/Switch' incorporates:
   *  DiscreteIntegrator: '<S94>/Integrator'
   *  Product: '<S99>/PProd Out'
   *  Sum: '<S103>/Sum'
   */
  if (regulator_FF_PI_plane_regress_B->Input7 > 0.0F) {
    rtb_Switch1 = (rtb_Sum2 * regulator_FF_PI_plane_regress_B->Input11 +
                   regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_o) + A2;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  Constant: '<S1>/Constant13'
   *  Constant: '<S1>/Constant14'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S1>/Constant7'
   *  Constant: '<S1>/Constant8'
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  regulator_FF_PI_plane_regress_B->Sum2 = (real32_T)(((((0.0555538535F *
    regulator_FF_PI_plane_regress_B->Input1 + 2.63315105F) + -0.0980042F *
    regulator_FF_PI_plane_regress_B->Input2) + -0.00108669978F *
    regulator_FF_PI_plane_regress_B->Input1 *
    regulator_FF_PI_plane_regress_B->Input2) + AlphaX * 0.000865390757F) +
    rtb_Switch1);

  /* S-Function (bur_out): '<Root>/Output2' */
  inst->Yellow_tab = regulator_FF_PI_plane_regress_B->Sum2;

  /* MATLAB Function: '<S4>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Green0_tmp_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform[i + 4] *
      -73.6121597F + HTransform[i] * -42.5F) + HTransform[i + 12]);
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S12>/cylinder height'
   *  Constant: '<S9>/cylinder height'
   *  Gain: '<S4>/Gain2'
   *  Gain: '<S4>/Gain5'
   *  MATLAB Function: '<S4>/requested alfa 2 deltaz1'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S9>/Sum'
   */
  rtb_Sum1 = (0.001F * regulator_FF_PI_plane_regr_norm(Green0_tmp_tmp_0, inst) - 0.115)
    - (0.001F * regulator_FF_PI_plane_regr_norm(Blue0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input6' */
  regulator_FF_PI_plane_regress_B->Input6 = inst->reset_PID_yellow;

  /* DiscreteIntegrator: '<S46>/Integrator' */
  if ((regulator_FF_PI_plane_regress_B->Input6 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e == 1)) {
    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_i = 0.0;
  }

  /* DiscreteIntegrator: '<S41>/Filter' */
  if ((regulator_FF_PI_plane_regress_B->Input6 <= 0.0F) &&
      (regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h == 1)) {
    regulator_FF_PI_plane_regres_DW->Filter_DSTATE_a = 0.0;
  }

  /* Product: '<S49>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S41>/Filter'
   *  Product: '<S40>/DProd Out'
   *  Sum: '<S41>/SumD'
   */
  A3 = (rtb_Sum1 * regulator_FF_PI_plane_regress_B->Input13 -
        regulator_FF_PI_plane_regres_DW->Filter_DSTATE_a) *
    regulator_FF_PI_plane_regress_B->Input14;

  /* Switch: '<Root>/Switch1' incorporates:
   *  DiscreteIntegrator: '<S46>/Integrator'
   *  Product: '<S51>/PProd Out'
   *  Sum: '<S55>/Sum'
   */
  if (regulator_FF_PI_plane_regress_B->Input6 > 0.0F) {
    rtb_Switch1 = (rtb_Sum1 * regulator_FF_PI_plane_regress_B->Input11 +
                   regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_i) + A3;
  } else {
    rtb_Switch1 = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  Constant: '<S1>/Constant11'
   *  Constant: '<S1>/Constant12'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant4'
   *  Constant: '<S1>/Constant5'
   *  MATLAB Function: '<S1>/MATLAB Function'
   */
  regulator_FF_PI_plane_regress_B->Sum1 = (real32_T)(((((0.0678467527F *
    regulator_FF_PI_plane_regress_B->Input1 + 2.748276F) + 0.102030516F *
    regulator_FF_PI_plane_regress_B->Input2) + 0.00089278433F *
    regulator_FF_PI_plane_regress_B->Input1 *
    regulator_FF_PI_plane_regress_B->Input2) + AlphaX * 4.88388287E-5F) +
    rtb_Switch1);

  /* S-Function (bur_out): '<Root>/Output4' */
  inst->Green_tab = regulator_FF_PI_plane_regress_B->Sum1;

  /* S-Function (bur_in): '<Root>/Input10' */
  regulator_FF_PI_plane_regress_B->Input10 = inst->tlak3;

  /* S-Function (bur_in): '<Root>/Input12' */
  regulator_FF_PI_plane_regress_B->Input12 = inst->I_parameter;

  /* S-Function (bur_in): '<Root>/Input8' */
  regulator_FF_PI_plane_regress_B->Input8 = inst->tlak1;

  /* S-Function (bur_in): '<Root>/Input9' */
  regulator_FF_PI_plane_regress_B->Input9 = inst->tlak2;

  /* Product: '<S43>/IProd Out' */
  rtb_Switch1 = rtb_Sum1 * regulator_FF_PI_plane_regress_B->Input12;

  /* Product: '<S91>/IProd Out' */
  rtb_Sum2 *= regulator_FF_PI_plane_regress_B->Input12;

  /* Product: '<S139>/IProd Out' */
  rtb_Sum_p *= regulator_FF_PI_plane_regress_B->Input12;

  /* Update for DiscreteIntegrator: '<S142>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE += 0.002 * rtb_Sum_p;
  if (regulator_FF_PI_plane_regress_B->Input5 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input5 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input5 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S142>/Integrator' */

  /* Update for DiscreteIntegrator: '<S137>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE += 0.002 * A1;
  if (regulator_FF_PI_plane_regress_B->Input5 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input5 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input5 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S137>/Filter' */

  /* Update for DiscreteIntegrator: '<S94>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_o += 0.002 * rtb_Sum2;
  if (regulator_FF_PI_plane_regress_B->Input7 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input7 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input7 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S94>/Integrator' */

  /* Update for DiscreteIntegrator: '<S89>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE_f += 0.002 * A2;
  if (regulator_FF_PI_plane_regress_B->Input7 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input7 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input7 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S89>/Filter' */

  /* Update for DiscreteIntegrator: '<S46>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_i += 0.002 * rtb_Switch1;
  if (regulator_FF_PI_plane_regress_B->Input6 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input6 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input6 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S46>/Integrator' */

  /* Update for DiscreteIntegrator: '<S41>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE_a += 0.002 * A3;
  if (regulator_FF_PI_plane_regress_B->Input6 > 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h = 1;
  } else if (regulator_FF_PI_plane_regress_B->Input6 < 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h = -1;
  } else if (regulator_FF_PI_plane_regress_B->Input6 == 0.0F) {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h = 0;
  } else {
    regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S41>/Filter' */
}

/* Model initialize function */
void regulator_FF_PI_plane_regress_initialize(RT_MODEL_regulator_FF_PI_plan_T *
  const regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst)
{
  DW_regulator_FF_PI_plane_regr_T *regulator_FF_PI_plane_regres_DW =
    regulator_FF_PI_plane_regres_M->dwork;

  /* InitializeConditions for DiscreteIntegrator: '<S142>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE = 0.0;
  regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S137>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE = 0.0;
  regulator_FF_PI_plane_regres_DW->Filter_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S94>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_o = 0.0;
  regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_l = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S89>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE_f = 0.0;
  regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S46>/Integrator' */
  regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_i = 0.0;
  regulator_FF_PI_plane_regres_DW->Integrator_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S41>/Filter' */
  regulator_FF_PI_plane_regres_DW->Filter_DSTATE_a = 0.0;
  regulator_FF_PI_plane_regres_DW->Filter_PrevResetState_h = 2;
}

/* Model terminate function */
void regulator_FF_PI_plane_regress_terminate(RT_MODEL_regulator_FF_PI_plan_T
  * regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst)
{}

/* Model data allocation function */
void regulator_FF_PI_plane_regress_initializeMemory(RT_MODEL_regulator_FF_PI_plan_T* const regulator_FF_PI_plane_regres_M, struct FF_PID_r * inst)
{  /* states (dwork) */  {  }  {    B_regulator_FF_PI_plane_regre_T *regulator_FF_PI_plane_regress_B =      regulator_FF_PI_plane_regres_M->blockIO;    DW_regulator_FF_PI_plane_regr_T *regulator_FF_PI_plane_regres_DW =      regulator_FF_PI_plane_regres_M->dwork;    /* block I/O */    {      regulator_FF_PI_plane_regress_B->Input1 = 0.0F;      regulator_FF_PI_plane_regress_B->Input2 = 0.0F;      regulator_FF_PI_plane_regress_B->Input3 = 0.0F;      regulator_FF_PI_plane_regress_B->Input4 = 0.0F;      regulator_FF_PI_plane_regress_B->Input11 = 0.0F;      regulator_FF_PI_plane_regress_B->Input5 = 0.0F;      regulator_FF_PI_plane_regress_B->Input13 = 0.0F;      regulator_FF_PI_plane_regress_B->Input14 = 0.0F;      regulator_FF_PI_plane_regress_B->Sum = 0.0F;      regulator_FF_PI_plane_regress_B->Input7 = 0.0F;      regulator_FF_PI_plane_regress_B->Sum2 = 0.0F;      regulator_FF_PI_plane_regress_B->Input6 = 0.0F;      regulator_FF_PI_plane_regress_B->Sum1 = 0.0F;      regulator_FF_PI_plane_regress_B->Input10 = 0.0F;      regulator_FF_PI_plane_regress_B->Input12 = 0.0F;      regulator_FF_PI_plane_regress_B->Input8 = 0.0F;      regulator_FF_PI_plane_regress_B->Input9 = 0.0F;    }    /* states (dwork) */    (void) memset((void *)regulator_FF_PI_plane_regres_DW, 0,                  sizeof(DW_regulator_FF_PI_plane_regr_T));    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE = 0.0;    regulator_FF_PI_plane_regres_DW->Filter_DSTATE = 0.0;    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_o = 0.0;    regulator_FF_PI_plane_regres_DW->Filter_DSTATE_f = 0.0;    regulator_FF_PI_plane_regres_DW->Integrator_DSTATE_i = 0.0;    regulator_FF_PI_plane_regres_DW->Filter_DSTATE_a = 0.0;  }}
