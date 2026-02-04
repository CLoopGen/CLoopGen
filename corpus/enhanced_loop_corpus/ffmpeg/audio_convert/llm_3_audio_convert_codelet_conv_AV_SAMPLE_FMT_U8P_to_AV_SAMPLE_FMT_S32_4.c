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
        uint8_t **output_ptrs = (uint8_t **)malloc(len * sizeof(uint8_t *));
        int i;
        for (i = 0; i < len; i++) {
            input_ptrs[i] = in[ch] + i * is;
            output_ptrs[i] = out + ch * out_bps + i * os;
        }
        for (i = 0; i < len; i++) {
            *(int32_t *)output_ptrs[i] = (*(const uint8_t *)input_ptrs[i] - 128) << 24;
        }
        free(input_ptrs);
        free(output_ptrs);
    }
}
