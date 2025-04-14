(********************************************************************
 * COPYRIGHT -- Bernecker + Rainer
 ********************************************************************
 * Program: Server
 * File: Server.st
 * Author: Bernecker + Rainer
 * Created: June 02, 2008
 ********************************************************************
 * Implementation of program Server
 ********************************************************************)

PROGRAM _CYCLIC


	CASE Server.sStep OF
		
		0:	(* Open UDP Port *)
			Server.UdpOpen_0.enable := 1;
			Server.UdpOpen_0.pIfAddr := 0;	(* Listen on all TCP/IP Interfaces*)
			Server.UdpOpen_0.port := 12050;	(* Port to listen*)
			Server.UdpOpen_0.options := 0;
			Server.UdpOpen_0;	(* Call the Function*)
			
			IF Server.UdpOpen_0.status = 0 THEN  (* UdpOpen successful*)
				Server.sStep := 1;	
			ELSIF Server.UdpOpen_0.status = ERR_FUB_BUSY THEN  (* UdpOpen not finished -> redo *)			
			  (* Busy *)	
			ELSE  (* Goto Error Step *)
				Server.sStep := 10;
			END_IF
			
		1:	(* Wait for Data *)
			Server.UdpRecv_0.enable := 1;
			Server.UdpRecv_0.ident := Server.UdpOpen_0.ident;	(* Client Ident from AsUDP.UDP_Open *)
			Server.UdpRecv_0.pData := ADR(Server.data_buffer);	(* Where to store the incoming data *)
			Server.UdpRecv_0.datamax := SIZEOF(Server.data_buffer);	(* Lenght of data buffer *)
			Server.UdpRecv_0.flags := 0;
			Server.UdpRecv_0.pIpAddr := ADR(Server.client_address);	(* IP Address of the Client *)
			Server.UdpRecv_0;	(* Call the Function*)
			
			IF Server.UdpRecv_0.status = 0 THEN  (* Data received *)
				Server.sStep := 2;
			ELSIF Server.UdpRecv_0.status = udpERR_NO_DATA THEN  (* No data received - wait *)
			  (* No Data received *)
			ELSIF Server.UdpRecv_0.status = ERR_FUB_BUSY THEN  (* UdpRecv not finished -> redo *)					
			  (* Busy *)
			ELSE  (* Goto Error Step *)
				Server.sStep := 10;
			END_IF
			
		2:	(* Send Data back to Client *)
			
			Server.UdpSend_0.enable := 1;
			Server.UdpSend_0.ident := Server.UdpOpen_0.ident;	// Client Ident from AsUDP.UDP_Open 
			Server.UdpSend_0.pHost := ADR(Server.client_address);	// IP Address of the Client 
			Server.UdpSend_0.port := Server.UdpRecv_0.port;		// Port number of the Client 
			Server.UdpSend_0.pData := ADR(Server.data_buffer);	// Which data to send 
			Server.UdpSend_0.datalen := SIZEOF(Server.data_buffer);	// Lenght of data to send 
			Server.UdpSend_0.flags := 0;
			Server.UdpSend_0;	// Call the Function
			
			IF switch = FALSE THEN
				// Yellow - 1, Red - 2, Undefined - 3
				packetPos.color := FIND(Server.data_buffer, 'yellow');
				IF(packetPos.color>1)THEN
					automatika.step_color := 1;
				ELSIF(packetPos.color=0)THEN
					packetPos.color := FIND(Server.data_buffer, 'red');
					IF(packetPos.color>1) THEN
						automatika.step_color:= 2;	
					ELSE
						automatika.step_color:= 3;
					END_IF
					
				END_IF
				// Volba kroku robota
				packetPos.step := FIND(Server.data_buffer, 'come');
				IF(packetPos.step >1)THEN
					global_step_udp := 1;
				ELSIF(packetPos.step = 0)THEN
					packetPos.step := FIND(Server.data_buffer, 'hold');
					IF(packetPos.step >1)THEN
						global_step_udp := 2;
					ELSIF(packetPos.step = 0)THEN
						packetPos.step := FIND(Server.data_buffer, 'release');
						IF(packetPos.step >1)THEN
							global_step_udp := 3;
						ELSIF(packetPos.step = 0)THEN
							packetPos.step := FIND(Server.data_buffer, 'continue');
							IF(packetPos.step >1)THEN
								global_step_udp := 4;
							END_IF
						END_IF
					END_IF
				END_IF
				
				packetPos.tlak1pos := FIND(Server.data_buffer, 'tlak1:');
				packetPos.tlak2pos := FIND(Server.data_buffer, 'tlak2:');
				packetPos.tlak3pos := FIND(Server.data_buffer, 'tlak3:');
				packetPos.end := FIND(Server.data_buffer, 'end');
				
				packetPos.tlak1Full := MID(Server.data_buffer, packetPos.tlak2pos - packetPos.tlak1pos -6,packetPos.tlak1pos+6);
				packetPos.tlak2Full := MID(Server.data_buffer, packetPos.tlak3pos - packetPos.tlak2pos -6,packetPos.tlak2pos +6);
				packetPos.tlak3Full := MID(Server.data_buffer, packetPos.end - packetPos.tlak3pos -6,packetPos.tlak3pos +6);
				
				FOR i:=0 TO 6 BY 1 DO	//11
					packetPos.commatlak1 := FIND(packetPos.tlak1Full, ',');
					packetPos.tlak1String[i] := MID(packetPos.tlak1Full, packetPos.commatlak1, 0);
					packetPos.tlak1Full := DELETE(packetPos.tlak1Full,packetPos.commatlak1+1, 0);
					packetPos.tlak1Desired[i] := atof(ADR(packetPos.tlak1String[i])) ;
					IF packetPos.tlak1Desired[i] >= packetPos.MAX_VALUE THEN
						packetPos.tlak1Desired[i] := packetPos.MAX_VALUE;
					END_IF
					modul.tlak1[i] := REAL_TO_INT(packetPos.tlak1Desired[i]);
				END_FOR
				
				FOR i:=0 TO 6 BY 1 DO	//11
					packetPos.commatlak2 := FIND(packetPos.tlak2Full, ',');
					packetPos.tlak2String[i] := MID(packetPos.tlak2Full, packetPos.commatlak2, 0);
					packetPos.tlak2Full := DELETE(packetPos.tlak2Full,packetPos.commatlak2+1, 0);
					packetPos.tlak2Desired[i] := atof(ADR(packetPos.tlak2String[i])) ;
					IF packetPos.tlak2Desired[i] >= packetPos.MAX_VALUE THEN
						packetPos.tlak2Desired[i] := packetPos.MAX_VALUE;
					END_IF
					modul.tlak2[i] := REAL_TO_INT(packetPos.tlak2Desired[i]);
				END_FOR
				
				FOR i:=0 TO 6 BY 1 DO	//11
					packetPos.commatlak3 := FIND(packetPos.tlak3Full, ',');
					packetPos.tlak3String[i] := MID(packetPos.tlak3Full, packetPos.commatlak3, 0);
					packetPos.tlak3Full := DELETE(packetPos.tlak3Full,packetPos.commatlak3+1, 0);
					packetPos.tlak3Desired[i] := atof(ADR(packetPos.tlak3String[i])) ;
					IF packetPos.tlak3Desired[i] >= packetPos.MAX_VALUE THEN
						packetPos.tlak3Desired[i] := packetPos.MAX_VALUE;
					END_IF
					modul.tlak3[i] := REAL_TO_INT(packetPos.tlak3Desired[i]);
				END_FOR
				
				
				
				
				(*FOR i:= 0 TO 6 BY 1 DO 
					IF packetPos.tlak2Desired[i] >= packetPos.MAX_VALUE THEN
						packetPos.tlak2Desired[i] := packetPos.MAX_VALUE;
						modul.tlak2[i] := REAL_TO_INT(packetPos.tlak2Desired[i]);	
					END_IF;
			    END_FOR *)
						
				//modul.tlak2[i] := REAL_TO_INT(packetPos.tlak2Desired[i]);
				// Server.data_buffer bolo povodne ked to slo STRING[5][0..100] a tu bolo Server.data_buffer[0]
				(*packetPos.p := FIND(Server.data_buffer, 'p:');
				packetPos.alpha := FIND(Server.data_buffer, 'a:');
				packetPos.end := FIND(Server.data_buffer, 'end');
				packetPos.pLength := UDINT_TO_INT(Server.UdpSend_0.datalen) - (packetPos.p + 1) - packetPos.alpha;
				packetPos.pFull := MID(Server.data_buffer, packetPos.alpha - packetPos.p -2,packetPos.p +2);
				packetPos.alphaLength := UDINT_TO_INT(Server.UdpSend_0.datalen) - (packetPos.alpha - 1) - packetPos.p;
				packetPos.alphaFull := MID(Server.data_buffer, packetPos.end+2 - packetPos.alpha, packetPos.alpha+2);
				
				

				packetPos.alphaFull := MID(Server.data_buffer, 13, 19);
				packetPos.alphaFullinfo:=packetPos.alphaFull;
				packetPos.pFullinfo:=packetPos.pFull;
				FOR i:=0 TO 3 BY 1 DO	//11
					packetPos.commaP := FIND(packetPos.pFull, ',');
					packetPos.pString[i] := MID(packetPos.pFull, packetPos.commaP, 0);
					packetPos.pFull := DELETE(packetPos.pFull,packetPos.commaP+1, 0);
					packetPos.pDesired[i] := atof(ADR(packetPos.pString[i])) ;
				END_FOR
				
				FOR a:=0 TO 3 BY 1 DO
				packetPos.commaAlpha := FIND(packetPos.alphaFull, ',');
				packetPos.alphaString[a] := MID(packetPos.alphaFull, packetPos.commaAlpha, 0);
				//modul.tlaky[a]:=atof(ADR(packetPos.alphaString[a])) ;
				packetPos.alphaFull := DELETE(packetPos.alphaFull,packetPos.commaAlpha+1, 0);
				packetPos.alphaDesired[a] := atof(ADR(packetPos.alphaString[a])) ;
				END_FOR*)
											
				
				//packetPos.pString[3] := MID(packetPos.qFull, packetPos.comma, 0);//12
				//packetPos.qFull := DELETE(packetPos.qFull, packetPos.comma+1, 0);
				//packetPos.qDesired[14] := atof(ADR(packetPos.qString[14]));//12
			END_IF
			
			
			IF Server.UdpSend_0.status = 0 THEN  (* Data sent *)
				Server.sStep := 1;					   
			ELSIF Server.UdpSend_0.status = ERR_FUB_BUSY THEN  (* UdpSend not finished -> redo *)						
				(* Busy *)
			ELSE  (* Goto Error Step *)
				Server.sStep := 10;
			END_IF
	    
		10:  (* Here some error Handling has to be implemented *)
			
	END_CASE		
			

END_PROGRAM
