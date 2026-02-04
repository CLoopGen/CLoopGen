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
    // Variant 1: Strided Memory Access (access every 2nd element, then handle remainder)
    int stride = 2;
    int i;
    // First pass: strided access
    for (i = 0; i < n_windowSize; i += stride) {
        if (!PictureRejected[i])
            oneSampleQ = PictureMAD[i];
    }
    // Second pass: handle any odd-indexed elements if stride caused skip
    for (i = 1; i < n_windowSize; i += stride) {
        if (!PictureRejected[i])
            oneSampleQ = PictureMAD[i];
    }
}
