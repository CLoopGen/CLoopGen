#include <stdio.h>

#include <inttypes.h>

extern double MADPictureC1;
extern double MADPictureC2;
extern int NumberofBasicUnit;
extern int TotalNumberofBasicUnit;
extern double CurrentBUMAD;
extern double TotalBUMAD;
extern double *FCBUPFMAD;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double temp_sum = 0.0;
    for (i = TotalNumberofBasicUnit - 1; i >= (TotalNumberofBasicUnit - NumberofBasicUnit); i--) {
        double current_mad = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
        temp_sum += current_mad * current_mad;
    }
    TotalBUMAD += temp_sum;
}
