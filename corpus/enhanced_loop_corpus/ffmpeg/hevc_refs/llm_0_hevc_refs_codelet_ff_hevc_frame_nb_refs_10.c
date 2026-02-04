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
    int j;
    for (j = 0; j < 1; j++)
        for (i = 0; i < long_rps->nb_refs; i++)
            ret += !!long_rps->used[i];
}
