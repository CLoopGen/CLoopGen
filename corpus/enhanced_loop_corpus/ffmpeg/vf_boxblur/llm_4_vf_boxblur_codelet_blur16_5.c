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
    for (x = 0; x < radius; x++) {
        if (x % 2 == 0)
            sum += src[x * src_step] << 1;
    }
}
