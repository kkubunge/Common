#ifndef IODEFINE_H
#define IODEFINE_H

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#define	MAX_STRING_SIZE				64
//------------------------------------------------------------------------------------------
#define	MAX_CLUSTER_DEPTH			50
#ifdef PM_CHAMBER_60
	#define MAX_PM_CHAMBER_DEPTH		60
#else
	#ifdef PM_CHAMBER_30
		#define MAX_PM_CHAMBER_DEPTH		30
	#else
		#define MAX_PM_CHAMBER_DEPTH		12
	#endif
#endif
#define	MAX_SUB_CHAMBER_DEPTH	30
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
enum { BUTTON_NEW , BUTTON_SAVE , BUTTON_SAVEAS , BUTTON_CANCEL , BUTTON_FILE };
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
void LogView_Open_Recipe( HWND hWnd , int ch , char *filename );
//------------------------------------------------------------------------------------------
extern int	 USE_CLUSTERDATA_ITEM_COUNT;
//------------------------------------------------------------------------------------------

BOOL Get_Resource_LIST_PMFILE_Index_from_Resource_RELOAD_PM( int data , int *res , int *index ); // 2004.05.13
BOOL Get_Index_from_Resource_LIST_PMFILE( int data , int *index ); // 2004.05.13

#endif
