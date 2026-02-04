#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern uint8_t *src;
extern int32_t src_stride;
extern uint8_t *ref;
extern int32_t ref_stride;
extern int32_t height;
extern int32_t ht_cnt;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ht_cnt = (height >> 3); ht_cnt--;) {
    uint8_t temp_src[8], temp_ref[8];
    for (int i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    uint32_t sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += temp_src[i] + temp_ref[i];
    }
    *(volatile uint32_t*)&src[0] = sum; 
    src += (4 * src_stride);
    ref += (5 * ref_stride);
    for (int i = 0; i < 8; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    sum = 0;
    for (int i = 0; i < 8; ++i) {
        sum += temp_src[i] ^ temp_ref[i];
    }
    *(volatile uint32_t*)&ref[0] = sum;
    src += (4 * src_stride);
    ref += (3 * ref_stride);
}
}
