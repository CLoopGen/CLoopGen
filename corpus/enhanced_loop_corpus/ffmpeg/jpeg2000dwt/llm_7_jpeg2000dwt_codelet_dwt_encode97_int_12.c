#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int *local_t = t;
    int local_w = w;
    int local_h = h;
    int size = local_w * local_h;
    int factor = 1 << 8;
    for (i = 1; i < size; i++) {
        local_t[i] *= factor;
        local_t[i] += local_t[i-1] & 0xFF; // Introduce RAW dependency: current depends on previous
    }
    if (size > 0)
        local_t[0] *= factor;
}
