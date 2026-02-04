#include <stdio.h>

#include <inttypes.h>

typedef enum {
    FALSE,
    TRUE
} Boolean;

extern Boolean PictureRejected[21];
extern int n_windowSize;
extern int n_realSize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 1;
    for (i = 0; i < n_windowSize; i += step) {
        if (PictureRejected[i] == TRUE) {
            n_realSize -= 1;
        }
        if (n_realSize < 0) break;
    }
}
