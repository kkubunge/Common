#ifndef LOTTYPE_H
#define LOTTYPE_H

typedef struct {
	char	LOT_ID[255+1];
	char	CLUSTER_RECIPE[MAX_LOTDATA_ITEM_COUNT][MAX_STRING_SIZE+1];
	char	CLUSTER_RECIPE2[MAX_LOTDATA_ITEM_COUNT][MAX_STRING_SIZE+1];
	int		CLUSTER_USING[MAX_LOTDATA_ITEM_COUNT];
	int		CLUSTER_DUMMY_USING;
	char	CLUSTER_DUMMY_RECIPE[MAX_STRING_SIZE+1];
	int		SPECIAL_INSIDE_DATA; // 2004.11.16
} LOTStepTemplate;

#endif
