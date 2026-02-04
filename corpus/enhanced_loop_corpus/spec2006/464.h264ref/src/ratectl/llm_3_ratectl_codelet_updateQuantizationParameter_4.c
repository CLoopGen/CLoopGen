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
    // Variant 2: Consecutive forward traversal using reversed effective range
    // Map loop index to access same elements consecutively from lower to higher address
    int start_idx = TotalNumberofBasicUnit - NumberofBasicUnit;
    int end_idx = TotalNumberofBasicUnit - 1;
    for (i = start_idx; i <= end_idx; i++) {
        CurrentBUMAD = MADPictureC1 * BUPFMAD[i] + MADPictureC2;
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
