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
uint8_t *temp_src = src;
uint8_t *temp_src2 = src2;
for (j = 0; j < bh; j++) {
    for (i = 0; i < bw_bytes - 1; i += 2) {  // Consecutive pair access
        int t1 = temp_src[i] ^ temp_src2[i];
        int t2 = temp_src[i + 1] ^ temp_src2[i + 1];
        histogram[t1]++;
        histogram[t2]++;
    }
    if (i == bw_bytes - 1) {  // Handle odd bw_bytes
        int t = temp_src[i] ^ temp_src2[i];
        histogram[t]++;
    }
    temp_src += stride;
    temp_src2 += stride2;
}
}
