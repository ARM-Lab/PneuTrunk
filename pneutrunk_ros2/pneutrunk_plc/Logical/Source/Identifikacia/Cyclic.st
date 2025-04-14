PROGRAM _CYCLIC
	
	IF meranie.spustit = TRUE THEN
		
		// ak sa meria ID2 pre spevnenie statickych hornych modulov
		modul.tlak1[0]	:= REAL_TO_INT(2*32767/9);
		modul.tlak2[0]	:= REAL_TO_INT(2*32767/9);
		modul.tlak3[0]	:= REAL_TO_INT(2*32767/9);
		// ak sa meria ID3 pre spevnenie statickych hornych modulov
		modul.tlak1[1]	:= REAL_TO_INT(2*32767/9);
		modul.tlak2[1]	:= REAL_TO_INT(2*32767/9);
		modul.tlak3[1]	:= REAL_TO_INT(2*32767/9);
		
		TON_0(IN := meranie.tonStart, PT := T#3s);
		modul.tlak1[cMod]	:= REAL_TO_INT(meranie.p1*32767/9);
		modul.tlak2[cMod]	:= REAL_TO_INT(meranie.p2*32767/9);
		modul.tlak3[cMod]	:= REAL_TO_INT(meranie.p3*32767/9);
		
		IF meranie.p2Koniec = TRUE THEN
			meranie.p2Koniec		:= FALSE;
			meranie.p3				:= meranie.p3Mem + meranie.inkrement;
			meranie.p3Mem			:= meranie.p3;
			IF meranie.p3 >= meranie.hornyTlak THEN	// velke mechy iba do 3.5 baru
				meranie.p3Mem		:= 0;
				meranie.p3 			:= 0;
				meranie.p2			:= 0;
				meranie.p1			:= 0;
				meranie.krok		:= 5;
			END_IF
		END_IF
		
		IF meranie.p1Koniec = TRUE THEN
			meranie.p1Koniec		:= FALSE;
			meranie.p2				:= meranie.p2Mem + meranie.inkrement;
			IF meranie.p2 >= meranie.hornyTlak THEN	// velke mechy iba do 3.5 baru
				meranie.p2 			:= 0;
				meranie.p2Koniec	:= TRUE;
			END_IF
			meranie.p2Mem			:= meranie.p2;
		END_IF
		
		CASE meranie.krok OF
			
			0:	// Referencia uhlov
				IF meranie.switchs = FALSE THEN
					meranie.switchs		:= TRUE;
					modul.tlak1[cMod]	:= REAL_TO_INT(3*32767/9);	// 3bar
					modul.tlak2[cMod]	:= REAL_TO_INT(3*32767/9);	// 3bar
					modul.tlak3[cMod]	:= REAL_TO_INT(3*32767/9);	// 3bar
					meranie.tonStart	:= TRUE;
				END_IF
				
				IF TON_0.Q = TRUE THEN
					meranie.switchs		:= FALSE;
					meranie.tonStart	:= FALSE;
					meranie.uhol1Ref	:= 0; //modul.uhol1[0];
					meranie.uhol2Ref	:= 0; //modul.uhol2[0];
					modul.tlak1[cMod]	:= 0;
					modul.tlak2[cMod]	:= 0;
					modul.tlak3[cMod]	:= 0;
					meranie.tonStart	:= TRUE;
					meranie.krok		:= 1;
				END_IF

			1:	// Mech aktivovany, caka sa na ustalenie
				IF TON_0.Q = TRUE THEN
					meranie.tonStart	:= FALSE;
					meranie.krok		:= 2;
				END_IF
			2:	// Meranie ci je mech ustaleny
				IF meranie.uhol1Stabilny = FALSE THEN
					FOR i:=0 TO meranie.pocetOverenie-2 BY 1 DO
						meranie.uhol1[i]	:= meranie.uhol1[i+1];
					END_FOR
					meranie.uhol1[meranie.pocetOverenie-1]		:= (modul.uhol1[cMod] - meranie.uhol1Ref);	
					// Pocitanie priemeru	
					meranie.uhol1Priemer := 0;
					FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
						meranie.uhol1Priemer := meranie.uhol1Priemer + meranie.uhol1[i];
					END_FOR
					meranie.uhol1Priemer := meranie.uhol1Priemer / meranie.pocetOverenie;
					
					IF((meranie.uhol1Priemer = meranie.uhol1[9]) AND
						(meranie.uhol1Priemer = meranie.uhol1[8]) AND
						(meranie.uhol1Priemer = meranie.uhol1[7]))THEN
						meranie.uhol1Stabilny	:= TRUE;
						FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
							meranie.uhol1[i] := 0;
						END_FOR
						meranie.uhol1Priemer := 0;
					ELSE
						meranie.uhol1Stabilny	:= FALSE;
					END_IF
				END_IF
				
				IF meranie.uhol2Stabilny = FALSE THEN
					FOR i:=0 TO meranie.pocetOverenie-2 BY 1 DO
						meranie.uhol2[i]			:= meranie.uhol2[i+1];
					END_FOR
					meranie.uhol2[meranie.pocetOverenie-1]	:= modul.uhol2[cMod] - meranie.uhol2Ref;	
					
					meranie.uhol2Priemer := 0;
					FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
						meranie.uhol2Priemer := meranie.uhol2Priemer + meranie.uhol2[i];
					END_FOR
					meranie.uhol2Priemer := meranie.uhol2Priemer / meranie.pocetOverenie;
					
					IF((meranie.uhol2Priemer = meranie.uhol2[9]) AND
						(meranie.uhol2Priemer = meranie.uhol2[8]) AND
						(meranie.uhol2Priemer = meranie.uhol2[7]))THEN
						meranie.uhol2Stabilny	:= TRUE;
						FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
							meranie.uhol2[i] := 0;
						END_FOR
						meranie.uhol2Priemer := 0;
					ELSE
						meranie.uhol2Stabilny	:= FALSE;
					END_IF
				END_IF
				
				IF((meranie.uhol1Stabilny = TRUE) AND (meranie.uhol2Stabilny = TRUE))THEN
					meranie.results			:= 1;		// ak true tento vysledok sa berie za ustaleny pre tlaky a uhly
					p1						:= meranie.p1;
					p2						:= meranie.p2;
					p3						:= meranie.p3;
					u1						:= modul.uhol1[cMod] - meranie.uhol1Ref;
					u2						:= modul.uhol2[cMod] - meranie.uhol2Ref;
					result					:= meranie.results;	
					meranie.krok 			:= 3;
					meranie.uhol1Stabilny	:= FALSE;
					meranie.uhol2Stabilny	:= FALSE;
					meranie.tonStart		:= TRUE;
				END_IF
			3:	// Mech bez tlaku, caka sa ustalenie
				IF meranie.switchs = FALSE THEN
					meranie.switchs			:= TRUE;
					meranie.p1				:= 0;
					meranie.p2				:= 0;
					meranie.p3				:= 0;
					meranie.results			:= 0;
					result					:= 0;
					p1						:= 0;
					p2						:= 0;
					p3						:= 0;
					u1						:= 0;
					u2						:= 0;
				END_IF
				
				IF TON_0.Q = TRUE THEN
					meranie.tonStart	:= FALSE;
					meranie.switchs		:= FALSE;
					meranie.krok		:= 4;
				END_IF
		
			4:	// Ak je mech nulovy a ustaleny ide odznova
				IF meranie.uhol1Stabilny = FALSE THEN
					FOR i:=0 TO meranie.pocetOverenie-2 BY 1 DO
						meranie.uhol1[i]			:= meranie.uhol1[i+1];
					END_FOR
					meranie.uhol1[meranie.pocetOverenie-1]	:= modul.uhol1[cMod] - meranie.uhol1Ref;	
					
					FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
						meranie.uhol1Priemer := meranie.uhol1Priemer + meranie.uhol1[i];
					END_FOR
					meranie.uhol1Priemer := meranie.uhol1Priemer / meranie.pocetOverenie;
					
					IF((meranie.uhol1Priemer = meranie.uhol1[9]) AND
						(meranie.uhol1Priemer = meranie.uhol1[8]) AND
						(meranie.uhol1Priemer = meranie.uhol1[7]))THEN
						meranie.uhol1Stabilny	:= TRUE;
						FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
							meranie.uhol1[i] := 0;
						END_FOR
						meranie.uhol1Priemer := 0;
					ELSE
						meranie.uhol1Stabilny	:= FALSE;
					END_IF
				END_IF
				
				IF meranie.uhol2Stabilny = FALSE THEN
					FOR i:=0 TO meranie.pocetOverenie-2 BY 1 DO
						meranie.uhol2[i]	:= meranie.uhol2[i+1];
					END_FOR
					meranie.uhol2[meranie.pocetOverenie-1]		:= modul.uhol2[cMod] - meranie.uhol2Ref;	
					
					FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
						meranie.uhol2Priemer := meranie.uhol2Priemer + meranie.uhol2[i];
					END_FOR
					meranie.uhol2Priemer := meranie.uhol2Priemer / meranie.pocetOverenie;
					
					IF((meranie.uhol2Priemer = meranie.uhol2[9]) AND
						(meranie.uhol2Priemer = meranie.uhol2[8]) AND
						(meranie.uhol2Priemer = meranie.uhol2[7]))THEN
						meranie.uhol2Stabilny	:= TRUE;
						FOR i:=0 TO meranie.pocetOverenie-1 BY 1 DO
							meranie.uhol2[i] := 0;
						END_FOR
						meranie.uhol2Priemer := 0;
					ELSE
						meranie.uhol2Stabilny	:= FALSE;
					END_IF
				END_IF
				
				IF((meranie.uhol1Stabilny = TRUE) AND (meranie.uhol2Stabilny = TRUE))THEN
					meranie.p1				:= meranie.p1Mem + meranie.inkrement;
					meranie.p2				:= meranie.p2Mem;
					meranie.p3				:= meranie.p3Mem;
					meranie.krok			:= 1;
					IF meranie.p1 >= meranie.hornyTlak THEN	// velke mechy iba do 3.5 baru
						meranie.p1 			:= 0;
						meranie.p1Koniec	:= TRUE;
					END_IF
					meranie.p1Mem			:= meranie.p1;
					meranie.tonStart		:= TRUE;
					meranie.uhol1Stabilny	:= FALSE;
					meranie.uhol2Stabilny	:= FALSE;
				END_IF
			
			5:	// meranie ukoncene
				
		END_CASE
		
	ELSE
		FOR i:=0 TO 5 BY 1 DO
			modul.tlak1[i]	:= 0;
			modul.tlak2[i]	:= 0;
			modul.tlak3[i]	:= 0;
		END_FOR
	END_IF // spustit meranie
END_PROGRAM
