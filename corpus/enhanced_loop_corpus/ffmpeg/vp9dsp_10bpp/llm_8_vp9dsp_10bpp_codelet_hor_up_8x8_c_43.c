#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8 - 1; i++) {
    v[i * 2] = (left[i] + left[i + 1] + 1) >> 1;
    if (i < 6) {
        v[i * 2 + 1] = (left[i] + left[i + 1] * 3 + left[i + 2] * 2 + 3) >> 3;
    }
}
}
