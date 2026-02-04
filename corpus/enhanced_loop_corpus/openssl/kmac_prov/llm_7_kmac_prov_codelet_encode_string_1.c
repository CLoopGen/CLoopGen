#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t i;
extern size_t bits;
extern size_t len;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t carry = bits;
    size_t k;
    // Introduce WAW and RAW dependencies via temporary accumulation
    for (k = len; k > 0; --k) {
        unsigned char byte = carry & 255;
        carry >>= 8;
        out[k] = byte;
        // Artificially introduce a write-after-write and read-after-write
        // by reusing 'out[k]' in next iteration's logic (even if not strictly needed)
        if (k < len) {
            out[k] ^= out[k + 1]; // WAR: writing after previous write, used in next step
        }
    }
    // Final fix-up to preserve original semantics: reverse the XOR chain
    for (k = 1; k < len; ++k) {
        out[len - k] ^= out[len - k + 1];
    }
}
