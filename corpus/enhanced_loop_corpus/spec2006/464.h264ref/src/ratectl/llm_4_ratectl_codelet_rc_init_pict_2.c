#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *BUPFMAD;
extern double *BUCFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < TotalNumberofBasicUnit; i++) {
        if (i % 2 == 0) {
            BUPFMAD[i] = BUCFMAD[i];
        }
    }
}
