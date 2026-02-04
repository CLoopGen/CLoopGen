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
        int16_t in_val_forward = input[i];
        int16_t in_val_reverse = input[len - i - 1];
        output[i] = ((in_val_forward * w) + (1 << 14)) >> 15;
        output[len - i - 1] = ((in_val_reverse * w) + (1 << 14)) >> 15;
    }
}
