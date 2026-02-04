#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct ChannelContext {
    float base[128];
    float imdct_in[128] __attribute__((aligned(32)));
    float imdct_out[128] __attribute__((aligned(32)));
    float imdct_prev[128] __attribute__((aligned(32)));
    int8_t scale_factors[128];
    uint8_t scale[128];
    int8_t intensity[8];
    int8_t *hfr_scale;
    unsigned int count;
    int chan_type;
} ChannelContext;

extern  float scale_conversion_table[];
extern ChannelContext *ch;
extern unsigned int hfr_group_count;
extern unsigned int bands_per_hfr_group;
extern unsigned int start_band;
extern unsigned int total_band_count;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_buffer[128];
    int valid_entries[128];
    int write_count = 0;

    for (int i = 0, k = start_band, l = start_band - 1; i < hfr_group_count; i++) {
        for (int j = 0; j < bands_per_hfr_group && k < total_band_count && l >= 0; j++, k++, l--) {
            float scaled_val = scale_conversion_table[(ch->hfr_scale[i] - ch->scale_factors[l]) & 63] * ch->imdct_in[l];
            local_buffer[write_count] = scaled_val;
            valid_entries[write_count] = k;
            write_count++;
        }
    }

    for (int idx = 0; idx < write_count; idx++) {
        int k = valid_entries[idx];
        ch->imdct_in[k] = local_buffer[idx];
    }
}
