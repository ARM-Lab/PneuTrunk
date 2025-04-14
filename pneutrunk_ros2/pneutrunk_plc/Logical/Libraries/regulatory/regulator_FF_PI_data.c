/*
 * regulator_FF_PI_data.c
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

/* Constant parameters (default storage) */
const ConstP_regulator_FF_PI_T regulator_FF_PI_ConstP = {
  /* Expression: uhol_tlak_pp
   * Referenced by: '<S1>/Constant'
   */
  { 4.94F, 6.03F, 6.83F, 7.62F, 7.57F, 7.83F, 8.5F, 8.01F, 8.67F, 9.42F, 10.08F,
    8.84F, 9.42F, 10.18F, 11.07F, 11.66F, 12.19F, 9.43F, 9.8F, 1.92F, 4.11F,
    2.18F, 0.05F, 5.8F, 4.08F, 2.15F, 7.57F, 5.65F, 3.94F, 2.0F, 9.02F, 7.47F,
    5.55F, 3.76F, 1.85F, 0.05F, 10.5F, 8.76F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.4F, 0.6F, 0.6F, 0.6F, 0.8F, 0.8F, 0.8F, 1.0F, 1.0F, 1.0F, 1.0F, 1.2F, 1.2F,
    1.2F, 1.2F, 1.2F, 1.2F, 1.4F, 1.4F, 0.0F, 0.0F, 0.2F, 0.4F, 0.0F, 0.2F, 0.4F,
    0.0F, 0.2F, 0.4F, 0.6F, 0.0F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F, 0.0F, 0.2F, 0.4F,
    0.6F, 0.8F, 1.0F, 0.8F, 1.0F, 1.2F, 1.0F, 1.2F, 1.4F, 1.6F, 1.2F, 1.4F, 1.6F,
    1.8F, 2.0F, 2.2F, 1.4F, 1.6F },

  /* Expression: uhol_tlak_np
   * Referenced by: '<S1>/Constant1'
   */
  { -2.29F, -5.29F, -3.51F, -2.23F, -1.83F, -0.67F, -0.09F, -7.86F, -6.13F,
    -5.25F, -4.82F, -3.77F, -2.62F, -3.19F, -2.25F, -1.56F, -0.05F, -1.71F,
    -1.28F, 1.79F, 1.38F, 2.1F, 0.01F, 4.31F, 2.37F, 6.03F, 1.44F, 1.98F, 0.04F,
    3.93F, 2.36F, 0.51F, 5.79F, 4.43F, 2.73F, 0.67F, 7.65F, 6.1F, 0.4F, 0.6F,
    0.6F, 0.6F, 0.6F, 0.6F, 0.6F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F,
    0.8F, 0.8F, 0.8F, 0.8F, 0.0F, 0.0F, 0.4F, 0.4F, 0.6F, 0.6F, 0.8F, 0.0F, 0.4F,
    0.4F, 0.6F, 0.6F, 0.6F, 0.8F, 0.8F, 0.8F, 0.8F, 1.0F, 1.0F, 0.0F, 0.0F, 0.0F,
    0.2F, 0.0F, 0.2F, 0.0F, 0.0F, 0.0F, 0.2F, 0.0F, 0.2F, 0.4F, 0.0F, 0.2F, 0.4F,
    0.6F, 0.0F, 0.2F, 0.4F, 0.6F, 1.0F, 1.2F, 1.2F, 1.4F, 1.4F, 0.8F, 1.2F, 1.4F,
    1.4F, 1.6F, 1.8F, 1.6F, 1.8F, 2.0F, 2.2F, 1.8F, 2.0F },

  /* Expression: uhol_tlak_nn
   * Referenced by: '<S1>/Constant2'
   */
  { -1.72F, -1.83F, -0.28F, -1.85F, -0.46F, -4.83F, -3.32F, -2.2F, -0.69F,
    -4.87F, -3.79F, -2.35F, -1.56F, -1.39F, -7.41F, -6.11F, -5.01F, -3.56F,
    -2.32F, -0.54F, -2.15F, -4.45F, -0.45F, -2.72F, -2.12F, -4.46F, -6.89F,
    -8.68F, -0.65F, -2.94F, -4.5F, -6.45F, -2.03F, -1.75F, -4.13F, -6.33F,
    -8.17F, -9.7F, 0.0F, 0.4F, 0.4F, 0.4F, 0.4F, 0.6F, 0.6F, 0.6F, 0.6F, 0.6F,
    0.6F, 0.6F, 0.6F, 0.6F, 0.8F, 0.8F, 0.8F, 0.8F, 0.8F, 0.0F, 0.0F, 0.0F, 0.2F,
    0.2F, 0.0F, 0.0F, 0.0F, 0.0F, 0.2F, 0.2F, 0.2F, 0.2F, 0.4F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.2F, 0.4F, 0.0F, 0.2F, 0.2F, 0.4F, 0.6F, 0.8F, 0.0F, 0.2F,
    0.4F, 0.6F, 0.4F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F, 0.0F, 0.6F, 0.8F, 0.6F, 0.8F,
    0.8F, 1.0F, 1.2F, 1.4F, 0.8F, 1.0F, 1.2F, 1.4F, 1.4F, 1.0F, 1.2F, 1.4F, 1.6F,
    1.8F },

  /* Expression: uhol_tlak_pn
   * Referenced by: '<S1>/Constant3'
   */
  { 0.31F, 1.68F, 2.8F, 3.65F, 4.88F, 5.33F, 5.98F, 6.5F, 6.89F, 7.36F, 7.72F,
    8.02F, 8.38F, 8.59F, 8.75F, 8.93F, 9.11F, 9.45F, 9.93F, -3.43F, -5.5F,
    -7.74F, -9.49F, -11.38F, -12.88F, -14.21F, -14.98F, -15.71F, -16.11F,
    -16.49F, -17.09F, -17.88F, -18.58F, -18.94F, -19.13F, -19.54F, -19.81F,
    -20.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F, 0.0F,
    0.0F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F, 1.2F, 1.4F, 1.6F, 1.8F, 2.0F, 2.2F, 2.4F,
    2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F, 0.2F, 0.4F, 0.6F, 0.8F, 1.0F, 1.2F,
    1.4F, 1.6F, 1.8F, 2.0F, 2.2F, 2.4F, 2.6F, 2.8F, 3.0F, 3.2F, 3.4F, 3.6F, 3.8F
  }
};
