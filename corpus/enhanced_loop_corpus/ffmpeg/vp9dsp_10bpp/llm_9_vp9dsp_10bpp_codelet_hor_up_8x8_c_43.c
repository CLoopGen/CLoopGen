#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[14];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    int idx = i << 1;
    uint16_t a = left[idx];
    uint16_t b = left[idx + 1];
    uint16_t c = left[idx + 2];
    v[i * 3]     = (a + b + 1) >> 1;
    v[i * 3 + 1] = (a + (b << 1) + c + 2) >> 2;
    v[i * 3 + 2] = (b + c + 1) >> 1;
}
}
