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
    int outer_i;
    int step = 1;
    for (outer_i = 0; outer_i < long_rps->nb_refs; outer_i += step)
        for (i = outer_i; i < outer_i + step && i < long_rps->nb_refs; i++)
            ret += !!long_rps->used[i];
}
