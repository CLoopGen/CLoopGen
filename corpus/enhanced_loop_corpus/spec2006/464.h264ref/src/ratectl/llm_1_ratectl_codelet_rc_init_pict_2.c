#include <stdio.h>

#include <inttypes.h>

extern int TotalNumberofBasicUnit;
extern double *BUPFMAD;
extern double *BUCFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (TotalNumberofBasicUnit > 0)
        for (i = 0; i < TotalNumberofBasicUnit; i += 2) {
            BUPFMAD[i] = BUCFMAD[i];
            if (i + 1 < TotalNumberofBasicUnit)
                BUPFMAD[i + 1] = BUCFMAD[i + 1];
        }
}
