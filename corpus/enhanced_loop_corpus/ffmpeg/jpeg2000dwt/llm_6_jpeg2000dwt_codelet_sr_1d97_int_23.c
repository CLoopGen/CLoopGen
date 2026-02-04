#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t temp_load1, temp_load2, temp_load3;
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        temp_load1 = p[2 * i];
        temp_load2 = p[2 * i + 2];
        temp_load3 = temp_load1 + temp_load2;
        p[2 * i + 1] += (int32_t)((103949LL * (int64_t)temp_load3 + (1 << 15)) >> 16);
    }
}
