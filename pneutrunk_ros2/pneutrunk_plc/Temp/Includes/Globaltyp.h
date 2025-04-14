/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1742762459_1_
#define _BUR_1742762459_1_

#include <bur/plctypes.h>

/* Datatypes and datatypes of function blocks */
typedef struct tlacidla
{	plcbit start;
	plcbit ros;
	plcbit stopLED;
	plcbit stop;
	plcbit startLED;
	plcbit startButton;
	plcbit centralStop;
	plcbit stropBielaLED;
	plcbit stropCervenaLED;
	plcbit klucik;
} tlacidla;

typedef struct automatic
{	signed short y_desired[7];
	signed short x_desired[7];
	signed short linear;
	plcbit ball_up;
	plcbit casovac;
	plcbit effector;
	plcbit casovac_uchopenie;
	plcbit ball_piston;
	plctime novyCyklus;
	plcbit novyCyklusStart;
	plcbit trajectoryStart2;
	plctime trajectoryTime2;
	plcbit automatic;
	plcbit holdPosition;
	signed short cas;
	signed short box;
	signed short step_color;
	plcbit popcorn;
	signed short testFarba;
	plcbit loptickyVzasobniku;
	signed short x_desired_previous[7];
	signed short y_desired_previous[7];
	signed short I_konstanta[7];
	plcbit levitacia;
} automatic;

typedef struct podavac
{	plcbit levitovanie;
	plcbit ball_piston_sjf;
	plcbit ball;
	plcbit ball_piston;
} podavac;

typedef struct identifikacia
{	float p3;
	float p2;
	float p1;
	unsigned char vzorka;
	signed short uhol2[10];
	signed short uhol2Priemer;
	signed short uhol1Priemer;
	signed short uhol1[10];
	plcbit uhol2Stabilny;
	plcbit uhol1Stabilny;
	signed short uhol2Ref;
	signed short uhol1Ref;
	unsigned char krok;
	float p2Mem;
	float p1Mem;
	plcbit tonStart;
	unsigned char pocetOverenie;
	plcbit spustit;
	plcbit p3Koniec;
	plcbit p2Koniec;
	plcbit p1Koniec;
	float p3Mem;
	signed short results;
	plcbit switchs;
	float inkrement;
	float hornyTlak;
} identifikacia;

typedef struct packetRS485
{	plcbyte packet[10];
	plcbyte sendPacketLED[6];
	plcbyte sendPacketSnimace[6];
	plcbyte sendPacketFinal[6];
	unsigned char id;
} packetRS485;

typedef struct packetUDP
{	float qDesired[41];
	signed short end;
	signed short color;
	signed short step;
	signed short tlak1pos;
	signed short tlak2pos;
	signed short tlak3pos;
	plcstring tlak1Full[81];
	plcstring tlak2Full[81];
	plcstring tlak3Full[81];
	signed short commatlak1;
	signed short commatlak2;
	signed short commatlak3;
	float tlak2Desired[7];
	float tlak1Desired[7];
	float tlak3Desired[7];
	plcstring tlak1String[7][7];
	plcstring tlak2String[7][7];
	plcstring tlak3String[7][7];
	float MAX_VALUE;
} packetUDP;

typedef struct tlaky
{	unsigned char tlak3;
	unsigned char tlak2;
	unsigned char tlak1;
} tlaky;

typedef struct moduly
{	float uhol2[7];
	float uhol1[7];
	plcbit koncak[7];
	plcbit led[7];
	signed short uholINT2;
	signed short uholINT1;
	signed short tlak1[7];
	signed short tlak2[7];
	signed short tlak3[7];
	signed short tlakLinear;
	float uhol_XminusRef[7];
	float uhol_YminusRef[7];
	float linearReal;
	plcbit naraz[8];
	plcbit narazAktivny;
	float tlaky[4];
} moduly;






__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/Global.typ\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1742762459_1_ */

