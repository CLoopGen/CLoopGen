#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern int block_size;
extern int y;
extern int sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int y;
    for (y = 0; y < block_size; y++) {
        int x;
        int local_sum = 0;
        for (x = 0; x < block_size; x++) {
            local_sum += src[x + y * stride];
        }
        sum += local_sum;
    }
}
