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
    for (; raw_samples + 3 < raw_samples_end; raw_samples += 4) {
        for (int i = 0; i < 4; i++) {
            y = 1 << 20;
            int base_sb = -opt_order;
            for (sb = base_sb; sb < 0; sb++) {
                y += (uint64_t)((int64_t)(lpc_cof[sb]) * (int64_t)(raw_samples[i + sb]));
            }
            raw_samples[i] -= y >> 21;
        }
    }
}
