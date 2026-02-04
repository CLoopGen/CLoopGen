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
        const uint8_t **input_ptrs = in;
        uint8_t *output_block = out + ch * out_bps;
        int i;
        for (i = 0; i < len; i++) {
            const uint8_t *pi = input_ptrs[ch] + i * is;
            uint8_t *po = output_block + i * os;
            *(uint8_t *)po = (*(const int16_t *)pi >> 8) + 128;
        }
    }
}
