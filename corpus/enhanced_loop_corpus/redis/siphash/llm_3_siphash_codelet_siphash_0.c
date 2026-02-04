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



void loop() {
    // Variant 2: Consecutive dual-load access – process two consecutive 8-byte chunks per iteration
    uint8_t *ptr = in;
    const uint8_t *limit = end - 15;  // Ensure at least two full 8-byte blocks

    for (; ptr <= limit; ptr += 16) {
        // Load two consecutive 64-bit values
        uint64_t m1 = (*(uint64_t *)(ptr));
        uint64_t m2 = (*(uint64_t *)(ptr + 8));

        // First round with m1
        v3 ^= m1;
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
        v0 ^= m1;

        // Second round with m2
        v3 ^= m2;
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
        v0 ^= m2;
    }

    // Process remaining bytes normally if any (single 8-byte block left)
    for (; ptr < end - 7; ptr += 8) {
        m = (*(uint64_t *)(ptr));
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
