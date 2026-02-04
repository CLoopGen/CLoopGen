#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int w;
extern  uint8_t *in;
extern uint8_t *out;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (j = 0; j < w; j++, out += 6, in -= 6) {
    int64_t v1 = ((uint64_t)((const uint8_t *)(in))[0] << 40);
    int64_t v2 = ((uint64_t)((const uint8_t *)(in))[1] << 32);
    int64_t v3 = ((uint64_t)((const uint8_t *)(in))[2] << 24);
    int64_t v4 = ((uint64_t)((const uint8_t *)(in))[3] << 16);
    int64_t v5 = ((uint64_t)((const uint8_t *)(in))[4] << 8);
    int64_t v6 = (uint64_t)((const uint8_t *)(in))[5];
    int64_t v = v1 | v2 | v3 | v4 | v5 | v6;

    uint64_t d = v;
    ((uint8_t *)(out))[5] = d;
    d >>= 8;
    ((uint8_t *)(out))[4] = d;
    d >>= 8;
    ((uint8_t *)(out))[3] = d;
    d >>= 8;
    ((uint8_t *)(out))[2] = d;
    d >>= 8;
    ((uint8_t *)(out))[1] = d;
    d >>= 8;
    ((uint8_t *)(out))[0] = d;
}
}
