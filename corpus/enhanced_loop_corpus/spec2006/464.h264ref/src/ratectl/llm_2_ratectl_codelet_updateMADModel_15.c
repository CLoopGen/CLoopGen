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
    // Variant 1: Strided memory access with stride of 2, processing even indices only
    int n = (int)n_windowSize;
    for (i = 0; i < n; i += 2) {
        int idx = i; // Stride of 2: access every second element
        error[idx] = MADPictureC1 * ReferenceMAD[idx] + MADPictureC2 - PictureMAD[idx];
        std += error[idx] * error[idx];
    }
    // Handle odd-sized window if needed by ensuring all elements are processed in original logic
    // Note: This variant processes only even indices; behavior changes intentionally for mutation.
}
