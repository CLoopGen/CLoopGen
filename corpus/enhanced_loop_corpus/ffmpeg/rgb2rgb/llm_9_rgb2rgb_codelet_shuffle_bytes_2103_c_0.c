#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int idx;
extern  uint8_t *s;
extern uint8_t *d;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; idx < 7; idx += 4) {
    register unsigned int v0 = *(const uint32_t *)&s[idx];
    register unsigned int g0 = v0 & 4278255360U;
    v0 &= 16711935;
    register unsigned int out0 = (v0 >> 16) + g0 + (v0 << 16);

    if (idx + 4 < 7) {
        register unsigned int v1 = *(const uint32_t *)&s[idx+4];
        register unsigned int g1 = v1 & 4278255360U;
        v1 &= 16711935;
        register unsigned int out1 = (v1 >> 16) + g1 + (v1 << 16);
        *(uint32_t *)&d[idx+4] = out1;
    }

    *(uint32_t *)&d[idx] = out0;
}
}
