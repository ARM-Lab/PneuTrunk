/* Automation Studio generated header file */
/* Do not edit ! */
/* regulatory 1.00.0 */

#ifndef _REGULATORY_
#define _REGULATORY_
#ifdef __cplusplus
extern "C" 
{
#endif
#ifndef _regulatory_VERSION
#define _regulatory_VERSION 1.00.0
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef struct emxArray_real_T
{	double* data;
	signed long* size;
	signed long allocatedSize;
	signed long numDimensions;
	plcbit canFreeData;
} emxArray_real_T;

typedef struct B_regulator_FF_PI_T
{	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Input11;
	float Input5;
	float Input13;
	float Input14;
	float Input8;
	float Input9;
	float Input10;
	float Sum;
	float Input7;
	float Sum2;
	float Input6;
	float Sum1;
	float Input12;
} B_regulator_FF_PI_T;

typedef struct DW_regulator_FF_PI_T
{	double Integrator_DSTATE;
	double Filter_DSTATE;
	double Integrator_DSTATE_o;
	double Filter_DSTATE_f;
	double Integrator_DSTATE_i;
	double Filter_DSTATE_a;
	signed char Integrator_PrevResetState;
	signed char Filter_PrevResetState;
	signed char Integrator_PrevResetState_l;
	signed char Filter_PrevResetState_e;
	signed char Integrator_PrevResetState_e;
	signed char Filter_PrevResetState_h;
} DW_regulator_FF_PI_T;

typedef struct ConstP_regulator_FF_PI_T
{	float Constant_Value_m[114];
	float Constant1_Value_b[114];
	float Constant2_Value[114];
	float Constant3_Value[114];
} ConstP_regulator_FF_PI_T;

typedef struct tag_RTM_regulator_FF_PI_T
{	unsigned char* errorStatus;
	struct B_regulator_FF_PI_T* blockIO;
	struct DW_regulator_FF_PI_T* dwork;
} tag_RTM_regulator_FF_PI_T;

typedef struct B_regulator_FF_PI_plane_regre_T
{	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Input11;
	float Input5;
	float Input13;
	float Input14;
	float Sum;
	float Input7;
	float Sum2;
	float Input6;
	float Sum1;
	float Input10;
	float Input12;
	float Input8;
	float Input9;
} B_regulator_FF_PI_plane_regre_T;

typedef struct DW_regulator_FF_PI_plane_regr_T
{	double Integrator_DSTATE;
	double Filter_DSTATE;
	double Integrator_DSTATE_o;
	double Filter_DSTATE_f;
	double Integrator_DSTATE_i;
	double Filter_DSTATE_a;
	signed char Integrator_PrevResetState;
	signed char Filter_PrevResetState;
	signed char Integrator_PrevResetState_l;
	signed char Filter_PrevResetState_e;
	signed char Integrator_PrevResetState_e;
	signed char Filter_PrevResetState_h;
} DW_regulator_FF_PI_plane_regr_T;

typedef struct tag_RTM_regulator_FF_PI_plane_T
{	unsigned char* errorStatus;
	struct B_regulator_FF_PI_plane_regre_T* blockIO;
	struct DW_regulator_FF_PI_plane_regr_T* dwork;
} tag_RTM_regulator_FF_PI_plane_T;

typedef struct B_PID_constant_T
{	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Input11;
	float Input5;
	float Input13;
	float Input14;
	float Switch2;
	float Input6;
	float Switch1;
	float Input7;
	float Switch;
	float Input12;
} B_PID_constant_T;

typedef struct DW_PID_constant_T
{	double Integrator_DSTATE;
	double Filter_DSTATE;
	double Integrator_DSTATE_f;
	double Filter_DSTATE_j;
	double Integrator_DSTATE_h;
	double Filter_DSTATE_m;
	signed char Integrator_PrevResetState;
	signed char Filter_PrevResetState;
	signed char Integrator_PrevResetState_m;
	signed char Filter_PrevResetState_e;
	signed char Integrator_PrevResetState_l;
	signed char Filter_PrevResetState_k;
} DW_PID_constant_T;

typedef struct tag_RTM_PID_constant_T
{	unsigned char* errorStatus;
	struct B_PID_constant_T* blockIO;
	struct DW_PID_constant_T* dwork;
} tag_RTM_PID_constant_T;

typedef struct B_requestedalfa2deltaz1_reg_F_T
{	float Blue_real;
	float Green_real;
	float Yellow_real;
	float Blue_ref;
	float Green_ref;
	float Yellow_ref;
} B_requestedalfa2deltaz1_reg_F_T;

typedef struct B_regulator_nelin_P_T
{	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Gain7;
	float Gain9;
	float Gain8;
} B_regulator_nelin_P_T;

typedef struct tag_RTM_regulator_nelin_P_T
{	unsigned char* errorStatus;
	struct B_regulator_nelin_P_T* blockIO;
} tag_RTM_regulator_nelin_P_T;

typedef struct B_PID_co_T
{	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Input11;
	float Input5;
	float Input13;
	float Input14;
	float Switch2;
	float Input6;
	float Switch1;
	float Input7;
	float Switch;
	float Input12;
} B_PID_co_T;

typedef struct DW_PID_co_T
{	double Integrator_DSTATE;
	double Filter_DSTATE;
	double Integrator_DSTATE_f;
	double Filter_DSTATE_j;
	double Integrator_DSTATE_h;
	double Filter_DSTATE_m;
	signed char Integrator_PrevResetState;
	signed char Filter_PrevResetState;
	signed char Integrator_PrevResetState_m;
	signed char Filter_PrevResetState_e;
	signed char Integrator_PrevResetState_l;
	signed char Filter_PrevResetState_k;
} DW_PID_co_T;

typedef struct tag_RTM_PID_co_T
{	unsigned char* errorStatus;
	struct B_PID_co_T* blockIO;
	struct DW_PID_co_T* dwork;
} tag_RTM_PID_co_T;

typedef struct B_reg_FF_PI_pl_regr_stiff_T
{	float Input15;
	float Input1;
	float Input2;
	float Input3;
	float Input4;
	float Input16;
	float Input11;
	float Input5;
	float Input13;
	float Input14;
	float Input17;
	float Sum;
	float Input7;
	float Sum2;
	float Input6;
	float Sum1;
	float Input10;
	float Input12;
	float Input8;
	float Input9;
} B_reg_FF_PI_pl_regr_stiff_T;

typedef struct DW_reg_FF_PI_pl_regr_stiff_T
{	double Integrator_DSTATE;
	double Filter_DSTATE;
	double Integrator_DSTATE_o;
	double Filter_DSTATE_f;
	double Integrator_DSTATE_i;
	double Filter_DSTATE_a;
	signed char Integrator_PrevResetState;
	signed char Filter_PrevResetState;
	signed char Integrator_PrevResetState_l;
	signed char Filter_PrevResetState_e;
	signed char Integrator_PrevResetState_e;
	signed char Filter_PrevResetState_h;
} DW_reg_FF_PI_pl_regr_stiff_T;

typedef struct ConstP_reg_FF_PI_pl_regr_stif_T
{	double Constant_Value[48];
	double Constant1_Value[48];
	double pooled1[48];
	double Constant13_Value[48];
	double Constant14_Value[48];
	double pooled2[48];
	double Constant2_Value[48];
	double Constant3_Value[48];
	double Constant4_Value[48];
	double pooled3[48];
	double Constant8_Value[48];
	double Constant9_Value[48];
} ConstP_reg_FF_PI_pl_regr_stif_T;

typedef struct tag_RTM_reg_FF_PI_pl_regr_sti_T
{	unsigned char* errorStatus;
	struct B_reg_FF_PI_pl_regr_stiff_T* blockIO;
	struct DW_reg_FF_PI_pl_regr_stiff_T* dwork;
} tag_RTM_reg_FF_PI_pl_regr_sti_T;

typedef struct FF_PID_r_t
{
	/* VAR_INPUT (analog) */
	signed char ssMethodType;
	float stiffness_ff;
	float ref_alfa_x;
	float ref_alfa_y;
	float real_alfa_x;
	float real_alfa_y;
	float poradie_vlnovcov;
	float P_parameter;
	float reset_PID_blue;
	float D_parameter;
	float N_parameter;
	float platform_ID;
	float reset_PID_green;
	float reset_PID_yellow;
	float tlak3;
	float I_parameter;
	float tlak1;
	float tlak2;
	/* VAR_OUTPUT (analog) */
	float Blue_tab;
	float Yellow_tab;
	float Green_tab;
	/* VAR (analog) */
	struct B_reg_FF_PI_pl_regr_stiff_T bur_B_reg_FF_PI_pl_regr_stiff_T;
	struct DW_reg_FF_PI_pl_regr_stiff_T bur_DW_reg_FF_PI_pl_regr_stiff_;
	struct tag_RTM_reg_FF_PI_pl_regr_sti_T bur_reg_FF_PI_pl_regr_stiff;
} FF_PID_r_t_typ;

typedef struct PID_c
{
	/* VAR_INPUT (analog) */
	signed char ssMethodType;
	float ref_alfa_x;
	float ref_alfa_y;
	float real_alfa_x;
	float real_alfa_y;
	float P_parameter;
	float reset_PID_blue;
	float D_parameter;
	float N_parameter;
	float reset_PID_yellow;
	float reset_PID_green;
	float I_parameter;
	/* VAR_OUTPUT (analog) */
	float Blue_tab;
	float Yellow_tab;
	float Green_tab;
	/* VAR (analog) */
	struct B_PID_co_T bur_B_PID_co_T;
	struct DW_PID_co_T bur_DW_PID_co_T;
	struct tag_RTM_PID_co_T bur_PID_co;
} PID_c_typ;

typedef struct nonL_P
{
	/* VAR_INPUT (analog) */
	signed char ssMethodType;
	float ref_alfa_x;
	float ref_alfa_y;
	float real_alfa_x;
	float real_alfa_y;
	/* VAR_OUTPUT (analog) */
	float Blue_tab;
	float Yellow_tab;
	float Green_tab;
	/* VAR (analog) */
	struct B_regulator_nelin_P_T bur_B_regulator_nelin_P_T;
	struct tag_RTM_regulator_nelin_P_T bur_regulator_nelin_P;
} nonL_P_typ;

typedef struct FF_PID_r
{
	/* VAR_INPUT (analog) */
	signed char ssMethodType;
	float ref_alfa_x;
	float ref_alfa_y;
	float real_alfa_x;
	float real_alfa_y;
	float P_parameter;
	float reset_PID_blue;
	float D_parameter;
	float N_parameter;
	float reset_PID_green;
	float reset_PID_yellow;
	float tlak3;
	float I_parameter;
	float tlak1;
	float tlak2;
	/* VAR_OUTPUT (analog) */
	float Blue_tab;
	float Yellow_tab;
	float Green_tab;
	/* VAR (analog) */
	struct B_regulator_FF_PI_plane_regre_T bur_B_regulator_FF_PI_plane_reg;
	struct DW_regulator_FF_PI_plane_regr_T bur_DW_regulator_FF_PI_plane_re;
	struct tag_RTM_regulator_FF_PI_plane_T bur_regulator_FF_PI_plane_regre;
} FF_PID_r_typ;

typedef struct FF_PID
{
	/* VAR_INPUT (analog) */
	signed char ssMethodType;
	float ref_alfa_x;
	float ref_alfa_y;
	float real_alfa_x;
	float real_alfa_y;
	float P_parameter;
	float reset_PID_blue;
	float D_parameter;
	float N_parameter;
	float tlak1;
	float tlak2;
	float tlak3;
	float reset_PID_green;
	float reset_PID_yellow;
	float I_parameter;
	/* VAR_OUTPUT (analog) */
	float Blue_tab;
	float Yellow_tab;
	float Green_tab;
	/* VAR (analog) */
	struct B_regulator_FF_PI_T bur_B_regulator_FF_PI_T;
	struct DW_regulator_FF_PI_T bur_DW_regulator_FF_PI_T;
	struct tag_RTM_regulator_FF_PI_T bur_regulator_FF_PI;
} FF_PID_typ;

typedef emxArray_real_T emxArray_real_T_regulator_FF_T2;

typedef tag_RTM_regulator_FF_PI_T RT_MODEL_regulator_FF_PI_T;

typedef tag_RTM_regulator_FF_PI_plane_T RT_MODEL_regulator_FF_PI_plan_T;

typedef tag_RTM_PID_constant_T RT_MODEL_PID_constant_T;

typedef tag_RTM_regulator_nelin_P_T RT_MODEL_regulator_nelin_P_T;

typedef tag_RTM_PID_co_T RT_MODEL_PID_co_T;

typedef tag_RTM_reg_FF_PI_pl_regr_sti_T RT_MODEL_reg_FF_PI_pl_regr_st_T;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FF_PID_r_t(struct FF_PID_r_t* inst);
_BUR_PUBLIC void PID_c(struct PID_c* inst);
_BUR_PUBLIC void nonL_P(struct nonL_P* inst);
_BUR_PUBLIC void FF_PID_r(struct FF_PID_r* inst);
_BUR_PUBLIC void FF_PID(struct FF_PID* inst);


#ifdef __cplusplus
};
#endif
#endif /* _REGULATORY_ */

