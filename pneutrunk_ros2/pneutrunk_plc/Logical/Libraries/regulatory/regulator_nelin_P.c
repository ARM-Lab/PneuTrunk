/*
 * regulator_nelin_P.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "regulator_nelin_P".
 *
 * Model version              : 1.10
 * Simulink Coder version : 9.6 (R2021b) 14-May-2021
 * C source code generated on : Fri Jul 29 10:48:17 2022
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "regulator_nelin_P.h"
#include "regulator_nelin_P_private.h"

/* Forward declaration for local functions */
static real32_T regulator_nelin_P_norm(const real32_T x[4], struct nonL_P* inst);

/* Function for MATLAB Function: '<S1>/requested alfa 2 deltaz1' */
static real32_T regulator_nelin_P_norm(const real32_T x[4], struct nonL_P* inst)
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
void regulator_nelin_P_step(RT_MODEL_regulator_nelin_P_T *const
  regulator_nelin_P_M, struct nonL_P* inst)
{
  B_regulator_nelin_P_T *regulator_nelin_P_B = regulator_nelin_P_M->blockIO;
  real_T Tz23[16];
  real_T Blue0_tmp[4];
  real_T Yellow0_tmp[4];
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
  regulator_nelin_P_B->Input1 = inst->ref_alfa_x;

  /* S-Function (bur_in): '<Root>/Input2' */
  regulator_nelin_P_B->Input2 = inst->ref_alfa_y;

  /* S-Function (bur_in): '<Root>/Input3' */
  regulator_nelin_P_B->Input3 = inst->real_alfa_x;

  /* S-Function (bur_in): '<Root>/Input4' */
  regulator_nelin_P_B->Input4 = inst->real_alfa_y;

  /* MATLAB Function: '<S1>/requested alfa 2 deltaz1' incorporates:
   *  Constant: '<S1>/Constant1'
   */
  AlphaX = regulator_nelin_P_B->Input1 * 3.14159274F / 180.0F;
  AlphaY = -regulator_nelin_P_B->Input2 * 3.14159274F / 180.0F;
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

  AlphaX = regulator_nelin_P_B->Input3 * 3.14159274F / 180.0F;
  AlphaY = -regulator_nelin_P_B->Input4 * 3.14159274F / 180.0F;
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

  /* Gain: '<Root>/Gain7' incorporates:
   *  Constant: '<S3>/cylinder height'
   *  Constant: '<S5>/cylinder height'
   *  Gain: '<Root>/Gain3'
   *  Gain: '<Root>/Gain5'
   *  Gain: '<S1>/Gain'
   *  Gain: '<S1>/Gain3'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<S1>/requested alfa 2 deltaz1'
   *  Sum: '<S3>/Sum'
   *  Sum: '<S5>/Sum'
   */
  regulator_nelin_P_B->Gain7 = (real32_T)(pow(2.71828182845904, (0.001F *
    regulator_nelin_P_norm(Yellow0_tmp_0, inst) - 0.115) * 1000.0 * 0.1528) * 0.03078
    - pow(2.71828182845904, (0.001F * regulator_nelin_P_norm(Yellow0_tmp_1, inst) -
    0.115) * 1000.0 * 0.1528) * 0.03078);

  /* S-Function (bur_out): '<Root>/Output1' */
  inst->Blue_tab = regulator_nelin_P_B->Gain7;

  /* MATLAB Function: '<S1>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Yellow0_tmp_0[i] = (real32_T)Blue0_tmp[i] - ((HTransform[i + 4] *
      -73.6121597F + HTransform[i] * -42.5F) + HTransform[i + 12]);
  }

  /* Gain: '<Root>/Gain9' incorporates:
   *  Constant: '<S6>/cylinder height'
   *  Constant: '<S8>/cylinder height'
   *  Gain: '<Root>/Gain2'
   *  Gain: '<Root>/Gain6'
   *  Gain: '<S1>/Gain2'
   *  Gain: '<S1>/Gain5'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<S1>/requested alfa 2 deltaz1'
   *  Sum: '<S6>/Sum'
   *  Sum: '<S8>/Sum'
   */
  regulator_nelin_P_B->Gain9 = (real32_T)(pow(2.71828182845904, (0.001F *
    regulator_nelin_P_norm(Blue0_tmp_0, inst) - 0.115) * 1000.0 * 0.1528) * 0.03078 -
    pow(2.71828182845904, (0.001F * regulator_nelin_P_norm(Yellow0_tmp_0, inst) -
    0.115) * 1000.0 * 0.1528) * 0.03078);

  /* S-Function (bur_out): '<Root>/Output2' */
  inst->Yellow_tab = regulator_nelin_P_B->Gain9;

  /* MATLAB Function: '<S1>/requested alfa 2 deltaz1' */
  for (i = 0; i < 4; i++) {
    Blue0_tmp_0[i] = (real32_T)Green0_tmp_tmp[i] - (HTransform[i] * 85.0F +
      HTransform[i + 12]);
  }

  /* Gain: '<Root>/Gain8' incorporates:
   *  Constant: '<S4>/cylinder height'
   *  Constant: '<S7>/cylinder height'
   *  Gain: '<Root>/Gain1'
   *  Gain: '<Root>/Gain4'
   *  Gain: '<S1>/Gain1'
   *  Gain: '<S1>/Gain4'
   *  MATLAB Function: '<Root>/MATLAB Function'
   *  MATLAB Function: '<S1>/requested alfa 2 deltaz1'
   *  Sum: '<S4>/Sum'
   *  Sum: '<S7>/Sum'
   */
  regulator_nelin_P_B->Gain8 = (real32_T)(pow(2.71828182845904, (0.001F *
    regulator_nelin_P_norm(Green0_tmp_tmp_0, inst) - 0.115) * 1000.0 * 0.1528) *
    0.03078 - pow(2.71828182845904, (0.001F * regulator_nelin_P_norm(Blue0_tmp_0, inst)
    - 0.115) * 1000.0 * 0.1528) * 0.03078);

  /* S-Function (bur_out): '<Root>/Output4' */
  inst->Green_tab = regulator_nelin_P_B->Gain8;
}

/* Model initialize function */
void regulator_nelin_P_initialize(RT_MODEL_regulator_nelin_P_T *const
  regulator_nelin_P_M, struct nonL_P* inst)
{
  UNUSED_PARAMETER(regulator_nelin_P_M);
}

/* Model terminate function */
void regulator_nelin_P_terminate(RT_MODEL_regulator_nelin_P_T
  * regulator_nelin_P_M, struct nonL_P* inst)
{}

/* Model data allocation function */
void regulator_nelin_P_initializeMemory(RT_MODEL_regulator_nelin_P_T* const regulator_nelin_P_M, struct nonL_P * inst)
{  /* block I/O */  {  }  {    B_regulator_nelin_P_T *regulator_nelin_P_B = regulator_nelin_P_M->blockIO;    /* block I/O */    {      regulator_nelin_P_B->Input1 = 0.0F;      regulator_nelin_P_B->Input2 = 0.0F;      regulator_nelin_P_B->Input3 = 0.0F;      regulator_nelin_P_B->Input4 = 0.0F;      regulator_nelin_P_B->Gain7 = 0.0F;      regulator_nelin_P_B->Gain9 = 0.0F;      regulator_nelin_P_B->Gain8 = 0.0F;    }  }}
