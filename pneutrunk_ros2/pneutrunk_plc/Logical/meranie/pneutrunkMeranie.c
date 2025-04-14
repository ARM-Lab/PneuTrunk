/*
 * pneutrunkMeranie.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "pneutrunkMeranie".
 *
 * Model version              : 1.6
 * Simulink Coder version : 9.8 (R2022b) 13-May-2022
 * C source code generated on : Wed May 24 11:04:27 2023
 *
 * Target selection: bur_grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Intel->x86/Pentium
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "pneutrunkMeranie.h"
#include <string.h>
#include "rt_nonfinite.h"
#include "pneutrunkMeranie_dt.h"

/* Block signals (default storage) */
B_pneutrunkMeranie_T pneutrunkMeranie_B;

/* Block states (default storage) */
DW_pneutrunkMeranie_T pneutrunkMeranie_DW;

/* Real-time model */
static RT_MODEL_pneutrunkMeranie_T pneutrunkMeranie_M_;
RT_MODEL_pneutrunkMeranie_T *const pneutrunkMeranie_M = &pneutrunkMeranie_M_;

/* Model output function */
void pneutrunkMeranie_output(void)
{
  /* S-Function (bur_in): '<Root>/Input3' */
  pneutrunkMeranie_B.Input3 = u1;

  /* S-Function (bur_in): '<Root>/Input' */
  pneutrunkMeranie_B.Input = p1;

  /* S-Function (bur_in): '<Root>/Input1' */
  pneutrunkMeranie_B.Input1 = p2;

  /* S-Function (bur_in): '<Root>/Input2' */
  pneutrunkMeranie_B.Input2 = p3;

  /* S-Function (bur_in): '<Root>/Input4' */
  pneutrunkMeranie_B.Input4 = u2;

  /* S-Function (bur_in): '<Root>/Input5' */
  pneutrunkMeranie_B.Input5 = result;
}

/* Model update function */
void pneutrunkMeranie_update(void)
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
  if (!(++pneutrunkMeranie_M->Timing.clockTick0)) {
    ++pneutrunkMeranie_M->Timing.clockTickH0;
  }

  pneutrunkMeranie_M->Timing.t[0] = pneutrunkMeranie_M->Timing.clockTick0 *
    pneutrunkMeranie_M->Timing.stepSize0 +
    pneutrunkMeranie_M->Timing.clockTickH0 *
    pneutrunkMeranie_M->Timing.stepSize0 * 4294967296.0;
}

/* Model initialize function */
void pneutrunkMeranie_initialize(void)
{
}

/* Model terminate function */
void pneutrunkMeranie_terminate(void)
{
  /* (no terminate code required) */
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  pneutrunkMeranie_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  pneutrunkMeranie_update();
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
  pneutrunkMeranie_initialize();
}

void MdlTerminate(void)
{
  pneutrunkMeranie_terminate();
}

/* Registration function */
RT_MODEL_pneutrunkMeranie_T *pneutrunkMeranie(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)pneutrunkMeranie_M, 0,
                sizeof(RT_MODEL_pneutrunkMeranie_T));

  /* Initialize timing info */
  {
    int_T *mdlTsMap = pneutrunkMeranie_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;

    /* polyspace +2 MISRA2012:D4.1 [Justified:Low] "pneutrunkMeranie_M points to
       static memory which is guaranteed to be non-NULL" */
    pneutrunkMeranie_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    pneutrunkMeranie_M->Timing.sampleTimes =
      (&pneutrunkMeranie_M->Timing.sampleTimesArray[0]);
    pneutrunkMeranie_M->Timing.offsetTimes =
      (&pneutrunkMeranie_M->Timing.offsetTimesArray[0]);

    /* task periods */
    pneutrunkMeranie_M->Timing.sampleTimes[0] = (0.1);

    /* task offsets */
    pneutrunkMeranie_M->Timing.offsetTimes[0] = (0.0);
  }

  rtmSetTPtr(pneutrunkMeranie_M, &pneutrunkMeranie_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = pneutrunkMeranie_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    pneutrunkMeranie_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(pneutrunkMeranie_M, -1);
  pneutrunkMeranie_M->Timing.stepSize0 = 0.1;

  /* External mode info */
  pneutrunkMeranie_M->Sizes.checksums[0] = (272960474U);
  pneutrunkMeranie_M->Sizes.checksums[1] = (2602910742U);
  pneutrunkMeranie_M->Sizes.checksums[2] = (2322055424U);
  pneutrunkMeranie_M->Sizes.checksums[3] = (1324330691U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[1];
    pneutrunkMeranie_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(pneutrunkMeranie_M->extModeInfo,
      &pneutrunkMeranie_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(pneutrunkMeranie_M->extModeInfo,
                        pneutrunkMeranie_M->Sizes.checksums);
    rteiSetTPtr(pneutrunkMeranie_M->extModeInfo, rtmGetTPtr(pneutrunkMeranie_M));
  }

  pneutrunkMeranie_M->solverInfoPtr = (&pneutrunkMeranie_M->solverInfo);
  pneutrunkMeranie_M->Timing.stepSize = (0.1);
  rtsiSetFixedStepSize(&pneutrunkMeranie_M->solverInfo, 0.1);
  rtsiSetSolverMode(&pneutrunkMeranie_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  pneutrunkMeranie_M->blockIO = ((void *) &pneutrunkMeranie_B);
  (void) memset(((void *) &pneutrunkMeranie_B), 0,
                sizeof(B_pneutrunkMeranie_T));

  {
    pneutrunkMeranie_B.Input = 0.0F;
    pneutrunkMeranie_B.Input1 = 0.0F;
    pneutrunkMeranie_B.Input2 = 0.0F;
  }

  /* states (dwork) */
  pneutrunkMeranie_M->dwork = ((void *) &pneutrunkMeranie_DW);
  (void) memset((void *)&pneutrunkMeranie_DW, 0,
                sizeof(DW_pneutrunkMeranie_T));

  /* data type transition information */
  {
    static DataTypeTransInfo dtInfo;
    (void) memset((char_T *) &dtInfo, 0,
                  sizeof(dtInfo));
    pneutrunkMeranie_M->SpecialInfo.mappingInfo = (&dtInfo);
    dtInfo.numDataTypes = 19;
    dtInfo.dataTypeSizes = &rtDataTypeSizes[0];
    dtInfo.dataTypeNames = &rtDataTypeNames[0];

    /* Block I/O transition table */
    dtInfo.BTransTable = &rtBTransTable;
  }

  /* Initialize Sizes */
  pneutrunkMeranie_M->Sizes.numContStates = (0);/* Number of continuous states */
  pneutrunkMeranie_M->Sizes.numY = (0);/* Number of model outputs */
  pneutrunkMeranie_M->Sizes.numU = (0);/* Number of model inputs */
  pneutrunkMeranie_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  pneutrunkMeranie_M->Sizes.numSampTimes = (1);/* Number of sample times */
  pneutrunkMeranie_M->Sizes.numBlocks = (14);/* Number of blocks */
  pneutrunkMeranie_M->Sizes.numBlockIO = (6);/* Number of block outputs */
  return pneutrunkMeranie_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
