#include <stdio.h>

#include <inttypes.h>

extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_accum[16];
    for (i = 0; i < 16; i++) {
        local_accum[i] = i + 1;
        if (i > 0) {
            local_accum[i] += local_accum[i - 1];
        }
    }
    i = local_accum[15];
}
