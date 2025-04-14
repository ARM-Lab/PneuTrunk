/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: regulatory
 * File: regulatory.c
 * Author: MartinV
 * Last modified by: MartinV
 * Created: 29-Jul-2022 10:48:23
 * Last modified: Fri Jul 29 10:47:54 2022
 * Model Version: 1.10
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



void nonL_P(struct nonL_P* inst)
{
  tag_RTM_regulator_nelin_P_T* const regulator_nelin_P_M = &(inst)->bur_regulator_nelin_P;
	inst->bur_regulator_nelin_P.blockIO = &(inst)->bur_B_regulator_nelin_P_T;
	
  switch (inst->ssMethodType)
  {
    case SS_INITIALIZE:
	  

      /* call model initialize functions */
		/*memInit function */
		regulator_nelin_P_initializeMemory(regulator_nelin_P_M, inst);
		regulator_nelin_P_initialize(regulator_nelin_P_M, inst);
      break;

    case SS_OUTPUT:
      /* call model step functions */
		regulator_nelin_P_step(regulator_nelin_P_M, inst);
      break;

    case SS_TERMINATE:
      /* call model terminate function */
		regulator_nelin_P_terminate(regulator_nelin_P_M, inst);
	  break;
  }
}

/*****************************************************************************
   Function block sample time: 0.002
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.5.1 (03-Dec-2021)
 *****************************************************************************/
