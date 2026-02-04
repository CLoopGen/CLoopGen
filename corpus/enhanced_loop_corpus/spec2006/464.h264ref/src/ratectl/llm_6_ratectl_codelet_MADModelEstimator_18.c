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
    double tempSum = 0.0;
    Boolean localEstimateX2 = FALSE;
    for (i = 0; i < n_windowSize; i++) {
        if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i])
            localEstimateX2 = TRUE;
        if (!PictureRejected[i])
            tempSum += PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
    }
    estimateX2 = localEstimateX2;
    MADPictureC1 += tempSum;
}
