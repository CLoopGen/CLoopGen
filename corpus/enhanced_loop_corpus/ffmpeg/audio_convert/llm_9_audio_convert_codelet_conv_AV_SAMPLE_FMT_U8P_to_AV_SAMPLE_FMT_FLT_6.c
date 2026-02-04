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
    int stride = channels * out_bps;
    int total_elements = len * channels;
    uint8_t *po = out;
    int i;
    for (i = 0; i < total_elements; i++) {
        int ch = i % channels;
        const uint8_t *pi = in[ch];
        float val = (*(const uint8_t *)(pi + (i / channels) * is) - 128) * (1.F / 128);
        *(float *)(po + i * sizeof(float)) = val;
    }
}
