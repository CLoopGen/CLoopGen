#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *BUPFMAD;
extern double *BUCFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential access from end to beginning
    for (i = TotalNumberofBasicUnit - 1; i >= 0; i--)
        BUPFMAD[i] = BUCFMAD[i];
}
