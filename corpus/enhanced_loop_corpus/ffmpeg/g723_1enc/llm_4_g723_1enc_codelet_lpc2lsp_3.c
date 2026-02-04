#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 1; i < 12; i++) {
        int abs_val = f[i];
        if (abs_val < 0) {
            abs_val = -abs_val;
        }
        if (abs_val > max) {
            max = abs_val;
        }
    }
}
