#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *top;
extern  uint16_t *left;
extern int i;
extern uint16_t v[94];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 64; i += 4) {
    v[i] = (left[i/2 + 1] + left[i/2] + 1) >> 1;
    v[i + 1] = (left[i/2 + 2] + (left[i/2 + 1] << 1) + left[i/2] + 2) >> 2;
    if (i < 32) {
        v[64 + i] = (top[i] * 3 + 2) >> 2;
        v[64 + i + 1] = (top[i + 1] + top[i] + 2) >> 1;
    }
}
}
