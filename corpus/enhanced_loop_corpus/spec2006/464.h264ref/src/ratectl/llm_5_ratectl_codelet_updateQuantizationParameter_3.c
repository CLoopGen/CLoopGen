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
int lower_bound = TotalNumberofBasicUnit - NumberofBasicUnit;
for (i = TotalNumberofBasicUnit - 1; i >= lower_bound; i--) {
    CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
    double sq = CurrentBUMAD * CurrentBUMAD;
    if (sq > 1e-9) {
        TotalBUMAD += sq;
    }
}
}
