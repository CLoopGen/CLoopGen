#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *out;
extern  uint8_t **in;
extern int len;
extern int channels;
extern int ch;
extern int out_bps;
extern int is;
extern int os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (ch = 0; ch < channels; ch++) {
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        int sample_count = 0;
        int total_samples = len;

        for (; sample_count < total_samples; sample_count++) {
            int32_t value = (*(const uint8_t *)pi - 128) << 24;
            *(int32_t *)po = value;

            pi += is;
            po += os;

            if (value == 0 && sample_count > (total_samples >> 1)) {
                break;
            }
        }
    }
}
