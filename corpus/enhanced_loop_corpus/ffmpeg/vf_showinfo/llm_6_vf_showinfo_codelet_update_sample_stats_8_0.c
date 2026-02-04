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
    int64_t temp_sum = 0;
    int64_t temp_sum2 = 0;
    for (i = 0; i < len; i++) {
        temp_sum += src[i];
        temp_sum2 += src[i] * src[i];
    }
    *sum = temp_sum;
    *sum2 = temp_sum2;
}
