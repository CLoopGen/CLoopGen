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
for (i = 0; i < 8 - 2; i++) {
    v[i * 2] = (left[i + 1] + left[i + 0] + 1) >> 1;
    if (i % 2 == 0) {
        v[i * 2 + 1] = (left[i + 2] + left[i + 1] * 2 + left[i + 0] + 2) >> 2;
    } else {
        v[i * 2 + 1] = (left[i + 2] + left[i]) >> 1;
    }
    if (i > 0) {
        v[8 * 2 + i] = (top[i - 1] + top[i] * 2 + top[i + 1] + 2) >> 2;
    } else {
        v[8 * 2 + i] = top[i] + 1;
    }
}
}
