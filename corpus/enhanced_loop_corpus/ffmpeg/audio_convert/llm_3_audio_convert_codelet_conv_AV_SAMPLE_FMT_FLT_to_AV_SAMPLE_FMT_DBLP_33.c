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
        const uint8_t **channel_indices = (const uint8_t **)malloc(len * sizeof(uint8_t *));
        uint8_t **output_ptrs = (uint8_t **)malloc(len * sizeof(uint8_t *));
        int i;
        for (i = 0; i < len; i++) {
            channel_indices[i] = in + ch * in_bps + i * is;
            output_ptrs[i] = out[ch] + i * os;
        }
        for (i = 0; i < len; i++) {
            *(double *)output_ptrs[i] = *(const float *)channel_indices[i];
        }
        free(channel_indices);
        free(output_ptrs);
    }
}
