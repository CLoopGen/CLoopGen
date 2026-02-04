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
    int32_t *rs = raw_samples;
    int64_t local_y;
    for (; rs < raw_samples_end; rs++) {
        local_y = 1 << 19;
        for (sb = -opt_order; sb < 0; sb++) {
            int64_t cof_val = lpc_cof[sb];
            int64_t sample_val = rs[sb];
            local_y += (uint64_t)(cof_val * sample_val);
        }
        rs[0] = rs[0] - (local_y >> 20);
    }
    raw_samples = rs;
}
