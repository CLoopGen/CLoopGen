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
for (i = 0; i < len2 && len > 0; i++) {
    int16_t w = window[i];
    int32_t product1 = input[i] * w;
    output[i] = (product1 + (1 << 14)) >> 15;
    int mirror_index = len - i - 1;
    if (mirror_index > i) {
        int32_t product2 = input[mirror_index] * w;
        output[mirror_index] = (product2 + (1 << 14)) >> 15;
    }
}
}
