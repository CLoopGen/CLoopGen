#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint16_t nops[10000];
extern int i;
extern int nop_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint16_t local_accum[2] = {0};
    for (i = 2500; i < 7500; i++) {
        local_accum[i & 1] += nops[i]; // Introduce WAR and WAW dependency via indexed update
    }
    nop_sum += (int)(local_accum[0] + local_accum[1]); // Reduce after loop to break loop-carried dependency on nop_sum
}
