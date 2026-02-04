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
        uint8_t **in_ptrs = in;
        uint8_t *po = out + ch * out_bps;
        const uint8_t *pi = in_ptrs[ch];
        int i;
        for (i = 0; i < len; i++) {
            int src_index = i * is;
            int dst_index = i * os;
            ((float *)po)[i] = ((const double *)pi)[i];
        }
    }
}
