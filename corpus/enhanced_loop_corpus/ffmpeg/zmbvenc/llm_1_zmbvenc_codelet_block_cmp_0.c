#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int stride;
extern uint8_t *src2;
extern int stride2;
extern int bh;
extern int i;
extern int j;
extern uint16_t histogram[256];
extern int bw_bytes;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int j_offset = 0;
for (j = 0; j < bh * bw_bytes; j++) {
    int i_inner = j % bw_bytes;
    int j_inner = j / bw_bytes;
    if (i_inner == 0 && j_inner > 0) {
        j_offset += stride;
    }
    int t = src[j_offset + i_inner] ^ src2[j_offset + i_inner];
    histogram[t]++;
}
}
