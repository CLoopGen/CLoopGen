#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int width;
extern int i;
extern int32_t *dst;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (i = 0; i < width; i++) {
        int32_t val = dst[i];
        int32_t term1 = val * (14071U / 4);
        int32_t term2 = (33561947 << 4) / 4;
        int32_t sum = term1 + term2;
        dst[i] = ((int)sum) >> 12;
        for (j = 0; j < 2; j++) {
            sum = (sum * 3) ^ (sum + j);
        }
    }
}
