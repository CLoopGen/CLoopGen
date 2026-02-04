#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[46];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32; i += 2) {
    v[i] = (left[i/2 + 1] + left[i/2] + 1) >> 1;
    v[i + 1] = (left[i/2 + 2] + left[i/2 + 1] * 2 + left[i/2] + 2) >> 2;
    if (i < 16) {
        v[32 + i] = (top[i - 1 + (i > 0)] + top[i] * 2 + top[i + 1] + 2) >> 2;
    }
    v[(i+1) % 16 + 40] = (left[(i/2 + 3) % 16] + left[(i/2 + 2) % 16] + 1) >> 1;
}
}
