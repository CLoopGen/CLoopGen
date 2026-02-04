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
    int8_t prev_dst = 0;
    for (i = 0; i < len; i++) {
        const int n = shift[0][i] + shift[1][i] + shift[2][i];
        int8_t computed_val = src2[i] + ((n * src2[i]) >> 7);
        dst[i] = (i == 0) ? computed_val : computed_val + prev_dst;
        prev_dst = computed_val;
    }
}
