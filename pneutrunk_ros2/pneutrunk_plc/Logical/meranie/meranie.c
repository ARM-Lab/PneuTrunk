/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: meranie
 * File: meranie.c
 * Author: km_2
 * Last modified by: km_2
 * Created: 24-May-2023 11:04:30
 * Last modified: Wed May 24 11:03:28 2023
 * Model Version: 1.6
 * Description: 
 * modified Comment: 
 ********************************************************************
 * Implementation of program meranie
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink V6.7
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
    if (rt_info.cycle_time != 100000)
    {
      /* cycle time does not match Simulink fixed-step size */
      ST_ident("meranie", 0, &st_ident);
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
  Task sample time: 0.1s
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.7.1 (02-Dec-2022)
 *****************************************************************************/
