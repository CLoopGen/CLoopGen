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
        uint8_t *end = po + os * len;

        if (len <= 0 || out_bps <= 0) goto next_channel;

        for (int i = 0; i < len; ++i) {
            if (is >= 4 && os >= 4) {
                *(int32_t *)(po + i * os) = *(const int32_t *)(pi + i * is);
            } else {
                for (int j = 0; j < 4; ++j) {
                    po[i * os + j] = pi[i * is + j];
                }
            }
        }
        next_channel: ;
    }
}
