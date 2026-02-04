#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < TotalNumberofBasicUnit; i += 2) {
        FCBUPFMAD[i] = FCBUCFMAD[i];
        if (i + 1 < TotalNumberofBasicUnit) {
            FCBUPFMAD[i + 1] = FCBUCFMAD[i + 1];
        }
    }
}
