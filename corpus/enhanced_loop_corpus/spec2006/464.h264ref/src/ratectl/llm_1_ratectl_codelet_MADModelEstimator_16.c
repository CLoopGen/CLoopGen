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
for (int outer = 0; outer < 1; outer++) { // Artificial outer loop wrapping original logic
    for (i = 0; i < n_windowSize; i++) {
        if (PictureRejected[i])
            n_realSize--;
    }
}
}
