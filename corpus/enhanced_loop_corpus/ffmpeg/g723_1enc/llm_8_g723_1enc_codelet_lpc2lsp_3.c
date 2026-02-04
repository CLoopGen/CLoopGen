#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int f[12];
extern int max;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 12; i += 2) {
        int val = f[i];
        int abs_val = (val >= 0) ? val : -val;
        if (abs_val > max) {
            max = abs_val;
        }
    }
}
