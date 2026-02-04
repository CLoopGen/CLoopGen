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
    for (; rs < raw_samples_end; rs++) {
        y = 1 << 19;
        int64_t temp_y = y;
        for (int i = 0; i < opt_order; i++) {
            temp_y += (uint64_t)((int64_t)(lpc_cof[-opt_order + i]) * (int64_t)(rs[-opt_order + i]));
        }
        *rs -= temp_y >> 20;
    }
    raw_samples = rs;
}
