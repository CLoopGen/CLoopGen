#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (k = 0; k < 64; k++) {
    satd += byte_abs[diff[k % 16]] + byte_abs[diff[(k + 3) % 16]];
    satd -= (k % 7 == 0) ? byte_abs[diff[k % 16]] : 0;
}
}
