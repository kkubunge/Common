#ifndef _CONSTANT_H_
#define _CONSTANT_H_


#define MAX_ITEM_COUNT	10000
#define MAX_MODULE_COUNT	10
#define MAX_ARM_COUNT	4

struct AWC_DATA
{
	int    nArmType;
	double dbMissX1;
	double dbMissY1;
	double dbMissX2;
	double dbMissY2;
	double dbCorrectR;
	double dbCorrectT;
};

struct MODULE_AWC_DATA
{
	unsigned int nCount;
	AWC_DATA     stPlaceData[MAX_ITEM_COUNT];
};

typedef struct
{
	int nYear;
	int nMonth;
	int nDay;
} _DATE_INFO;

enum {
	BM1 = 0,
	BM2	,
	PM1	,
	PM2	,
	PM3	,
	PM4	,
	PM5	,
	ALL_MODULE
};

enum {
	MISS1 = 0,
	MISS2,
	CORRECT,
	ALL_DATA
};

enum {
	A1_ARM = 0,
	A2_ARM ,
	B1_ARM ,
	B2_ARM ,
	ALL_ARM
};



#endif