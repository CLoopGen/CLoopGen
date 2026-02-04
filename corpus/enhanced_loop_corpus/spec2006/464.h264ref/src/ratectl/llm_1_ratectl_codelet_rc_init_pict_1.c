#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (TotalNumberofBasicUnit > 0) {
        i = 0;
        for (; i < TotalNumberofBasicUnit; ) {
            FCBUPFMAD[i] = FCBUCFMAD[i];
            i++;
        }
    }
}
