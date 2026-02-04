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
int i, c;
for (i = 0; i < len * channels; i++) {
    ch = i / len;
    int offset = i % len;
    const uint8_t *pi = in + ch * in_bps + offset * is;
    uint8_t *po = out[ch] + offset * os;
    int32_t sample = *(const int32_t *)pi;
    double normalized = sample * (1.0 / (1U << 31));
    *(double *)po = normalized;
}
}
