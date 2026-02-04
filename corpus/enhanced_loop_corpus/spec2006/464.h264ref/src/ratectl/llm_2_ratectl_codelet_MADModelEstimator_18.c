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
    // Variant 1: Strided memory access with step size of 2
    for (i = 0; i < n_windowSize; i += 2) {
        if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i])
            estimateX2 = TRUE;
        if (!PictureRejected[i])
            MADPictureC1 += PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
    }
    // Handle odd-sized window by processing last element if needed
    if (n_windowSize % 2 == 1 && n_windowSize > 0) {
        i = n_windowSize - 1;
        if ((PictureMAD[i] != oneSampleQ) && !PictureRejected[i])
            estimateX2 = TRUE;
        if (!PictureRejected[i])
            MADPictureC1 += PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
    }
}
