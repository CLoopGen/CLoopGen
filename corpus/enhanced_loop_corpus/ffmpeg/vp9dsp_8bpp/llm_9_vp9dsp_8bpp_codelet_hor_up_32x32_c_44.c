#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *left;
extern int i;
extern uint8_t v[62];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 60; i += 3) {
    v[i] = (left[i / 3] + left[i / 3 + 1] + 1) >> 1;
    if (i + 1 < 62) {
        v[i + 1] = (left[i / 3] * 3 + left[i / 3 + 1] + 2) >> 2;
    }
    if (i + 2 < 62) {
        v[i + 2] = (left[i / 3] + left[i / 3 + 1] * 2 + left[i / 3 + 2] + 2) >> 2;
    }
}
}
