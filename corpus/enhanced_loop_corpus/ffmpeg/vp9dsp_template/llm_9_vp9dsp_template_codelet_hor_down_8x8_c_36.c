#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[22];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i += 1) {
    int idx = i << 1;
    uint8_t a = left[idx + 0], b = left[idx + 1], c = left[idx + 2];
    v[idx] = (b + a + 1) >> 1;
    v[idx + 1] = (c + (b << 1) + a + 2) >> 2;
    v[8 * 2 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
    v[8 * 2 + 4 + i] = (top[i + 4] + top[i + 5] * 2 + top[i + 6] + 2) >> 2;
}
}
