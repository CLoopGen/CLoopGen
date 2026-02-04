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



void loop() {
    int limit = long_rps->nb_refs;
    for (i = 0; i < limit; i += 2) {
        ret += !!long_rps->used[i];
        if (i + 1 < limit) {
            ret += !!long_rps->used[i + 1];
        }
    }
}
