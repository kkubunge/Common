#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <process.h>
#include <time.h>

#include <Kutlgui2.h>

//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
void Event_Message_Received() {
	if ( KGUI_STANDARD_Get_Screen_Handle() == NULL ) return; // 2004.05.19
	SendMessage( KGUI_STANDARD_Get_Screen_Handle() , WM_USER , WM_USER , (LPARAM) NULL );
}
//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
BOOL Program_Init_Code() {
	return TRUE;
}