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
    int x_outer;
    for (x_outer = 0; x_outer < radius; x_outer++) {
        for (x = 0; x < 1; x++) {
            sum += src[x_outer * src_step] << 1;
        }
    }
}
