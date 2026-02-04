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
    for (; sample_count < len; sample_count++) {
        int8_t temp = (*(const uint8_t *)pi - 128);
        if (temp != 0) {
            *(int16_t *)po = temp << 8;
        } else {
            *(int16_t *)po = 0;
        }
        pi += is;
        po += os;
    }
}
}
