#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *output;
extern  int16_t *input;
extern  int16_t *window;
extern unsigned int len;
extern int i;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len2; i++) {
    int16_t w = window[i];
    int32_t product_center = input[i] * w;
    int32_t product_mirror = input[len - i - 1] * w;
    int32_t biased_center = product_center + (1 << 14);
    int32_t biased_mirror = product_mirror + (1 << 14);
    output[i] = biased_center >> 15;
    output[len - i - 1] = biased_mirror >> 15;
}
}
