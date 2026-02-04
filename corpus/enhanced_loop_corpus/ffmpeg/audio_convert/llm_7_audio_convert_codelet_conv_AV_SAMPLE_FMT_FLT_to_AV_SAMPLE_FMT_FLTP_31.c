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
    const uint8_t *base_in = in + ch * in_bps;
    uint8_t *base_out = out[ch];
    for (int i = 0; i < len; i++) {
        float temp_val = *(const float *)(base_in + i * is);
        *(float *)(base_out + i * os) = temp_val;
    }
}
}
