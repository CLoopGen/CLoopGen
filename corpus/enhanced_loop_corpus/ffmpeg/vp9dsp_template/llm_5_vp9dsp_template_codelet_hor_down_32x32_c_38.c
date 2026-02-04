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
for (i = 0; i < 32 - 2; i++) {
    uint8_t temp1 = left[i + 1];
    uint8_t temp2 = left[i + 0];
    v[i * 2] = (temp1 + temp2 + 1) >> 1;

    if (i > 0) {
        v[i * 2 + 1] = (left[i + 2] + temp1 * 2 + temp2 + 2) >> 2;
    } else {
        v[i * 2 + 1] = (left[i + 2] + temp1 + temp2 + 1) >> 1;
    }

    if (i < 1) continue;

    v[32 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
}
}
