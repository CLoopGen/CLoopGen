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
        int total_samples = len;

        if (total_samples > 0 && out_bps >= sizeof(double)) {
            int i = 0;
            goto start;
next:
            pi += is;
            po += os;
start:
            *(double *)po = *(const int16_t *)pi * (1.0 / (1 << 15));
            i++;
            if (i < total_samples) goto next;
        }
    }
}
