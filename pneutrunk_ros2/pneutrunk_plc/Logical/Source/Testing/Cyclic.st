PROGRAM _CYCLIC
	
	IF i >= 30000 THEN
		i := 0;
	ELSE
		i := i + 100;
	END_IF
	
	modul.tlak1[0] := i;
	 
END_PROGRAM
