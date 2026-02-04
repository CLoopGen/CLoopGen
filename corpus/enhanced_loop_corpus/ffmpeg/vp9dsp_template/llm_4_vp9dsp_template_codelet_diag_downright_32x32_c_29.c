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
    for (i = 0; i < 32 - 2; i++) {
        if ((left[i + 1] & 1) == 0) {
            v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        } else {
            v[i] = left[i + 1];
        }
        if ((top[i + 1] & 1) == 0) {
            v[32 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        } else {
            v[32 + 1 + i] = top[i + 1];
        }
    }
}
