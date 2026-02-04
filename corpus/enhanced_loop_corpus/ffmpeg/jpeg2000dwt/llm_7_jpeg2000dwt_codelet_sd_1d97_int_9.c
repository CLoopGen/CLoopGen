#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int prev_val = 0, current_val;
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        current_val = p[2 * i];
        p[2 * i] -= (3472LL * (prev_val + p[2 * i + 1]) + (1 << 15)) >> 16;
        prev_val = current_val;
    }
}
