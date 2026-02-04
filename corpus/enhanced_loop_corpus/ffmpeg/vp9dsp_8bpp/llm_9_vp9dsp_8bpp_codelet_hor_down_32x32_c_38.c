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
for (i = 0; i < 48; i += 3) {
    v[i] = (left[i % 30 + 1] + left[i % 30] + 1) >> 1;
    v[i + 1] = (left[i % 30 + 2] + left[i % 30 + 1] * 2 + left[i % 30] + 2) >> 2;
    v[i + 2] = (top[(i/3) + 0] + top[(i/3) + 1] + 1) >> 1;
    if (i + 32 < 94) {
        v[i + 32] ^= (left[i % 30] + top[i % 30]) & 0xFF;
    }
}
}
