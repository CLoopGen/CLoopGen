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
    // Variant 1: Strided memory access (stride of 2, stepping backwards by 2)
    int stride = 2;
    int start = TotalNumberofBasicUnit - 1;
    int end = (TotalNumberofBasicUnit - NumberofBasicUnit);
    for (i = start; i >= end; i -= stride) {
        if (i >= 0) {  // Safety check for valid index
            CurrentBUMAD = MADPictureC1 * BUPFMAD[i] + MADPictureC2;
            TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
        }
    }
}
