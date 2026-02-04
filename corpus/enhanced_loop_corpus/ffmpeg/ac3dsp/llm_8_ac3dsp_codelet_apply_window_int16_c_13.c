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
for (i = 0; i < len2; i += 2) {
    int16_t w1 = window[i];
    int16_t w2 = window[i + 1];
    int32_t val1 = input[i] * w1;
    int32_t val2 = input[i + 1] * w2;
    output[i] = (val1 + (1 << 14)) >> 15;
    output[i + 1] = (val2 + (1 << 14)) >> 15;
    output[len - i - 1] = (((input[len - i - 1]) * w1) + (1 << 14)) >> 15;
    if (i + 1 < len2) {
        output[len - i - 2] = (((input[len - i - 2]) * w2) + (1 << 14)) >> 15;
    }
}
}
