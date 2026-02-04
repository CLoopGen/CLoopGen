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
        for (int offset = 0; offset < len; offset++) {
            const uint8_t *pi1 = in + ch * in_bps + offset * is;
            uint8_t *po1 = out[ch] + offset * os;
            *(float *)po1 = *(const float *)pi1;

            if (ch + 1 < channels) {
                const uint8_t *pi2 = in + (ch + 1) * in_bps + offset * is;
                uint8_t *po2 = out[ch + 1] + offset * os;
                *(float *)po2 = *(const float *)pi2;
            }
        }
    }
}
