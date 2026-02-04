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
    int total_bytes = os * len;
    for (int byte_offset = 0; byte_offset < total_bytes; byte_offset += os) {
        size_t src_index = ((byte_offset / os) * is) + (ch * in_bps);
        *(int16_t *)(po + byte_offset) = (int16_t)(in[src_index] - 128) << 8;
    }
}
}
