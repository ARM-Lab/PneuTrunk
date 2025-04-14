/*
 * regulator_FF_PI.h
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

#ifndef RTW_HEADER_regulator_FF_PI_h_
#define RTW_HEADER_regulator_FF_PI_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#ifndef regulator_FF_PI_COMMON_INCLUDES_
#define regulator_FF_PI_COMMON_INCLUDES_
#include <stdlib.h>
#include "rtwtypes.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#endif                                 /* regulator_FF_PI_COMMON_INCLUDES_ */

#include "regulator_FF_PI_types.h"
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

#define regulator_FF_PI_M_TYPE         RT_MODEL_regulator_FF_PI_T

/* Block signals (default storage) */

/* Block states (default storage) for system '<Root>' */

/* Constant parameters (default storage) */

/* Real-time Model Data Structure */

/* External data declarations for dependent source files */
extern const char *RT_MEMORY_ALLOCATION_ERROR;

/* Constant parameters (default storage) */
extern const ConstP_regulator_FF_PI_T regulator_FF_PI_ConstP;

/* Model entry point functions */
extern void regulator_FF_PI_initializeMemory(RT_MODEL_regulator_FF_PI_T * const regulator_FF_PI_M, struct FF_PID* inst);
extern void regulator_FF_PI_initialize(RT_MODEL_regulator_FF_PI_T *const
  regulator_FF_PI_M, struct FF_PID* inst);
extern void regulator_FF_PI_step(RT_MODEL_regulator_FF_PI_T *const
  regulator_FF_PI_M, struct FF_PID* inst);
extern void regulator_FF_PI_terminate(RT_MODEL_regulator_FF_PI_T
  * regulator_FF_PI_M, struct FF_PID* inst);

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
 * '<Root>' : 'regulator_FF_PI'
 * '<S1>'   : 'regulator_FF_PI/FF_zlozka'
 * '<S2>'   : 'regulator_FF_PI/Subsystem'
 * '<S3>'   : 'regulator_FF_PI/FF_zlozka/ff'
 * '<S4>'   : 'regulator_FF_PI/FF_zlozka/prepinac'
 * '<S5>'   : 'regulator_FF_PI/Subsystem/AlfaX_baseY2deltaz2'
 * '<S6>'   : 'regulator_FF_PI/Subsystem/V_PID_Yellow'
 * '<S7>'   : 'regulator_FF_PI/Subsystem/V_PID_Yellow1'
 * '<S8>'   : 'regulator_FF_PI/Subsystem/V_PID_blue'
 * '<S9>'   : 'regulator_FF_PI/Subsystem/abs2relat1'
 * '<S10>'  : 'regulator_FF_PI/Subsystem/abs2relat2'
 * '<S11>'  : 'regulator_FF_PI/Subsystem/abs2relat3'
 * '<S12>'  : 'regulator_FF_PI/Subsystem/abs2relat4'
 * '<S13>'  : 'regulator_FF_PI/Subsystem/abs2relat7'
 * '<S14>'  : 'regulator_FF_PI/Subsystem/abs2relat8'
 * '<S15>'  : 'regulator_FF_PI/Subsystem/AlfaX_baseY2deltaz2/requested alfa 2 deltaz1'
 * '<S16>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Anti-windup'
 * '<S17>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/D Gain'
 * '<S18>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Filter'
 * '<S19>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Filter ICs'
 * '<S20>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/I Gain'
 * '<S21>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Ideal P Gain'
 * '<S22>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk'
 * '<S23>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Integrator'
 * '<S24>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Integrator ICs'
 * '<S25>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/N Copy'
 * '<S26>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/N Gain'
 * '<S27>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/P Copy'
 * '<S28>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Parallel P Gain'
 * '<S29>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Reset Signal'
 * '<S30>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Saturation'
 * '<S31>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Saturation Fdbk'
 * '<S32>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Sum'
 * '<S33>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Sum Fdbk'
 * '<S34>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tracking Mode'
 * '<S35>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tracking Mode Sum'
 * '<S36>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tsamp - Integral'
 * '<S37>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tsamp - Ngain'
 * '<S38>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/postSat Signal'
 * '<S39>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/preSat Signal'
 * '<S40>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Anti-windup/Passthrough'
 * '<S41>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/D Gain/External Parameters'
 * '<S42>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Filter/Disc. Forward Euler Filter'
 * '<S43>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Filter ICs/Internal IC - Filter'
 * '<S44>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/I Gain/External Parameters'
 * '<S45>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Ideal P Gain/Passthrough'
 * '<S46>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Ideal P Gain Fdbk/Disabled'
 * '<S47>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Integrator/Discrete'
 * '<S48>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Integrator ICs/Internal IC'
 * '<S49>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/N Copy/Disabled'
 * '<S50>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/N Gain/External Parameters'
 * '<S51>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/P Copy/Disabled'
 * '<S52>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Parallel P Gain/External Parameters'
 * '<S53>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Reset Signal/External Reset'
 * '<S54>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Saturation/Passthrough'
 * '<S55>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Saturation Fdbk/Disabled'
 * '<S56>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Sum/Sum_PID'
 * '<S57>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Sum Fdbk/Disabled'
 * '<S58>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tracking Mode/Disabled'
 * '<S59>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tracking Mode Sum/Passthrough'
 * '<S60>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tsamp - Integral/Passthrough'
 * '<S61>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/Tsamp - Ngain/Passthrough'
 * '<S62>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/postSat Signal/Forward_Path'
 * '<S63>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow/preSat Signal/Forward_Path'
 * '<S64>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Anti-windup'
 * '<S65>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/D Gain'
 * '<S66>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Filter'
 * '<S67>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Filter ICs'
 * '<S68>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/I Gain'
 * '<S69>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Ideal P Gain'
 * '<S70>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk'
 * '<S71>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Integrator'
 * '<S72>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Integrator ICs'
 * '<S73>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/N Copy'
 * '<S74>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/N Gain'
 * '<S75>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/P Copy'
 * '<S76>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Parallel P Gain'
 * '<S77>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Reset Signal'
 * '<S78>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Saturation'
 * '<S79>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Saturation Fdbk'
 * '<S80>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Sum'
 * '<S81>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Sum Fdbk'
 * '<S82>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tracking Mode'
 * '<S83>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tracking Mode Sum'
 * '<S84>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tsamp - Integral'
 * '<S85>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tsamp - Ngain'
 * '<S86>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/postSat Signal'
 * '<S87>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/preSat Signal'
 * '<S88>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Anti-windup/Passthrough'
 * '<S89>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/D Gain/External Parameters'
 * '<S90>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Filter/Disc. Forward Euler Filter'
 * '<S91>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Filter ICs/Internal IC - Filter'
 * '<S92>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/I Gain/External Parameters'
 * '<S93>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Ideal P Gain/Passthrough'
 * '<S94>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Ideal P Gain Fdbk/Disabled'
 * '<S95>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Integrator/Discrete'
 * '<S96>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Integrator ICs/Internal IC'
 * '<S97>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/N Copy/Disabled'
 * '<S98>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/N Gain/External Parameters'
 * '<S99>'  : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/P Copy/Disabled'
 * '<S100>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Parallel P Gain/External Parameters'
 * '<S101>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Reset Signal/External Reset'
 * '<S102>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Saturation/Passthrough'
 * '<S103>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Saturation Fdbk/Disabled'
 * '<S104>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Sum/Sum_PID'
 * '<S105>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Sum Fdbk/Disabled'
 * '<S106>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tracking Mode/Disabled'
 * '<S107>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tracking Mode Sum/Passthrough'
 * '<S108>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tsamp - Integral/Passthrough'
 * '<S109>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/Tsamp - Ngain/Passthrough'
 * '<S110>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/postSat Signal/Forward_Path'
 * '<S111>' : 'regulator_FF_PI/Subsystem/V_PID_Yellow1/preSat Signal/Forward_Path'
 * '<S112>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Anti-windup'
 * '<S113>' : 'regulator_FF_PI/Subsystem/V_PID_blue/D Gain'
 * '<S114>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Filter'
 * '<S115>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Filter ICs'
 * '<S116>' : 'regulator_FF_PI/Subsystem/V_PID_blue/I Gain'
 * '<S117>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Ideal P Gain'
 * '<S118>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Ideal P Gain Fdbk'
 * '<S119>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Integrator'
 * '<S120>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Integrator ICs'
 * '<S121>' : 'regulator_FF_PI/Subsystem/V_PID_blue/N Copy'
 * '<S122>' : 'regulator_FF_PI/Subsystem/V_PID_blue/N Gain'
 * '<S123>' : 'regulator_FF_PI/Subsystem/V_PID_blue/P Copy'
 * '<S124>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Parallel P Gain'
 * '<S125>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Reset Signal'
 * '<S126>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Saturation'
 * '<S127>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Saturation Fdbk'
 * '<S128>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Sum'
 * '<S129>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Sum Fdbk'
 * '<S130>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tracking Mode'
 * '<S131>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tracking Mode Sum'
 * '<S132>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tsamp - Integral'
 * '<S133>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tsamp - Ngain'
 * '<S134>' : 'regulator_FF_PI/Subsystem/V_PID_blue/postSat Signal'
 * '<S135>' : 'regulator_FF_PI/Subsystem/V_PID_blue/preSat Signal'
 * '<S136>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Anti-windup/Passthrough'
 * '<S137>' : 'regulator_FF_PI/Subsystem/V_PID_blue/D Gain/External Parameters'
 * '<S138>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Filter/Disc. Forward Euler Filter'
 * '<S139>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Filter ICs/Internal IC - Filter'
 * '<S140>' : 'regulator_FF_PI/Subsystem/V_PID_blue/I Gain/External Parameters'
 * '<S141>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Ideal P Gain/Passthrough'
 * '<S142>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Ideal P Gain Fdbk/Disabled'
 * '<S143>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Integrator/Discrete'
 * '<S144>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Integrator ICs/Internal IC'
 * '<S145>' : 'regulator_FF_PI/Subsystem/V_PID_blue/N Copy/Disabled'
 * '<S146>' : 'regulator_FF_PI/Subsystem/V_PID_blue/N Gain/External Parameters'
 * '<S147>' : 'regulator_FF_PI/Subsystem/V_PID_blue/P Copy/Disabled'
 * '<S148>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Parallel P Gain/External Parameters'
 * '<S149>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Reset Signal/External Reset'
 * '<S150>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Saturation/Passthrough'
 * '<S151>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Saturation Fdbk/Disabled'
 * '<S152>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Sum/Sum_PID'
 * '<S153>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Sum Fdbk/Disabled'
 * '<S154>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tracking Mode/Disabled'
 * '<S155>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tracking Mode Sum/Passthrough'
 * '<S156>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tsamp - Integral/Passthrough'
 * '<S157>' : 'regulator_FF_PI/Subsystem/V_PID_blue/Tsamp - Ngain/Passthrough'
 * '<S158>' : 'regulator_FF_PI/Subsystem/V_PID_blue/postSat Signal/Forward_Path'
 * '<S159>' : 'regulator_FF_PI/Subsystem/V_PID_blue/preSat Signal/Forward_Path'
 */
#endif                                 /* RTW_HEADER_regulator_FF_PI_h_ */
