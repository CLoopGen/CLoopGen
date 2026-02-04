#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef enum {
    NPY_CLIP = 0,
    NPY_WRAP = 1,
    NPY_RAISE = 2
} NPY_CLIPMODE;

extern NPY_CLIPMODE *modes;
extern int n;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access (traverse from end to start)
    for (i = n - 1; i >= 1; --i) {
        modes[i] = modes[0];
    }
}
