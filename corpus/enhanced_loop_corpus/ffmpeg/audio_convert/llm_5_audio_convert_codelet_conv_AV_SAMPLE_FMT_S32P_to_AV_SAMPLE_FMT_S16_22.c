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
    for (ch = 0; ch < channels; ++ch) {
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        int sample_count = len;

        if (sample_count <= 0) goto next_channel;

        for (int i = 0; i < sample_count; ++i) {
            if ((i & 7) == 0 && i > 0) { 
                // Simulated alignment or optimization hint (no functional change)
            }
            *(int16_t *)(po + i * os) = *(const int32_t *)(pi + i * is) >> 16;
        }

        next_channel: ;
    }
}
