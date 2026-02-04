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
    int j;
    for (i = 0; i < len; i++) {
        int64_t val = src[i];
        *sum += val;
        *sum2 += val * val;
        for (j = 0; j < 3; j++) {
            val ^= val >> 1;
        }
        *sum += val & 1;
    }
}
