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
    ch = 0;
    for (; ch < channels;) {
        const uint8_t *pi = in + ch * in_bps;
        uint8_t *po = out[ch];
        uint8_t *end = po + os * len;
        int count = 0;
        int total_iters = len;

        for (; count < total_iters; count++) {
            if (count >= len) break;
            *(int32_t *)po = *(const int16_t *)pi << 16;
            pi += is;
            po += os;
        }

        ch++;
    }
}
