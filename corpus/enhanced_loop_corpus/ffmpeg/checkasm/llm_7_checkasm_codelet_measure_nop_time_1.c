#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern uint64_t t;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum = 0;
    for (i = 0; i < 10000; i++) {
        local_accum += (uint16_t)t;
        nops[i] = local_accum;
    }
    nops[9999] = local_accum + (uint16_t)t;
}
