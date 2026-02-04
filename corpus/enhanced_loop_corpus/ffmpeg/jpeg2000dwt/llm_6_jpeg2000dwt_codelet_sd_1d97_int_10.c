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
    int temp_load1, temp_load2;
    for (i = (i0 >> 1) - 1; i < (i1 >> 1); i++) {
        temp_load1 = p[2 * i];
        temp_load2 = p[2 * i + 2];
        p[2 * i + 1] += (57862LL * (temp_load1 + temp_load2) + (1 << 15)) >> 16;
    }
}
