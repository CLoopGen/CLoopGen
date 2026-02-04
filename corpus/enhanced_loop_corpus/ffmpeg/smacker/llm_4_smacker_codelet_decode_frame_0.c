#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern int i;
extern int stride;
extern int map;
extern int hi;
extern int lo;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 4; i++) {
    out[0] = (map & 1) ? hi : lo;
    out[1] = (map & 2) ? hi : lo;
    out[2] = (map & 4) ? hi : lo;
    out[3] = (map & 8) ? hi : lo;
    map >>= 4;
    out += stride;
}
}
