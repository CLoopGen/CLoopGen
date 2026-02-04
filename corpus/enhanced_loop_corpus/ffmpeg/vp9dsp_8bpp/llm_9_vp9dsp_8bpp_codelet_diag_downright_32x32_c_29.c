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
for (i = 0; i < 32 - 1; i += 2) {
    v[i] = (left[i] + left[i + 1] + 1) >> 1;
    if (i + 1 < 32 - 1) {
        v[i + 1] = (left[i + 1] + left[i + 2] + 1) >> 1;
    }
    v[32 + i] = (top[i] + top[i + 1] + 1) >> 1;
    if (i + 1 < 32 - 1) {
        v[32 + i + 1] = (top[i + 1] + top[i + 2] + 1) >> 1;
    }
}
}
