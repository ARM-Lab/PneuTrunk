PROGRAM _INIT
	
	cMod := 2;
	meranie.hornyTlak	:= 5.1;
	meranie.p1	:= 0.001;
	meranie.tonStart	:= TRUE;
	meranie.inkrement	:= 0.3;
	// ak sa meria ID2 pre spevnenie statickych hornych modulov
	modul.tlak1[0]	:= REAL_TO_INT(2*32767/9);
	modul.tlak2[0]	:= REAL_TO_INT(2*32767/9);
	modul.tlak3[0]	:= REAL_TO_INT(2*32767/9);
	// ak sa meria ID3 pre spevnenie statickych hornych modulov
	modul.tlak1[1]	:= REAL_TO_INT(2*32767/9);
	modul.tlak2[1]	:= REAL_TO_INT(2*32767/9);
	modul.tlak3[1]	:= REAL_TO_INT(2*32767/9);
END_PROGRAM