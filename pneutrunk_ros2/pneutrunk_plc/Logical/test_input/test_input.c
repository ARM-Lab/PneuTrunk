/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: test_input
 * File: test_input.c
 * Author: varga
 * Last modified by: varga
 * Created: 06-Feb-2024 09:08:10
 * Last modified: Mon Feb 05 15:54:01 2024
 * Model Version: 1.4
 * Description: 
 * modified Comment: 
 ********************************************************************
 * Implementation of program test_input
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink V6.8
 * (GRT based with External Mode support)
 ********************************************************************/

#define _ASMATH_
#define ASMATH_
#define _ASMATH_H
#define ASMATH_H
#define _ASMATH_H_
#define ASMATH_H_
#define _ASSTRING_
#define ASSTRING_
#define _ASSTRING_H
#define ASSTRING_H
#define _ASSTRING_H_
#define ASSTRING_H_ 

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
 #include <AsDefault.h>
#endif

#include "rtwtypes.h"
#include "rtmodel.h"
#include "ext_work.h"

#define EXPAND_CONCAT(name1,name2) name1 ## name2
#define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
#define RT_MODEL            CONCAT(MODEL,_rtModel)

#ifdef __cplusplus

extern "C" {

#endif

extern RT_MODEL *MODEL(void);

extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

#ifdef __cplusplus

}

#endif


#ifdef EXT_MODE
#  define rtExtModeSingleTaskUpload(S)                          \
   {                                                            \
        int stIdx;                                              \
        rtExtModeUploadCheckTrigger(rtmGetNumSampleTimes(S));   \
        for (stIdx=0; stIdx<NUMST; stIdx++) {                   \
            if (rtmIsSampleHit(S, stIdx, 0 /*unused*/)) {       \
                rtExtModeUpload(stIdx,rtmGetTaskTime(S,stIdx)); \
            }                                                   \
        }                                                       \
   }
#else
#  define rtExtModeSingleTaskUpload(S) /* Do nothing */
#endif

RT_MODEL  *S;

#ifdef __cplusplus
    unsigned long bur_heap_size = 6553500;
#endif 


void _INIT mainINIT( void )
{
    UDINT st_ident;
    RTInfo_typ rt_info;
    rt_info.enable = 1;
    RTInfo(&rt_info);
    if (rt_info.cycle_time != 12000)
    {
      /* cycle time does not match Simulink fixed-step size */
      ST_ident("test_input", 0, &st_ident);
      ST_tmp_suspend(st_ident);
      ERR_warning(33310, 0);
    }
    
    rtExtModeParseArgs(0, NULL, NULL);
	
	S = MODEL();
	
	MdlInitializeSizes();
	MdlInitializeSampleTimes();
    
    rtExtModeCheckInit(rtmGetNumSampleTimes(S));
    rtExtModeWaitForStartPkt(rtmGetRTWExtModeInfo(S),
                             rtmGetNumSampleTimes(S),
                             (boolean_T *)&rtmGetStopRequested(S));
    
	MdlStart();
}

extern int num_calls_rtIOStream;

void _CYCLIC mainCYCLIC( void )
{

	num_calls_rtIOStream = 0;

	rtExtModeOneStep(rtmGetRTWExtModeInfo(S),
                     rtmGetNumSampleTimes(S),
                     (boolean_T *)&rtmGetStopRequested(S));
    
	MdlOutputs(0);

	rtExtModeSingleTaskUpload(S);
    
    MdlUpdate(0);
}

void _EXIT mainEXIT( void )
{
    rtExtModeShutdown(rtmGetNumSampleTimes(S));

    MdlTerminate();
}

/*****************************************************************************
  Task sample time: 0.012s
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.8.0 (22-Mar-2023)
 *****************************************************************************/
