#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern double PictureMAD[21];
extern int n_windowSize;
extern int i;
extern double oneSampleQ;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double tempSum = 0.0;
    for (i = 0; i < n_windowSize; i++) {
        if (!PictureRejected[i])
            tempSum += PictureMAD[i];
    }
    oneSampleQ = tempSum;
}
