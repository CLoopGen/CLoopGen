#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *reg_dense;
extern  uint8_t *reg_raw;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint8_t *local_reg_dense = reg_dense;
    uint8_t *local_reg_raw = reg_raw;
    int limit = 1 << 14;
    for (int i = 0; i < limit; i += 2) {
        unsigned long indices[2] = {i, i + 1};
        uint8_t values[2] = {local_reg_raw[indices[0]], local_reg_raw[indices[1]]};
        unsigned long bytes[2], fb[2], fb8[2];
        uint8_t merged_low[2], merged_high[2];

        for (int j = 0; j < 2 && indices[j] < limit; j++) {
            bytes[j] = indices[j] * 6 / 8;
            fb[j] = (indices[j] * 6) & 7;
            fb8[j] = 8 - fb[j];
            merged_low[j] = (values[j] << fb[j]) & 0xFF;
            merged_high[j] = values[j] >> fb8[j];
            local_reg_dense[bytes[j]] = (local_reg_dense[bytes[j]] & ~(((1 << 6) - 1) << fb[j])) | merged_low[j];
            if (fb8[j] < 6) {
                local_reg_dense[bytes[j] + 1] = (local_reg_dense[bytes[j] + 1] & ~(((1 << 6) - 1) >> fb8[j])) | merged_high[j];
            }
        }
    }
}
