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
    int outer_i;
    int inner_i;
    int range = (TotalNumberofBasicUnit - (TotalNumberofBasicUnit - NumberofBasicUnit));
    for (outer_i = 0; outer_i < range; outer_i++) {
        inner_i = (TotalNumberofBasicUnit - 1) - outer_i;
        CurrentBUMAD = MADPictureC1 * BUPFMAD[inner_i] + MADPictureC2;
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
