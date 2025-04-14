/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: regulatory
 * File: regulatory.c
 * Author: MartinV
 * Last modified by: MartinV
 * Created: 26-Sep-2022 14:44:03
 * Last modified: Mon Sep 26 14:43:43 2022
 * Model Version: 1.9
 * Description: 
 * modified Comment: 
 ********************************************************************
 * Implementation of program regulatory
 ********************************************************************
 * Generated with B&R Automation Studio Target for Simulink V6.5
 * (GRT based)
 ********************************************************************/

#include <bur/plctypes.h>

#include "rtwtypes.h"
#include "rtmodel.h"

#define EXPAND_CONCAT(name1,name2) name1 ## name2
#define CONCAT(name1,name2) EXPAND_CONCAT(name1,name2)
#define RT_MODEL            CONCAT(MODEL,_rtModel)

#ifdef __cplusplus

extern "C" {

#endif

/* Defines */
#define SS_TERMINATE 4
#define SS_OUTPUT 3
#define SS_INITIALIZE 2



#ifdef __cplusplus

}

#endif


#ifdef __cplusplus
    unsigned long bur_heap_size = 6553500;
#endif



void PID_c(struct PID_c* inst)
{
  tag_RTM_PID_co_T* const PID_co_M = &(inst)->bur_PID_co;
	inst->bur_PID_co.blockIO = &(inst)->bur_B_PID_co_T;
	inst->bur_PID_co.dwork = &(inst)->bur_DW_PID_co_T;
	
  switch (inst->ssMethodType)
  {
    case SS_INITIALIZE:
	  

      /* call model initialize functions */
		/*memInit function */
		PID_co_initializeMemory(PID_co_M, inst);
		PID_co_initialize(PID_co_M, inst);
      break;

    case SS_OUTPUT:
      /* call model step functions */
		PID_co_step(PID_co_M, inst);
      break;

    case SS_TERMINATE:
      /* call model terminate function */
		PID_co_terminate(PID_co_M, inst);
	  break;
  }
}

/*****************************************************************************
   Function block sample time: 0.002
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.5.1 (03-Dec-2021)
 *****************************************************************************/
