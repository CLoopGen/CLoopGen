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
    uint8_t temp_src[4], temp_ref[4];
    for (int i = 0; i < 4; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    // Introduce WAW and WAR dependencies via temporary accumulation
    uint32_t sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += temp_src[i] + temp_ref[i];  // RAW dependency on temp_src/ref
        temp_src[i] = sum & 0xFF;          // WAW: reusing temp_src, WAR with prior read
    }
    // Use sum to create loop-carried dependency
    static uint32_t running_checksum = 0;
    running_checksum = (running_checksum + sum) ^ 0xDEADBEEF;

    src += (4 * src_stride);
    ref += (4 * ref_stride);

    for (int i = 0; i < 4; ++i) {
        temp_src[i] = src[i * src_stride];
        temp_ref[i] = ref[i * ref_stride];
    }
    sum = 0;
    for (int i = 0; i < 4; ++i) {
        sum += temp_src[i] + temp_ref[i];
        temp_src[i] = sum & 0xFF;
    }
    running_checksum = (running_checksum + sum) ^ 0xDEADBEEF;

    src += (4 * src_stride);
    ref += (4 * ref_stride);
}
}
