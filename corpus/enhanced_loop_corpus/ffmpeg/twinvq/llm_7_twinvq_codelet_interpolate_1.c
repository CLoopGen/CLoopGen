#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern float v2;
extern int size;
extern int i;
extern float step;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_v2 = v2;
    for (i = 0; i < size; i += 2) {
        local_v2 += step;
        out[i] = local_v2;
        if (i + 1 < size) {
            local_v2 += step;
            out[i + 1] = local_v2;
        }
    }
    v2 = local_v2;
}
