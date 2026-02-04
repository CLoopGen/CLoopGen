#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  uint8_t *in;
extern uint64_t v0;
extern uint64_t v1;
extern uint64_t v2;
extern uint64_t v3;
extern uint64_t m;
extern  uint8_t *end;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    uint64_t temp_v0 = v0, temp_v1 = v1, temp_v2 = v2, temp_v3 = v3;
    for (; in != end; in += 8) {
        m = (*((uint64_t *)(in)));
        temp_v3 ^= m;
        temp_v0 += temp_v1;
        temp_v1 = (uint64_t)(((temp_v1) << (13)) | ((temp_v1) >> (64 - (13))));
        temp_v1 ^= temp_v0;
        temp_v0 = (uint64_t)(((temp_v0) << (32)) | ((temp_v0) >> (64 - (32))));
        temp_v2 += temp_v3;
        temp_v3 = (uint64_t)(((temp_v3) << (16)) | ((temp_v3) >> (64 - (16))));
        temp_v3 ^= temp_v2;
        temp_v0 += temp_v3;
        temp_v3 = (uint64_t)(((temp_v3) << (21)) | ((temp_v3) >> (64 - (21))));
        temp_v3 ^= temp_v0;
        temp_v2 += temp_v1;
        temp_v1 = (uint64_t)(((temp_v1) << (17)) | ((temp_v1) >> (64 - (17))));
        temp_v1 ^= temp_v2;
        temp_v2 = (uint64_t)(((temp_v2) << (32)) | ((temp_v2) >> (64 - (32))));
        temp_v0 ^= m;
    }
    v0 = temp_v0; v1 = temp_v1; v2 = temp_v2; v3 = temp_v3;
}
