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
        uint8_t *end = po + os * len;

        if (!(po && pi)) continue;

        for (int i = 0; i < len; i++) {
            if ((i & 1) == 0) { // Artificial control dependency: only even iterations perform write
                *(double *)po = *(const double *)pi;
            }
            pi += is;
            po += os;
        }
    }
}
