/*
 * pneutr2_reg_FF_stiff_private.h
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

#ifndef RTW_HEADER_pneutr2_reg_FF_stiff_private_h_
#define RTW_HEADER_pneutr2_reg_FF_stiff_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#include "pneutr2_reg_FF_stiff.h"
#include "pneutr2_reg_FF_stiff_types.h"

extern real32_T look1_tf_binlcpw(real_T u0, const real_T bp0[], const real32_T
  table[], uint32_T maxIndex);
extern void pneutr2_reg_FF_stiff_ID1(real32_T rtu_poz_u_x, real32_T rtu_poz_u_y,
  const real_T rtu_coef_1blue[48], const real_T rtu_coef_2green[48], const
  real_T rtu_coef_3yellow[48], real32_T rtu_tuhost, B_ID1_pneutr2_reg_FF_stiff_T
  *localB);
extern void pneutr2_r_requestedalfa2deltaz1(real32_T rtu_AlphaX_ref, real32_T
  rtu_AlphaY_ref, real32_T rtu_AlphaX_real, real32_T rtu_AlphaY_real, real_T
  rtu_A, real_T rtu_B, real32_T rtu_poradie, B_requestedalfa2deltaz1_pneut_T
  *localB);
extern void pneutr2_reg_FF_s_MATLABFunction(real_T rtu_in, real_T
  rtu_previous_in, real_T rtu_step, real_T rtu_pocet_stepov, real_T rtu_last_in,
  real_T rtu_neupravujuci_uhol, B_MATLABFunction_pneutr2_reg__T *localB);

#endif                          /* RTW_HEADER_pneutr2_reg_FF_stiff_private_h_ */
