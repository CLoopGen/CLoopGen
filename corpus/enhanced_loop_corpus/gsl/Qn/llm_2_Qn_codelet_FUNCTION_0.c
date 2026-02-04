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
    // Variant 1: Strided memory access with stride of 2
    // Arrays are accessed in a strided pattern: i += 2, processing even indices first
    for (i = 0; i < ni; i += 2) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
    // Handle odd indices if ni is odd
    for (i = 1; i < ni; i += 2) {
        left[i] = ni - i + 1;
        right[i] = (i <= h) ? ni : ni - (i - h);
    }
}
