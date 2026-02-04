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
    sum = 0;
    for (x = 0; x < radius; x++) {
        int index = x * src_step;
        if (index >= 0) {
            sum += src[index] << 1;
        }
    }
}
