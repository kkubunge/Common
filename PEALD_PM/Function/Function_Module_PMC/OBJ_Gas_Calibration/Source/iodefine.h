#ifndef IODEFINE_H
#define IODEFINE_H
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
typedef enum {
	IO_Driver_Loding,

	PLOTTING_CONTROL_GAS_A	,
	PLOTTING_CONTROL_GAS_B	,
	PLOTTING_CONTROL_TEMP_A	,
	PLOTTING_CONTROL_TEMP_B	,
	INTLKS_CONTROL			,



	MFC01StPtAO		 		,
	MFC02StPtAO		 		,
	MFC03StPtAO		 		,
	MFC04StPtAO		 		,
	MFC05StPtAO		 		,
	MFC06StPtAO		 		,
	MFC07StPtAO		 		,
	MFC08StPtAO		 		,
	MFC09StPtAO		 		,
	MFC10StPtAO		 		,
	MFC11StPtAO		 		,
	MFC12StPtAO		 		,
	MFC13StPtAO		 		,
	MFC14StPtAO		 		,
	MFC15StPtAO		 		,
	MFC16StPtAO		 		,
	MFC17StPtAO		 		,
	MFC18StPtAO		 		,

	MFC01FlwAI		 		,
	MFC02FlwAI				,
	MFC03FlwAI		 		,
	MFC04FlwAI		 		,
	MFC05FlwAI		 		,
	MFC06FlwAI		 		,
	MFC07FlwAI		 		,
	MFC08FlwAI		 		,
	MFC09FlwAI		 		,
	MFC10FlwAI		 		,
	MFC11FlwAI		 		,
	MFC12FlwAI			 	,
	MFC13FlwAI		 		,
	MFC14FlwAI		 		,
	MFC15FlwAI		 		,
	MFC16FlwAI		 		,
	MFC17FlwAI		 		,
	MFC18FlwAI		 		,


 	M651_Pressure		 	,
	M651_Position			,


 	M_CAL_GAS_SELECT		,
 	M_CAL_GAUGE_SELECT		,
	M_CAL_MODE_SELECT		,
 	M_CAL_START_PRESS		,
 	M_CAL_FINAL_PRESS		,
 	M_CAL_TARGET_PRESS		,
	M_CAL_ELAPSE_TIME_SET	,
 	M_CAL_ELAPSED_TIME		,
 	M_CAL_PUMP_TIME_SET		,
 	M_CAL_PUMP_ELAPSED		,
 	M_CAL_PURGE_TIME_SET	,
 	M_CAL_PURGE_ELAPSED		,
 	M_CAL_CHAMBER_TEMP		,
 	M_CAL_CHAMBER_VOLUME	,
 	M_CAL_TOTAL_ACT_FLOW	,
 	M_CAL_PURGE_GAS_SET		,
 	M_CAL_STABLE_TIME_SET	,
 	M_CAL_STABLE_ELAPSED	,

 	M_CALI_MFC01_FACTOR		,
 	M_CALI_MFC02_FACTOR		,
 	M_CALI_MFC03_FACTOR		,
 	M_CALI_MFC04_FACTOR		,
 	M_CALI_MFC05_FACTOR		,
 	M_CALI_MFC06_FACTOR		,
 	M_CALI_MFC07_FACTOR		,
 	M_CALI_MFC08_FACTOR		,
 	M_CALI_MFC09_FACTOR		,
 	M_CALI_MFC10_FACTOR		,
 	M_CALI_MFC11_FACTOR		,
 	M_CALI_MFC12_FACTOR		,
 	M_CALI_MFC13_FACTOR		,
 	M_CALI_MFC14_FACTOR		,
 	M_CALI_MFC15_FACTOR		,
 	M_CALI_MFC16_FACTOR		,
 	M_CALI_MFC17_FACTOR		,
 	M_CALI_MFC18_FACTOR		,
 

 	M_CALI_MFC01_SET		,
 	M_CALI_MFC02_SET		,
 	M_CALI_MFC03_SET		,
 	M_CALI_MFC04_SET		,
 	M_CALI_MFC05_SET		,
 	M_CALI_MFC06_SET		,
 	M_CALI_MFC07_SET		,
 	M_CALI_MFC08_SET		,
 	M_CALI_MFC09_SET		,
 	M_CALI_MFC10_SET		,
 	M_CALI_MFC11_SET		,
 	M_CALI_MFC12_SET		,
 	M_CALI_MFC13_SET		,
 	M_CALI_MFC14_SET		,
 	M_CALI_MFC15_SET		,
 	M_CALI_MFC16_SET		,
 	M_CALI_MFC17_SET		,
 	M_CALI_MFC18_SET		,
//----------------------------

	M_CAL_GasType_SELECT	,
	M_CAL_AutoMan_SELECT	,
	M_CAL_Chuck_Htr_Model	,

	M_CAL_LoopCount			,

	M_CAL_MFC_SET_1			,
	M_CAL_MFC_SET_2			,
	M_CAL_MFC_SET_3			,
	M_CAL_MFC_SET_4			,
	M_CAL_MFC_SET_5			,

	
	M_CAL_MFC_ACT_FLOW_1	,
	M_CAL_MFC_ACT_FLOW_2	,
	M_CAL_MFC_ACT_FLOW_3	,
	M_CAL_MFC_ACT_FLOW_4	,
	M_CAL_MFC_ACT_FLOW_5	,

	M_CAL_MFC_FACTOR_1		,
	M_CAL_MFC_FACTOR_2		,
	M_CAL_MFC_FACTOR_3		,
	M_CAL_MFC_FACTOR_4		,
	M_CAL_MFC_FACTOR_5		,
  
	M_CAL_MFC_FACTOR_AVG	,

	M_CAL_GAS_SELECT_RESULT	,
	M_CAL_GasType_SELECT_RESULT ,
    //... 2016.02.16
	CHUCK_HOME_STAT_A		,
	CHUCK_HOME_STAT_B		,

	Eu1_CurrTemp			,
	Eu2_CurrTemp			,

	AUTO_MFC_VERIFY_CTR				,
	M_CAL_GAS00						,
	M_CAL_GAS01						,
	M_CAL_GAS02						,
	M_CAL_GAS03						,
	M_CAL_GAS04						,
	M_CAL_GAS05						,
	M_CAL_GAS06						,
	M_CAL_GAS07						,
	M_CAL_GAS08						,
	M_CAL_GAS09						,
	M_CAL_GAS10						,
	M_CAL_GAS11						,
	M_CAL_GAS12						,
	M_CAL_GAS13						,
	M_CAL_GAS14						,
	M_CAL_GAS15						,
	M_CAL_GAS16						,
	M_CAL_GAS17						,

	M_CAL_GasType00					,
	M_CAL_GasType01					,
	M_CAL_GasType02					,
	M_CAL_GasType03					,
	M_CAL_GasType04					,
	M_CAL_GasType05					,
	M_CAL_GasType06					,
	M_CAL_GasType07					,
	M_CAL_GasType08					,
	M_CAL_GasType09					,
	M_CAL_GasType10					,
	M_CAL_GasType11					,
	M_CAL_GasType12					,
	M_CAL_GasType13					,
	M_CAL_GasType14					,
	M_CAL_GasType15					,
	M_CAL_GasType16					,
	M_CAL_GasType17					,
	M_CAL_GasType18					,

	M_CAL_MFC00_SET_1				,
	M_CAL_MFC00_SET_2				,
	M_CAL_MFC00_SET_3				,
	M_CAL_MFC00_SET_4				,
	M_CAL_MFC00_SET_5				,
	M_CAL_MFC00_ACT_FLOW_1			,
	M_CAL_MFC00_ACT_FLOW_2			,
	M_CAL_MFC00_ACT_FLOW_3			,
	M_CAL_MFC00_ACT_FLOW_4			,
	M_CAL_MFC00_ACT_FLOW_5			,
	M_CAL_MFC00_FACTOR_1			,
	M_CAL_MFC00_FACTOR_2			,
	M_CAL_MFC00_FACTOR_3			,
	M_CAL_MFC00_FACTOR_4			,
	M_CAL_MFC00_FACTOR_5			,
	M_CAL_MFC00_FACTOR_AVG			,

	M_CAL_MFC01_SET_1				,
	M_CAL_MFC01_SET_2				,
	M_CAL_MFC01_SET_3				,
	M_CAL_MFC01_SET_4				,
	M_CAL_MFC01_SET_5				,
	M_CAL_MFC01_ACT_FLOW_1			,
	M_CAL_MFC01_ACT_FLOW_2			,
	M_CAL_MFC01_ACT_FLOW_3			,
	M_CAL_MFC01_ACT_FLOW_4			,
	M_CAL_MFC01_ACT_FLOW_5			,
	M_CAL_MFC01_FACTOR_1			,
	M_CAL_MFC01_FACTOR_2			,
	M_CAL_MFC01_FACTOR_3			,
	M_CAL_MFC01_FACTOR_4			,
	M_CAL_MFC01_FACTOR_5			,
	M_CAL_MFC01_FACTOR_AVG			,

	M_CAL_MFC02_SET_1				,
	M_CAL_MFC02_SET_2				,
	M_CAL_MFC02_SET_3				,
	M_CAL_MFC02_SET_4				,
	M_CAL_MFC02_SET_5				,
	M_CAL_MFC02_ACT_FLOW_1			,
	M_CAL_MFC02_ACT_FLOW_2			,
	M_CAL_MFC02_ACT_FLOW_3			,
	M_CAL_MFC02_ACT_FLOW_4			,
	M_CAL_MFC02_ACT_FLOW_5			,
	M_CAL_MFC02_FACTOR_1			,
	M_CAL_MFC02_FACTOR_2			,
	M_CAL_MFC02_FACTOR_3			,
	M_CAL_MFC02_FACTOR_4			,
	M_CAL_MFC02_FACTOR_5			,
	M_CAL_MFC02_FACTOR_AVG			,

	M_CAL_MFC03_SET_1				,
	M_CAL_MFC03_SET_2				,
	M_CAL_MFC03_SET_3				,
	M_CAL_MFC03_SET_4				,
	M_CAL_MFC03_SET_5				,
	M_CAL_MFC03_ACT_FLOW_1			,
	M_CAL_MFC03_ACT_FLOW_2			,
	M_CAL_MFC03_ACT_FLOW_3			,
	M_CAL_MFC03_ACT_FLOW_4			,
	M_CAL_MFC03_ACT_FLOW_5			,
	M_CAL_MFC03_FACTOR_1			,
	M_CAL_MFC03_FACTOR_2			,
	M_CAL_MFC03_FACTOR_3			,
	M_CAL_MFC03_FACTOR_4			,
	M_CAL_MFC03_FACTOR_5			,
	M_CAL_MFC03_FACTOR_AVG			,

	M_CAL_MFC04_SET_1				,
	M_CAL_MFC04_SET_2				,
	M_CAL_MFC04_SET_3				,
	M_CAL_MFC04_SET_4				,
	M_CAL_MFC04_SET_5				,
	M_CAL_MFC04_ACT_FLOW_1			,
	M_CAL_MFC04_ACT_FLOW_2			,
	M_CAL_MFC04_ACT_FLOW_3			,
	M_CAL_MFC04_ACT_FLOW_4			,
	M_CAL_MFC04_ACT_FLOW_5			,
	M_CAL_MFC04_FACTOR_1			,
	M_CAL_MFC04_FACTOR_2			,
	M_CAL_MFC04_FACTOR_3			,
	M_CAL_MFC04_FACTOR_4			,
	M_CAL_MFC04_FACTOR_5			,
	M_CAL_MFC04_FACTOR_AVG			,

	M_CAL_MFC05_SET_1				,
	M_CAL_MFC05_SET_2				,
	M_CAL_MFC05_SET_3				,
	M_CAL_MFC05_SET_4				,
	M_CAL_MFC05_SET_5				,
	M_CAL_MFC05_ACT_FLOW_1			,
	M_CAL_MFC05_ACT_FLOW_2			,
	M_CAL_MFC05_ACT_FLOW_3			,
	M_CAL_MFC05_ACT_FLOW_4			,
	M_CAL_MFC05_ACT_FLOW_5			,
	M_CAL_MFC05_FACTOR_1			,
	M_CAL_MFC05_FACTOR_2			,
	M_CAL_MFC05_FACTOR_3			,
	M_CAL_MFC05_FACTOR_4			,
	M_CAL_MFC05_FACTOR_5			,
	M_CAL_MFC05_FACTOR_AVG			,

	M_CAL_MFC06_SET_1				,
	M_CAL_MFC06_SET_2				,
	M_CAL_MFC06_SET_3				,
	M_CAL_MFC06_SET_4				,
	M_CAL_MFC06_SET_5				,
	M_CAL_MFC06_ACT_FLOW_1			,
	M_CAL_MFC06_ACT_FLOW_2			,
	M_CAL_MFC06_ACT_FLOW_3			,
	M_CAL_MFC06_ACT_FLOW_4			,
	M_CAL_MFC06_ACT_FLOW_5			,
	M_CAL_MFC06_FACTOR_1			,
	M_CAL_MFC06_FACTOR_2			,
	M_CAL_MFC06_FACTOR_3			,
	M_CAL_MFC06_FACTOR_4			,
	M_CAL_MFC06_FACTOR_5			,
	M_CAL_MFC06_FACTOR_AVG			,

	M_CAL_MFC07_SET_1				,
	M_CAL_MFC07_SET_2				,
	M_CAL_MFC07_SET_3				,
	M_CAL_MFC07_SET_4				,
	M_CAL_MFC07_SET_5				,
	M_CAL_MFC07_ACT_FLOW_1			,
	M_CAL_MFC07_ACT_FLOW_2			,
	M_CAL_MFC07_ACT_FLOW_3			,
	M_CAL_MFC07_ACT_FLOW_4			,
	M_CAL_MFC07_ACT_FLOW_5			,
	M_CAL_MFC07_FACTOR_1			,
	M_CAL_MFC07_FACTOR_2			,
	M_CAL_MFC07_FACTOR_3			,
	M_CAL_MFC07_FACTOR_4			,
	M_CAL_MFC07_FACTOR_5			,
	M_CAL_MFC07_FACTOR_AVG			,

	M_CAL_MFC08_SET_1				,
	M_CAL_MFC08_SET_2				,
	M_CAL_MFC08_SET_3				,
	M_CAL_MFC08_SET_4				,
	M_CAL_MFC08_SET_5				,
	M_CAL_MFC08_ACT_FLOW_1			,
	M_CAL_MFC08_ACT_FLOW_2			,
	M_CAL_MFC08_ACT_FLOW_3			,
	M_CAL_MFC08_ACT_FLOW_4			,
	M_CAL_MFC08_ACT_FLOW_5			,
	M_CAL_MFC08_FACTOR_1			,
	M_CAL_MFC08_FACTOR_2			,
	M_CAL_MFC08_FACTOR_3			,
	M_CAL_MFC08_FACTOR_4			,
	M_CAL_MFC08_FACTOR_5			,
	M_CAL_MFC08_FACTOR_AVG			,

	M_CAL_MFC09_SET_1				,
	M_CAL_MFC09_SET_2				,
	M_CAL_MFC09_SET_3				,
	M_CAL_MFC09_SET_4				,
	M_CAL_MFC09_SET_5				,
	M_CAL_MFC09_ACT_FLOW_1			,
	M_CAL_MFC09_ACT_FLOW_2			,
	M_CAL_MFC09_ACT_FLOW_3			,
	M_CAL_MFC09_ACT_FLOW_4			,
	M_CAL_MFC09_ACT_FLOW_5			,
	M_CAL_MFC09_FACTOR_1			,
	M_CAL_MFC09_FACTOR_2			,
	M_CAL_MFC09_FACTOR_3			,
	M_CAL_MFC09_FACTOR_4			,
	M_CAL_MFC09_FACTOR_5			,
	M_CAL_MFC09_FACTOR_AVG			,

	M_CAL_MFC10_SET_1				,
	M_CAL_MFC10_SET_2				,
	M_CAL_MFC10_SET_3				,
	M_CAL_MFC10_SET_4				,
	M_CAL_MFC10_SET_5				,
	M_CAL_MFC10_ACT_FLOW_1			,
	M_CAL_MFC10_ACT_FLOW_2			,
	M_CAL_MFC10_ACT_FLOW_3			,
	M_CAL_MFC10_ACT_FLOW_4			,
	M_CAL_MFC10_ACT_FLOW_5			,
	M_CAL_MFC10_FACTOR_1			,
	M_CAL_MFC10_FACTOR_2			,
	M_CAL_MFC10_FACTOR_3			,
	M_CAL_MFC10_FACTOR_4			,
	M_CAL_MFC10_FACTOR_5			,
	M_CAL_MFC10_FACTOR_AVG			,

	M_CAL_MFC11_SET_1				,
	M_CAL_MFC11_SET_2				,
	M_CAL_MFC11_SET_3				,
	M_CAL_MFC11_SET_4				,
	M_CAL_MFC11_SET_5				,
	M_CAL_MFC11_ACT_FLOW_1			,
	M_CAL_MFC11_ACT_FLOW_2			,
	M_CAL_MFC11_ACT_FLOW_3			,
	M_CAL_MFC11_ACT_FLOW_4			,
	M_CAL_MFC11_ACT_FLOW_5			,
	M_CAL_MFC11_FACTOR_1			,
	M_CAL_MFC11_FACTOR_2			,
	M_CAL_MFC11_FACTOR_3			,
	M_CAL_MFC11_FACTOR_4			,
	M_CAL_MFC11_FACTOR_5			,
	M_CAL_MFC11_FACTOR_AVG			,

	M_CAL_MFC12_SET_1				,
	M_CAL_MFC12_SET_2				,
	M_CAL_MFC12_SET_3				,
	M_CAL_MFC12_SET_4				,
	M_CAL_MFC12_SET_5				,
	M_CAL_MFC12_ACT_FLOW_1			,
	M_CAL_MFC12_ACT_FLOW_2			,
	M_CAL_MFC12_ACT_FLOW_3			,
	M_CAL_MFC12_ACT_FLOW_4			,
	M_CAL_MFC12_ACT_FLOW_5			,
	M_CAL_MFC12_FACTOR_1			,
	M_CAL_MFC12_FACTOR_2			,
	M_CAL_MFC12_FACTOR_3			,
	M_CAL_MFC12_FACTOR_4			,
	M_CAL_MFC12_FACTOR_5			,
	M_CAL_MFC12_FACTOR_AVG			,

	M_CAL_MFC13_SET_1				,
	M_CAL_MFC13_SET_2				,
	M_CAL_MFC13_SET_3				,
	M_CAL_MFC13_SET_4				,
	M_CAL_MFC13_SET_5				,
	M_CAL_MFC13_ACT_FLOW_1			,
	M_CAL_MFC13_ACT_FLOW_2			,
	M_CAL_MFC13_ACT_FLOW_3			,
	M_CAL_MFC13_ACT_FLOW_4			,
	M_CAL_MFC13_ACT_FLOW_5			,
	M_CAL_MFC13_FACTOR_1			,
	M_CAL_MFC13_FACTOR_2			,
	M_CAL_MFC13_FACTOR_3			,
	M_CAL_MFC13_FACTOR_4			,
	M_CAL_MFC13_FACTOR_5			,
	M_CAL_MFC13_FACTOR_AVG			,

	M_CAL_MFC14_SET_1				,
	M_CAL_MFC14_SET_2				,
	M_CAL_MFC14_SET_3				,
	M_CAL_MFC14_SET_4				,
	M_CAL_MFC14_SET_5				,
	M_CAL_MFC14_ACT_FLOW_1			,
	M_CAL_MFC14_ACT_FLOW_2			,
	M_CAL_MFC14_ACT_FLOW_3			,
	M_CAL_MFC14_ACT_FLOW_4			,
	M_CAL_MFC14_ACT_FLOW_5			,
	M_CAL_MFC14_FACTOR_1			,
	M_CAL_MFC14_FACTOR_2			,
	M_CAL_MFC14_FACTOR_3			,
	M_CAL_MFC14_FACTOR_4			,
	M_CAL_MFC14_FACTOR_5			,
	M_CAL_MFC14_FACTOR_AVG			,

	M_CAL_MFC15_SET_1				,
	M_CAL_MFC15_SET_2				,
	M_CAL_MFC15_SET_3				,
	M_CAL_MFC15_SET_4				,
	M_CAL_MFC15_SET_5				,
	M_CAL_MFC15_ACT_FLOW_1			,
	M_CAL_MFC15_ACT_FLOW_2			,
	M_CAL_MFC15_ACT_FLOW_3			,
	M_CAL_MFC15_ACT_FLOW_4			,
	M_CAL_MFC15_ACT_FLOW_5			,
	M_CAL_MFC15_FACTOR_1			,
	M_CAL_MFC15_FACTOR_2			,
	M_CAL_MFC15_FACTOR_3			,
	M_CAL_MFC15_FACTOR_4			,
	M_CAL_MFC15_FACTOR_5			,
	M_CAL_MFC15_FACTOR_AVG			,

	M_CAL_MFC16_SET_1				,
	M_CAL_MFC16_SET_2				,
	M_CAL_MFC16_SET_3				,
	M_CAL_MFC16_SET_4				,
	M_CAL_MFC16_SET_5				,
	M_CAL_MFC16_ACT_FLOW_1			,
	M_CAL_MFC16_ACT_FLOW_2			,
	M_CAL_MFC16_ACT_FLOW_3			,
	M_CAL_MFC16_ACT_FLOW_4			,
	M_CAL_MFC16_ACT_FLOW_5			,
	M_CAL_MFC16_FACTOR_1			,
	M_CAL_MFC16_FACTOR_2			,
	M_CAL_MFC16_FACTOR_3			,
	M_CAL_MFC16_FACTOR_4			,
	M_CAL_MFC16_FACTOR_5			,
	M_CAL_MFC16_FACTOR_AVG			,

	M_CAL_MFC17_SET_1				,
	M_CAL_MFC17_SET_2				,
	M_CAL_MFC17_SET_3				,
	M_CAL_MFC17_SET_4				,
	M_CAL_MFC17_SET_5				,
	M_CAL_MFC17_ACT_FLOW_1			,
	M_CAL_MFC17_ACT_FLOW_2			,
	M_CAL_MFC17_ACT_FLOW_3			,
	M_CAL_MFC17_ACT_FLOW_4			,
	M_CAL_MFC17_ACT_FLOW_5			,
	M_CAL_MFC17_FACTOR_1			,
	M_CAL_MFC17_FACTOR_2			,
	M_CAL_MFC17_FACTOR_3			,
	M_CAL_MFC17_FACTOR_4			,
	M_CAL_MFC17_FACTOR_5			,
	M_CAL_MFC17_FACTOR_AVG			,

	MFC01_Name,
	MFC02_Name,
	MFC03_Name,
	MFC04_Name,
	MFC05_Name,
	MFC06_Name,
	MFC07_Name,
	MFC08_Name,
	MFC09_Name,
	MFC10_Name,
	MFC11_Name,
	MFC12_Name,
	MFC13_Name,
	MFC14_Name,
	MFC15_Name,
	MFC16_Name,
	MFC17_Name,
	MFC18_Name,

	M_CAL_GAS_Name		,

	//... 2016.02.16 Abort Gas, Vacuum Control Function Added
	ABORT_GAS			,
	VACUUM_CONTROL		,

	//... 2016.02.16 Manual MFC Set
	Manual_MFC1_SET		,
	Manual_MFC2_SET		,
	Manual_MFC3_SET		,
	Manual_MFC4_SET		,
	Manual_MFC5_SET		,
	Manual_MFC6_SET		,
	Manual_MFC7_SET		,
	Manual_MFC8_SET		,
	Manual_MFC9_SET		,
	Manual_MFC10_SET	,
	Manual_MFC11_SET	,
	Manual_MFC12_SET	,
	Manual_MFC13_SET	,
	Manual_MFC14_SET	,
	Manual_MFC15_SET	,
	Manual_MFC16_SET	,
	Manual_MFC17_SET	,
	Manual_MFC18_SET	,
	//2014.11.26
	HIGH_MFC_CAL,
	M_CAL_CHAMBER_TEMP_Ret,
	//2015.04.08
 	PLCInkUnlockStsDO	,   
 	PLCInkUnlockStsDI   ,
	PLCIntLockDO		,
	M_CAL_LeakChkDM		,
} IOPointIndex;
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------
#endif
