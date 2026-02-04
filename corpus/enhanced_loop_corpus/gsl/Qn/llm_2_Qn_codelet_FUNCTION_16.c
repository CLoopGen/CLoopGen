#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int ni;
extern int *left;
extern int *right;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (unrolled-like pattern)
    // Arrays are accessed in a strided manner: i += 2, processing two indices per iteration
    int stride = 2;
    for (i = 0; i < ni; i += stride) {
        int j = i;
        left[j] = ni - j + 1;
        right[j] = (j <= h) ? ni : ni - (j - h);
        if (i + 1 < ni) {
            j = i + 1;
            left[j] = ni - j + 1;
            right[j] = (j <= h) ? ni : ni - (j - h);
        }
    }
}
