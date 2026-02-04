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
        const uint8_t **input_ptrs = (const uint8_t **)malloc(len * sizeof(uint8_t *));
        uint8_t *output_base = out + ch * out_bps;
        for (int i = 0; i < len; i++) {
            input_ptrs[i] = in[ch] + i * is;
        }
        for (int i = 0; i < len; i++) {
            const uint8_t *pi = input_ptrs[i];
            uint8_t *po = output_base + i * os;
            *(int16_t *)po = (*(const uint8_t *)pi - 128) << 8;
        }
        free(input_ptrs);
    }
}
