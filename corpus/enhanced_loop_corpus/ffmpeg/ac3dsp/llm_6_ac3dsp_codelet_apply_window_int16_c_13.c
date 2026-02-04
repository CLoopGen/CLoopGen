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
    int16_t temp;
    for (i = 0; i < len2; i++) {
        int16_t w = window[i];
        temp = (((input[i]) * (w)) + (1 << 14)) >> 15;
        output[i] = temp;
        output[len - i - 1] = (((input[len - i - 1]) * (w)) + (1 << 14)) >> 15;
    }
}
