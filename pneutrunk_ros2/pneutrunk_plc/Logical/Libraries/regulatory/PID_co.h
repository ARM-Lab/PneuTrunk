/*
 * PID_co.h
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

#ifndef RTW_HEADER_PID_co_h_
#define RTW_HEADER_PID_co_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef PID_co_COMMON_INCLUDES_
#define PID_co_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* PID_co_COMMON_INCLUDES_ */

#include "PID_co_types.h"
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

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
#define rtmGetBlockIO(rtm)             ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
#define rtmSetBlockIO(rtm, val)        ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetRootDWork
#define rtmGetRootDWork(rtm)           ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
#define rtmSetRootDWork(rtm, val)      ((rtm)->dwork = (val))
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#define PID_co_M_TYPE                  RT_MODEL_PID_co_T

/* Block signals (default storage) */

/* Block states (default storage) for system '<Root>' */

/* Real-time Model Data Structure */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern void PID_co_initializeMemory(RT_MODEL_PID_co_T * const PID_co_M, struct PID_c* inst);
extern void PID_co_initialize(RT_MODEL_PID_co_T *const PID_co_M, struct PID_c* inst);
extern void PID_co_step(RT_MODEL_PID_co_T *const PID_co_M, struct PID_c* inst);
extern void PID_co_terminate(RT_MODEL_PID_co_T * PID_co_M, struct PID_c* inst);

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
 * '<Root>' : 'PID_co'
 * '<S1>'   : 'PID_co/Subsystem'
 * '<S2>'   : 'PID_co/Subsystem/AlfaX_baseY2deltaz2'
 * '<S3>'   : 'PID_co/Subsystem/V_PID_Yellow'
 * '<S4>'   : 'PID_co/Subsystem/V_PID_Yellow1'
 * '<S5>'   : 'PID_co/Subsystem/V_PID_blue'
 * '<S6>'   : 'PID_co/Subsystem/abs2relat1'
 * '<S7>'   : 'PID_co/Subsystem/abs2relat2'
 * '<S8>'   : 'PID_co/Subsystem/abs2relat3'
 * '<S9>'   : 'PID_co/Subsystem/abs2relat4'
 * '<S10>'  : 'PID_co/Subsystem/abs2relat7'
 * '<S11>'  : 'PID_co/Subsystem/abs2relat8'
 * '<S12>'  : 'PID_co/Subsystem/AlfaX_baseY2deltaz2/requested alfa 2 deltaz1'
 * '<S13>'  : 'PID_co/Subsystem/V_PID_Yellow/Anti-windup'
 * '<S14>'  : 'PID_co/Subsystem/V_PID_Yellow/D Gain'
 * '<S15>'  : 'PID_co/Subsystem/V_PID_Yellow/Filter'
 * '<S16>'  : 'PID_co/Subsystem/V_PID_Yellow/Filter ICs'
 * '<S17>'  : 'PID_co/Subsystem/V_PID_Yellow/I Gain'
 * '<S18>'  : 'PID_co/Subsystem/V_PID_Yellow/Ideal P Gain'
 * '<S19>'  : 'PID_co/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk'
 * '<S20>'  : 'PID_co/Subsystem/V_PID_Yellow/Integrator'
 * '<S21>'  : 'PID_co/Subsystem/V_PID_Yellow/Integrator ICs'
 * '<S22>'  : 'PID_co/Subsystem/V_PID_Yellow/N Copy'
 * '<S23>'  : 'PID_co/Subsystem/V_PID_Yellow/N Gain'
 * '<S24>'  : 'PID_co/Subsystem/V_PID_Yellow/P Copy'
 * '<S25>'  : 'PID_co/Subsystem/V_PID_Yellow/Parallel P Gain'
 * '<S26>'  : 'PID_co/Subsystem/V_PID_Yellow/Reset Signal'
 * '<S27>'  : 'PID_co/Subsystem/V_PID_Yellow/Saturation'
 * '<S28>'  : 'PID_co/Subsystem/V_PID_Yellow/Saturation Fdbk'
 * '<S29>'  : 'PID_co/Subsystem/V_PID_Yellow/Sum'
 * '<S30>'  : 'PID_co/Subsystem/V_PID_Yellow/Sum Fdbk'
 * '<S31>'  : 'PID_co/Subsystem/V_PID_Yellow/Tracking Mode'
 * '<S32>'  : 'PID_co/Subsystem/V_PID_Yellow/Tracking Mode Sum'
 * '<S33>'  : 'PID_co/Subsystem/V_PID_Yellow/Tsamp - Integral'
 * '<S34>'  : 'PID_co/Subsystem/V_PID_Yellow/Tsamp - Ngain'
 * '<S35>'  : 'PID_co/Subsystem/V_PID_Yellow/postSat Signal'
 * '<S36>'  : 'PID_co/Subsystem/V_PID_Yellow/preSat Signal'
 * '<S37>'  : 'PID_co/Subsystem/V_PID_Yellow/Anti-windup/Passthrough'
 * '<S38>'  : 'PID_co/Subsystem/V_PID_Yellow/D Gain/External Parameters'
 * '<S39>'  : 'PID_co/Subsystem/V_PID_Yellow/Filter/Disc. Forward Euler Filter'
 * '<S40>'  : 'PID_co/Subsystem/V_PID_Yellow/Filter ICs/Internal IC - Filter'
 * '<S41>'  : 'PID_co/Subsystem/V_PID_Yellow/I Gain/External Parameters'
 * '<S42>'  : 'PID_co/Subsystem/V_PID_Yellow/Ideal P Gain/Passthrough'
 * '<S43>'  : 'PID_co/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk/Disabled'
 * '<S44>'  : 'PID_co/Subsystem/V_PID_Yellow/Integrator/Discrete'
 * '<S45>'  : 'PID_co/Subsystem/V_PID_Yellow/Integrator ICs/Internal IC'
 * '<S46>'  : 'PID_co/Subsystem/V_PID_Yellow/N Copy/Disabled'
 * '<S47>'  : 'PID_co/Subsystem/V_PID_Yellow/N Gain/External Parameters'
 * '<S48>'  : 'PID_co/Subsystem/V_PID_Yellow/P Copy/Disabled'
 * '<S49>'  : 'PID_co/Subsystem/V_PID_Yellow/Parallel P Gain/External Parameters'
 * '<S50>'  : 'PID_co/Subsystem/V_PID_Yellow/Reset Signal/External Reset'
 * '<S51>'  : 'PID_co/Subsystem/V_PID_Yellow/Saturation/Enabled'
 * '<S52>'  : 'PID_co/Subsystem/V_PID_Yellow/Saturation Fdbk/Disabled'
 * '<S53>'  : 'PID_co/Subsystem/V_PID_Yellow/Sum/Sum_PID'
 * '<S54>'  : 'PID_co/Subsystem/V_PID_Yellow/Sum Fdbk/Disabled'
 * '<S55>'  : 'PID_co/Subsystem/V_PID_Yellow/Tracking Mode/Disabled'
 * '<S56>'  : 'PID_co/Subsystem/V_PID_Yellow/Tracking Mode Sum/Passthrough'
 * '<S57>'  : 'PID_co/Subsystem/V_PID_Yellow/Tsamp - Integral/Passthrough'
 * '<S58>'  : 'PID_co/Subsystem/V_PID_Yellow/Tsamp - Ngain/Passthrough'
 * '<S59>'  : 'PID_co/Subsystem/V_PID_Yellow/postSat Signal/Forward_Path'
 * '<S60>'  : 'PID_co/Subsystem/V_PID_Yellow/preSat Signal/Forward_Path'
 * '<S61>'  : 'PID_co/Subsystem/V_PID_Yellow1/Anti-windup'
 * '<S62>'  : 'PID_co/Subsystem/V_PID_Yellow1/D Gain'
 * '<S63>'  : 'PID_co/Subsystem/V_PID_Yellow1/Filter'
 * '<S64>'  : 'PID_co/Subsystem/V_PID_Yellow1/Filter ICs'
 * '<S65>'  : 'PID_co/Subsystem/V_PID_Yellow1/I Gain'
 * '<S66>'  : 'PID_co/Subsystem/V_PID_Yellow1/Ideal P Gain'
 * '<S67>'  : 'PID_co/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk'
 * '<S68>'  : 'PID_co/Subsystem/V_PID_Yellow1/Integrator'
 * '<S69>'  : 'PID_co/Subsystem/V_PID_Yellow1/Integrator ICs'
 * '<S70>'  : 'PID_co/Subsystem/V_PID_Yellow1/N Copy'
 * '<S71>'  : 'PID_co/Subsystem/V_PID_Yellow1/N Gain'
 * '<S72>'  : 'PID_co/Subsystem/V_PID_Yellow1/P Copy'
 * '<S73>'  : 'PID_co/Subsystem/V_PID_Yellow1/Parallel P Gain'
 * '<S74>'  : 'PID_co/Subsystem/V_PID_Yellow1/Reset Signal'
 * '<S75>'  : 'PID_co/Subsystem/V_PID_Yellow1/Saturation'
 * '<S76>'  : 'PID_co/Subsystem/V_PID_Yellow1/Saturation Fdbk'
 * '<S77>'  : 'PID_co/Subsystem/V_PID_Yellow1/Sum'
 * '<S78>'  : 'PID_co/Subsystem/V_PID_Yellow1/Sum Fdbk'
 * '<S79>'  : 'PID_co/Subsystem/V_PID_Yellow1/Tracking Mode'
 * '<S80>'  : 'PID_co/Subsystem/V_PID_Yellow1/Tracking Mode Sum'
 * '<S81>'  : 'PID_co/Subsystem/V_PID_Yellow1/Tsamp - Integral'
 * '<S82>'  : 'PID_co/Subsystem/V_PID_Yellow1/Tsamp - Ngain'
 * '<S83>'  : 'PID_co/Subsystem/V_PID_Yellow1/postSat Signal'
 * '<S84>'  : 'PID_co/Subsystem/V_PID_Yellow1/preSat Signal'
 * '<S85>'  : 'PID_co/Subsystem/V_PID_Yellow1/Anti-windup/Passthrough'
 * '<S86>'  : 'PID_co/Subsystem/V_PID_Yellow1/D Gain/External Parameters'
 * '<S87>'  : 'PID_co/Subsystem/V_PID_Yellow1/Filter/Disc. Forward Euler Filter'
 * '<S88>'  : 'PID_co/Subsystem/V_PID_Yellow1/Filter ICs/Internal IC - Filter'
 * '<S89>'  : 'PID_co/Subsystem/V_PID_Yellow1/I Gain/External Parameters'
 * '<S90>'  : 'PID_co/Subsystem/V_PID_Yellow1/Ideal P Gain/Passthrough'
 * '<S91>'  : 'PID_co/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk/Disabled'
 * '<S92>'  : 'PID_co/Subsystem/V_PID_Yellow1/Integrator/Discrete'
 * '<S93>'  : 'PID_co/Subsystem/V_PID_Yellow1/Integrator ICs/Internal IC'
 * '<S94>'  : 'PID_co/Subsystem/V_PID_Yellow1/N Copy/Disabled'
 * '<S95>'  : 'PID_co/Subsystem/V_PID_Yellow1/N Gain/External Parameters'
 * '<S96>'  : 'PID_co/Subsystem/V_PID_Yellow1/P Copy/Disabled'
 * '<S97>'  : 'PID_co/Subsystem/V_PID_Yellow1/Parallel P Gain/External Parameters'
 * '<S98>'  : 'PID_co/Subsystem/V_PID_Yellow1/Reset Signal/External Reset'
 * '<S99>'  : 'PID_co/Subsystem/V_PID_Yellow1/Saturation/Enabled'
 * '<S100>' : 'PID_co/Subsystem/V_PID_Yellow1/Saturation Fdbk/Disabled'
 * '<S101>' : 'PID_co/Subsystem/V_PID_Yellow1/Sum/Sum_PID'
 * '<S102>' : 'PID_co/Subsystem/V_PID_Yellow1/Sum Fdbk/Disabled'
 * '<S103>' : 'PID_co/Subsystem/V_PID_Yellow1/Tracking Mode/Disabled'
 * '<S104>' : 'PID_co/Subsystem/V_PID_Yellow1/Tracking Mode Sum/Passthrough'
 * '<S105>' : 'PID_co/Subsystem/V_PID_Yellow1/Tsamp - Integral/Passthrough'
 * '<S106>' : 'PID_co/Subsystem/V_PID_Yellow1/Tsamp - Ngain/Passthrough'
 * '<S107>' : 'PID_co/Subsystem/V_PID_Yellow1/postSat Signal/Forward_Path'
 * '<S108>' : 'PID_co/Subsystem/V_PID_Yellow1/preSat Signal/Forward_Path'
 * '<S109>' : 'PID_co/Subsystem/V_PID_blue/Anti-windup'
 * '<S110>' : 'PID_co/Subsystem/V_PID_blue/D Gain'
 * '<S111>' : 'PID_co/Subsystem/V_PID_blue/Filter'
 * '<S112>' : 'PID_co/Subsystem/V_PID_blue/Filter ICs'
 * '<S113>' : 'PID_co/Subsystem/V_PID_blue/I Gain'
 * '<S114>' : 'PID_co/Subsystem/V_PID_blue/Ideal P Gain'
 * '<S115>' : 'PID_co/Subsystem/V_PID_blue/Ideal P Gain Fdbk'
 * '<S116>' : 'PID_co/Subsystem/V_PID_blue/Integrator'
 * '<S117>' : 'PID_co/Subsystem/V_PID_blue/Integrator ICs'
 * '<S118>' : 'PID_co/Subsystem/V_PID_blue/N Copy'
 * '<S119>' : 'PID_co/Subsystem/V_PID_blue/N Gain'
 * '<S120>' : 'PID_co/Subsystem/V_PID_blue/P Copy'
 * '<S121>' : 'PID_co/Subsystem/V_PID_blue/Parallel P Gain'
 * '<S122>' : 'PID_co/Subsystem/V_PID_blue/Reset Signal'
 * '<S123>' : 'PID_co/Subsystem/V_PID_blue/Saturation'
 * '<S124>' : 'PID_co/Subsystem/V_PID_blue/Saturation Fdbk'
 * '<S125>' : 'PID_co/Subsystem/V_PID_blue/Sum'
 * '<S126>' : 'PID_co/Subsystem/V_PID_blue/Sum Fdbk'
 * '<S127>' : 'PID_co/Subsystem/V_PID_blue/Tracking Mode'
 * '<S128>' : 'PID_co/Subsystem/V_PID_blue/Tracking Mode Sum'
 * '<S129>' : 'PID_co/Subsystem/V_PID_blue/Tsamp - Integral'
 * '<S130>' : 'PID_co/Subsystem/V_PID_blue/Tsamp - Ngain'
 * '<S131>' : 'PID_co/Subsystem/V_PID_blue/postSat Signal'
 * '<S132>' : 'PID_co/Subsystem/V_PID_blue/preSat Signal'
 * '<S133>' : 'PID_co/Subsystem/V_PID_blue/Anti-windup/Passthrough'
 * '<S134>' : 'PID_co/Subsystem/V_PID_blue/D Gain/External Parameters'
 * '<S135>' : 'PID_co/Subsystem/V_PID_blue/Filter/Disc. Forward Euler Filter'
 * '<S136>' : 'PID_co/Subsystem/V_PID_blue/Filter ICs/Internal IC - Filter'
 * '<S137>' : 'PID_co/Subsystem/V_PID_blue/I Gain/External Parameters'
 * '<S138>' : 'PID_co/Subsystem/V_PID_blue/Ideal P Gain/Passthrough'
 * '<S139>' : 'PID_co/Subsystem/V_PID_blue/Ideal P Gain Fdbk/Disabled'
 * '<S140>' : 'PID_co/Subsystem/V_PID_blue/Integrator/Discrete'
 * '<S141>' : 'PID_co/Subsystem/V_PID_blue/Integrator ICs/Internal IC'
 * '<S142>' : 'PID_co/Subsystem/V_PID_blue/N Copy/Disabled'
 * '<S143>' : 'PID_co/Subsystem/V_PID_blue/N Gain/External Parameters'
 * '<S144>' : 'PID_co/Subsystem/V_PID_blue/P Copy/Disabled'
 * '<S145>' : 'PID_co/Subsystem/V_PID_blue/Parallel P Gain/External Parameters'
 * '<S146>' : 'PID_co/Subsystem/V_PID_blue/Reset Signal/External Reset'
 * '<S147>' : 'PID_co/Subsystem/V_PID_blue/Saturation/Enabled'
 * '<S148>' : 'PID_co/Subsystem/V_PID_blue/Saturation Fdbk/Disabled'
 * '<S149>' : 'PID_co/Subsystem/V_PID_blue/Sum/Sum_PID'
 * '<S150>' : 'PID_co/Subsystem/V_PID_blue/Sum Fdbk/Disabled'
 * '<S151>' : 'PID_co/Subsystem/V_PID_blue/Tracking Mode/Disabled'
 * '<S152>' : 'PID_co/Subsystem/V_PID_blue/Tracking Mode Sum/Passthrough'
 * '<S153>' : 'PID_co/Subsystem/V_PID_blue/Tsamp - Integral/Passthrough'
 * '<S154>' : 'PID_co/Subsystem/V_PID_blue/Tsamp - Ngain/Passthrough'
 * '<S155>' : 'PID_co/Subsystem/V_PID_blue/postSat Signal/Forward_Path'
 * '<S156>' : 'PID_co/Subsystem/V_PID_blue/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_PID_co_h_ */
