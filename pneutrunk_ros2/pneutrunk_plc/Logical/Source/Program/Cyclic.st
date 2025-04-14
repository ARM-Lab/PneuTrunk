PROGRAM _CYCLIC
	
	TON_0(IN := automatika.casovac, PT := INT_TO_TIME(automatika.cas));
	TON_1(IN := automatika.casovac_uchopenie, PT := T#4s);
	//TON_2(IN := automatika.trajectoryStart, PT := automatika.trajectoryTime);
	//TON_4(IN := automatika.trajectoryStart2, PT := automatika.trajectoryTime2);
	//TON_3(IN := automatika.novyCyklusStart, PT := automatika.novyCyklus);

	
	CASE global_step OF
		
		0:	// caka kym spravi uvodne odmeranie referencii....v controlleri ak je krok 4, vtedy prechadza global_step = 1
			(*
			automatika.y_desired[0]	:= 0;
			automatika.y_desired[1]	:= 0;
			automatika.y_desired[2]	:= 0;
			automatika.y_desired[3]	:= 0;
			automatika.y_desired[4]	:= 0;
			automatika.y_desired[5]	:= 0;
			automatika.y_desired[6]	:= 0;
			
			automatika.x_desired[0]	:= 0;
			automatika.x_desired[1]	:= 0;
			automatika.x_desired[2]	:= 0;
			automatika.x_desired[3]	:= 0;
			automatika.x_desired[4]	:= 0;
			automatika.x_desired[5]	:= 0;
			automatika.x_desired[6]	:= 0;
			*)
			automatika.linear		:= 23;
			FOR i:=0 TO 6 BY 1 DO
				automatika.I_konstanta[i]	:= 5;
			END_FOR
			automatika.automatic	:= FALSE;
			(*
			IF automatika.step_color = 1 OR automatika.step_color = 2 THEN
				global_step				:= 999;
			END_IF				
			*)
			modul;
			
		999:
			IF automatika.step_color = 1 OR automatika.step_color = 2 THEN
				automatika.loptickyVzasobniku	:= TRUE;
			ELSE
				automatika.loptickyVzasobniku	:= FALSE;
			END_IF
			
			IF automatika.loptickyVzasobniku = TRUE OR global_step_udp = 1 THEN
				automatika.effector		:= FALSE;
			//	global_step_udp			:= 0;
				global_step				:= 1;
				automatika.automatic	:= FALSE;
				I_ON					:= FALSE;
			END_IF
			FOR i:=0 TO 6 BY 1 DO
				automatika.I_konstanta[i]	:= 0;
			END_FOR
			
		1:	
			automatika.cas			:= 1000;
			automatika.casovac		:= TRUE;
			I_ON					:= TRUE;
			global_step				:= 100;
			
		100:
			IF TON_0.Q = TRUE THEN
				automatika.casovac	:= FALSE;
				IF global_step_udp = 1 THEN
					global_step				:= 11;
				ELSE
					automatika.cas			:= 1000;
					automatika.casovac		:= TRUE;
					global_step				:= 2;
				END_IF
			END_IF
			
		2:
			IF TON_0.Q=TRUE THEN
				automatika.casovac		:= FALSE;
				//automatika.ball_up		:= TRUE;
				global_step				:= 3;
			//	automatika.ball_piston	:= FALSE;
			END_IF
			
			
		3:	// pohyb pre uchopenie gulicky
			//automatika.casovac_uchopenie	:= TRUE;
			IF(automatika.step_color = 1)THEN
				automatika.box := 1;
				automatika.loptickyVzasobniku := TRUE;
			ELSIF(automatika.step_color = 2)THEN
				automatika.box	:= 2;
				automatika.loptickyVzasobniku := TRUE;
			ELSIF(automatika.step_color = 3)THEN
				automatika.loptickyVzasobniku := FALSE;
				automatika.box := 3;
			END_IF
			
			automatika.casovac			:= TRUE;
			automatika.cas				:= 5000;
			automatika.effector			:= FALSE;
			automatika.linear			:= 23;
			global_step					:= 4;
			FOR i:=0 TO 6 BY 1 DO
				automatika.I_konstanta[i]	:= 30;
			END_FOR
		4:
			// Pohyb ku levitujucej lopte
			
			automatika.y_desired[0]	:= TIME_TO_INT(TON_0.ET)*(-7)/((automatika.cas));
			automatika.y_desired[1]	:= TIME_TO_INT(TON_0.ET)*(6)/((automatika.cas));	
			automatika.y_desired[2]	:= TIME_TO_INT(TON_0.ET)*(-10)/((automatika.cas));
			automatika.y_desired[3]	:= TIME_TO_INT(TON_0.ET)*(-10)/((automatika.cas));
			automatika.y_desired[4]	:= TIME_TO_INT(TON_0.ET)*(-8)/((automatika.cas));
			automatika.y_desired[5]	:= TIME_TO_INT(TON_0.ET)*(-5)/((automatika.cas));
			automatika.y_desired[6]	:= TIME_TO_INT(TON_0.ET)*(-5)/((automatika.cas));//-10
			
			automatika.x_desired[0]	:= TIME_TO_INT(TON_0.ET)*5/((automatika.cas));
			automatika.x_desired[1]	:= TIME_TO_INT(TON_0.ET)*4/((automatika.cas));
			automatika.x_desired[2]	:= TIME_TO_INT(TON_0.ET)*5/((automatika.cas));
			automatika.x_desired[3]	:= TIME_TO_INT(TON_0.ET)*5/((automatika.cas));
			automatika.x_desired[4]	:= TIME_TO_INT(TON_0.ET)*5/((automatika.cas));
			automatika.x_desired[5]	:= TIME_TO_INT(TON_0.ET)*1/((automatika.cas));
			automatika.x_desired[6]	:= 0;// TIME_TO_INT(TON_0.ET)*2/((automatika.cas));
			
			//automatika.linear		:= TIME_TO_INT(TON_2.ET)*30/(TIME_TO_INT(automatika.trajectoryTime));
			
			IF TON_0.Q=TRUE THEN
				automatika.casovac			:= FALSE;
				automatika.casovac_uchopenie:= TRUE;
				global_step					:= 55;
				FOR i:=0 TO 6 BY 1 DO
					automatika.x_desired_previous[i]	:= automatika.x_desired[i];
					automatika.y_desired_previous[i]	:= automatika.y_desired[i];
					automatika.I_konstanta[i]			:= 20;
				END_FOR
			END_IF
			
		55:
			IF TON_1.Q = TRUE THEN
				automatika.levitacia			:= TRUE;
				automatika.linear				:= 30;
				automatika.casovac_uchopenie	:= FALSE;
				global_step						:= 555;
			END_IF
			
		555:
			automatika.cas						:= 1000;
			automatika.casovac					:= TRUE;
			global_step							:= 5;
			
		5:	// uchopenie
			IF TON_0.Q = TRUE THEN
				automatika.casovac				:= FALSE;
				automatika.effector				:= TRUE;
				global_step						:= 6;
			END_IF
		
		6:	
			automatika.casovac_uchopenie		:= TRUE;
			global_step							:= 7;
			automatika.linear					:= 23;
			
		7:
			IF TON_1.Q = TRUE THEN
				automatika.casovac_uchopenie	:= FALSE;
				global_step						:= 8;
				automatika.levitacia			:= FALSE;
				automatika.ball_piston			:= TRUE;
				automatika.cas					:= 4500;
				automatika.casovac				:= TRUE;
				FOR i:=0 TO 6 BY 1 DO
					automatika.I_konstanta[i]	:= 50;
				END_FOR
			END_IF
			
		8:	
			IF(automatika.box = 1) THEN
				// prenesenie objektu
				automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(7)/((automatika.cas));
				automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));	// 5000ms
				automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
				automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
				automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(8)/((automatika.cas));
				automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(5)/((automatika.cas));
				automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
			
				automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(2)/((automatika.cas));
				automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(-2)/((automatika.cas));
				automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(-2)/((automatika.cas));
				automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(-2)/((automatika.cas));
				automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(-5)/((automatika.cas));
				automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) +  TIME_TO_INT(TON_0.ET)*(-5)/((automatika.cas));
				automatika.x_desired[6]	:= TIME_TO_INT(TON_0.ET)*(-5)/((automatika.cas));
			
				automatika.linear		:= TIME_TO_INT(TON_0.ET)*30/((automatika.cas));
			ELSIF(automatika.box = 2) THEN
				// prenesenie objektu
				automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(7)/((automatika.cas));
				automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(2)/((automatika.cas));	// 5000ms
				automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
				automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
				automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(8)/((automatika.cas));
				automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(5)/((automatika.cas));
				automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
			
				automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-8)/((automatika.cas));//-5
				automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-3)/((automatika.cas));//0
				automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(5)/((automatika.cas));
				automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
				automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
				automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
				automatika.x_desired[6]	:= 0;
			
				automatika.linear		:= TIME_TO_INT(TON_0.ET)*30/((automatika.cas));
			ELSIF(automatika.box = 3) THEN
				(*
				IF(automatika.step_color = 1)THEN
					automatika.loptickyVzasobniku	:= TRUE;
					automatika.box := 1;
				ELSIF(automatika.step_color = 2)THEN
					automatika.box	:= 2;
					automatika.loptickyVzasobniku	:= TRUE;
				ELSIF(automatika.step_color = 3)THEN
					*)
					automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//+ TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	// 5000ms
					automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);// TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
					automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas);//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
					automatika.x_desired[6]	:= 0;//TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));;
					
					automatika.loptickyVzasobniku	:= FALSE;
					automatika.effector				:= FALSE;
					global_step						:= 0;
				//END_IF
				
			END_IF

			IF TON_0.Q=TRUE THEN
				automatika.casovac					:= FALSE;
				automatika.ball_piston				:= FALSE;
				IF automatika.loptickyVzasobniku = TRUE THEN
					global_step						:= 9;
				ELSE
					global_step						:= 999;//0
				END_IF
				FOR i:=0 TO 6 BY 1 DO
					automatika.x_desired_previous[i]:= automatika.x_desired[i];
					automatika.y_desired_previous[i]:= automatika.y_desired[i];
				END_FOR
			END_IF

		9:
			automatika.effector				:= FALSE;
			automatika.cas					:= 2000;
			automatika.casovac				:= TRUE;
			global_step						:= 901;
			
		901:
			IF(automatika.step_color = 3)THEN
				automatika.testFarba	:= 1;
			END_IF
			global_step					:= 902;
			
		902:
			IF(automatika.step_color = 3)THEN
				automatika.testFarba	:= 2;
			END_IF
			global_step					:= 903;
			
		903:
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				automatika.popcorn			:= FALSE;
				IF(automatika.step_color = 3)THEN
					automatika.testFarba	:= 0;
					automatika.loptickyVzasobniku	:= FALSE;
				END_IF
				global_step					:= 904;			
			END_IF
			
		904:
			automatika.cas					:= 4000;
			automatika.casovac				:= TRUE;
			global_step						:= 905;
			
		905:
			
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	// 5000ms
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			automatika.linear		:= 23;
			
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				global_step					:= 999;//posledne bolo 1 predtym 0
			END_IF
			
			
		11:
			automatika.cas					:= 5000;
			global_step						:= 111;
			automatika.linear				:= 23;
			FOR i:=0 TO 6 BY 1 DO
				automatika.x_desired_previous[i]:= automatika.x_desired[i];
				automatika.y_desired_previous[i]:= automatika.y_desired[i];
				automatika.I_konstanta[i]	:= 50;
			END_FOR
			automatika.casovac				:= TRUE;
			
		111:
			// ide po loptu
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(2)/((automatika.cas));//0
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(18)/((automatika.cas));	
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(18)/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(18)/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-18)/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-15)/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-18)/((automatika.cas));//-18
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(15)/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(13)/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(3)/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-10)/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-12)/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(-15)/((automatika.cas));//-10
			
			IF TON_0.Q=TRUE THEN
				automatika.casovac			:= FALSE;
				global_step					:= 1110;
			END_IF
		1110:
			automatika.cas					:= 3500;
			automatika.casovac				:= TRUE;
			global_step						:= 11101;
		11101:
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				automatika.ball_up			:= TRUE;
				global_step					:= 11102;
			END_IF
		11102:
			automatika.cas					:= 3000;
			automatika.casovac				:= TRUE;
			global_step						:= 1112;	
			
		1112:// pockanie na vysunutie linearneho clena
			IF TON_0.Q = TRUE THEN
				automatika.casovac		:= FALSE;
			//	automatika.linear		:= 30;
				global_step				:= 1113;
			END_IF
				
		1113:// uchopenie lopty
			automatika.cas				:= 3000;
			automatika.casovac			:= TRUE;
			automatika.effector			:= TRUE;
			global_step					:= 122;

		122://pockanie na uchopenie lopty
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				automatika.linear			:= 23;
				automatika.ball_up			:= FALSE;	// dvihac lopty dole
				global_step					:= 1222;
			END_IF
			
		1222:	
			automatika.cas					:= 3000;
			automatika.casovac				:= TRUE;
			global_step						:= 12222;
		12222:
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				global_step					:= 12223;
			END_IF
			
		12223:
			automatika.cas					:= 3000;
			automatika.casovac				:= TRUE;
			
			FOR i:=0 TO 6 BY 1 DO
				automatika.x_desired_previous[i]:= automatika.x_desired[i];
				automatika.y_desired_previous[i]:= automatika.y_desired[i];
			END_FOR
			global_step						:= 12224;
			
		12224:
			
			// nulova poloha
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			(*
			automatika.y_desired[4]	:= TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
			automatika.y_desired[5]	:= TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
			automatika.y_desired[6]	:= TIME_TO_INT(TON_0.ET)*(0)/((automatika.cas));
			
			automatika.x_desired[0]	:= TIME_TO_INT(TON_0.ET)*(-12)/((automatika.cas));
			automatika.x_desired[1]	:= TIME_TO_INT(TON_0.ET)*(-10)/((automatika.cas));
			automatika.x_desired[2]	:= TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
			automatika.x_desired[3]	:= TIME_TO_INT(TON_0.ET)*(10)/((automatika.cas));
			automatika.x_desired[4]	:= TIME_TO_INT(TON_0.ET)*(15)/((automatika.cas));
			automatika.x_desired[5]	:= TIME_TO_INT(TON_0.ET)*(15)/((automatika.cas));
			automatika.x_desired[6]	:= TIME_TO_INT(TON_0.ET)*(15)/((automatika.cas));
			*)
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				global_step					:= 12225;
			END_IF

		12225:
			automatika.cas					:= 4000;
			FOR i:=0 TO 6 BY 1 DO
				automatika.x_desired_previous[i]:= automatika.x_desired[i];
				automatika.y_desired_previous[i]:= automatika.y_desired[i];
			END_FOR
			automatika.casovac				:= TRUE;
			automatika.popcorn				:= TRUE;
			global_step						:= 12226;
			
		12226:
			(*
			automatika.x_desired[0]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[1]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[2]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[3]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[4]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[5]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[6]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			*)
			
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	// 5000ms
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				automatika.automatic		:= TRUE;
				global_step					:= 15;//12227
			END_IF
			
		12227:
			automatika.cas					:= 6000;
			global_step						:= 12228;
			FOR i:=0 TO 6 BY 1 DO
				automatika.x_desired_previous[i]:= automatika.x_desired[i];
				automatika.y_desired_previous[i]:= automatika.y_desired[i];
			END_FOR
			automatika.casovac				:= TRUE;
			
		12228:
			(*
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[2]))/((automatika.cas));	
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[4]))/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[6]))/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[8]))/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[10]))/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[12]))/((automatika.cas));
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[3]))/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[5]))/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[7]))/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[9]))/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[11]))/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[13]))/((automatika.cas));
			*)
			automatika.y_desired[0]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[1]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[2]))/((automatika.cas));	
			automatika.y_desired[2]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[4]))/((automatika.cas));
			automatika.y_desired[3]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[6]))/((automatika.cas));
			automatika.y_desired[4]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[8]))/((automatika.cas));
			automatika.y_desired[5]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[10]))/((automatika.cas));
			automatika.y_desired[6]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[12]))/((automatika.cas));
			
			automatika.x_desired[0]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[1]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[3]))/((automatika.cas));
			automatika.x_desired[2]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[5]))/((automatika.cas));
			automatika.x_desired[3]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[7]))/((automatika.cas));
			automatika.x_desired[4]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[9]))/((automatika.cas));
			automatika.x_desired[5]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[11]))/((automatika.cas));
			automatika.x_desired[6]	:= TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[13]))/((automatika.cas));
			
			IF TON_0.Q THEN
				automatika.casovac				:= FALSE;
				FOR i:=0 TO 6 BY 1 DO
					automatika.I_konstanta[i]	:= 20;
				END_FOR 
				automatika.automatic			:= TRUE;
				automatika.holdPosition			:= FALSE;
				global_step						:= 15;
				automatika.popcorn				:= FALSE;
			END_IF	
				
		13:
			IF global_step_udp = 1 THEN
				automatika.effector			:= FALSE;
				//automatika.casovac_uchopenie:= TRUE;
				global_step					:= 14;
			END_IF
		
		14:
			//IF TON_1.Q = TRUE THEN
				automatika.casovac_uchopenie:= FALSE;
				global_step					:= 15;
			//END_IF
			
		15:
			IF global_step_udp = 2 THEN
				automatika.holdPosition		:= TRUE;
				automatika.cas				:= 1000;
				automatika.casovac			:= TRUE;
				global_step					:= 16;
			END_IF
		16:
			IF TON_0.Q = TRUE THEN
				automatika.casovac			:= FALSE;
				global_step					:= 17;
				automatika.popcorn			:= FALSE;
			END_IF
		17:	// pustenie objektu a cakanie na povel pokracovat
			IF global_step_udp = 3 THEN
				automatika.effector			:= FALSE;
				global_step					:= 18;
			END_IF
			
		18:
			IF global_step_udp = 4 THEN
				
				automatika.automatic		:= FALSE;
				automatika.holdPosition		:= FALSE;
				I_ON						:= FALSE;
				global_step					:= 19;//19
			END_IF
			
		19:
			
			
			FOR i:=0 TO 6 BY 1 DO
				automatika.x_desired_previous[i]	:= REAL_TO_INT(packetPos.qDesired[i*2]); //automatika.x_desired[i];
				automatika.y_desired_previous[i]	:= REAL_TO_INT(-packetPos.qDesired[i*2+1]); //automatika.y_desired[i];
				automatika.x_desired[i]				:= 0;
				automatika.y_desired[i]				:= 0;
				packetPos.qDesired[i*2]				:= 0;
				packetPos.qDesired[i*2+1]			:= 0;
				automatika.I_konstanta[i]			:= 5;
			END_FOR
			
			global_step				:= 20;
		20:
			I_ON					:= TRUE;
			automatika.cas			:= 5000;
			automatika.casovac		:= TRUE;
			global_step				:= 21;
		21:
			
			
			automatika.y_desired[0]	:= 0;
			automatika.y_desired[1]	:= 0;	// 5000ms
			automatika.y_desired[2]	:= 0;
			automatika.y_desired[3]	:= 0;
			automatika.y_desired[4]	:= 0;
			automatika.y_desired[5]	:= 0;
			automatika.y_desired[6]	:= 0;
			
			automatika.x_desired[0]	:= 0;
			automatika.x_desired[1]	:= 0;
			automatika.x_desired[2]	:= 0;
			automatika.x_desired[3]	:= 0;
			automatika.x_desired[4]	:= 0;
			automatika.x_desired[5]	:= 0;
			automatika.x_desired[6]	:= 0;
			(*
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[0]))/((automatika.cas));
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(REAL_TO_INT(packetPos.qDesired[1]))/((automatika.cas));
			*)
			automatika.linear		:= 23;
			
			IF TON_0.Q = TRUE THEN
				automatika.casovac	:= FALSE;
				global_step			:= 999;
			END_IF
			
			(*
			FOR i:=0 TO 6 BY 1 DO
				packetPos.qDesired[i*2]		:= 0;
				packetPos.qDesired[i*2+1]	:= 0;
				automatika.y_desired[i]		:= 0;
				automatika.x_desired[i]		:= 0;
			END_FOR
		*)
			
			
		//	IF TON_0.Q = TRUE THEN
		//		automatika.casovac		:= FALSE;
				//	global_step				:= 999;
		//	END_IF
			
		//	global_step						:= 20;
			
		22:
			
			
			(*
			automatika.y_desired[0]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[1]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	// 5000ms
			automatika.y_desired[2]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[3]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[4]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[5]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[6]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			automatika.x_desired[0]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[1]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[2]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[3]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[4]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[5]	:= TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			*)
			(*
			automatika.y_desired[0]	:= (automatika.y_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[1]	:= (automatika.y_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));	// 5000ms
			automatika.y_desired[2]	:= (automatika.y_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[3]	:= (automatika.y_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[4]	:= (automatika.y_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[5]	:= (automatika.y_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.y_desired[6]	:= (automatika.y_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			
			automatika.x_desired[0]	:= (automatika.x_desired_previous[0]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[1]	:= (automatika.x_desired_previous[1]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[2]	:= (automatika.x_desired_previous[2]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[3]	:= (automatika.x_desired_previous[3]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[4]	:= (automatika.x_desired_previous[4]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[5]	:= (automatika.x_desired_previous[5]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			automatika.x_desired[6]	:= (automatika.x_desired_previous[6]*(automatika.cas - TIME_TO_INT(TON_0.ET))/automatika.cas) + TIME_TO_INT(TON_0.ET)*(1)/((automatika.cas));
			*)

			
			

	END_CASE
		 
END_PROGRAM
