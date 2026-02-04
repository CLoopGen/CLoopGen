#include <stdio.h>

#include <inttypes.h>

extern double MADPictureC1;
extern double MADPictureC2;
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int n_windowSize;
extern int i;
extern double error[20];
extern double std;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int outer = 0; outer < (int)n_windowSize; outer++) {
        error[outer] = MADPictureC1 * ReferenceMAD[outer] + MADPictureC2 - PictureMAD[outer];
        std += error[outer] * error[outer];
        
        for (int inner = 0; inner < 1; inner++) {
            continue;
        }
    }
}
