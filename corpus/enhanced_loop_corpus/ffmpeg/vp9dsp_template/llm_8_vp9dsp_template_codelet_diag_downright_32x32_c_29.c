#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[63];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 32 - 4; i += 2) {
    uint8_t l0 = left[i];
    uint8_t l1 = left[i + 1];
    uint8_t l2 = left[i + 2];
    uint8_t t0 = top[i];
    uint8_t t1 = top[i + 1];
    uint8_t t2 = top[i + 2];
    v[i] = (l0 + l1 * 2 + l2 + 2) >> 2;
    v[i + 1] = (left[i + 1] + left[i + 2] * 2 + left[i + 3] + 2) >> 2;
    v[32 + 1 + i] = (t0 + t1 * 2 + t2 + 2) >> 2;
    v[32 + 1 + i + 1] = (top[i + 1] + top[i + 2] * 2 + top[i + 3] + 2) >> 2;
}
}
