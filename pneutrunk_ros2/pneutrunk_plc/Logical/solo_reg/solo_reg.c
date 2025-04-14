/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: solo_reg
 * File: solo_reg.c
 * Author: varga
 * Last modified by: varga
 * Created: 15-Feb-2024 10:44:14
 * Last modified: Thu Feb 15 10:41:29 2024
 * Model Version: 4.30
 * Description: 
 * modified Comment: 
 ********************************************************************
 * Implementation of program solo_reg
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink V6.8
 * (GRT based)
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


#ifdef __cplusplus
    unsigned long bur_heap_size = 6553500;
#endif


void _INIT mainINIT( void )
{
    
    UDINT st_ident;
    RTInfo_typ rt_info;
    rt_info.enable = 1;
    RTInfo(&rt_info);
    if (rt_info.cycle_time != 16000)
    {
      /* cycle time does not match Simulink fixed-step size */
      ST_ident("solo_reg", 0, &st_ident);
      ST_tmp_suspend(st_ident);
      ERR_warning(33310, 0);
    }

	RT_MODEL  *S;

	S = MODEL();

	MdlInitializeSizes();
	MdlInitializeSampleTimes();
	MdlStart();
	
}

void _CYCLIC mainCYCLIC( void )
{
	MdlOutputs(0);
	MdlUpdate(0);
	
}

void _EXIT mainEXIT( void )
{
	MdlTerminate();
	
}

/*****************************************************************************
  Task sample time: 0.016s
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.8.0 (22-Mar-2023)
 *****************************************************************************/
