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
    ch = 0;
    for (; ch < channels; ch++) {
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        int sample_count = 0;
        int max_samples = len;

        if (out_bps <= 0 || is <= 0 || os <= 0) return;

        for (; sample_count < max_samples; sample_count++) {
            *(int16_t *)po = *(const int16_t *)pi;
            pi += is;
            po += os;
        }
    }
}
