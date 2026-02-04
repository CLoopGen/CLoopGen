#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *dst;
extern int len;
extern  int8_t * *shift;
extern int i;
extern  int8_t *src2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < len; i++) {
        const int n = shift[0][i] + shift[1][i] + shift[2][i];
        dst[i] = src2[i];
        if ((n & 1) && i % 2 == 0) {
            dst[i] = src2[i] + ((n * src2[i]) >> 6);
        }
    }
}
