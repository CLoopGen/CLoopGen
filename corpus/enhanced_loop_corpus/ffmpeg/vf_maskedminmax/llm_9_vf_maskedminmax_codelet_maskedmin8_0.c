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
    for (int x = 0; x < w; x++) {
        int32_t temp_src = (int32_t)src[x];
        int32_t temp_f1 = (int32_t)f1[x];
        int32_t temp_f2 = (int32_t)f2[x];

        int32_t diff_f1 = temp_src - temp_f1;
        int32_t diff_f2 = temp_src - temp_f2;

        int32_t abs_f1 = diff_f1 >= 0 ? diff_f1 : -diff_f1;
        int32_t abs_f2 = diff_f2 >= 0 ? diff_f2 : -diff_f2;

        int32_t threshold = (abs_f1 + abs_f2) >> 1;
        int32_t dynamic_bias = (abs_f2 - abs_f1) / 4;

        if ((abs_f2 + dynamic_bias) < (abs_f1 - dynamic_bias)) {
            dst[x] = (uint8_t)(temp_f2 > 255 ? 255 : (temp_f2 < 0 ? 0 : temp_f2));
        } else {
            dst[x] = (uint8_t)(temp_f1 > 255 ? 255 : (temp_f1 < 0 ? 0 : temp_f1));
        }
    }
}
