#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
struct DssSpSubframe {
    int16_t gain;
    int32_t combined_pulse_pos;
    int16_t pulse_pos[7];
    int16_t pulse_val[7];
};


extern  uint16_t dss_sp_fixed_cb_gain[64];
extern  int16_t dss_sp_pulse_val[8];
extern int32_t *vector_buf;
extern  struct DssSpSubframe *sf;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 7; i++) {
        int16_t pos = sf->pulse_pos[i];
        int16_t val_index = sf->pulse_val[i];
        if (pos >= 0) {
            int32_t product = dss_sp_fixed_cb_gain[sf->gain] * dss_sp_pulse_val[val_index];
            vector_buf[pos] += (product + 16384) >> 15;
        }
    }
}
