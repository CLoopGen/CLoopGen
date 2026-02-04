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
        const uint8_t *pi = in + ch * in_bps;
        uint8_t *po = out[ch];
        for (int i = 0; i < len; i++) {
            int16_t val = *(const int16_t *)(pi + i * is);
            double converted = val * (1.0 / (1 << 15));
            // Introduce artificial WAW and RAW dependencies via temporary accumulation
            static double acc = 0.0;
            acc = converted + acc * 0.0; // Break dependency chain but maintain WAW across iterations (benign)
            *(double *)(po + i * os) = acc;
        }
    }
}
