#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *top;
extern  uint8_t *left;
extern int i;
extern uint8_t v[31];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 2; i++) {
        if (i % 2 == 0) {
            v[i] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
        } else {
            v[i] = 0;
        }
        if (i % 3 != 0) {
            v[16 + 1 + i] = (top[i] + top[i + 1] * 2 + top[i + 2] + 2) >> 2;
        } else {
            v[16 + 1 + i] = top[i + 1];
        }
    }
}
