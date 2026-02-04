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
    int step = 2;
    int limit = n_windowSize + (n_windowSize % 2);
    for (i = 0; i < limit; i += step) {
        int idx = i < n_windowSize ? i : i - 1;
        if (!PictureRejected[idx])
            oneSampleQ = (PictureMAD[idx] + oneSampleQ) * 0.5;
    }
}
