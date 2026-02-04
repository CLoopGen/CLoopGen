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
        const uint8_t *pi1 = in + ch * in_bps;
        uint8_t *po1 = out[ch];
        const uint8_t *pi2 = (ch + 1 < channels) ? in + (ch + 1) * in_bps : NULL;
        uint8_t *po2 = (ch + 1 < channels) ? out[ch + 1] : NULL;
        int i;
        for (i = 0; i < len; i++) {
            *(float *)(po1 + i * os) = *(const double *)(pi1 + i * is);
            if (pi2 && po2) {
                *(float *)(po2 + i * os) = *(const double *)(pi2 + i * is);
            }
        }
    }
}
