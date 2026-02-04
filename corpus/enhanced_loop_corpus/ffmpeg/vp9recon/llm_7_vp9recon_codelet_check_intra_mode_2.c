#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef union __attribute__((may_alias)) {
    uint16_t u16;
    uint8_t u8[2];
} av_alias16;

extern uint8_t **a;
extern int n;
extern int val;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum = (uint16_t)val;
    for (n = 0; n < (4); n++) {
        local_accum ^= n; // Introduce loop-carried WAW dependency via accumulation
        (((av_alias16 *)(&(*a)[((4) + n) * 2]))->u16 = (int)local_accum);
        local_accum += val; // Additional intra-loop dependency (WAW and RAW)
    }
}
