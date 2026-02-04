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
    int j, i;
    for (j = 0; j < 1; j++) {
        for (i = TotalNumberofBasicUnit - 1; i >= (TotalNumberofBasicUnit - NumberofBasicUnit); i--) {
            CurrentBUMAD = MADPictureC1 * FCBUPFMAD[i] + MADPictureC2;
            TotalBUMAD += CurrentBUMAD * CurrentBUMAD;
        }
    }
}
