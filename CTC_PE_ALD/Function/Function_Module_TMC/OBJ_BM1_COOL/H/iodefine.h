#ifndef IODEFINE_H
#define IODEFINE_H
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
typedef enum {
	IO_Driver_Loding	 ,

	Progress			 ,
	Process_Run			 ,
	Process_Message		 ,

	PRM_BM1_COOL_TIME	 ,

	CTC_TR_Clear		 ,

	ATMVACSensorXI       ,

	CTC_BM1_Wafer_Status ,
	CTC_BM1_Wafer_Result ,
	CTC_BM1_Wafer_Status2,
	CTC_BM1_Wafer_Result2,
	CTC_BM1_Wafer_Status3,
	CTC_BM1_Wafer_Result3,
	CTC_BM1_Wafer_Status4,
	CTC_BM1_Wafer_Result4,
	CTC_BM1_Wafer_Status5,
	CTC_BM1_Wafer_Result5,
	CTC_BM1_Wafer_Status6,
	CTC_BM1_Wafer_Result6

} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#define		MAX_STEP_COUNT		100
#define		MAX_RECIPENAME_LEN	19
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#endif
