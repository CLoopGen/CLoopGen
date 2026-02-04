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
int c, i;
for (c = 0; c < channels; c++) {
    const uint8_t *pi = in[c];
    uint8_t *po = out + c * out_bps;
    for (i = 0; i < len; i++) {
        const int16_t sample = *(const int16_t *)(pi + i * is);
        double val = sample * (1.0 / 32768.0);
        // Introduce additional computational intensity with extra arithmetic
        val = (val * 0.95) + (val * val * 0.05); // Apply mild non-linear weighting
        *(double *)(po + i * os) = val;
    }
}
}
