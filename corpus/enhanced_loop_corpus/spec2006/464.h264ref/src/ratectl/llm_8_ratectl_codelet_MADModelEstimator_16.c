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
    int j;
    for (j = 0; j < n_windowSize * 2; j += 2) {
        int idx = j / 2;
        if (idx < n_windowSize && PictureRejected[idx])
            n_realSize--;
    }
}
