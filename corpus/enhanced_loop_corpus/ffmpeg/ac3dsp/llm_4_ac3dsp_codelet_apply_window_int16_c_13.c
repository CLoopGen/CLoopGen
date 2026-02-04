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
    if (i >= len) continue;
    int16_t w = window[i];
    int16_t val = input[i];
    output[i] = ((val * w + (1 << 14)) >> 15);
    int index = len - i - 1;
    if (index != i) {
        output[index] = (((input[index]) * w) + (1 << 14)) >> 15;
    }
}
}
