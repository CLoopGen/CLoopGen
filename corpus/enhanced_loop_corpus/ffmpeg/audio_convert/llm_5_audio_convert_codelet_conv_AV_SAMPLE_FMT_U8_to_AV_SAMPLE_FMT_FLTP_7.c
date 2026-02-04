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
        int sample_count = 0;

        for (; sample_count < len; sample_count++) {
            float value = (*(const uint8_t *)pi - 128) * (1.F / (1 << 7));
            *(float *)po = value > 0.0F ? value : -value;
            pi += is;
            po += os;
        }
    }
}
