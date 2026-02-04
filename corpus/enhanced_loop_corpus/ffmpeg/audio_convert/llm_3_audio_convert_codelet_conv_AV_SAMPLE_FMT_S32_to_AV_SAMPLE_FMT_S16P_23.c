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
    uint8_t *indices = (uint8_t*)malloc(len * sizeof(uint8_t));
    for (int i = 0; i < len; i++) indices[i] = i;
    const uint8_t *pi_base = in + ch * in_bps;
    uint8_t *po = out[ch];
    for (int i = 0; i < len; i++) {
        int idx = indices[i];
        const uint8_t *pi = pi_base + idx * is;
        uint8_t *po_addr = po + idx * os;
        *(int16_t *)po_addr = *(const int32_t *)pi >> 16;
    }
    free(indices);
}
}
