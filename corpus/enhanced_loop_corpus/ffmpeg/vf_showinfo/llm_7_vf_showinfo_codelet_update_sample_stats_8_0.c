#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern int len;
extern int64_t *sum;
extern int64_t *sum2;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int64_t local_sum = *sum;
    int64_t local_sum2 = *sum2;
    for (i = 0; i < len; i++) {
        uint8_t val = src[i];
        local_sum += val;
        local_sum2 += val * val;
    }
    *sum = local_sum;
    *sum2 = local_sum2;
}
