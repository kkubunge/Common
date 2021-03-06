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
		IO_DRIVER_LOAD,
		
		//... User Config Parameter
		FC_MOTOR_CONTROL,
		PRMA_ZMT_CtrlTmOut,
		PRMA_ZMT_ErrTol,
		PRMA_ZMT_HmHighLmt,
		PRMA_ZMT_HmLowLmt,
		PRMA_ZMT_Pulse_mm,
		PRMA_ZMT_Offset,
		PRMA_ZMT_Offset2,
		PRMA_ZMT_OffsIgLow,
		PRMA_ZMT_OffsIgHigh,
		PRMA_ZMT_NormSpeed,
	
		//... Function Virtual IO
		ZMT_SetPosAM,
		ZMT_SetPos2AM,
	
		//... Motor IO
		R_Motor_CommStat,
		R_Motor_Stop,
		R_Motor_Fast1_Home,
		R_Motor_Move_Home,
		R_Motor_Move_ABS,
		R_Motor_Status_DI,
	
		R_Move_Pulse_Set,
		R_Motor1_Position,
		R_Motor2_Position,
	
		R_All_Move_Pulse_Set,
		R_Motor_Move_All,
		R_Pulse_Set_String,
		R_Position8_Pulse,
		R_Position9_Pulse,
	
		R_Motor1_High_Speed,
		R_Motor2_High_Speed,
	
		//... DeviceNet IO
		ZMT_HomeSnsDI,
		ZMT2_HomeSnsDI,
	
		//... Reference Virtual IO
		PRO_RunStsDM,
		PMC_EVENT_LOG_CLI,

		//... 2015.02.28 Add Chuck Move Cycle for MAHA-DPT MFG TFT
		M_MT_CycMvSelDM,
		M_MT_CycMvPosAM,
		M_MT_CycMvTgtCntAM,
		//
		M_MT_CycMvCurCntAM,
		M_MT_CycMvUpTmAM,
		M_MT_CycMvDnTmAM,
		//
		M_MT_ParmSaveDM,

		//... 2015.03.20 Add Need Home Virtual IO Add for MC OFF Case
		R_Motor_NeedHomeDM,
		//... 2016.01.19
		ALECHK_DynCntDM,
		CHUCK_UPPOS_AM,	
		CHUCK_DOWNPOS_AM,
		LeakChkStsDM,
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
