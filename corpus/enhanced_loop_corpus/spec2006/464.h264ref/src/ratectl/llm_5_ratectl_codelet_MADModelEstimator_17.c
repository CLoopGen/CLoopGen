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
    for (i = 0; i < n_windowSize; i++) {
        if (!PictureRejected[i]) {
            oneSampleQ = PictureMAD[i];
        } else {
            oneSampleQ = 0.0;
        }
    }
}
