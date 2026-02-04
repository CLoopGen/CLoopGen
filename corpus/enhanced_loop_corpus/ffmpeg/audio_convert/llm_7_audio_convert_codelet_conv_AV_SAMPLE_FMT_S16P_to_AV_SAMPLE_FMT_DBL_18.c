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
    const uint8_t *pi_base = in[ch];
    uint8_t *po_base = out + ch * out_bps;
    int total_samples = len;
    for (int i = 0; i < total_samples; i++) {
        const uint8_t *pi = pi_base + i * is;
        uint8_t *po = po_base + i * os;
        double sample = *(const int16_t *)pi * (1. / (1 << 15));
        // Introduce artificial write-after-write dependency with intermediate volatile
        volatile double temp = sample;
        *(double *)po = (double)temp;
    }
}
}
