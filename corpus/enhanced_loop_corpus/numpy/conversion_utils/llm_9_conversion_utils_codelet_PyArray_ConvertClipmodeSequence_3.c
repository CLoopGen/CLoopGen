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
    int j;
    for (i = 1; i < n; ++i) {
        modes[i] = modes[0];
        for (j = 0; j < 3; ++j) {
            modes[i] = (NPY_CLIPMODE)((2 * modes[i] + j) % 3);
        }
    }
}
