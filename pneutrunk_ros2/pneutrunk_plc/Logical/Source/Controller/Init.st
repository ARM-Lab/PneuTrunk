PROGRAM _INIT
//	traj_0(ssMethodType := 2, aktualny_uhol_x := 0, aktualny_uhol_y := 0, pozadovany_uhol_x := 0, pozadovany_uhol_y :=0, dlzka_pohybu := 1);

//	traj_1(ssMethodType := 2, aktualny_uhol_x := 0, aktualny_uhol_y := 0, pozadovany_uhol_x := 0, pozadovany_uhol_y :=0, dlzka_pohybu := 1);

//	uhol2zdvyh_0(ssMethodType := 2, uhol_x := 15, uhol_y := 15);
			
	//FF_PID_r_t_0(ssMethodType := 0, ref_alfa_x := 0, ref_alfa_y := 0, real_alfa_x := 0, real_alfa_y := 0, P_parameter := 0, reset_PID_blue := 0, D_parameter := 0, N_parameter := 0, stiffness_ff := 3, reset_PID_green := 0, reset_PID_yellow := 0, tlak3 := 0, I_parameter := 0, tlak1 := 0, tlak2 := 0);
	FOR id:=0 TO 6 BY 1 DO
		modull.poradie[id]	:= 3;
	END_FOR
	
	maxUhol := 18;
	
	modull.FF_stiffness[0]	:= 3;
	stiffness_ff:= modull.FF_stiffness[0];
	switch := FALSE;
	poradie_ID1:=3;	 
	poradie_ID2:=3;	 
	poradie_ID3:=3;	 
	poradie_ID4:=3;	 
	poradie_ID5:=3;	 
	poradie_ID6:=3;	
	poradie_ID7:=3;	
	
	I_konstanta_ID1:=30;
	I_konstanta_ID2:=30;
	I_konstanta_ID3:=30;
	I_konstanta_ID4:=30;
	I_konstanta_ID5:=30;
	I_konstanta_ID6:=30;
	I_konstanta_ID7:=30;
	
	IF buttons.klucik = TRUE THEN
		buttons.stropBielaLED	:= TRUE;
	END_IF
	
	buttons.stropCervenaLED	:= FALSE;
	
END_PROGRAM