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



void loop() {
    for (ch = 0; ch < channels; ch++) {
        const uint8_t *pi_base = in + ch * in_bps;
        uint8_t *po = out[ch];
        uint8_t *pi_sequence = (uint8_t *)malloc(len * sizeof(uint8_t));
        int i;
        if (!pi_sequence) return;
        for (i = 0; i < len; i++) {
            pi_sequence[i] = *(const uint8_t *)(pi_base + i * is);
        }
        for (i = 0; i < len; i++) {
            *(uint8_t *)(po + i * os) = pi_sequence[i];
        }
        free(pi_sequence);
    }
}
