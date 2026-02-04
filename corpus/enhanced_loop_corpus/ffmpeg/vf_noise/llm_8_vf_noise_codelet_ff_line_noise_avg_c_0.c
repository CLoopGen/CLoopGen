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
    for (i = 0; i < len; i += 2) {
        const int n0 = shift[0][i] + shift[1][i] + shift[2][i];
        dst[i] = src2[i] + ((n0 * src2[i]) >> 7);
        if (i + 1 < len) {
            const int n1 = shift[0][i+1] + shift[1][i+1] + shift[2][i+1];
            dst[i+1] = src2[i+1] + ((n1 * src2[i+1]) >> 7);
        }
    }
}
