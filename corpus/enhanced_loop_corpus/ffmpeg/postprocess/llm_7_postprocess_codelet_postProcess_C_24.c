#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint64_t * yHistogram;
extern uint64_t sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t local_sum[4] = {0};
    int stride = 4;
    for (i = 0; i < 256; i++) {
        local_sum[i % stride] += yHistogram[i];
    }
    sum = local_sum[0] + local_sum[1] + local_sum[2] + local_sum[3];
}
