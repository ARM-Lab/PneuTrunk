
TYPE
	mech : 	STRUCT 
		pozadovany_uhol_y_old : ARRAY[0..6]OF REAL;
		real_uhol_y_kalibrovane : ARRAY[0..6]OF REAL;
		real_uhol_x_kalibrovane : ARRAY[0..6]OF REAL;
		pozadovany_uhol_y : ARRAY[0..6]OF REAL;
		pozadovany_uhol_x : ARRAY[0..6]OF REAL;
		FF_stiffness : ARRAY[0..6]OF REAL;
		PID_P : ARRAY[0..6]OF REAL;
		PID_I : ARRAY[0..6]OF REAL;
		PID_D : ARRAY[0..6]OF REAL;
		PID_N : ARRAY[0..6]OF REAL;
		reset_I_reg : ARRAY[0..6]OF REAL;
		tlak3 : ARRAY[0..6]OF REAL;
		tlak2 : ARRAY[0..6]OF REAL;
		tlak1 : ARRAY[0..6]OF REAL;
		poradie : ARRAY[0..6]OF INT;
		error_total : ARRAY[0..6]OF REAL;
		error_y : ARRAY[0..6]OF REAL;
		error_x : ARRAY[0..6]OF REAL;
		pozadovany_uhol_x_old : ARRAY[0..6]OF REAL;
		nula_y : ARRAY[0..6]OF REAL;
		nula_x : ARRAY[0..6]OF REAL;
		pozadovanyLinear : REAL;
		efektor : BOOL;
	END_STRUCT;
END_TYPE
