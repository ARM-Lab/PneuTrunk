/*
 * regulator_nelin_P.h
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

#ifndef RTW_HEADER_regulator_nelin_P_h_
#define RTW_HEADER_regulator_nelin_P_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef regulator_nelin_P_COMMON_INCLUDES_
#define regulator_nelin_P_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* regulator_nelin_P_COMMON_INCLUDES_ */

#include "regulator_nelin_P_types.h"
#include "regulatory.h"
/* Beginning of Dynamic TypeDefs: */
/* End of Dynamic TypeDefs: */
#ifndef MIN
#define MIN(a,b)	((a) < (b) ? (a) : (b))
#endif

#ifndef MAX
#define MAX(a,b)	((a) > (b) ? (a) : (b))
#endif

#ifndef AST_ROUND
#define AST_ROUND(x) ((x)>=0?(long long)((x)+0.5):(long long)((x)-0.5))
#endif


/* Shared type includes */
#include "multiword_types.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define regulator_nelin_P_M_TYPE       RT_MODEL_regulator_nelin_P_T

/* Block signals (default storage) */

/* Real-time Model Data Structure */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern void regulator_nelin_P_initializeMemory(RT_MODEL_regulator_nelin_P_T * const regulator_nelin_P_M, struct nonL_P* inst);
extern void regulator_nelin_P_initialize(RT_MODEL_regulator_nelin_P_T *const
  regulator_nelin_P_M, struct nonL_P* inst);
extern void regulator_nelin_P_step(RT_MODEL_regulator_nelin_P_T *const
  regulator_nelin_P_M, struct nonL_P* inst);
extern void regulator_nelin_P_terminate(RT_MODEL_regulator_nelin_P_T
  * regulator_nelin_P_M, struct nonL_P* inst);

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'regulator_nelin_P'
 * '<S1>'   : 'regulator_nelin_P/AlfaX_baseY2deltaz2'
 * '<S2>'   : 'regulator_nelin_P/MATLAB Function'
 * '<S3>'   : 'regulator_nelin_P/abs2relat1'
 * '<S4>'   : 'regulator_nelin_P/abs2relat2'
 * '<S5>'   : 'regulator_nelin_P/abs2relat3'
 * '<S6>'   : 'regulator_nelin_P/abs2relat4'
 * '<S7>'   : 'regulator_nelin_P/abs2relat5'
 * '<S8>'   : 'regulator_nelin_P/abs2relat6'
 * '<S9>'   : 'regulator_nelin_P/AlfaX_baseY2deltaz2/requested alfa 2 deltaz1'
 */
#endif                                 /* RTW_HEADER_regulator_nelin_P_h_ */
