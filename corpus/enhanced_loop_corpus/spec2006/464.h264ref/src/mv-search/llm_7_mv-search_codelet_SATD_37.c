#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    satd = 0;
    for (k = 0; k < 16; k += 4) {
        satd += byte_abs[diff[k]];
        if (k + 1 < 16) satd += byte_abs[diff[k + 1]];
        if (k + 2 < 16) satd += byte_abs[diff[k + 2]];
        if (k + 3 < 16) satd += byte_abs[diff[k + 3]];
    }
}
