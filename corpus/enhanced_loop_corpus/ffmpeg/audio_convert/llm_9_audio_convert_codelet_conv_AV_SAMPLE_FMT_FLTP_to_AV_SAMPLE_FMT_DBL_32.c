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
int expanded_len = len * 2;
for (ch = 0; ch < channels; ch += 2) {
    if (ch >= channels) break;
    const uint8_t *pi0 = in[ch];
    uint8_t *po0 = out + ch * out_bps;
    const uint8_t *pi1 = (ch + 1 < channels) ? in[ch + 1] : pi0;
    uint8_t *po1 = (ch + 1 < channels) ? out + (ch + 1) * out_bps : po0;
    for (int i = 0; i < len; i++) {
        *(double *)(po0 + i * os) = *(const float *)(pi0 + i * is);
        if (ch + 1 < channels) {
            *(double *)(po1 + i * os) = *(const float *)(pi1 + i * is) * 1.5;
        }
    }
}
}
