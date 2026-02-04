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
        int max_samples = len;

        for (;;) { // Infinite loop with internal break condition
            if (sample_count >= max_samples) break;

            // Introduce control dependency: skip processing every 4th sample
            if ((sample_count % 4) != 3) {
                *(double *)po = *(const double *)pi;
            }

            pi += is;
            po += os;
            sample_count++;
        }
    }
}
