#ifndef IODEFINE_H
#define IODEFINE_H

//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//
// IO List
//
typedef enum {
	IO_Driver_Loding,
	CONTROL			  ,
	CASSETTE_TIMEOUT  ,
	LL_DoorLXO		  ,
	LL_DoorRXO		  ,
	LL_DoorLXI		  ,
	LL_DoorRXI		  ,
	LFrontSlideDI     ,
	RFrontSlideDI     ,
	LL_ATMVACSensorXI,

	CTC_EVENT_LOG_SVR,			// 2013.11.15

	CTC_BM_Wafer_Status,
	CTC_BM_Wafer_Status2,
	//... 2016.04.16
	M_SVlv_ParmSaveDM,
	M_Door_StartStopDM,		
	M_SVlv_StartStopDM,	
	M_Door_CycTgtMdlDM,		      
	M_Door_CycCurCntAM,		     
	M_Door_CycTgtCntAM,		     
	BM_Door_OPTm_AM,		
	M_DoorBM_OP_MinTmAM,	 	    
	M_DoorBM_OP_MaxTmAM,				
	M_DoorBM_OP_AvgTmAM,		    
	BM_Door_CLTm_AM,		                
	M_DoorBM_CL_MinTmAM,		
	M_DoorBM_CL_MaxTmAM,			
	M_DoorBM_CL_AvgTmAM,		
	CTC_AbortControl,	    
	//...
} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------

#endif
