#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern double MADPictureC1;
extern Boolean PictureRejected[21];
extern double PictureMAD[21];
extern double ReferenceMAD[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;
extern double oneSampleQ;
extern Boolean estimateX2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double accumulation[21] = {0};
    for (i = 0; i < n_windowSize; i++) {
        accumulation[i] = 0.0;
        if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i]) {
            estimateX2 = TRUE;
        }
        if (!PictureRejected[i]) {
            accumulation[i] = PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
        }
    }
    for (i = 0; i < n_windowSize; i++) {
        MADPictureC1 += accumulation[i];
    }
}
