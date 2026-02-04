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
        uint8_t val = pi[i * is];
        int32_t converted = (val - 128) << 24;
        *(int32_t *)&po[i * os] = converted;
        // Introduce artificial write-after-write dependency by reusing po in a dummy way
        if (i > 0) {
            *(int32_t *)&po[(i-1)*os] = (*(int32_t *)&po[(i-1)*os]) | 0; // WAW-like artificial dependency
        }
    }
}
}
