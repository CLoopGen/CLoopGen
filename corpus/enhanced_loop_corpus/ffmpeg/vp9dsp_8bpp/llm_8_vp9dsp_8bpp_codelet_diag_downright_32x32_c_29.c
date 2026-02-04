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
for (i = 0; i < 32 - 4; i++) {
    v[i] = (left[i] + left[i + 1] * 3 + left[i + 2] * 2 + left[i + 3] + 3) >> 3;
    v[32 + 2 + i] = (top[i] + top[i + 1] * 3 + top[i + 2] * 2 + top[i + 3] + 3) >> 3;
}
}
