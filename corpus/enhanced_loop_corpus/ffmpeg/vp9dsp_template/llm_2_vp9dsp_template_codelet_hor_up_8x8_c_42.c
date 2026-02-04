#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 8 - 2; i++) {
        int idx = i * 2;
        v[idx] = (left[i] + left[i + 1] + 1) >> 1;
        v[idx + 1] = (left[i] + left[i + 1] * 2 + left[i + 2] + 2) >> 2;
    }
}
