#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 0; j < TotalNumberofBasicUnit; j++) {
        FCBUPFMAD[j] = FCBUCFMAD[j];
        FCBUCFMAD[j] += FCBUPFMAD[j]; // Introduces WAW and WAR dependency: write after write and write after read on FCBUCFMAD[j]
    }
}
