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
double temp_mad1, temp_mad2;
int start = TotalNumberofBasicUnit - NumberofBasicUnit;
int end = TotalNumberofBasicUnit - 1;
for (i = start; i <= end; i++) {
    temp_mad1 = MADPictureC1 * BUPFMAD[i];
    temp_mad2 = temp_mad1 + MADPictureC2;
    TotalBUMAD += temp_mad2 * temp_mad2;
}
}
