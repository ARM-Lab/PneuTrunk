/********************************************************************
 * COPYRIGHT -- B&R Industrial Automation GmbH
 ********************************************************************
 * Program: regulatory
 * File: regulatory.c
 * Author: MartinV
 * Last modified by: MartinV
 * Created: 26-Jun-2023 09:10:34
 * Last modified: Wed Jun 21 13:14:00 2023
 * Model Version: 1.154
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



void FF_PID_r_t(struct FF_PID_r_t* inst)
{
  tag_RTM_reg_FF_PI_pl_regr_sti_T* const reg_FF_PI_pl_regr_stiff_M = &(inst)->bur_reg_FF_PI_pl_regr_stiff;
	inst->bur_reg_FF_PI_pl_regr_stiff.blockIO = &(inst)->bur_B_reg_FF_PI_pl_regr_stiff_T;
	inst->bur_reg_FF_PI_pl_regr_stiff.dwork = &(inst)->bur_DW_reg_FF_PI_pl_regr_stiff_;
	
  switch (inst->ssMethodType)
  {
    case SS_INITIALIZE:
	  

      /* call model initialize functions */
		/*memInit function */
		reg_FF_PI_pl_regr_stiff_initializeMemory(reg_FF_PI_pl_regr_stiff_M, inst);
		reg_FF_PI_pl_regr_stiff_initialize(reg_FF_PI_pl_regr_stiff_M, inst);
      break;

    case SS_OUTPUT:
      /* call model step functions */
		reg_FF_PI_pl_regr_stiff_step(reg_FF_PI_pl_regr_stiff_M, inst);
      break;

    case SS_TERMINATE:
      /* call model terminate function */
		reg_FF_PI_pl_regr_stiff_terminate(reg_FF_PI_pl_regr_stiff_M, inst);
	  break;
  }
}

/*****************************************************************************
   Function block sample time: 0.002
 *****************************************************************************/

/*****************************************************************************
   B&R Automation Studio Target for Simulink Version: V6.5.1 (03-Dec-2021)
 *****************************************************************************/
