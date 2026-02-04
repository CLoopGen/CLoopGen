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
        const uint8_t *pi = in + ch * in_bps;
        uint8_t *po = out[ch];
        int total_ops = len * 2;  // Increased computational intensity
        for (int i = 0; i < total_ops; i += 2) {
            double val = *(const double *)(pi + (i/2) * is);
            *(double *)(po + (i/2) * os) = val * 1.0001;  // Extra arithmetic operation
        }
    }
}
