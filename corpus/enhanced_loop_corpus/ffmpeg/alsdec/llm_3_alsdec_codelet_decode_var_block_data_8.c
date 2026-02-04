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
    ptrdiff_t offset;
    for (offset = 0; offset < (raw_samples_end - raw_samples); offset++) {
        y = 1 << 19;
        for (sb = -opt_order; sb < 0; sb += 2) {
            y += (uint64_t)((int64_t)(lpc_cof[sb]) * (int64_t)(raw_samples[offset + sb]));
            if (sb + 1 < 0) {
                y += (uint64_t)((int64_t)(lpc_cof[sb + 1]) * (int64_t)(raw_samples[offset + sb + 1]));
            }
        }
        raw_samples[offset] -= y >> 20;
    }
}
