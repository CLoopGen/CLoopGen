#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (i = 0; i < TotalNumberofBasicUnit; i++)
    FCBUPFMAD[i] = FCBUCFMAD[i];

}
