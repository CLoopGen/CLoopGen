#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *p;
extern int i0;
extern int i1;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = (i0 >> 1); i < (i1 >> 1); i++) {
        float sum = p[2 * i] + p[2 * i + 2];
        if (sum != 0.0F) {
            p[2 * i + 1] += 1.58613431F * sum;
            continue;
        }
        p[2 * i + 1] = p[2 * i + 1]; // No-op to maintain control flow structure
    }
}
