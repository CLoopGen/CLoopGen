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
    int prev_val = 0;
    for (i = ((i0 + 1) >> 1) - 1; i < (i1 + 1) >> 1; i++) {
        int current_load = p[2 * i + 1];
        p[2 * i + 1] = current_load - ((prev_val + p[2 * i + 2]) >> 1);
        prev_val = p[2 * i];
    }
}
