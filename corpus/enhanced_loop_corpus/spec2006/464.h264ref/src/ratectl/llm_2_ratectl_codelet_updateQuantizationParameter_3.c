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
    // Variant 1: Consecutive Memory Access (reverse traversal with offset adjustment)
    int start = TotalNumberofBasicUnit - NumberofBasicUnit;
    int end = TotalNumberofBasicUnit - 1;
    for (i = 0; i <= (end - start); i++) {
        int idx = end - i;  // Reverse indexing to maintain original access order
        CurrentBUMAD = MADPictureC1 * FCBUPFMAD[idx] + MADPictureC2;
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
