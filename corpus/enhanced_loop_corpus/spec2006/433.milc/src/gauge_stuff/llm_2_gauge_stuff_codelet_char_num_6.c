#include <stdio.h>

#include <inttypes.h>

extern int *chr;
extern int length;
extern int j;
extern int bdig[6];
extern int tenl;
extern int newv;
extern int old;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access on bdig array with stride of 2 (reverse traversal)
    // This modifies the access pattern to be non-consecutive, accessing every second element
    for (j = ((length - 1) | 1); j >= 1; j -= 2) {
        newv = old - tenl * bdig[j];
        newv = newv * 10 + bdig[j];
        if (newv < *chr)
            *chr = newv;
        old = newv;

        // Handle adjacent index if within bounds
        int prev_j = j - 1;
        if (prev_j >= 1) {
            newv = old - tenl * bdig[prev_j];
            newv = newv * 10 + bdig[prev_j];
            if (newv < *chr)
                *chr = newv;
            old = newv;
        }
    }
}
