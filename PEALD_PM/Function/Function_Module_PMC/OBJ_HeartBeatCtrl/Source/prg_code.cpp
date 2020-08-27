///////////////////////////////////////////////////////////////////////////////
// AbortProcess

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>

//==========================================================================================
extern "C"
{

#include <Kutlstr.h>
#include <Kutltime.h>
#include "cimseqnc.h"
#include "iodefine.h"

} // End of [extern "C"]
//==========================================================================================

//--------------------------------------------------------------------
#ifndef _DEBUG
// #define _DEBUG
#endif

//------------------------------------------------------------------------------------------
#define APP_NAME	"HeartBeatControl"

#define POLLING_TIME	1000
//------------------------------------------------------------------------------------------

IO_Name_String_Map IO_STR_Map_Table[] = {
	{ "VRCP_HeartBeatDO",	_K_D_IO	,	VRCP_HeartBeatDO, 0},
	""
};

//------------------------------------------------------------------------------------------
// Check HeartBeat
int g_nVRCP_HeartBeatDO = 0;
//------------------------------------------------------------------------------------------

void HeartBeat_Loop()
{
	int nIOStatus;

	while( TRUE )		// infinite loop
	{
		if(g_nVRCP_HeartBeatDO == 0) g_nVRCP_HeartBeatDO = 1;
		else g_nVRCP_HeartBeatDO = 0;
		WRITE_DIGITAL(VRCP_HeartBeatDO, g_nVRCP_HeartBeatDO, &nIOStatus);

		Sleep(POLLING_TIME);
	};
}

//==========================================================================================
extern "C"
{

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------

Module_Status Program_Main() {
	Module_Status msRet = SYS_SUCCESS;
	// printf("Entered %s\n", APP_NAME);

	HeartBeat_Loop();

	// printf("Leaved %s\n", APP_NAME);
	return msRet;
}

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void Screen_Nav_Info( int no ) {
	if(no == -1)
	{
		// Deinitialize
	}
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void Program_Enter_Code() {
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
BOOL Program_Init_Code() {
	return TRUE;
}

} // End of [extern "C"]
//==========================================================================================