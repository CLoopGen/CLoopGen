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
    int ch = i / len;
    int sample_idx = i % len;
    const uint8_t *pi = in[ch] + sample_idx * is;
    uint8_t *po = out + ch * out_bps + sample_idx * os;
    *(double *)po = *(const float *)pi;
}
}
