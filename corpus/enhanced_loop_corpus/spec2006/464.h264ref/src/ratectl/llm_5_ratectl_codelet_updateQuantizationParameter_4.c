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
int threshold = TotalNumberofBasicUnit - NumberofBasicUnit;
for (i = TotalNumberofBasicUnit - 1; i >= threshold; i--) {
    double temp = BUPFMAD[i];
    CurrentBUMAD = MADPictureC1 * temp + MADPictureC2;
    if (CurrentBUMAD > 0.0) {
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
}
