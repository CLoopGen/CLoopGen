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
    for (int j = 0; j < len; j += 2) {
        for (int i = j; i < j + 2 && i < len; i++) {
            const int n = shift[0][i] + shift[1][i] + shift[2][i];
            dst[i] = src2[i] + ((n * src2[i]) >> 7);
        }
    }
}
