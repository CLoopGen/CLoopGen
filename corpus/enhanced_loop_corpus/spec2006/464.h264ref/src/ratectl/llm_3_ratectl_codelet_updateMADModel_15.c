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
    // Variant 2: Reverse-order memory access (backward traversal)
    int n = (int)n_windowSize;
    for (i = n - 1; i >= 0; i--) {
        error[i] = MADPictureC1 * ReferenceMAD[i] + MADPictureC2 - PictureMAD[i];
        std += error[i] * error[i];
    }
}
