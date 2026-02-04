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
for (ch = 0; ch < channels; ch++) {
    const uint8_t *pi = in[ch];
    uint8_t *po = out + ch * out_bps;
    for (int i = 0; i < len; i++) {
        int32_t sample;
        float converted;

        // Introduce temporary with explicit dependency chain (RAW: read after write in same iteration)
        sample = *(const int32_t *)pi;
        converted = sample * (1.F / (1U << 31));
        *(float *)po = converted;

        // Update pointers sequentially (eliminate pointer arithmetic dependency on prior iteration)
        pi += is;
        po += os;
    }
}
}
