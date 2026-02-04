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
    // Variant 2: Reduced trip count and simplified computation by removing squaring operation, replacing with absolute accumulation
    int step = 2; // Process every second element to reduce trip count
    for (i = TotalNumberofBasicUnit - 1; i >= (TotalNumberofBasicUnit - NumberofBasicUnit); i -= step) {
        CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
        TotalBUMAD += (CurrentBUMAD > 0.0) ? CurrentBUMAD : -CurrentBUMAD; // Absolute value instead of square
    }
}
