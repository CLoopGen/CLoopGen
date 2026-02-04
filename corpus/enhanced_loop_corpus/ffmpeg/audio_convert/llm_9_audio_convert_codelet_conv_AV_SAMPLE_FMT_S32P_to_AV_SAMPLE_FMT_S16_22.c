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
int total_elements = len * channels;
for (int idx = 0; idx < total_elements; idx++) {
    int ch = idx % channels;
    int i = idx / channels;
    const uint8_t *pi = in[ch];
    uint8_t *po = out + ch * out_bps;
    *(int16_t *)(po + i * os) = (*(const int32_t *)(pi + i * is)) >> 16;
}
}
