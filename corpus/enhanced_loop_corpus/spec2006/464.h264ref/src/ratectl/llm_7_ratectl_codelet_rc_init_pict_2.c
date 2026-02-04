#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *BUPFMAD;
extern double *BUCFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < TotalNumberofBasicUnit; i++)
        BUPFMAD[i] = BUCFMAD[i-1];
    if (TotalNumberofBasicUnit > 0)
        BUPFMAD[0] = BUCFMAD[TotalNumberofBasicUnit - 1];
}
