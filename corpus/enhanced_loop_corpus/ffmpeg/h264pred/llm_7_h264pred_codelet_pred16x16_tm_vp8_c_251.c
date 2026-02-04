#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern ptrdiff_t stride;
extern  uint8_t *cm;
extern uint8_t *top;
extern int y;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
uint8_t prev_src_val = 0;
for (y = 0; y < 16; y++) {
    uint8_t key = src[-1] ^ prev_src_val;
    const uint8_t *cm_in = cm + key;
    prev_src_val = 0;
    src[0] = cm_in[top[0]];
    prev_src_val ^= src[0];
    src[1] = cm_in[top[1]];
    prev_src_val ^= src[1];
    src[2] = cm_in[top[2]];
    prev_src_val ^= src[2];
    src[3] = cm_in[top[3]];
    prev_src_val ^= src[3];
    src[4] = cm_in[top[4]];
    prev_src_val ^= src[4];
    src[5] = cm_in[top[5]];
    prev_src_val ^= src[5];
    src[6] = cm_in[top[6]];
    prev_src_val ^= src[6];
    src[7] = cm_in[top[7]];
    prev_src_val ^= src[7];
    src[8] = cm_in[top[8]];
    prev_src_val ^= src[8];
    src[9] = cm_in[top[9]];
    prev_src_val ^= src[9];
    src[10] = cm_in[top[10]];
    prev_src_val ^= src[10];
    src[11] = cm_in[top[11]];
    prev_src_val ^= src[11];
    src[12] = cm_in[top[12]];
    prev_src_val ^= src[12];
    src[13] = cm_in[top[13]];
    prev_src_val ^= src[13];
    src[14] = cm_in[top[14]];
    prev_src_val ^= src[14];
    src[15] = cm_in[top[15]];
    prev_src_val ^= src[15];
    src += stride;
}
}
