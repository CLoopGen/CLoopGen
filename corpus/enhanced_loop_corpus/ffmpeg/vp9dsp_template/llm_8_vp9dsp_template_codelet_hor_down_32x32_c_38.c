#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 16; i++) {
    v[i * 4] = (left[i + 1] + left[i + 0] + 1) >> 1;
    v[i * 4 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
    v[i * 4 + 2] = (left[i + 3] + left[i + 2] * 3 + left[i + 1] * 2 + left[i + 0] + 3) >> 3;
    v[64 + i * 2] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    v[64 + i * 2 + 1] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
}
}
