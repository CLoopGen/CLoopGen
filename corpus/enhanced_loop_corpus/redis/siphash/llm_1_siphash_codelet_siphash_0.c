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
    for (; in + 8 <= end; in += 8) {
        for (int unroll_factor = 0; unroll_factor < 1; ++unroll_factor) {
            m = (*((uint64_t *)(in)));
            v3 ^= m;
            v0 += v1;
            v1 = (uint64_t)(((v1) << (13)) | ((v1) >> (64 - (13))));
            v1 ^= v0;
            v0 = (uint64_t)(((v0) << (32)) | ((v0) >> (64 - (32))));
            v2 += v3;
            v3 = (uint64_t)(((v3) << (16)) | ((v3) >> (64 - (16))));
            v3 ^= v2;
            v0 += v3;
            v3 = (uint64_t)(((v3) << (21)) | ((v3) >> (64 - (21))));
            v3 ^= v0;
            v2 += v1;
            v1 = (uint64_t)(((v1) << (17)) | ((v1) >> (64 - (17))));
            v1 ^= v2;
            v2 = (uint64_t)(((v2) << (32)) | ((v2) >> (64 - (32))));
            v0 ^= m;
        }
    }
}
