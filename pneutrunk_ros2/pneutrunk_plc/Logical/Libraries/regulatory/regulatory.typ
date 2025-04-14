

TYPE
	emxArray_real_T :  STRUCT   
		data :  REFERENCE TO LREAL;   
		size :  REFERENCE TO DINT;   
		allocatedSize :  DINT;   
		numDimensions :  DINT;   
		canFreeData :  BOOL;   
	END_STRUCT;

	B_regulator_FF_PI_T :  STRUCT   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Input11 :  REAL;   
		Input5 :  REAL;   
		Input13 :  REAL;   
		Input14 :  REAL;   
		Input8 :  REAL;   
		Input9 :  REAL;   
		Input10 :  REAL;   
		Sum :  REAL;   
		Input7 :  REAL;   
		Sum2 :  REAL;   
		Input6 :  REAL;   
		Sum1 :  REAL;   
		Input12 :  REAL;   
	END_STRUCT;

	DW_regulator_FF_PI_T :  STRUCT   
		Integrator_DSTATE :  LREAL;   
		Filter_DSTATE :  LREAL;   
		Integrator_DSTATE_o :  LREAL;   
		Filter_DSTATE_f :  LREAL;   
		Integrator_DSTATE_i :  LREAL;   
		Filter_DSTATE_a :  LREAL;   
		Integrator_PrevResetState :  SINT;   
		Filter_PrevResetState :  SINT;   
		Integrator_PrevResetState_l :  SINT;   
		Filter_PrevResetState_e :  SINT;   
		Integrator_PrevResetState_e :  SINT;   
		Filter_PrevResetState_h :  SINT;   
	END_STRUCT;

	ConstP_regulator_FF_PI_T :  STRUCT   
		Constant_Value_m :  ARRAY[0..113] OF REAL;   
		Constant1_Value_b :  ARRAY[0..113] OF REAL;   
		Constant2_Value :  ARRAY[0..113] OF REAL;   
		Constant3_Value :  ARRAY[0..113] OF REAL;   
	END_STRUCT;

	tag_RTM_regulator_FF_PI_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_regulator_FF_PI_T;   
		dwork :  REFERENCE TO DW_regulator_FF_PI_T;   
	END_STRUCT;

	B_regulator_FF_PI_plane_regre_T :  STRUCT   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Input11 :  REAL;   
		Input5 :  REAL;   
		Input13 :  REAL;   
		Input14 :  REAL;   
		Sum :  REAL;   
		Input7 :  REAL;   
		Sum2 :  REAL;   
		Input6 :  REAL;   
		Sum1 :  REAL;   
		Input10 :  REAL;   
		Input12 :  REAL;   
		Input8 :  REAL;   
		Input9 :  REAL;   
	END_STRUCT;

	DW_regulator_FF_PI_plane_regr_T :  STRUCT   
		Integrator_DSTATE :  LREAL;   
		Filter_DSTATE :  LREAL;   
		Integrator_DSTATE_o :  LREAL;   
		Filter_DSTATE_f :  LREAL;   
		Integrator_DSTATE_i :  LREAL;   
		Filter_DSTATE_a :  LREAL;   
		Integrator_PrevResetState :  SINT;   
		Filter_PrevResetState :  SINT;   
		Integrator_PrevResetState_l :  SINT;   
		Filter_PrevResetState_e :  SINT;   
		Integrator_PrevResetState_e :  SINT;   
		Filter_PrevResetState_h :  SINT;   
	END_STRUCT;

	tag_RTM_regulator_FF_PI_plane_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_regulator_FF_PI_plane_regre_T;   
		dwork :  REFERENCE TO DW_regulator_FF_PI_plane_regr_T;   
	END_STRUCT;

	B_PID_constant_T :  STRUCT   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Input11 :  REAL;   
		Input5 :  REAL;   
		Input13 :  REAL;   
		Input14 :  REAL;   
		Switch2 :  REAL;   
		Input6 :  REAL;   
		Switch1 :  REAL;   
		Input7 :  REAL;   
		Switch :  REAL;   
		Input12 :  REAL;   
	END_STRUCT;

	DW_PID_constant_T :  STRUCT   
		Integrator_DSTATE :  LREAL;   
		Filter_DSTATE :  LREAL;   
		Integrator_DSTATE_f :  LREAL;   
		Filter_DSTATE_j :  LREAL;   
		Integrator_DSTATE_h :  LREAL;   
		Filter_DSTATE_m :  LREAL;   
		Integrator_PrevResetState :  SINT;   
		Filter_PrevResetState :  SINT;   
		Integrator_PrevResetState_m :  SINT;   
		Filter_PrevResetState_e :  SINT;   
		Integrator_PrevResetState_l :  SINT;   
		Filter_PrevResetState_k :  SINT;   
	END_STRUCT;

	tag_RTM_PID_constant_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_PID_constant_T;   
		dwork :  REFERENCE TO DW_PID_constant_T;   
	END_STRUCT;

	B_requestedalfa2deltaz1_reg_F_T :  STRUCT   
		Blue_real :  REAL;   
		Green_real :  REAL;   
		Yellow_real :  REAL;   
		Blue_ref :  REAL;   
		Green_ref :  REAL;   
		Yellow_ref :  REAL;   
	END_STRUCT;

	B_regulator_nelin_P_T :  STRUCT   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Gain7 :  REAL;   
		Gain9 :  REAL;   
		Gain8 :  REAL;   
	END_STRUCT;

	tag_RTM_regulator_nelin_P_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_regulator_nelin_P_T;   
	END_STRUCT;

	B_PID_co_T :  STRUCT   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Input11 :  REAL;   
		Input5 :  REAL;   
		Input13 :  REAL;   
		Input14 :  REAL;   
		Switch2 :  REAL;   
		Input6 :  REAL;   
		Switch1 :  REAL;   
		Input7 :  REAL;   
		Switch :  REAL;   
		Input12 :  REAL;   
	END_STRUCT;

	DW_PID_co_T :  STRUCT   
		Integrator_DSTATE :  LREAL;   
		Filter_DSTATE :  LREAL;   
		Integrator_DSTATE_f :  LREAL;   
		Filter_DSTATE_j :  LREAL;   
		Integrator_DSTATE_h :  LREAL;   
		Filter_DSTATE_m :  LREAL;   
		Integrator_PrevResetState :  SINT;   
		Filter_PrevResetState :  SINT;   
		Integrator_PrevResetState_m :  SINT;   
		Filter_PrevResetState_e :  SINT;   
		Integrator_PrevResetState_l :  SINT;   
		Filter_PrevResetState_k :  SINT;   
	END_STRUCT;

	tag_RTM_PID_co_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_PID_co_T;   
		dwork :  REFERENCE TO DW_PID_co_T;   
	END_STRUCT;

	B_reg_FF_PI_pl_regr_stiff_T :  STRUCT   
		Input15 :  REAL;   
		Input1 :  REAL;   
		Input2 :  REAL;   
		Input3 :  REAL;   
		Input4 :  REAL;   
		Input16 :  REAL;   
		Input11 :  REAL;   
		Input5 :  REAL;   
		Input13 :  REAL;   
		Input14 :  REAL;   
		Input17 :  REAL;   
		Sum :  REAL;   
		Input7 :  REAL;   
		Sum2 :  REAL;   
		Input6 :  REAL;   
		Sum1 :  REAL;   
		Input10 :  REAL;   
		Input12 :  REAL;   
		Input8 :  REAL;   
		Input9 :  REAL;   
	END_STRUCT;

	DW_reg_FF_PI_pl_regr_stiff_T :  STRUCT   
		Integrator_DSTATE :  LREAL;   
		Filter_DSTATE :  LREAL;   
		Integrator_DSTATE_o :  LREAL;   
		Filter_DSTATE_f :  LREAL;   
		Integrator_DSTATE_i :  LREAL;   
		Filter_DSTATE_a :  LREAL;   
		Integrator_PrevResetState :  SINT;   
		Filter_PrevResetState :  SINT;   
		Integrator_PrevResetState_l :  SINT;   
		Filter_PrevResetState_e :  SINT;   
		Integrator_PrevResetState_e :  SINT;   
		Filter_PrevResetState_h :  SINT;   
	END_STRUCT;

	ConstP_reg_FF_PI_pl_regr_stif_T :  STRUCT   
		Constant_Value :  ARRAY[0..47] OF LREAL;   
		Constant1_Value :  ARRAY[0..47] OF LREAL;   
		pooled1 :  ARRAY[0..47] OF LREAL;   
		Constant13_Value :  ARRAY[0..47] OF LREAL;   
		Constant14_Value :  ARRAY[0..47] OF LREAL;   
		pooled2 :  ARRAY[0..47] OF LREAL;   
		Constant2_Value :  ARRAY[0..47] OF LREAL;   
		Constant3_Value :  ARRAY[0..47] OF LREAL;   
		Constant4_Value :  ARRAY[0..47] OF LREAL;   
		pooled3 :  ARRAY[0..47] OF LREAL;   
		Constant8_Value :  ARRAY[0..47] OF LREAL;   
		Constant9_Value :  ARRAY[0..47] OF LREAL;   
	END_STRUCT;

	tag_RTM_reg_FF_PI_pl_regr_sti_T :  STRUCT   
		errorStatus :  REFERENCE TO USINT;   
		blockIO :  REFERENCE TO B_reg_FF_PI_pl_regr_stiff_T;   
		dwork :  REFERENCE TO DW_reg_FF_PI_pl_regr_stiff_T;   
	END_STRUCT;

	emxArray_real_T_regulator_FF_T2 :emxArray_real_T;	(*  *)

	RT_MODEL_regulator_FF_PI_T :tag_RTM_regulator_FF_PI_T;	(*  *)

	RT_MODEL_regulator_FF_PI_plan_T :tag_RTM_regulator_FF_PI_plane_T;	(*  *)

	RT_MODEL_PID_constant_T :tag_RTM_PID_constant_T;	(*  *)

	RT_MODEL_regulator_nelin_P_T :tag_RTM_regulator_nelin_P_T;	(*  *)

	RT_MODEL_PID_co_T :tag_RTM_PID_co_T;	(*  *)

	RT_MODEL_reg_FF_PI_pl_regr_st_T :tag_RTM_reg_FF_PI_pl_regr_sti_T;	(*  *)

END_TYPE
