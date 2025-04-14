/*
 * reg_FF_PI_pl_regr_stiff.h
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

#ifndef RTW_HEADER_reg_FF_PI_pl_regr_stiff_h_
#define RTW_HEADER_reg_FF_PI_pl_regr_stiff_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef reg_FF_PI_pl_regr_stiff_COMMON_INCLUDES_
#define reg_FF_PI_pl_regr_stiff_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                            /* reg_FF_PI_pl_regr_stiff_COMMON_INCLUDES_ */

#include "reg_FF_PI_pl_regr_stiff_types.h"
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

#define reg_FF_PI_pl_regr_stiff_M_TYPE RT_MODEL_reg_FF_PI_pl_regr_st_T

/* Block signals (default storage) */

/* Block states (default storage) for system '<Root>' */

/* Constant parameters (default storage) */

/* Real-time Model Data Structure */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Constant parameters (default storage) */
extern const ConstP_reg_FF_PI_pl_regr_stif_T reg_FF_PI_pl_regr_stiff_ConstP;

/* Model entry point functions */
extern void reg_FF_PI_pl_regr_stiff_initializeMemory(RT_MODEL_reg_FF_PI_pl_regr_st_T * const reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst);
extern void reg_FF_PI_pl_regr_stiff_initialize(RT_MODEL_reg_FF_PI_pl_regr_st_T *
  const reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst);
extern void reg_FF_PI_pl_regr_stiff_step(RT_MODEL_reg_FF_PI_pl_regr_st_T *const
  reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst);
extern void reg_FF_PI_pl_regr_stiff_terminate(RT_MODEL_reg_FF_PI_pl_regr_st_T
  * reg_FF_PI_pl_regr_stiff_M, struct FF_PID_r_t* inst);

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
 * '<Root>' : 'reg_FF_PI_pl_regr_stiff'
 * '<S1>'   : 'reg_FF_PI_pl_regr_stiff/FF_zlozka'
 * '<S2>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem'
 * '<S3>'   : 'reg_FF_PI_pl_regr_stiff/FF_zlozka/MATLAB Function'
 * '<S4>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/AlfaX_baseY2deltaz2'
 * '<S5>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow'
 * '<S6>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1'
 * '<S7>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue'
 * '<S8>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat1'
 * '<S9>'   : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat2'
 * '<S10>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat3'
 * '<S11>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat4'
 * '<S12>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat7'
 * '<S13>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/abs2relat8'
 * '<S14>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/AlfaX_baseY2deltaz2/requested alfa 2 deltaz1'
 * '<S15>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Anti-windup'
 * '<S16>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/D Gain'
 * '<S17>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Filter'
 * '<S18>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Filter ICs'
 * '<S19>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/I Gain'
 * '<S20>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Ideal P Gain'
 * '<S21>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk'
 * '<S22>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Integrator'
 * '<S23>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Integrator ICs'
 * '<S24>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/N Copy'
 * '<S25>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/N Gain'
 * '<S26>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/P Copy'
 * '<S27>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Parallel P Gain'
 * '<S28>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Reset Signal'
 * '<S29>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Saturation'
 * '<S30>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Saturation Fdbk'
 * '<S31>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Sum'
 * '<S32>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Sum Fdbk'
 * '<S33>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tracking Mode'
 * '<S34>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tracking Mode Sum'
 * '<S35>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tsamp - Integral'
 * '<S36>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tsamp - Ngain'
 * '<S37>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/postSat Signal'
 * '<S38>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/preSat Signal'
 * '<S39>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Anti-windup/Passthrough'
 * '<S40>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/D Gain/External Parameters'
 * '<S41>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Filter/Disc. Forward Euler Filter'
 * '<S42>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Filter ICs/Internal IC - Filter'
 * '<S43>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/I Gain/External Parameters'
 * '<S44>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Ideal P Gain/Passthrough'
 * '<S45>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Integrator/Discrete'
 * '<S47>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Integrator ICs/Internal IC'
 * '<S48>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/N Copy/Disabled'
 * '<S49>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/N Gain/External Parameters'
 * '<S50>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/P Copy/Disabled'
 * '<S51>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Parallel P Gain/External Parameters'
 * '<S52>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Reset Signal/External Reset'
 * '<S53>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Saturation/External'
 * '<S54>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Saturation/External/Saturation Dynamic'
 * '<S55>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Saturation Fdbk/Disabled'
 * '<S56>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Sum/Sum_PID'
 * '<S57>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Sum Fdbk/Disabled'
 * '<S58>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tracking Mode/Disabled'
 * '<S59>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/postSat Signal/Forward_Path'
 * '<S63>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow/preSat Signal/Forward_Path'
 * '<S64>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Anti-windup'
 * '<S65>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/D Gain'
 * '<S66>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Filter'
 * '<S67>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Filter ICs'
 * '<S68>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/I Gain'
 * '<S69>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Ideal P Gain'
 * '<S70>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk'
 * '<S71>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Integrator'
 * '<S72>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Integrator ICs'
 * '<S73>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/N Copy'
 * '<S74>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/N Gain'
 * '<S75>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/P Copy'
 * '<S76>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Parallel P Gain'
 * '<S77>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Reset Signal'
 * '<S78>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Saturation'
 * '<S79>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Saturation Fdbk'
 * '<S80>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Sum'
 * '<S81>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Sum Fdbk'
 * '<S82>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tracking Mode'
 * '<S83>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tracking Mode Sum'
 * '<S84>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tsamp - Integral'
 * '<S85>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tsamp - Ngain'
 * '<S86>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/postSat Signal'
 * '<S87>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/preSat Signal'
 * '<S88>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Anti-windup/Passthrough'
 * '<S89>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/D Gain/External Parameters'
 * '<S90>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/I Gain/External Parameters'
 * '<S93>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Integrator/Discrete'
 * '<S96>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Integrator ICs/Internal IC'
 * '<S97>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/N Copy/Disabled'
 * '<S98>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/N Gain/External Parameters'
 * '<S99>'  : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/P Copy/Disabled'
 * '<S100>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Parallel P Gain/External Parameters'
 * '<S101>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Reset Signal/External Reset'
 * '<S102>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Saturation/External'
 * '<S103>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Saturation/External/Saturation Dynamic'
 * '<S104>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Saturation Fdbk/Disabled'
 * '<S105>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Sum/Sum_PID'
 * '<S106>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Sum Fdbk/Disabled'
 * '<S107>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tracking Mode/Disabled'
 * '<S108>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tracking Mode Sum/Passthrough'
 * '<S109>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tsamp - Integral/Passthrough'
 * '<S110>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/Tsamp - Ngain/Passthrough'
 * '<S111>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/postSat Signal/Forward_Path'
 * '<S112>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_Yellow1/preSat Signal/Forward_Path'
 * '<S113>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Anti-windup'
 * '<S114>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/D Gain'
 * '<S115>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Filter'
 * '<S116>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Filter ICs'
 * '<S117>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/I Gain'
 * '<S118>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Ideal P Gain'
 * '<S119>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Ideal P Gain Fdbk'
 * '<S120>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Integrator'
 * '<S121>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Integrator ICs'
 * '<S122>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/N Copy'
 * '<S123>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/N Gain'
 * '<S124>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/P Copy'
 * '<S125>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Parallel P Gain'
 * '<S126>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Reset Signal'
 * '<S127>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Saturation'
 * '<S128>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Saturation Fdbk'
 * '<S129>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Sum'
 * '<S130>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Sum Fdbk'
 * '<S131>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tracking Mode'
 * '<S132>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tracking Mode Sum'
 * '<S133>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tsamp - Integral'
 * '<S134>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tsamp - Ngain'
 * '<S135>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/postSat Signal'
 * '<S136>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/preSat Signal'
 * '<S137>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Anti-windup/Passthrough'
 * '<S138>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/D Gain/External Parameters'
 * '<S139>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Filter/Disc. Forward Euler Filter'
 * '<S140>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Filter ICs/Internal IC - Filter'
 * '<S141>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/I Gain/External Parameters'
 * '<S142>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Ideal P Gain/Passthrough'
 * '<S143>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Ideal P Gain Fdbk/Disabled'
 * '<S144>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Integrator/Discrete'
 * '<S145>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Integrator ICs/Internal IC'
 * '<S146>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/N Copy/Disabled'
 * '<S147>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/N Gain/External Parameters'
 * '<S148>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/P Copy/Disabled'
 * '<S149>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Parallel P Gain/External Parameters'
 * '<S150>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Reset Signal/External Reset'
 * '<S151>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Saturation/External'
 * '<S152>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Saturation/External/Saturation Dynamic'
 * '<S153>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Saturation Fdbk/Disabled'
 * '<S154>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Sum/Sum_PID'
 * '<S155>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Sum Fdbk/Disabled'
 * '<S156>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tracking Mode/Disabled'
 * '<S157>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tracking Mode Sum/Passthrough'
 * '<S158>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tsamp - Integral/Passthrough'
 * '<S159>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/Tsamp - Ngain/Passthrough'
 * '<S160>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/postSat Signal/Forward_Path'
 * '<S161>' : 'reg_FF_PI_pl_regr_stiff/Subsystem/V_PID_blue/preSat Signal/Forward_Path'
 */
#endif                               /* RTW_HEADER_reg_FF_PI_pl_regr_stiff_h_ */
