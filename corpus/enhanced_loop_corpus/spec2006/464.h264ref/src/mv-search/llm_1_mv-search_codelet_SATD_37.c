#include <stdio.h>

#include <inttypes.h>

extern int *byte_abs;
extern int *diff;
extern int k;
extern int satd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (k = 0; k < 4; k++) {
        for (int j = 0; j < 4; j++) {
            satd += byte_abs[diff[k * 4 + j]];
        }
    }
}
