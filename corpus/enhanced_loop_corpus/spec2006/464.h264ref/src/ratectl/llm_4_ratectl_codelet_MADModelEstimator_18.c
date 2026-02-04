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
for (i = 0; i < n_windowSize; i++) {
    if (PictureRejected[i])
        continue;
    if (PictureMAD[i] != oneSampleQ)
        estimateX2 = TRUE;
    MADPictureC1 += PictureMAD[i] / (ReferenceMAD[i] * n_realSize);
}
}
