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
    // Variant 2: Strided Memory Access (access every second element in reverse, doubling over iterations)
    int step = 2;
    int count = TotalNumberofBasicUnit - 1;
    int limit = TotalNumberofBasicUnit - NumberofBasicUnit;

    // Adjust starting point if the number of elements is odd
    if ((TotalNumberofBasicUnit - limit) % 2 == 0) {
        count--;  // Ensure we stay within bounds when stepping
    }

    for (; count >= limit; count -= step) {
        CurrentBUMAD = MADPictureC1 * FCBUPFMAD[count] + MADPictureC2;
        TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
    }
}
