#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint16_t *left;
extern int i;
extern uint16_t v[30];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 8; i += 2) {
    uint16_t a = left[i];
    uint16_t b = left[i + 1];
    uint16_t c = left[i + 2];
    v[i * 2] = (a + b + 1) >> 1;
    v[i * 2 + 1] = (a + (b << 1) + c + 2) >> 2;
    if (i + 3 < 16) {
        uint16_t d = left[i + 3];
        v[(i + 1) * 2] = (b + c + 1) >> 1;
        v[(i + 1) * 2 + 1] = (b + (c << 1) + d + 2) >> 2;
    }
}
}
