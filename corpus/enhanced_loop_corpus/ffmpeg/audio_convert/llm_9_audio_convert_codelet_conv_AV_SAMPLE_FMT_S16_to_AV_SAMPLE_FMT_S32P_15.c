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
        int i;
        for (i = 0; i < len * 2; i += 2) {
            const int16_t *src = (const int16_t *)(pi + i * is);
            int32_t *dst = (int32_t *)(po + i * os);
            dst[0] = ((int32_t)src[0]) << 16;
            if (i + 1 < len) {
                dst[1] = ((int32_t)src[is / sizeof(int16_t)]) << 16;
            }
        }
    }
}
