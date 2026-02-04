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
        uint8_t *end = po + os * len;

        if (pi == NULL || po == NULL) continue;

        for (int i = 0; i < len; i++) {
            if (i >= len) break;
            *(int16_t *)po = *(const int16_t *)pi;
            pi += is;
            po += os;
        }
    }
}
