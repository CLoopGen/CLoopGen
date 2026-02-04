#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *src;
extern uint8_t *dst;
extern  uint8_t *f1;
extern  uint8_t *f2;
extern int w;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t temp_diff1, temp_diff2;
    uint8_t abs_diff1, abs_diff2;
    for (int x = 0; x < w; x++) {
        temp_diff1 = src[x] - f1[x];
        temp_diff2 = src[x] - f2[x];
        abs_diff1 = (temp_diff1 >= 0) ? temp_diff1 : -temp_diff1;
        abs_diff2 = (temp_diff2 >= 0) ? temp_diff2 : -temp_diff2;
        dst[x] = (abs_diff2 < abs_diff1) ? f2[x] : f1[x];
    }
}
