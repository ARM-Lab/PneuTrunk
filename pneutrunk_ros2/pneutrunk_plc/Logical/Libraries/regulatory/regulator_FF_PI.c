/*
 * regulator_FF_PI.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "regulator_FF_PI".
 *
 * Model version              : 1.96
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Tue Apr  5 15:19:23 2022
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "regulator_FF_PI.h"
#include "regulator_FF_PI_private.h"

/* Forward declaration for local functions */
static real32_T regulator_FF_PI_norm(const real32_T x[4], struct FF_PID* inst);

/* Function for MATLAB Function: '<S5>/requested alfa 2 deltaz1' */
static real32_T regulator_FF_PI_norm(const real32_T x[4], struct FF_PID* inst)
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
void regulator_FF_PI_step(RT_MODEL_regulator_FF_PI_T *const regulator_FF_PI_M, struct FF_PID* inst)
{
  B_regulator_FF_PI_T *regulator_FF_PI_B = regulator_FF_PI_M->blockIO;
  DW_regulator_FF_PI_T *regulator_FF_PI_DW = regulator_FF_PI_M->dwork;
  real_T oblast_bodov[114];
  real_T Tz23[16];
  real_T Blue0_tmp[4];
  real_T Yellow0_tmp[4];
  real_T A1;
  real_T A2;
  real_T rtb_out;
  real_T tlaky_idx_0;
  real_T tlaky_idx_1;
  real_T tlaky_idx_2;
  real_T tmp;
  real_T tolerancia_bodov;
  real_T tolerancia_tlakov;
  int32_T Tz23_tmp;
  int32_T counter3;
  int32_T i;
  int32_T k;
  real32_T rtb_MultiportSwitch[114];
  real32_T rozdiel[95];
  real32_T vzd_bodov[76];
  real32_T AlphaY_0[16];
  real32_T HTransform[16];
  real32_T HTransform_tmp_1[16];
  real32_T Tz23_0[16];
  real32_T Blue0_tmp_0[4];
  real32_T Green0_tmp_tmp_0[4];
  real32_T Yellow0_tmp_0[4];
  real32_T Yellow0_tmp_1[4];
  real32_T AlphaX;
  real32_T AlphaY;
  real32_T akt_u_idx_2;
  real32_T akt_u_idx_3;
  real32_T akt_u_idx_4;
  real32_T rozdiel_tmp;
  real32_T vzd_bodov_tmp;
  int8_T Green0_tmp_tmp[4];
  int8_T HTransform_tmp[4];
  int8_T HTransform_tmp_0[4];

  /* S-Function (bur_in): '<Root>/Input1' */
  regulator_FF_PI_B->Input1 = inst->ref_alfa_x;

  /* S-Function (bur_in): '<Root>/Input2' */
  regulator_FF_PI_B->Input2 = inst->ref_alfa_y;

  /* S-Function (bur_in): '<Root>/Input3' */
  regulator_FF_PI_B->Input3 = inst->real_alfa_x;

  /* S-Function (bur_in): '<Root>/Input4' */
  regulator_FF_PI_B->Input4 = inst->real_alfa_y;

  /* MATLAB Function: '<S5>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S5>/Constant1'
   */
  AlphaX = regulator_FF_PI_B->Input1 * 3.14159274F / 180.0F;
  AlphaY = -regulator_FF_PI_B->Input2 * 3.14159274F / 180.0F;
  Tz23[2] = 0.0;
  Tz23[6] = 0.0;
  Tz23[10] = 1.0;
  Tz23[14] = 57.5;
  akt_u_idx_2 = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  akt_u_idx_3 = sinf(AlphaX);
  AlphaX = cosf(AlphaX);
  AlphaY_0[0] = AlphaY;
  AlphaY_0[4] = 0.0F;
  AlphaY_0[8] = akt_u_idx_2;
  AlphaY_0[12] = 0.0F;
  AlphaY_0[2] = -akt_u_idx_2;
  AlphaY_0[6] = 0.0F;
  AlphaY_0[10] = AlphaY;
  AlphaY_0[14] = 0.0F;
  Tz23[0] = 1.0;
  Tz23[1] = 0.0;
  Tz23[3] = 0.0;
  HTransform_tmp_0[0] = 1;
  AlphaY_0[1] = 0.0F;
  AlphaY_0[3] = 0.0F;
  HTransform_tmp[0] = 0;
  Tz23[4] = 0.0;
  Tz23[5] = 1.0;
  Tz23[7] = 0.0;
  HTransform_tmp_0[1] = 0;
  AlphaY_0[5] = 1.0F;
  AlphaY_0[7] = 0.0F;
  HTransform_tmp[1] = 0;
  Tz23[8] = 0.0;
  Tz23[9] = 0.0;
  Tz23[11] = 0.0;
  HTransform_tmp_0[2] = 0;
  AlphaY_0[9] = 0.0F;
  AlphaY_0[11] = 0.0F;
  HTransform_tmp[2] = 0;
  Tz23[12] = 0.0;
  Tz23[13] = 0.0;
  Tz23[15] = 1.0;
  HTransform_tmp_0[3] = 0;
  AlphaY_0[13] = 0.0F;
  AlphaY_0[15] = 1.0F;
  HTransform_tmp[3] = 1;
  HTransform_tmp_1[1] = 0.0F;
  HTransform_tmp_1[5] = AlphaX;
  HTransform_tmp_1[9] = -akt_u_idx_3;
  HTransform_tmp_1[13] = 0.0F;
  HTransform_tmp_1[2] = 0.0F;
  HTransform_tmp_1[6] = akt_u_idx_3;
  HTransform_tmp_1[10] = AlphaX;
  HTransform_tmp_1[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      Tz23_0[Tz23_tmp] = 0.0F;
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3] * (real32_T)Tz23[i];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 1] * (real32_T)Tz23[i + 4];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 2] * (real32_T)Tz23[i + 8];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 3] * (real32_T)Tz23[i + 12];
    }

    counter3 = i << 2;
    HTransform_tmp_1[counter3] = HTransform_tmp_0[i];
    HTransform_tmp_1[counter3 + 3] = HTransform_tmp[i];
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
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 3] * Tz23_0[i + 12];
    }

    akt_u_idx_2 = 0.0F;
    akt_u_idx_3 = 0.0F;
    akt_u_idx_4 = 0.0F;
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 3] * AlphaY_0[i + 12];
      akt_u_idx_2 += HTransform[Tz23_tmp] * (real32_T)Green0_tmp_tmp[k];
      akt_u_idx_3 += HTransform[Tz23_tmp] * (real32_T)Yellow0_tmp[k];
      akt_u_idx_4 += HTransform[Tz23_tmp] * (real32_T)Blue0_tmp[k];
    }

    Green0_tmp_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - akt_u_idx_2;
    Yellow0_tmp_0[i] = (real32_T)Yellow0_tmp[i] - akt_u_idx_3;
    Blue0_tmp_0[i] = (real32_T)Blue0_tmp[i] - akt_u_idx_4;
  }

  AlphaX = regulator_FF_PI_B->Input3 * 3.14159274F / 180.0F;
  AlphaY = -regulator_FF_PI_B->Input4 * 3.14159274F / 180.0F;
  akt_u_idx_2 = sinf(AlphaY);
  AlphaY = cosf(AlphaY);
  akt_u_idx_3 = sinf(AlphaX);
  AlphaX = cosf(AlphaX);
  AlphaY_0[0] = AlphaY;
  AlphaY_0[4] = 0.0F;
  AlphaY_0[8] = akt_u_idx_2;
  AlphaY_0[12] = 0.0F;
  AlphaY_0[2] = -akt_u_idx_2;
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
  HTransform_tmp_1[1] = 0.0F;
  HTransform_tmp_1[5] = AlphaX;
  HTransform_tmp_1[9] = -akt_u_idx_3;
  HTransform_tmp_1[13] = 0.0F;
  HTransform_tmp_1[2] = 0.0F;
  HTransform_tmp_1[6] = akt_u_idx_3;
  HTransform_tmp_1[10] = AlphaX;
  HTransform_tmp_1[14] = 0.0F;
  for (i = 0; i < 4; i++) {
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      Tz23_0[Tz23_tmp] = 0.0F;
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3] * (real32_T)Tz23[i];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 1] * (real32_T)Tz23[i + 4];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 2] * (real32_T)Tz23[i + 8];
      Tz23_0[Tz23_tmp] += AlphaY_0[counter3 + 3] * (real32_T)Tz23[i + 12];
    }

    counter3 = i << 2;
    HTransform_tmp_1[counter3] = HTransform_tmp_0[i];
    HTransform_tmp_1[counter3 + 3] = HTransform_tmp[i];
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
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      AlphaY_0[Tz23_tmp] = 0.0F;
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3] * Tz23_0[i];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 1] * Tz23_0[i + 4];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 2] * Tz23_0[i + 8];
      AlphaY_0[Tz23_tmp] += HTransform_tmp_1[counter3 + 3] * Tz23_0[i + 12];
    }

    akt_u_idx_2 = 0.0F;
    for (k = 0; k < 4; k++) {
      counter3 = k << 2;
      Tz23_tmp = i + counter3;
      HTransform[Tz23_tmp] = 0.0F;
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3] * AlphaY_0[i];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 1] * AlphaY_0[i + 4];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 2] * AlphaY_0[i + 8];
      HTransform[Tz23_tmp] += (real32_T)Tz23[counter3 + 3] * AlphaY_0[i + 12];
      akt_u_idx_2 += HTransform[Tz23_tmp] * (real32_T)Yellow0_tmp[k];
    }

    Yellow0_tmp_1[i] = (real32_T)Yellow0_tmp[i] - akt_u_idx_2;
  }

  /* Sum: '<S2>/Sum' incorporates:
   *  Constant: '<S11>/cylinder height'
   *  Constant: '<S9>/cylinder height'
   *  Gain: '<S5>/Gain'
   *  Gain: '<S5>/Gain3'
   *  MATLAB Function: '<S5>/requested alfa 2 deltaz1'
   *  Sum: '<S11>/Sum'
   *  Sum: '<S9>/Sum'
   */
  A2 = (0.001F * regulator_FF_PI_norm(Yellow0_tmp_1, inst) - 0.115) - (0.001F *
    regulator_FF_PI_norm(Yellow0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input11' */
  regulator_FF_PI_B->Input11 = inst->P_parameter;

  /* S-Function (bur_in): '<Root>/Input5' */
  regulator_FF_PI_B->Input5 = inst->reset_PID_blue;

  /* DiscreteIntegrator: '<S143>/Integrator' */
  if ((regulator_FF_PI_B->Input5 <= 0.0F) &&
      (regulator_FF_PI_DW->Integrator_PrevResetState == 1)) {
    regulator_FF_PI_DW->Integrator_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input13' */
  regulator_FF_PI_B->Input13 = inst->D_parameter;

  /* DiscreteIntegrator: '<S138>/Filter' */
  if ((regulator_FF_PI_B->Input5 <= 0.0F) &&
      (regulator_FF_PI_DW->Filter_PrevResetState == 1)) {
    regulator_FF_PI_DW->Filter_DSTATE = 0.0;
  }

  /* S-Function (bur_in): '<Root>/Input14' */
  regulator_FF_PI_B->Input14 = inst->N_parameter;

  /* Product: '<S146>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S138>/Filter'
   *  Product: '<S137>/DProd Out'
   *  Sum: '<S138>/SumD'
   */
  A1 = (A2 * regulator_FF_PI_B->Input13 - regulator_FF_PI_DW->Filter_DSTATE) *
    regulator_FF_PI_B->Input14;

  /* S-Function (bur_in): '<Root>/Input8' */
  regulator_FF_PI_B->Input8 = inst->tlak1;

  /* S-Function (bur_in): '<Root>/Input9' */
  regulator_FF_PI_B->Input9 = inst->tlak2;

  /* S-Function (bur_in): '<Root>/Input10' */
  regulator_FF_PI_B->Input10 = inst->tlak3;

  /* MATLAB Function: '<S1>/prepinac' */
  rtb_out = 1.0;
  if ((regulator_FF_PI_B->Input1 < 0.0F) && (regulator_FF_PI_B->Input2 > 0.0F))
  {
    rtb_out = 2.0;
  }

  if ((regulator_FF_PI_B->Input1 > 0.0F) && (regulator_FF_PI_B->Input2 < 0.0F))
  {
    rtb_out = 3.0;
  }

  if ((regulator_FF_PI_B->Input1 <= 0.0F) && (regulator_FF_PI_B->Input2 <= 0.0F))
  {
    rtb_out = 4.0;
  }

  /* End of MATLAB Function: '<S1>/prepinac' */

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant1'
   *  Constant: '<S1>/Constant2'
   *  Constant: '<S1>/Constant3'
   */
  switch ((int32_T)rtb_out) {
   case 1:
    for (i = 0; i < 114; i++) {
      rtb_MultiportSwitch[i] = regulator_FF_PI_ConstP.Constant_Value_m[i];
    }
    break;

   case 2:
    for (i = 0; i < 114; i++) {
      rtb_MultiportSwitch[i] = regulator_FF_PI_ConstP.Constant1_Value_b[i];
    }
    break;

   case 3:
    for (i = 0; i < 114; i++) {
      rtb_MultiportSwitch[i] = regulator_FF_PI_ConstP.Constant3_Value[i];
    }
    break;

   default:
    for (i = 0; i < 114; i++) {
      rtb_MultiportSwitch[i] = regulator_FF_PI_ConstP.Constant2_Value[i];
    }
    break;
  }

  /* End of MultiPortSwitch: '<S1>/Multiport Switch' */

  /* MATLAB Function: '<S1>/ff' incorporates:
   *  MultiPortSwitch: '<S1>/Multiport Switch'
   */
  akt_u_idx_2 = regulator_FF_PI_B->Input8;
  akt_u_idx_3 = regulator_FF_PI_B->Input9;
  akt_u_idx_4 = regulator_FF_PI_B->Input10;
  tolerancia_bodov = 2.0;
  tolerancia_tlakov = 2.0;
  counter3 = 0;
  tlaky_idx_0 = 0.0;
  tlaky_idx_1 = 0.0;
  tlaky_idx_2 = 0.0;
  for (k = 0; k < 19; k++) {
    rozdiel[k] = rtb_MultiportSwitch[k] - regulator_FF_PI_B->Input1;
    rozdiel[k + 19] = rtb_MultiportSwitch[k + 19] - regulator_FF_PI_B->Input2;
    AlphaX = rtb_MultiportSwitch[k + 38];
    rozdiel[k + 38] = AlphaX;
    AlphaY = rtb_MultiportSwitch[k + 57];
    rozdiel[k + 57] = AlphaY;
    rozdiel_tmp = rtb_MultiportSwitch[k + 76];
    rozdiel[k + 76] = rozdiel_tmp;
    vzd_bodov_tmp = rozdiel[k + 19];
    vzd_bodov[k] = sqrtf(vzd_bodov_tmp * vzd_bodov_tmp + rozdiel[k] * rozdiel[k]);
    vzd_bodov[k + 19] = AlphaX;
    vzd_bodov[k + 38] = AlphaY;
    vzd_bodov[k + 57] = rozdiel_tmp;
  }

  for (i = 0; i < 114; i++) {
    oblast_bodov[i] = 0.0;
  }

  rtb_out = 0.0;
  if (regulator_FF_PI_B->Input8 <= 2.0F) {
    akt_u_idx_2 = 2.0F;
  }

  if (regulator_FF_PI_B->Input9 <= 2.0F) {
    akt_u_idx_3 = 2.0F;
  }

  if (regulator_FF_PI_B->Input10 <= 2.0F) {
    akt_u_idx_4 = 2.0F;
  }

  int32_T exitg1;
  do {
    exitg1 = 0;
    for (k = 0; k < 19; k++) {
      if ((vzd_bodov[k] <= tolerancia_bodov) && (fabsf(((akt_u_idx_2 +
              akt_u_idx_3) + akt_u_idx_4) - rtb_MultiportSwitch[k + 95]) <=
           tolerancia_tlakov)) {
        rtb_out++;
        for (i = 0; i < 6; i++) {
          oblast_bodov[((int32_T)rtb_out + 19 * i) - 1] = rtb_MultiportSwitch[19
            * i + k];
        }

        rozdiel_tmp = (real32_T)oblast_bodov[(int32_T)rtb_out - 1] -
          regulator_FF_PI_B->Input1;
        vzd_bodov_tmp = (real32_T)oblast_bodov[(int32_T)rtb_out + 18] -
          regulator_FF_PI_B->Input2;
        rozdiel_tmp = sqrtf(rozdiel_tmp * rozdiel_tmp + vzd_bodov_tmp *
                            vzd_bodov_tmp);
        if (rozdiel_tmp <= 0.5F) {
          if (counter3 == 0) {
            counter3 = 1;
            tlaky_idx_0 = oblast_bodov[(int32_T)rtb_out + 37];
            tlaky_idx_1 = oblast_bodov[(int32_T)rtb_out + 56];
            tlaky_idx_2 = oblast_bodov[(int32_T)rtb_out + 75];
          } else {
            AlphaX = (real32_T)oblast_bodov[(int32_T)(rtb_out - 1.0) - 1] -
              regulator_FF_PI_B->Input1;
            AlphaY = (real32_T)oblast_bodov[(int32_T)(rtb_out - 1.0) + 18] -
              regulator_FF_PI_B->Input2;
            if (rozdiel_tmp < sqrtf(AlphaX * AlphaX + AlphaY * AlphaY)) {
              tlaky_idx_0 = oblast_bodov[(int32_T)rtb_out + 37];
              tlaky_idx_1 = oblast_bodov[(int32_T)rtb_out + 56];
              tlaky_idx_2 = oblast_bodov[(int32_T)rtb_out + 75];
            }
          }
        }
      }
    }

    if (rtb_out == 0.0) {
      tolerancia_bodov++;
      tolerancia_tlakov++;
    } else {
      exitg1 = 1;
    }
  } while (exitg1 == 0);

  if (counter3 == 0) {
    tolerancia_bodov = oblast_bodov[38];
    for (counter3 = 2; counter3 <= (int32_T)rtb_out; counter3++) {
      tolerancia_bodov += oblast_bodov[counter3 + 37];
    }

    tolerancia_tlakov = oblast_bodov[57];
    for (counter3 = 2; counter3 <= (int32_T)rtb_out; counter3++) {
      tolerancia_tlakov += oblast_bodov[counter3 + 56];
    }

    tlaky_idx_2 = oblast_bodov[76];
    for (counter3 = 2; counter3 <= (int32_T)rtb_out; counter3++) {
      tlaky_idx_2 += oblast_bodov[counter3 + 75];
    }

    tlaky_idx_0 = tolerancia_bodov / (real_T)(int32_T)rtb_out;
    tlaky_idx_1 = tolerancia_tlakov / (real_T)(int32_T)rtb_out;
    tlaky_idx_2 /= (real_T)(int32_T)rtb_out;
  }

  /* Switch: '<Root>/Switch2' incorporates:
   *  DiscreteIntegrator: '<S143>/Integrator'
   *  Product: '<S148>/PProd Out'
   *  Sum: '<S152>/Sum'
   */
  if (regulator_FF_PI_B->Input5 > 0.0F) {
    tmp = (A2 * regulator_FF_PI_B->Input11 +
           regulator_FF_PI_DW->Integrator_DSTATE) + A1;
  } else {
    tmp = 0.0;
  }

  /* End of Switch: '<Root>/Switch2' */

  /* Sum: '<Root>/Sum' incorporates:
   *  MATLAB Function: '<S1>/ff'
   */
  regulator_FF_PI_B->Sum = (real32_T)(tmp + tlaky_idx_0);

  /* S-Function (bur_out): '<Root>/Output1' */
  inst->Blue_tab = regulator_FF_PI_B->Sum;

  /* MATLAB Function: '<S5>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Yellow0_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] * 85.0F +
      HTransform[i + 12]);
  }

  /* Sum: '<S2>/Sum2' incorporates:
   *  Constant: '<S12>/cylinder height'
   *  Constant: '<S14>/cylinder height'
   *  Gain: '<S5>/Gain1'
   *  Gain: '<S5>/Gain4'
   *  MATLAB Function: '<S5>/requested alfa 2 deltaz1'
   *  Sum: '<S12>/Sum'
   *  Sum: '<S14>/Sum'
   */
  tolerancia_tlakov = (0.001F * regulator_FF_PI_norm(Yellow0_tmp_0, inst) - 0.115) -
    (0.001F * regulator_FF_PI_norm(Green0_tmp_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input7' */
  regulator_FF_PI_B->Input7 = inst->reset_PID_green;

  /* DiscreteIntegrator: '<S95>/Integrator' */
  if ((regulator_FF_PI_B->Input7 <= 0.0F) &&
      (regulator_FF_PI_DW->Integrator_PrevResetState_l == 1)) {
    regulator_FF_PI_DW->Integrator_DSTATE_o = 0.0;
  }

  /* DiscreteIntegrator: '<S90>/Filter' */
  if ((regulator_FF_PI_B->Input7 <= 0.0F) &&
      (regulator_FF_PI_DW->Filter_PrevResetState_e == 1)) {
    regulator_FF_PI_DW->Filter_DSTATE_f = 0.0;
  }

  /* Product: '<S98>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S90>/Filter'
   *  Product: '<S89>/DProd Out'
   *  Sum: '<S90>/SumD'
   */
  rtb_out = (tolerancia_tlakov * regulator_FF_PI_B->Input13 -
             regulator_FF_PI_DW->Filter_DSTATE_f) * regulator_FF_PI_B->Input14;

  /* Switch: '<Root>/Switch' incorporates:
   *  DiscreteIntegrator: '<S95>/Integrator'
   *  Product: '<S100>/PProd Out'
   *  Sum: '<S104>/Sum'
   */
  if (regulator_FF_PI_B->Input7 > 0.0F) {
    tmp = (tolerancia_tlakov * regulator_FF_PI_B->Input11 +
           regulator_FF_PI_DW->Integrator_DSTATE_o) + rtb_out;
  } else {
    tmp = 0.0;
  }

  /* End of Switch: '<Root>/Switch' */

  /* Sum: '<Root>/Sum2' incorporates:
   *  MATLAB Function: '<S1>/ff'
   */
  regulator_FF_PI_B->Sum2 = (real32_T)(tmp + tlaky_idx_2);

  /* S-Function (bur_out): '<Root>/Output2' */
  inst->Yellow_tab = regulator_FF_PI_B->Sum2;

  /* MATLAB Function: '<S5>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Green0_tmp_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform[i + 4] *
      -73.6121597F + HTransform[i] * -42.5F) + HTransform[i + 12]);
  }

  /* Sum: '<S2>/Sum1' incorporates:
   *  Constant: '<S10>/cylinder height'
   *  Constant: '<S13>/cylinder height'
   *  Gain: '<S5>/Gain2'
   *  Gain: '<S5>/Gain5'
   *  MATLAB Function: '<S5>/requested alfa 2 deltaz1'
   *  Sum: '<S10>/Sum'
   *  Sum: '<S13>/Sum'
   */
  tlaky_idx_2 = (0.001F * regulator_FF_PI_norm(Green0_tmp_tmp_0, inst) - 0.115) -
    (0.001F * regulator_FF_PI_norm(Blue0_tmp_0, inst) - 0.115);

  /* S-Function (bur_in): '<Root>/Input6' */
  regulator_FF_PI_B->Input6 = inst->reset_PID_yellow;

  /* DiscreteIntegrator: '<S47>/Integrator' */
  if ((regulator_FF_PI_B->Input6 <= 0.0F) &&
      (regulator_FF_PI_DW->Integrator_PrevResetState_e == 1)) {
    regulator_FF_PI_DW->Integrator_DSTATE_i = 0.0;
  }

  /* DiscreteIntegrator: '<S42>/Filter' */
  if ((regulator_FF_PI_B->Input6 <= 0.0F) &&
      (regulator_FF_PI_DW->Filter_PrevResetState_h == 1)) {
    regulator_FF_PI_DW->Filter_DSTATE_a = 0.0;
  }

  /* Product: '<S50>/NProd Out' incorporates:
   *  DiscreteIntegrator: '<S42>/Filter'
   *  Product: '<S41>/DProd Out'
   *  Sum: '<S42>/SumD'
   */
  tolerancia_bodov = (tlaky_idx_2 * regulator_FF_PI_B->Input13 -
                      regulator_FF_PI_DW->Filter_DSTATE_a) *
    regulator_FF_PI_B->Input14;

  /* Switch: '<Root>/Switch1' incorporates:
   *  DiscreteIntegrator: '<S47>/Integrator'
   *  Product: '<S52>/PProd Out'
   *  Sum: '<S56>/Sum'
   */
  if (regulator_FF_PI_B->Input6 > 0.0F) {
    tmp = (tlaky_idx_2 * regulator_FF_PI_B->Input11 +
           regulator_FF_PI_DW->Integrator_DSTATE_i) + tolerancia_bodov;
  } else {
    tmp = 0.0;
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Sum: '<Root>/Sum1' incorporates:
   *  MATLAB Function: '<S1>/ff'
   */
  regulator_FF_PI_B->Sum1 = (real32_T)(tmp + tlaky_idx_1);

  /* S-Function (bur_out): '<Root>/Output4' */
  inst->Green_tab = regulator_FF_PI_B->Sum1;

  /* S-Function (bur_in): '<Root>/Input12' */
  regulator_FF_PI_B->Input12 = inst->I_parameter;

  /* Product: '<S44>/IProd Out' */
  tlaky_idx_0 = tlaky_idx_2 * regulator_FF_PI_B->Input12;

  /* Product: '<S92>/IProd Out' */
  tolerancia_tlakov *= regulator_FF_PI_B->Input12;

  /* Product: '<S140>/IProd Out' */
  A2 *= regulator_FF_PI_B->Input12;

  /* Update for DiscreteIntegrator: '<S143>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE += 0.002 * A2;
  if (regulator_FF_PI_B->Input5 > 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState = 1;
  } else if (regulator_FF_PI_B->Input5 < 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState = -1;
  } else if (regulator_FF_PI_B->Input5 == 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState = 0;
  } else {
    regulator_FF_PI_DW->Integrator_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S143>/Integrator' */

  /* Update for DiscreteIntegrator: '<S138>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE += 0.002 * A1;
  if (regulator_FF_PI_B->Input5 > 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState = 1;
  } else if (regulator_FF_PI_B->Input5 < 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState = -1;
  } else if (regulator_FF_PI_B->Input5 == 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState = 0;
  } else {
    regulator_FF_PI_DW->Filter_PrevResetState = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S138>/Filter' */

  /* Update for DiscreteIntegrator: '<S95>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE_o += 0.002 * tolerancia_tlakov;
  if (regulator_FF_PI_B->Input7 > 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_l = 1;
  } else if (regulator_FF_PI_B->Input7 < 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_l = -1;
  } else if (regulator_FF_PI_B->Input7 == 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_l = 0;
  } else {
    regulator_FF_PI_DW->Integrator_PrevResetState_l = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S95>/Integrator' */

  /* Update for DiscreteIntegrator: '<S90>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE_f += 0.002 * rtb_out;
  if (regulator_FF_PI_B->Input7 > 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_e = 1;
  } else if (regulator_FF_PI_B->Input7 < 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_e = -1;
  } else if (regulator_FF_PI_B->Input7 == 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_e = 0;
  } else {
    regulator_FF_PI_DW->Filter_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S90>/Filter' */

  /* Update for DiscreteIntegrator: '<S47>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE_i += 0.002 * tlaky_idx_0;
  if (regulator_FF_PI_B->Input6 > 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_e = 1;
  } else if (regulator_FF_PI_B->Input6 < 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_e = -1;
  } else if (regulator_FF_PI_B->Input6 == 0.0F) {
    regulator_FF_PI_DW->Integrator_PrevResetState_e = 0;
  } else {
    regulator_FF_PI_DW->Integrator_PrevResetState_e = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S47>/Integrator' */

  /* Update for DiscreteIntegrator: '<S42>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE_a += 0.002 * tolerancia_bodov;
  if (regulator_FF_PI_B->Input6 > 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_h = 1;
  } else if (regulator_FF_PI_B->Input6 < 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_h = -1;
  } else if (regulator_FF_PI_B->Input6 == 0.0F) {
    regulator_FF_PI_DW->Filter_PrevResetState_h = 0;
  } else {
    regulator_FF_PI_DW->Filter_PrevResetState_h = 2;
  }

  /* End of Update for DiscreteIntegrator: '<S42>/Filter' */
}

/* Model initialize function */
void regulator_FF_PI_initialize(RT_MODEL_regulator_FF_PI_T *const
  regulator_FF_PI_M, struct FF_PID* inst)
{
  DW_regulator_FF_PI_T *regulator_FF_PI_DW = regulator_FF_PI_M->dwork;

  /* InitializeConditions for DiscreteIntegrator: '<S143>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE = 0.0;
  regulator_FF_PI_DW->Integrator_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S138>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE = 0.0;
  regulator_FF_PI_DW->Filter_PrevResetState = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S95>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE_o = 0.0;
  regulator_FF_PI_DW->Integrator_PrevResetState_l = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S90>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE_f = 0.0;
  regulator_FF_PI_DW->Filter_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S47>/Integrator' */
  regulator_FF_PI_DW->Integrator_DSTATE_i = 0.0;
  regulator_FF_PI_DW->Integrator_PrevResetState_e = 2;

  /* InitializeConditions for DiscreteIntegrator: '<S42>/Filter' */
  regulator_FF_PI_DW->Filter_DSTATE_a = 0.0;
  regulator_FF_PI_DW->Filter_PrevResetState_h = 2;
}

/* Model terminate function */
void regulator_FF_PI_terminate(RT_MODEL_regulator_FF_PI_T * regulator_FF_PI_M, struct FF_PID* inst)
{}

/* Model data allocation function */
void regulator_FF_PI_initializeMemory(RT_MODEL_regulator_FF_PI_T* const regulator_FF_PI_M, struct FF_PID * inst)
{  /* states (dwork) */  {  }  {    B_regulator_FF_PI_T *regulator_FF_PI_B = regulator_FF_PI_M->blockIO;    DW_regulator_FF_PI_T *regulator_FF_PI_DW = regulator_FF_PI_M->dwork;    /* block I/O */    {      regulator_FF_PI_B->Input1 = 0.0F;      regulator_FF_PI_B->Input2 = 0.0F;      regulator_FF_PI_B->Input3 = 0.0F;      regulator_FF_PI_B->Input4 = 0.0F;      regulator_FF_PI_B->Input11 = 0.0F;      regulator_FF_PI_B->Input5 = 0.0F;      regulator_FF_PI_B->Input13 = 0.0F;      regulator_FF_PI_B->Input14 = 0.0F;      regulator_FF_PI_B->Input8 = 0.0F;      regulator_FF_PI_B->Input9 = 0.0F;      regulator_FF_PI_B->Input10 = 0.0F;      regulator_FF_PI_B->Sum = 0.0F;      regulator_FF_PI_B->Input7 = 0.0F;      regulator_FF_PI_B->Sum2 = 0.0F;      regulator_FF_PI_B->Input6 = 0.0F;      regulator_FF_PI_B->Sum1 = 0.0F;      regulator_FF_PI_B->Input12 = 0.0F;    }    /* states (dwork) */    (void) memset((void *)regulator_FF_PI_DW, 0,                  sizeof(DW_regulator_FF_PI_T));    regulator_FF_PI_DW->Integrator_DSTATE = 0.0;    regulator_FF_PI_DW->Filter_DSTATE = 0.0;    regulator_FF_PI_DW->Integrator_DSTATE_o = 0.0;    regulator_FF_PI_DW->Filter_DSTATE_f = 0.0;    regulator_FF_PI_DW->Integrator_DSTATE_i = 0.0;    regulator_FF_PI_DW->Filter_DSTATE_a = 0.0;  }}
