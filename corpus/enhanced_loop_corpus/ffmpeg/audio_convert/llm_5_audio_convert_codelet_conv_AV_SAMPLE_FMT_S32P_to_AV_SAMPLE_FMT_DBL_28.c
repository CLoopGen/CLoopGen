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
    for (ch = 0; ch < channels; ++ch) {
        const uint8_t *pi = in[ch];
        uint8_t *po = out + ch * out_bps;
        int count = len;

        if (!(count > 0)) continue;

        int i = 0;
        goto check;
loop_body:
        *(double *)po = *(const int32_t *)pi * (1. / (1U << 31));
        pi += is;
        po += os;
        i++;
check:
        if (i < count) goto loop_body;
    }
}
