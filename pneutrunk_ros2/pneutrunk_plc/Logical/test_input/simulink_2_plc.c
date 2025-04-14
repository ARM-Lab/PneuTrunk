/*
 * simulink_2_plc.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "simulink_2_plc".
 *
 * Model version              : 1.4
 * Simulink Coder version : 9.9 (R2023a) 19-Nov-2022
 * C source code generated on : Tue Feb  6 09:08:04 2024
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "simulink_2_plc.h"
#include <math.h>
#include "rtwtypes.h"
#include "rt_nonfinite.h"
#include "simulink_2_plc_dt.h"

/* Block signals (default storage) */
B_simulink_2_plc_T simulink_2_plc_B;

/* Real-time model */
static RT_MODEL_simulink_2_plc_T simulink_2_plc_M_;
RT_MODEL_simulink_2_plc_T *const simulink_2_plc_M = &simulink_2_plc_M_;

/* Model output function */
void simulink_2_plc_output(void)
{
  /* Sin: '<Root>/Sine Wave' */
  simulink_2_plc_B.SineWave = sin(simulink_2_plc_P.SineWave_Freq *
    simulink_2_plc_M->Timing.t[0] + simulink_2_plc_P.SineWave_Phase) *
    simulink_2_plc_P.SineWave_Amp + simulink_2_plc_P.SineWave_Bias;

  /* Gain: '<Root>/Gain' */
  simulink_2_plc_B.Gain = (real32_T)(simulink_2_plc_P.Gain_Gain *
    simulink_2_plc_B.SineWave);

  /* S-Function (bur_out): '<Root>/Output' */
  cos_test_hodnota2 = simulink_2_plc_B.Gain;

  /* Sin: '<Root>/Sine Wave1' */
  simulink_2_plc_B.SineWave1 = sin(simulink_2_plc_P.SineWave1_Freq *
    simulink_2_plc_M->Timing.t[0] + simulink_2_plc_P.SineWave1_Phase) *
    simulink_2_plc_P.SineWave1_Amp + simulink_2_plc_P.SineWave1_Bias;

  /* Gain: '<Root>/Gain1' */
  simulink_2_plc_B.Gain1 = (real32_T)(simulink_2_plc_P.Gain1_Gain *
    simulink_2_plc_B.SineWave1);

  /* S-Function (bur_out): '<Root>/Output1' */
  cos_test_hodnota1 = simulink_2_plc_B.Gain1;
}

/* Model update function */
void simulink_2_plc_update(void)
{
  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++simulink_2_plc_M->Timing.clockTick0)) {
    ++simulink_2_plc_M->Timing.clockTickH0;
  }

  simulink_2_plc_M->Timing.t[0] = simulink_2_plc_M->Timing.clockTick0 *
    simulink_2_plc_M->Timing.stepSize0 + simulink_2_plc_M->Timing.clockTickH0 *
    simulink_2_plc_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.012s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++simulink_2_plc_M->Timing.clockTick1)) {
      ++simulink_2_plc_M->Timing.clockTickH1;
    }

    simulink_2_plc_M->Timing.t[1] = simulink_2_plc_M->Timing.clockTick1 *
      simulink_2_plc_M->Timing.stepSize1 + simulink_2_plc_M->Timing.clockTickH1 *
      simulink_2_plc_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
void simulink_2_plc_initialize(void)
{
}

/* Model terminate function */
void simulink_2_plc_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  simulink_2_plc_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  simulink_2_plc_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  simulink_2_plc_initialize();
}

void MdlTerminate(void)
{
  simulink_2_plc_terminate();
}

/* Registration function */
RT_MODEL_simulink_2_plc_T *simulink_2_plc(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)simulink_2_plc_M, 0,
                sizeof(RT_MODEL_simulink_2_plc_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&simulink_2_plc_M->solverInfo,
                          &simulink_2_plc_M->Timing.simTimeStep);
    rtsiSetTPtr(&simulink_2_plc_M->solverInfo, &rtmGetTPtr(simulink_2_plc_M));
    rtsiSetStepSizePtr(&simulink_2_plc_M->solverInfo,
                       &simulink_2_plc_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&simulink_2_plc_M->solverInfo, (&rtmGetErrorStatus
      (simulink_2_plc_M)));
    rtsiSetRTModelPtr(&simulink_2_plc_M->solverInfo, simulink_2_plc_M);
  }

  rtsiSetSimTimeStep(&simulink_2_plc_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&simulink_2_plc_M->solverInfo,"FixedStepDiscrete");

  /* Initialize timing info */
  {
    int_T *mdlTsMap = simulink_2_plc_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "simulink_2_plc_M points to
       static memory which is guaranteed to be non-NULL" */
    simulink_2_plc_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    simulink_2_plc_M->Timing.sampleTimes =
      (&simulink_2_plc_M->Timing.sampleTimesArray[0]);
    simulink_2_plc_M->Timing.offsetTimes =
      (&simulink_2_plc_M->Timing.offsetTimesArray[0]);

    /* task periods */
    simulink_2_plc_M->Timing.sampleTimes[0] = (0.0);
    simulink_2_plc_M->Timing.sampleTimes[1] = (0.012);

    /* task offsets */
    simulink_2_plc_M->Timing.offsetTimes[0] = (0.0);
    simulink_2_plc_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(simulink_2_plc_M, &simulink_2_plc_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = simulink_2_plc_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    simulink_2_plc_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(simulink_2_plc_M, -1);
  simulink_2_plc_M->Timing.stepSize0 = 0.012;
  simulink_2_plc_M->Timing.stepSize1 = 0.012;

  /* External mode info */
  simulink_2_plc_M->Sizes.checksums[0] = (3322673890U);
  simulink_2_plc_M->Sizes.checksums[1] = (3210621631U);
  simulink_2_plc_M->Sizes.checksums[2] = (3529363431U);
  simulink_2_plc_M->Sizes.checksums[3] = (3889799710U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    simulink_2_plc_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(simulink_2_plc_M->extModeInfo,
      &simulink_2_plc_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(simulink_2_plc_M->extModeInfo,
                        simulink_2_plc_M->Sizes.checksums);
    rteiSetTPtr(simulink_2_plc_M->extModeInfo, rtmGetTPtr(simulink_2_plc_M));
  }

  simulink_2_plc_M->solverInfoPtr = (&simulink_2_plc_M->solverInfo);
  simulink_2_plc_M->Timing.stepSize = (0.012);
  rtsiSetFixedStepSize(&simulink_2_plc_M->solverInfo, 0.012);
  rtsiSetSolverMode(&simulink_2_plc_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  simulink_2_plc_M->blockIO = ((void *) &simulink_2_plc_B);

  {
    simulink_2_plc_B.SineWave = 0.0;
    simulink_2_plc_B.SineWave1 = 0.0;
    simulink_2_plc_B.Gain = 0.0F;
    simulink_2_plc_B.Gain1 = 0.0F;
  }

  /* parameters */
  simulink_2_plc_M->defaultParam = ((real_T *)&simulink_2_plc_P);

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    simulink_2_plc_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;

    /* Parameters transition table */
    dtInfo.PTransTable = &rtPTransTable;
  }

  /* Initialize Sizes */
  simulink_2_plc_M->Sizes.numContStates = (0);/* Number of continuous states */
  simulink_2_plc_M->Sizes.numY = (0);  /* Number of model outputs */
  simulink_2_plc_M->Sizes.numU = (0);  /* Number of model inputs */
  simulink_2_plc_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  simulink_2_plc_M->Sizes.numSampTimes = (2);/* Number of sample times */
  simulink_2_plc_M->Sizes.numBlocks = (7);/* Number of blocks */
  simulink_2_plc_M->Sizes.numBlockIO = (4);/* Number of block outputs */
  simulink_2_plc_M->Sizes.numBlockPrms = (10);/* Sum of parameter "widths" */
  return simulink_2_plc_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
