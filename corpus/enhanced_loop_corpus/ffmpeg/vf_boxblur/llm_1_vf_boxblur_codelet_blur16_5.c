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
    sum = 0;
    for (x = 0; x < radius; x++) {
        int inner_limit = (src[x * src_step] & 1) ? 2 : 1;
        for (int j = 0; j < inner_limit; j++)
            sum += src[x * src_step] << 1;
    }
}
