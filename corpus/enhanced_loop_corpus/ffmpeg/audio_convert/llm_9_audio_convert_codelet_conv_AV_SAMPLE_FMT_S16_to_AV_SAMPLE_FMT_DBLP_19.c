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
for (ch = 0; ch < channels; ch += 2) {
    if (ch + 1 >= channels) {
        const uint8_t *pi = in + ch * in_bps;
        uint8_t *po = out[ch];
        for (int i = 0; i < len; i++) {
            *(double *)po = (*(const int16_t *)pi) * (1.0 / 32768.0);
            pi += is;
            po += os;
        }
    } else {
        const uint8_t *pi0 = in + ch * in_bps;
        const uint8_t *pi1 = in + (ch + 1) * in_bps;
        uint8_t *po0 = out[ch];
        uint8_t *po1 = out[ch + 1];
        for (int i = 0; i < len; i++) {
            *(double *)po0 = (*(const int16_t *)pi0) * (1.0 / 32768.0);
            *(double *)po1 = (*(const int16_t *)pi1) * (1.0 / 32768.0);
            pi0 += is;
            pi1 += is;
            po0 += os;
            po1 += os;
        }
    }
}
}
