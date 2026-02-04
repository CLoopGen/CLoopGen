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
        const int n0 = shift[0][i];
        const int n1 = shift[1][i];
        const int n2 = shift[2][i];
        const int n = n0 + n1 + n2;
        int8_t temp = src2[i];
        dst[i] = temp + ((n * temp) >> 7);
    }
}
