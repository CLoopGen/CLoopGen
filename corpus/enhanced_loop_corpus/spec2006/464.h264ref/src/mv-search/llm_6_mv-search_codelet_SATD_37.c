#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_satd = 0;
    for (k = 0; k < 16; k++) {
        temp_satd += byte_abs[diff[k]];
    }
    satd = temp_satd;
}
