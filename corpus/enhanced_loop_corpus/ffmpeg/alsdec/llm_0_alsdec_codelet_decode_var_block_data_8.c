#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int opt_order;
extern int sb;
extern int64_t y;
extern int32_t *lpc_cof;
extern int32_t *raw_samples;
extern int32_t *raw_samples_end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; raw_samples < raw_samples_end; raw_samples++) {
        y = 1 << 19;
        sb = -opt_order;
        for (; sb < 0; sb++) {
            y += (uint64_t)((int64_t)(lpc_cof[sb]) * (int64_t)(raw_samples[sb]));
        }
        *raw_samples -= y >> 20;
    }
}
