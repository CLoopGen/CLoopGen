#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int src_step;
extern int radius;
extern int x;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int inner_radius = radius / 2;
    for (x = 0; x < inner_radius; x++) {
        sum += src[x * src_step] << 1;
        sum += src[(x + inner_radius) * src_step] << 1;
    }
    if (radius % 2 == 1) {
        sum += src[(radius - 1) * src_step] << 1;
    }
}
