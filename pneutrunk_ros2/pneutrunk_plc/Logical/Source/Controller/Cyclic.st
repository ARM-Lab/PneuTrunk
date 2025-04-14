PROGRAM _CYCLIC
	
	TON_0(IN := kalibraciaStart, PT := T#5s0ms);
		
	IF buttons.klucik = FALSE THEN
		global_step		:= 0;
		step 			:= 7;
		buttons.stropBielaLED	:= FALSE;
	END_IF
	
	
	CASE step OF
		
		0:  // Detekcia referencnej polohy
			IF switch2 = FALSE THEN
				buttons.startLED				:= FALSE;
				switch2 						:= TRUE;
				FOR id:=0 TO 6 BY 1 DO
					modul.tlak1[id]	:= REAL_TO_INT(0);
					modul.tlak2[id]	:= REAL_TO_INT(0);
					modul.tlak3[id]	:= REAL_TO_INT(0);
					packetPos.qDesired[id*2] 	:= 0;
					packetPos.qDesired[id*2+1] 	:= 0;
					automatika.x_desired[id]	:= 0;
					automatika.y_desired[id]	:= 0;
					switch						:= FALSE;
				END_FOR
				
			END_IF
			
			IF buttons.startButton = TRUE THEN
				buttons.start	:= TRUE;
				global_step_udp	:= 0;
			END_IF
			
			IF buttons.start = TRUE AND buttons.centralStop = TRUE THEN
				buttons.stop					:= FALSE;
				buttons.stopLED					:= FALSE;
				buttons.stropCervenaLED			:= FALSE;
				buttons.startLED				:= TRUE;
				IF switch = FALSE THEN
					switch 						:= TRUE;
					kalibraciaStart 			:= TRUE;
					FOR id:=0 TO 6 BY 1 DO
						modul.tlak1[id]			:= REAL_TO_INT(4*32767/9);
						modul.tlak2[id]			:= REAL_TO_INT(4*32767/9);
						modul.tlak3[id]			:= REAL_TO_INT(4*32767/9);
					END_FOR
				END_IF
				
				IF switch = TRUE AND TON_0.Q = TRUE THEN
					switch			:= FALSE;
					kalibraciaStart	:= FALSE;
					step			:= 1;
				END_IF	
			END_IF
			global_step				:= 0;
			buttons.stropBielaLED	:= TRUE;
		1:	// Vypustenie vzduchu zo vsetkych mechov, zapnutie I-regulatora 
			(*
			FOR id:=0 TO 6 BY 1 DO
				modul.tlak1[id]	:= 0;
				modul.tlak2[id]	:= 0;
				modul.tlak3[id]	:= 0;
			END_FOR
			*)
			//I_ON					:= TRUE;
			switch2 				:= FALSE;
			kalibraciaStart			:= TRUE;
			
			step					:= 2;
		
		2:	// cakaj
			IF TON_0.Q = TRUE THEN
				kalibraciaStart		:= FALSE;
				step				:= 3;
			END_IF
			
		3:
			FOR id:=0 TO 6 BY 1 DO
				modull.nula_x[id]:= 0;
				modull.nula_y[id]:= 0;
			END_FOR
			
			FOR id:=0 TO 6 BY 1 DO
				modull.nula_x[id]:= modul.uhol1[id];
				modull.nula_y[id]:= modul.uhol2[id];
			END_FOR
			step					:= 4;
			
			global_step 			:= 999;
			global_step_udp			:= 0;			// aby nahodou nemal na zaciatku gesto z predoslej udalosti
			I_ON					:= TRUE;
			
			FOR id:=0 TO 6 BY 1 DO
				modul.tlak1[id]	:= 0;
				modul.tlak2[id]	:= 0;
				modul.tlak3[id]	:= 0;
			END_FOR
			
			
		4:
			
			FOR id:=0 TO 6 BY 1 DO
				modull.real_uhol_x_kalibrovane[id]	:= modul.uhol1[id];
				modull.real_uhol_y_kalibrovane[id]	:= modul.uhol2[id];
				modul.uhol_XminusRef[id] 			:= modull.real_uhol_x_kalibrovane[id] - modull.nula_x[id];
				modul.uhol_YminusRef[id] 			:= modull.real_uhol_y_kalibrovane[id] - modull.nula_y[id];
				modul.linearReal		 			:= ref_linearny_posun;
			END_FOR
			
			IF (automatika.step_color = 1 OR automatika.step_color = 2) AND global_step = 0 THEN
				global_step			:= 999;
			END_IF
			
			
			zasobnik.ball			:= automatika.ball_up;
			zasobnik.ball_piston	:= automatika.ball_piston;
			zasobnik.ball_piston_sjf:= automatika.popcorn;
			zasobnik.levitovanie	:= automatika.levitacia;
			modull.efektor			:= automatika.effector;
			I_konstanta_ID1			:= automatika.I_konstanta[0];
			I_konstanta_ID2			:= automatika.I_konstanta[1];
			I_konstanta_ID3			:= automatika.I_konstanta[2];
			I_konstanta_ID4			:= automatika.I_konstanta[3];
			I_konstanta_ID5			:= automatika.I_konstanta[4];
			I_konstanta_ID6			:= automatika.I_konstanta[5];
			I_konstanta_ID7			:= automatika.I_konstanta[6];
			
			
			IF buttons.stop = TRUE THEN
				buttons.start		:= FALSE;
				buttons.startLED	:= FALSE;
				buttons.stopLED		:= TRUE;
				global_step			:= 7;
			END_IF
			
			IF buttons.start = TRUE AND buttons.centralStop = TRUE THEN
				(*
				FOR id:=0 TO 6 BY 1 DO
					modull.real_uhol_x_kalibrovane[id]	:= modul.uhol1[id];
					modull.real_uhol_y_kalibrovane[id]	:= modul.uhol2[id];
					modul.uhol_XminusRef[id] 			:= modull.real_uhol_x_kalibrovane[id] - modull.nula_x[id];
					modul.uhol_YminusRef[id] 			:= modull.real_uhol_y_kalibrovane[id] - modull.nula_y[id];
					modul.linearReal		 			:= ref_linearny_posun;
				END_FOR
				*)
				IF automatika.automatic = TRUE THEN
					IF automatika.holdPosition = FALSE THEN
						FOR id:=0 TO 6 BY 1 DO
							modull.pozadovany_uhol_y[id]	:=  packetPos.qDesired[id*2];
							modull.pozadovany_uhol_x[id]	:= -packetPos.qDesired[id*2+1];
						END_FOR
						modull.pozadovanyLinear				:= packetPos.qDesired[14]*7/25 + 23;
					END_IF
				ELSE
					FOR id:=0 TO 6 BY 1 DO
						modull.pozadovany_uhol_x[id]	:= automatika.x_desired[id];
						modull.pozadovany_uhol_y[id] 	:= automatika.y_desired[id];
					END_FOR
					modull.pozadovanyLinear				:= automatika.linear;
				END_IF

				// Joint limits
				FOR id:=0 TO 6 BY 1 DO
					IF modull.pozadovany_uhol_x[id] >= maxUhol THEN
						modull.pozadovany_uhol_x[id]	:= maxUhol;
					ELSIF modull.pozadovany_uhol_x[id] <= - maxUhol THEN
						modull.pozadovany_uhol_x[id] := -maxUhol;
					END_IF
			
					IF modull.pozadovany_uhol_y[id] >= maxUhol THEN
						modull.pozadovany_uhol_y[id]	:= maxUhol;
					ELSIF modull.pozadovany_uhol_y[id] <= - maxUhol THEN
						modull.pozadovany_uhol_y[id] := -maxUhol;
					END_IF
			
				END_FOR
	
				ref_alfa_x_ID1:= modull.pozadovany_uhol_x[0];
				ref_alfa_y_ID1:= modull.pozadovany_uhol_y[0];
				ref_alfa_x_ID2:= modull.pozadovany_uhol_x[1];
				ref_alfa_y_ID2:= modull.pozadovany_uhol_y[1];
				ref_alfa_x_ID3:= modull.pozadovany_uhol_x[2];
				ref_alfa_y_ID3:= modull.pozadovany_uhol_y[2];	
				ref_alfa_x_ID4:= modull.pozadovany_uhol_x[3];
				ref_alfa_y_ID4:= modull.pozadovany_uhol_y[3];
				ref_alfa_x_ID5:= modull.pozadovany_uhol_x[4];
				ref_alfa_y_ID5:= modull.pozadovany_uhol_y[4];
				ref_alfa_x_ID6:= modull.pozadovany_uhol_x[5];
				ref_alfa_y_ID6:= modull.pozadovany_uhol_y[5];
				ref_alfa_x_ID7:= modull.pozadovany_uhol_x[6];
				ref_alfa_y_ID7:= modull.pozadovany_uhol_y[6];
				
				// Obmedzenie pre linearny posun (ak je hodnota nad 30 regulator sa sprava divne, nechce sa vypnut)
				IF modull.pozadovanyLinear >30 THEN
					ref_linearny_posun	:= 30;
				ELSIF modull.pozadovanyLinear <23 THEN
					ref_linearny_posun	:= 23;
				ELSE
					ref_linearny_posun	:= modull.pozadovanyLinear;
				END_IF
				
				
				act_alfa_x_ID1:= modull.real_uhol_x_kalibrovane[0] - modull.nula_x[0];
				act_alfa_y_ID1:= modull.real_uhol_y_kalibrovane[0] - modull.nula_y[0];
				act_alfa_x_ID2:= modull.real_uhol_x_kalibrovane[1] - modull.nula_x[1];
				act_alfa_y_ID2:= modull.real_uhol_y_kalibrovane[1] - modull.nula_y[1];
				act_alfa_x_ID3:= modull.real_uhol_x_kalibrovane[2] - modull.nula_x[2];
				act_alfa_y_ID3:= modull.real_uhol_y_kalibrovane[2] - modull.nula_y[2];
				act_alfa_x_ID4:= modull.real_uhol_x_kalibrovane[3] - modull.nula_x[3];
				act_alfa_y_ID4:= modull.real_uhol_y_kalibrovane[3] - modull.nula_y[3];
				act_alfa_x_ID5:= modull.real_uhol_x_kalibrovane[4] - modull.nula_x[4];
				act_alfa_y_ID5:= modull.real_uhol_y_kalibrovane[4] - modull.nula_y[4];
				act_alfa_x_ID6:= modull.real_uhol_x_kalibrovane[5] - modull.nula_x[5];
				act_alfa_y_ID6:= modull.real_uhol_y_kalibrovane[5] - modull.nula_y[5];
				act_alfa_x_ID7:= modull.real_uhol_x_kalibrovane[6] - modull.nula_x[6];
				act_alfa_y_ID7:= modull.real_uhol_y_kalibrovane[6] - modull.nula_y[6];
				
				
				// Nastavenie tlakov podla regulacie
				// ID1
				id:=0;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID1*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID1*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID1*32767/9);
		
				// ID2
				id:=1;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID2*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID2*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID2*32767/9);
		
				// ID3
				id:=2;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID3*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID3*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID3*32767/9);
		
				// ID4
				id:=3;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID4*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID4*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID4*32767/9);
		
				// ID5
				id:=4;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID5*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID5*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID5*32767/9);
		
				// ID6
				id:=5;
				modul.tlak1[id] := REAL_TO_INT(Blue_tab_ID6*32767/9);		
				modul.tlak2[id] := REAL_TO_INT(Green_tab_ID6*32767/9);
				modul.tlak3[id] := REAL_TO_INT(Yellow_tab_ID6*32767/9);
				
				// ID7
				id:=6;
				modul.tlak3[id] := REAL_TO_INT(Blue_tab_ID7*32767/9);		
				modul.tlak1[id] := REAL_TO_INT(Green_tab_ID7*32767/9);
				modul.tlak2[id] := REAL_TO_INT(Yellow_tab_ID7*32767/9);
		
				//lin_modul
				modul.tlakLinear:= REAL_TO_INT(lin_pressure*32767/9);
				
			ELSIF buttons.centralStop = FALSE OR buttons.start = FALSE THEN
				buttons.start			:= FALSE;
				switch					:= FALSE;
				switch2					:= FALSE;
				I_ON					:= FALSE;
				kalibraciaStart			:= FALSE;
				step					:= 0;
				global_step_udp			:= 0;
				global_step				:= 0;
				automatika.casovac		:= FALSE;
				automatika.ball_piston	:= FALSE;
				automatika.ball_up		:= FALSE;
				automatika.levitacia	:= FALSE;
				zasobnik.levitovanie	:= FALSE;
				zasobnik.ball_piston_sjf:= FALSE;
				automatika.popcorn		:= FALSE;
				automatika.casovac_uchopenie:= FALSE;
				automatika.effector		:= FALSE;
				automatika.holdPosition	:= FALSE;
				automatika.automatic	:= FALSE;
				act_alfa_x_ID1:= 0;
				act_alfa_y_ID1:= 0;
				act_alfa_x_ID2:= 0;
				act_alfa_y_ID2:= 0;
				act_alfa_x_ID3:= 0;
				act_alfa_y_ID3:= 0;
				act_alfa_x_ID4:= 0;
				act_alfa_y_ID4:= 0;
				act_alfa_x_ID5:= 0;
				act_alfa_y_ID5:= 0;
				act_alfa_x_ID6:= 0;
				act_alfa_y_ID6:= 0;
				act_alfa_x_ID7:= 0;
				act_alfa_y_ID7:= 0;
				ref_alfa_x_ID1:= 0;
				ref_alfa_y_ID1:= 0;
				ref_alfa_x_ID2:= 0;
				ref_alfa_y_ID2:= 0;
				ref_alfa_x_ID3:= 0;
				ref_alfa_y_ID3:= 0;	
				ref_alfa_x_ID4:= 0;
				ref_alfa_y_ID4:= 0;
				ref_alfa_x_ID5:= 0;
				ref_alfa_y_ID5:= 0;
				ref_alfa_x_ID6:= 0;
				ref_alfa_y_ID6:= 0;
				ref_alfa_x_ID7:= 0;
				ref_alfa_y_ID7:= 0;
				FOR i:=0 TO 6 BY 1 DO
					modul.tlak1[i] 				:= 0;
					modul.tlak2[i]				:= 0;
					modul.tlak3[i] 				:= 0;
					modull.pozadovany_uhol_y[i]	:= 0;
					modull.pozadovany_uhol_x[i]	:= 0;
					modull.real_uhol_x_kalibrovane[i]	:= 0;
					modull.real_uhol_y_kalibrovane[i] 	:= 0;
					modull.nula_x[i]			:= 0;
					modull.nula_y[i]			:= 0;
				END_FOR
				modul.tlakLinear		:= 0;
				modull.efektor			:= FALSE;
				modull.pozadovanyLinear	:= 23;
				zasobnik.ball			:= FALSE;
				zasobnik.ball_piston	:= FALSE;
			END_IF
		5: // kolaborativny mod - doslo k narazu, alebo stlacenie stop		
			buttons.startLED			:= FALSE;
			buttons.stopLED				:= TRUE;
			IF buttons.start = TRUE THEN 
				buttons.stropBielaLED	:= FALSE;
				buttons.stropCervenaLED	:= TRUE;
				buttons.start			:= FALSE;
			END_IF
			step						:= 6;
			global_step					:= 0;
				
		6:
			IF buttons.stop = TRUE THEN
				buttons.stopLED			:= FALSE;
				buttons.stropCervenaLED	:= FALSE;
				buttons.stropBielaLED	:= TRUE;
				step					:= 7;
			END_IF
			
				
		7:	// resetovanie vsetkeho
			buttons.start			:= FALSE;
			switch					:= FALSE;
			switch2					:= FALSE;
			I_ON					:= FALSE;
			kalibraciaStart			:= FALSE;
			step					:= 0;
			global_step_udp			:= 0;
			global_step				:= 0;
			automatika.casovac		:= FALSE;
			zasobnik.levitovanie	:= FALSE;
			zasobnik.ball_piston_sjf:= FALSE;
			automatika.ball_piston	:= FALSE;
			automatika.ball_up		:= FALSE;
			automatika.popcorn		:= FALSE;
			zasobnik.ball_piston_sjf:= FALSE;
			automatika.casovac_uchopenie:= FALSE;
			automatika.effector		:= FALSE;
			automatika.holdPosition	:= FALSE;
			automatika.automatic	:= FALSE;
			act_alfa_x_ID1:= 0;
			act_alfa_y_ID1:= 0;
			act_alfa_x_ID2:= 0;
			act_alfa_y_ID2:= 0;
			act_alfa_x_ID3:= 0;
			act_alfa_y_ID3:= 0;
			act_alfa_x_ID4:= 0;
			act_alfa_y_ID4:= 0;
			act_alfa_x_ID5:= 0;
			act_alfa_y_ID5:= 0;
			act_alfa_x_ID6:= 0;
			act_alfa_y_ID6:= 0;
			act_alfa_x_ID7:= 0;
			act_alfa_y_ID7:= 0;
			ref_alfa_x_ID1:= 0;
			ref_alfa_y_ID1:= 0;
			ref_alfa_x_ID2:= 0;
			ref_alfa_y_ID2:= 0;
			ref_alfa_x_ID3:= 0;
			ref_alfa_y_ID3:= 0;	
			ref_alfa_x_ID4:= 0;
			ref_alfa_y_ID4:= 0;
			ref_alfa_x_ID5:= 0;
			ref_alfa_y_ID5:= 0;
			ref_alfa_x_ID6:= 0;
			ref_alfa_y_ID6:= 0;
			ref_alfa_x_ID7:= 0;
			ref_alfa_y_ID7:= 0;
			FOR i:=0 TO 6 BY 1 DO
				modul.tlak1[i] 				:= 0;
				modul.tlak2[i]				:= 0;
				modul.tlak3[i] 				:= 0;
				modull.pozadovany_uhol_y[i]	:= 0;
				modull.pozadovany_uhol_x[i]	:= 0;
				modull.real_uhol_x_kalibrovane[i]	:= 0;
				modull.real_uhol_y_kalibrovane[i] 	:= 0;
				modull.nula_x[i]			:= 0;
				modull.nula_y[i]			:= 0;
			END_FOR
			modul.tlakLinear		:= 0;
			modull.efektor			:= FALSE;
			modull.pozadovanyLinear	:= 23;
			zasobnik.ball			:= FALSE;
			zasobnik.ball_piston	:= FALSE;
			IF buttons.klucik = FALSE THEN
				step				:= 8;
				global_step			:= 0;
			ELSE
				step				:= 0;
			END_IF
		8:
			IF buttons.klucik = TRUE THEN
				step				:= 0;
				global_step			:= 0;
			ELSE
				buttons.stropBielaLED	:= FALSE;
			END_IF
		
	END_CASE
	
	IF I_ON= TRUE THEN
		RESET_ID1:= TRUE;
		RESET_ID2:= TRUE;
		RESET_ID3:= TRUE;
		RESET_ID4:= TRUE;
		RESET_ID5:= TRUE;
		RESET_ID6:= TRUE;
		RESET_ID7:= TRUE;
	ELSE	
		RESET_ID1:= FALSE;
		RESET_ID2:= FALSE;
		RESET_ID3:= FALSE;
		RESET_ID4:= FALSE;
		RESET_ID5:= FALSE;
		RESET_ID6:= FALSE;
		RESET_ID7:= FALSE;
	END_IF
	
	I_konstanta_ID1;
	I_konstanta_ID2;
	I_konstanta_ID3;
	I_konstanta_ID4;
	I_konstanta_ID5;
	I_konstanta_ID6;
	I_konstanta_ID7;
	
END_PROGRAM
