#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int depth = 0; depth < 2; depth++) {
        for (i = 0; i < 16 - 2; i++) {
            if (depth == 0) {
                v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
            } else {
                v[i * 2 + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
            }
        }
    }
}
