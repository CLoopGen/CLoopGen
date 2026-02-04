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
    // Variant 1: Strided Memory Access (access every 2nd element first, then handle remainder)
    int stride = 2;
    // First pass: strided access with step size 2
    for (i = 0; i < n_windowSize; i += stride) {
        if (PictureRejected[i])
            n_realSize--;
    }
    // Second pass: handle odd indices if stride leaves them out
    for (i = 1; i < n_windowSize; i += stride) {
        if (PictureRejected[i])
            n_realSize--;
    }
}
