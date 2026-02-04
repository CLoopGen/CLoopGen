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
    // Variant 1: Increased computational intensity with additional arithmetic operations and unrolled-like behavior (2 operations per iteration)
    double temp1, temp2;
    for (i = TotalNumberofBasicUnit - 1; i >= (TotalNumberofBasicUnit - NumberofBasicUnit); i -= 2) {
        // First element
        CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
        temp1 = CurrentBUMAD * CurrentBUMAD;
        TotalBUMAD += temp1;

        // Second element (if within bounds)
        if (i - 1 >= (TotalNumberofBasicUnit - NumberofBasicUnit)) {
            CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i-1] + MADPictureC2;
            temp2 = CurrentBUMAD * CurrentBUMAD;
            TotalBUMAD += temp2;
        }
    }
}
