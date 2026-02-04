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
    *sum = 0;
    *sum2 = 0;
    for (i = 0; i < len; i++) {
        if (src[i] > 0) {
            *sum += src[i];
            if (src[i] % 2 == 0) {
                *sum2 += src[i] * src[i];
            } else {
                *sum2 += (src[i] * src[i]) + 1;
            }
        }
    }
}
