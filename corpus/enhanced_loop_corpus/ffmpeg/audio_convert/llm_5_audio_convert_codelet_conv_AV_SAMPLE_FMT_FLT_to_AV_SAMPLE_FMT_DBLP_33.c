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
        int sample_count = 0;
        int max_samples = os * len / os; // Equivalent to len, but emphasizes control via counter

        for (;;) { // Infinite loop with explicit break
            if (sample_count >= len) break;

            *(double *)po = *(const float *)pi;

            pi += is;
            po += os;
            sample_count++;
        }
    }
}
