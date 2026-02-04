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
    uint8_t *po = out[ch];
    const uint8_t *base_pi = in + ch * in_bps;
    int i;
    for (i = 0; i < len; i++) {
        // Access input and output arrays with strided access pattern
        const uint8_t *pi = base_pi + i * is;
        uint8_t *target_po = po + i * os;
        *(double *)target_po = *(const int32_t *)pi * (1. / (1U << 31));
    }
}
}
