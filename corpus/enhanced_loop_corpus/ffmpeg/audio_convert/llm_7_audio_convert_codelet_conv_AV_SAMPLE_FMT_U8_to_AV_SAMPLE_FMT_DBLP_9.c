#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t **out;
extern  uint8_t *in;
extern int len;
extern int channels;
extern int ch;
extern int in_bps;
extern int is;
extern int os;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ch = 0; ch < channels; ch++) {
    const uint8_t *base_pi = in + ch * in_bps;
    uint8_t *base_po = out[ch];
    for (int i = 0; i < len; i++) {
        const uint8_t *pi = base_pi + i * is;
        uint8_t *po = base_po + i * os;
        double sample = (double)(*pi - 128) * (1.0 / 128.0);
        *(double *)po = sample;
    }
}
}
