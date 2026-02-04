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
int i;
for (i = 0; i < len * channels; i++) {
    int ch = i / len;
    int sample = i % len;
    const uint8_t *pi = in + ch * in_bps + sample * is;
    uint8_t *po = out[ch] + sample * os;
    *(float *)po = (*(const uint8_t *)pi - 128) * (1.F / (1 << 7));
}
}
