#include <stdio.h>

#include <inttypes.h>

typedef unsigned int u32;

extern u32 x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Reduced complexity: fewer iterations, simplified operations
    for (i = 10; i > 0; i--) {
        // Only first two rounds executed with reduced shift counts
        (x[0] += x[4], x[12] = (((x[12] ^ x[0]) << 8) | ((x[12] ^ x[0]) >> 24)), x[8] += x[12], x[4] ^= x[8]);
        (x[1] += x[5], x[13] = (((x[13] ^ x[1]) << 8) | ((x[13] ^ x[1]) >> 24)), x[9] += x[13], x[5] ^= x[9]);
        (x[2] += x[6], x[14] = (((x[14] ^ x[2]) << 8) | ((x[14] ^ x[2]) >> 24)), x[10] += x[14], x[6] ^= x[10]);
        (x[3] += x[7], x[15] = (((x[15] ^ x[3]) << 8) | ((x[15] ^ x[3]) >> 24)), x[11] += x[15], x[7] ^= x[11]);

        (x[0] += x[5], x[15] = (((x[15] ^ x[0]) << 8) | ((x[15] ^ x[0]) >> 24)), x[10] += x[15], x[5] ^= x[10]);
        (x[1] += x[6], x[12] = (((x[12] ^ x[1]) << 8) | ((x[12] ^ x[1]) >> 24)), x[11] += x[12], x[6] ^= x[11]);
        (x[2] += x[7], x[13] = (((x[13] ^ x[2]) << 8) | ((x[13] ^ x[2]) >> 24)), x[8] += x[13], x[7] ^= x[8]);
        (x[3] += x[4], x[14] = (((x[14] ^ x[3]) << 8) | ((x[14] ^ x[3]) >> 24)), x[9] += x[14], x[4] ^= x[9]);
    }
}
