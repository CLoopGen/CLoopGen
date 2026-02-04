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
    if (n_windowSize > 0) {
        i = 0;
        for (; i < n_windowSize; ) {
            if (!PictureRejected[i])
                oneSampleQ = PictureMAD[i];
            i++;
        }
    }
}
