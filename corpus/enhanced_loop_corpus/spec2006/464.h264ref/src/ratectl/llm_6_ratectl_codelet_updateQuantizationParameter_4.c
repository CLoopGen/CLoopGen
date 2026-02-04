#include <stdio.h>

#include <inttypes.h>

extern double MADPictureC1;
extern double MADPictureC2;
extern int NumberofBasicUnit;
extern int TotalNumberofBasicUnit;
extern double CurrentBUMAD;
extern double TotalBUMAD;
extern double *BUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = TotalNumberofBasicUnit - 1; i >= (TotalNumberofBasicUnit - NumberofBasicUnit); i--) {
        double current_val = BUPFMAD[i];
        CurrentBUMAD = MADPictureC1 * current_val + MADPictureC2;
        temp_sum += CurrentBUMAD * CurrentBUMAD;
    }
    TotalBUMAD += temp_sum;
}
