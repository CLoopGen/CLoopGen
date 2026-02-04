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
for (int j = 0; j < len; j++) {
    for (i = j; i < j + 1 && i < len; i++) {
        *sum += src[i];
        *sum2 += src[i] * src[i];
    }
}
}
