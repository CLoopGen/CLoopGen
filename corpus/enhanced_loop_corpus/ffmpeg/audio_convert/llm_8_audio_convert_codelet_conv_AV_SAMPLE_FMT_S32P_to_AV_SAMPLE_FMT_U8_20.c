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
    const uint8_t *pi = in[ch];
    uint8_t *po = out + ch * out_bps;
    int i;
    for (i = 0; i < len; i++) {
        int32_t val = *(const int32_t *)(pi + i * is);
        uint8_t result = ((val >> 24) & 0xFF) + 128;
        *(uint8_t *)(po + i * os) = result;
    }
}
}
