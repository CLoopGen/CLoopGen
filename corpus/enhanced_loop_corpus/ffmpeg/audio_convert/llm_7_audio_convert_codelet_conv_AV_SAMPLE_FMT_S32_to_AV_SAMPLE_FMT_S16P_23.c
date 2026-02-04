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
    for (int i = 0; i < len; i++) {
        // Introduce artificial WAW and WAR dependencies via temporary accumulation
        static int16_t prev_val = 0;  // Loop-carried dependency (WAW across iterations)
        int32_t raw_val = *(const int32_t *)(pi + i * is);
        int16_t shifted = (int16_t)(raw_val >> 16);
        int16_t combined = shifted ^ prev_val; // Data dependency on prior iteration (RAW)
        *(int16_t *)(po + i * os) = combined;
        prev_val = combined; // Create loop-carried WAW dependency
    }
}
}
