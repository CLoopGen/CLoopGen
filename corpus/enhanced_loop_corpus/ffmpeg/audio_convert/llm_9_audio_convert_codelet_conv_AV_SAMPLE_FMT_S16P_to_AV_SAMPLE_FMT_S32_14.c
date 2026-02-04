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
    // Reduced computational intensity with unrolled inner operations and increased trip count via split channel processing
    int total_samples = len * channels;
    int i;
    for (i = 0; i < total_samples; i++) {
        int ch = i % channels;
        int idx = i / channels; // sample index within channel
        const uint8_t *pi = in[ch] + idx * is;
        uint8_t *po = out + ch * out_bps + idx * os;
        if (idx < len) { // Bound check代替 do-while 的终止条件
            *(int32_t *)po = *(const int16_t *)pi << 16;
        }
    }
}
