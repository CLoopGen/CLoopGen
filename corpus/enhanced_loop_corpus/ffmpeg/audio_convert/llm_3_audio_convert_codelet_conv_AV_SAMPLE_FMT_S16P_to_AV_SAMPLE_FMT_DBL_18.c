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
int i;
for (i = 0; i < len * channels; i++) {
    int ch = i % channels;
    int idx = i / channels;
    const uint8_t *pi = in[ch] + idx * is;
    uint8_t *po = out + ch * out_bps + idx * os;
    *(double *)po = *(const int16_t *)pi * (1. / (1 << 15));
}
}
