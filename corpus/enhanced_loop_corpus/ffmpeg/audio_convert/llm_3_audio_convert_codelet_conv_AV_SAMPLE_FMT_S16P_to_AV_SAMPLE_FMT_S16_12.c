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
        const uint8_t **input_ptr = (const uint8_t **)in;
        uint8_t *base_out = out + ch * out_bps;
        int sample;
        for (sample = 0; sample < len; sample++) {
            size_t read_index = sample * is;
            size_t write_index = sample * os;
            ((int16_t *)(base_out + write_index))[0] = ((const int16_t *)(input_ptr[ch] + read_index))[0];
        }
    }
}
