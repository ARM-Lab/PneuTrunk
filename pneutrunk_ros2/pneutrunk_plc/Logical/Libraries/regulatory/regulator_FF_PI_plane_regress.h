/*
 * regulator_FF_PI_plane_regress.h
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

#ifndef RTW_HEADER_regulator_FF_PI_plane_regress_h_
#define RTW_HEADER_regulator_FF_PI_plane_regress_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef regulator_FF_PI_plane_regress_COMMON_INCLUDES_
#define regulator_FF_PI_plane_regress_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                      /* regulator_FF_PI_plane_regress_COMMON_INCLUDES_ */

#include "regulator_FF_PI_plane_regress_types.h"
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

#define regulator_FF_PI_plane_regress_M_TYPE RT_MODEL_regulator_FF_PI_plan_T

/* Block signals (default storage) */

/* Block states (default storage) for system '<Root>' */

/* Real-time Model Data Structure */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Model entry point functions */
extern void regulator_FF_PI_plane_regress_initializeMemory(RT_MODEL_regulator_FF_PI_plan_T * const regulator_FF_PI_plane_regress_M, struct FF_PID_r* inst);
extern void regulator_FF_PI_plane_regress_initialize
  (RT_MODEL_regulator_FF_PI_plan_T *const regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst);
extern void regulator_FF_PI_plane_regress_step(RT_MODEL_regulator_FF_PI_plan_T *
  const regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst);
extern void regulator_FF_PI_plane_regress_terminate
  (RT_MODEL_regulator_FF_PI_plan_T * regulator_FF_PI_plane_regres_M, struct FF_PID_r* inst);

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
 * '<Root>' : 'regulator_FF_PI_plane_regress'
 * '<S1>'   : 'regulator_FF_PI_plane_regress/FF_zlozka'
 * '<S2>'   : 'regulator_FF_PI_plane_regress/Subsystem'
 * '<S3>'   : 'regulator_FF_PI_plane_regress/FF_zlozka/MATLAB Function'
 * '<S4>'   : 'regulator_FF_PI_plane_regress/Subsystem/AlfaX_baseY2deltaz2'
 * '<S5>'   : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow'
 * '<S6>'   : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1'
 * '<S7>'   : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue'
 * '<S8>'   : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat1'
 * '<S9>'   : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat2'
 * '<S10>'  : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat3'
 * '<S11>'  : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat4'
 * '<S12>'  : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat7'
 * '<S13>'  : 'regulator_FF_PI_plane_regress/Subsystem/abs2relat8'
 * '<S14>'  : 'regulator_FF_PI_plane_regress/Subsystem/AlfaX_baseY2deltaz2/requested alfa 2 deltaz1'
 * '<S15>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Anti-windup'
 * '<S16>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/D Gain'
 * '<S17>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Filter'
 * '<S18>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Filter ICs'
 * '<S19>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/I Gain'
 * '<S20>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Ideal P Gain'
 * '<S21>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk'
 * '<S22>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Integrator'
 * '<S23>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Integrator ICs'
 * '<S24>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/N Copy'
 * '<S25>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/N Gain'
 * '<S26>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/P Copy'
 * '<S27>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Parallel P Gain'
 * '<S28>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Reset Signal'
 * '<S29>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Saturation'
 * '<S30>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Saturation Fdbk'
 * '<S31>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Sum'
 * '<S32>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Sum Fdbk'
 * '<S33>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tracking Mode'
 * '<S34>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tracking Mode Sum'
 * '<S35>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tsamp - Integral'
 * '<S36>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tsamp - Ngain'
 * '<S37>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/postSat Signal'
 * '<S38>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/preSat Signal'
 * '<S39>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Anti-windup/Passthrough'
 * '<S40>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/D Gain/External Parameters'
 * '<S41>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Filter/Disc. Forward Euler Filter'
 * '<S42>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Filter ICs/Internal IC - Filter'
 * '<S43>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/I Gain/External Parameters'
 * '<S44>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Ideal P Gain/Passthrough'
 * '<S45>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk/Disabled'
 * '<S46>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Integrator/Discrete'
 * '<S47>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Integrator ICs/Internal IC'
 * '<S48>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/N Copy/Disabled'
 * '<S49>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/N Gain/External Parameters'
 * '<S50>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/P Copy/Disabled'
 * '<S51>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Parallel P Gain/External Parameters'
 * '<S52>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Reset Signal/External Reset'
 * '<S53>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Saturation/Passthrough'
 * '<S54>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Saturation Fdbk/Disabled'
 * '<S55>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Sum/Sum_PID'
 * '<S56>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Sum Fdbk/Disabled'
 * '<S57>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tracking Mode/Disabled'
 * '<S58>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tracking Mode Sum/Passthrough'
 * '<S59>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tsamp - Integral/Passthrough'
 * '<S60>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/Tsamp - Ngain/Passthrough'
 * '<S61>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/postSat Signal/Forward_Path'
 * '<S62>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow/preSat Signal/Forward_Path'
 * '<S63>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Anti-windup'
 * '<S64>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/D Gain'
 * '<S65>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Filter'
 * '<S66>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Filter ICs'
 * '<S67>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/I Gain'
 * '<S68>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Ideal P Gain'
 * '<S69>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk'
 * '<S70>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Integrator'
 * '<S71>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Integrator ICs'
 * '<S72>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/N Copy'
 * '<S73>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/N Gain'
 * '<S74>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/P Copy'
 * '<S75>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Parallel P Gain'
 * '<S76>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Reset Signal'
 * '<S77>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Saturation'
 * '<S78>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Saturation Fdbk'
 * '<S79>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Sum'
 * '<S80>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Sum Fdbk'
 * '<S81>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tracking Mode'
 * '<S82>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tracking Mode Sum'
 * '<S83>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tsamp - Integral'
 * '<S84>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tsamp - Ngain'
 * '<S85>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/postSat Signal'
 * '<S86>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/preSat Signal'
 * '<S87>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Anti-windup/Passthrough'
 * '<S88>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/D Gain/External Parameters'
 * '<S89>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Filter/Disc. Forward Euler Filter'
 * '<S90>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Filter ICs/Internal IC - Filter'
 * '<S91>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/I Gain/External Parameters'
 * '<S92>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Ideal P Gain/Passthrough'
 * '<S93>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk/Disabled'
 * '<S94>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Integrator/Discrete'
 * '<S95>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Integrator ICs/Internal IC'
 * '<S96>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/N Copy/Disabled'
 * '<S97>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/N Gain/External Parameters'
 * '<S98>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/P Copy/Disabled'
 * '<S99>'  : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Parallel P Gain/External Parameters'
 * '<S100>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Reset Signal/External Reset'
 * '<S101>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Saturation/Passthrough'
 * '<S102>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Saturation Fdbk/Disabled'
 * '<S103>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Sum/Sum_PID'
 * '<S104>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Sum Fdbk/Disabled'
 * '<S105>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tracking Mode/Disabled'
 * '<S106>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tracking Mode Sum/Passthrough'
 * '<S107>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tsamp - Integral/Passthrough'
 * '<S108>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/Tsamp - Ngain/Passthrough'
 * '<S109>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/postSat Signal/Forward_Path'
 * '<S110>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_Yellow1/preSat Signal/Forward_Path'
 * '<S111>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Anti-windup'
 * '<S112>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/D Gain'
 * '<S113>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Filter'
 * '<S114>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Filter ICs'
 * '<S115>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/I Gain'
 * '<S116>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Ideal P Gain'
 * '<S117>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Ideal P Gain Fdbk'
 * '<S118>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Integrator'
 * '<S119>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Integrator ICs'
 * '<S120>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/N Copy'
 * '<S121>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/N Gain'
 * '<S122>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/P Copy'
 * '<S123>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Parallel P Gain'
 * '<S124>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Reset Signal'
 * '<S125>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Saturation'
 * '<S126>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Saturation Fdbk'
 * '<S127>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Sum'
 * '<S128>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Sum Fdbk'
 * '<S129>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tracking Mode'
 * '<S130>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tracking Mode Sum'
 * '<S131>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tsamp - Integral'
 * '<S132>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tsamp - Ngain'
 * '<S133>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/postSat Signal'
 * '<S134>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/preSat Signal'
 * '<S135>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Anti-windup/Passthrough'
 * '<S136>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/D Gain/External Parameters'
 * '<S137>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Filter/Disc. Forward Euler Filter'
 * '<S138>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Filter ICs/Internal IC - Filter'
 * '<S139>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/I Gain/External Parameters'
 * '<S140>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Ideal P Gain/Passthrough'
 * '<S141>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Ideal P Gain Fdbk/Disabled'
 * '<S142>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Integrator/Discrete'
 * '<S143>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Integrator ICs/Internal IC'
 * '<S144>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/N Copy/Disabled'
 * '<S145>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/N Gain/External Parameters'
 * '<S146>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/P Copy/Disabled'
 * '<S147>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Parallel P Gain/External Parameters'
 * '<S148>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Reset Signal/External Reset'
 * '<S149>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Saturation/Passthrough'
 * '<S150>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Saturation Fdbk/Disabled'
 * '<S151>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Sum/Sum_PID'
 * '<S152>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Sum Fdbk/Disabled'
 * '<S153>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tracking Mode/Disabled'
 * '<S154>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tracking Mode Sum/Passthrough'
 * '<S155>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tsamp - Integral/Passthrough'
 * '<S156>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/Tsamp - Ngain/Passthrough'
 * '<S157>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/postSat Signal/Forward_Path'
 * '<S158>' : 'regulator_FF_PI_plane_regress/Subsystem/V_PID_blue/preSat Signal/Forward_Path'
 */
#endif                         /* RTW_HEADER_regulator_FF_PI_plane_regress_h_ */
