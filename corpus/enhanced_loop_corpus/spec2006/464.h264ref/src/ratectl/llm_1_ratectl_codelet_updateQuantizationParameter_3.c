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
    int outer_i;
    int stride = 1;
    for (outer_i = TotalNumberofBasicUnit - 1; outer_i >= (TotalNumberofBasicUnit - NumberofBasicUnit); outer_i -= stride) {
        i = outer_i;
        CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
