/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: regulatory
 * File: regulatory.c
 * Author: MartinV
 * Last modified by: MartinV
 * Created: 05-Apr-2022 15:19:28
 * Last modified: Mon Apr 04 12:56:55 2022
 * Model Version: 1.96
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



void FF_PID(struct FF_PID* inst)
{
  tag_RTM_regulator_FF_PI_T* const regulator_FF_PI_M = &(inst)->bur_regulator_FF_PI;
	inst->bur_regulator_FF_PI.blockIO = &(inst)->bur_B_regulator_FF_PI_T;
	inst->bur_regulator_FF_PI.dwork = &(inst)->bur_DW_regulator_FF_PI_T;
	
  switch (inst->ssMethodType)
  {
    case SS_INITIALIZE:
	  

      /* call model initialize functions */
		/*memInit function */
		regulator_FF_PI_initializeMemory(regulator_FF_PI_M, inst);
		regulator_FF_PI_initialize(regulator_FF_PI_M, inst);
      break;

    case SS_OUTPUT:
      /* call model step functions */
		regulator_FF_PI_step(regulator_FF_PI_M, inst);
      break;

    case SS_TERMINATE:
      /* call model terminate function */
		regulator_FF_PI_terminate(regulator_FF_PI_M, inst);
	  break;
  }
}

/*****************************************************************************
   Function block sample time: 0.002
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.5.1 (03-Dec-2021)
 *****************************************************************************/
