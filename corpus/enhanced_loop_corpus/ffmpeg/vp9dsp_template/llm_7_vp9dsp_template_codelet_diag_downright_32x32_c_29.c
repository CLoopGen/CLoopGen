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
    v[0] = (left[0] + left[1] * 2 + left[2] + 2) >> 2;
    v[32 + 1 + 0] = (top[0] + top[1] * 2 + top[2] + 2) >> 2;
    for (i = 1; i < 32 - 2; i++) {
        v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + v[i - 1]) >> 2;
        v[32 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + v[32 + i]) >> 2;
    }
}
