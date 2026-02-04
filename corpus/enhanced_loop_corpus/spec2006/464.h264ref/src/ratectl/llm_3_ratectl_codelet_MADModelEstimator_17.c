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
    // Variant 2: Reverse Consecutive Memory Access Pattern
    int i;
    for (i = n_windowSize - 1; i >= 0; i--) {
        if (!PictureRejected[i])
            oneSampleQ = PictureMAD[i];
    }
}
