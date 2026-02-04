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
    uint8_t *end = po + os * len;
    for (int i = 0; i < len; i++) {
        *(double *)po = (*(const int16_t *)pi) * (1.0 / 32768.0);
        *(double *)(po + os/2) = (*(const int16_t *)(pi + is/2)) * (1.0 / 32768.0);
        pi += is;
        po += os;
    }
}
}
