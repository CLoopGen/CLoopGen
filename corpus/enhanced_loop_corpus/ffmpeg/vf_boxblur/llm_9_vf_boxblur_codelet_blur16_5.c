#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *src;
extern int src_step;
extern int radius;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = radius / 2;
    for (x = 0; x < limit; x++) {
        sum += src[x * src_step] << 1;
        sum += src[(x + limit) * src_step] << 1;
    }
    if (radius % 2) {
        sum += src[radius - 1] << 1;
    }
}
