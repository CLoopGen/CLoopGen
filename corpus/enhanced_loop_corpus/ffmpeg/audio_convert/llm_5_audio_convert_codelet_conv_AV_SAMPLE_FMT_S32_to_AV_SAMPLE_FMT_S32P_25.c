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
        int total_samples = len;

        for (int i = 0; i < total_samples; i++) {
            if (i % 4 == 0 && os >= 4) {
                *(int32_t *)po = *(const int32_t *)pi;
            } else {
                for (int b = 0; b < os && b < 4; b++) {
                    po[b] = pi[b];
                }
            }
            pi += is;
            po += os;
        }
    }
}
