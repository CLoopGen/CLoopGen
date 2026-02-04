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
    double temp_error;
    for (i = 0; i < (int)n_windowSize; i++) {
        temp_error = MADPictureC1 * ReferenceMAD[i] + MADPictureC2 - PictureMAD[i];
        error[i] = temp_error;
        std += temp_error * temp_error;
    }
}
