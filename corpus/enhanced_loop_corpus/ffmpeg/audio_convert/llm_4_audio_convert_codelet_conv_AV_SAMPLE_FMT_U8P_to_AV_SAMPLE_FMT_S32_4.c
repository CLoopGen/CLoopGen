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

        if (pi == NULL || po == end) continue;

        for (int i = 0; i < len; i++) {
            if ((*(const uint8_t *)pi & 0x80) == 0) {
                *(int32_t *)po = -2147483648; // negative max if below 128
            } else {
                *(int32_t *)po = (*(const uint8_t *)pi - 128) << 24;
            }
            pi += is;
            po += os;
        }
    }
}
