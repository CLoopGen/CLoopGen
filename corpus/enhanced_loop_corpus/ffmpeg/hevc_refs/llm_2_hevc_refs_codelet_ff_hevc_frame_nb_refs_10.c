#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct LongTermRPS {
    int poc[32];
    uint8_t poc_msb_present[32];
    uint8_t used[32];
    uint8_t nb_refs;
} LongTermRPS;

extern int ret;
extern int i;
extern  LongTermRPS *long_rps;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2
    for (i = 0; i < long_rps->nb_refs; i += 2)
        ret += !!long_rps->used[i];
}
