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
    double localMAD = 0.0;
    Boolean localEstimate = FALSE;
    int step = (n_windowSize > 10) ? 3 : 1;
    for (i = 0; i < n_windowSize; i += step) {
        if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i]) {
            localEstimate = TRUE;
        }
        if (!PictureRejected[i]) {
            double ratio = PictureMAD[i] / ReferenceMAD[i];
            localMAD += ratio * (1.0 / n_realSize);
        }
    }
    MADPictureC1 += localMAD;
    if (localEstimate)
        estimateX2 = TRUE;
}
