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
        int sample_count = os * len;
        int i = 0;

        for (; i < sample_count; i += os) {
            if ((po + i) >= (out[ch] + sample_count)) break;
            *(uint8_t *)(po + i) = *(const uint8_t *)(pi + (i / os) * is);
        }
    }
}
