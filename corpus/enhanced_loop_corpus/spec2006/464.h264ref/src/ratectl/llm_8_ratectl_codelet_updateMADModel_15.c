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
    for (i = 0; i < (int)n_windowSize; i += 2) {
        if (i + 1 < (int)n_windowSize) {
            error[i] = MADPictureC1 * ReferenceMAD[i] + MADPictureC2 - PictureMAD[i];
            error[i+1] = MADPictureC1 * ReferenceMAD[i+1] + MADPictureC2 - PictureMAD[i+1];
            std += error[i] * error[i] + error[i+1] * error[i+1];
        } else {
            error[i] = MADPictureC1 * ReferenceMAD[i] + MADPictureC2 - PictureMAD[i];
            std += error[i] * error[i];
        }
    }
}
