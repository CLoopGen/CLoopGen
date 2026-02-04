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
    uint8_t temp[4];
    for (i = 0; i < 4; i++) {
        temp[0] = (map & 1) ? hi : lo;
        temp[1] = (map & 2) ? hi : lo;
        temp[2] = (map & 4) ? hi : lo;
        temp[3] = (map & 8) ? hi : lo;
        map >>= 4;
        out[0] = temp[0];
        out[1] = temp[1];
        out[2] = temp[2];
        out[3] = temp[3];
        out += stride;
    }
}
