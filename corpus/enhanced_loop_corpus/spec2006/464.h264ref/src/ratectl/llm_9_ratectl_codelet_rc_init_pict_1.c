#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *FCBUCFMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double a = 1.5, b = 0.8, c;
    for (i = 0; i < TotalNumberofBasicUnit * 2; i++) {
        c = a * FCBUCFMAD[i % TotalNumberofBasicUnit] + b;
        FCBUPFMAD[i % TotalNumberofBasicUnit] = c;
    }
}
