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
    uint8_t local_hi = hi;
    uint8_t local_lo = lo;
    int local_map = map;
    uint8_t *local_out = out;
    for (i = 0; i < 4; i++) {
        uint8_t val0 = (local_map & 1) ? local_hi : local_lo;
        uint8_t val1 = (local_map & 2) ? local_hi : local_lo;
        uint8_t val2 = (local_map & 4) ? local_hi : local_lo;
        uint8_t val3 = (local_map & 8) ? local_hi : local_lo;
        local_out[0] = val0;
        local_out[1] = val1;
        local_out[2] = val2;
        local_out[3] = val3;
        local_map >>= 4;
        local_out += stride;
    }
    out = local_out;
    map = local_map;
}
