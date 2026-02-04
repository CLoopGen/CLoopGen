#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = TotalNumberofBasicUnit - 1; i >= 0; i--)
        FCBUPFMAD[i] = FCBUCFMAD[i];
}
