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
    int prev_update = 0;
    for (i = (i0 >> 1) - 2; i < (i1 >> 1) + 1; i++) {
        long long temp_val = (103949LL * (p[2 * i] + p[2 * i + 2]) + (1 << 15)) >> 16;
        int current_val = p[2 * i + 1] - temp_val - prev_update;
        p[2 * i + 1] = current_val;
        prev_update = temp_val;
    }
}
