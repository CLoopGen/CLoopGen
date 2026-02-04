#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct {
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

extern unsigned char digest[20];
extern SHA1_CTX *context;
extern unsigned int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with temporary array to accumulate digest values
    unsigned char temp_digest[20];
    uint32_t *state = context->state;
    for (i = 0; i < 20; i += 4) {
        uint32_t val = state[i >> 2];
        temp_digest[i]     = (unsigned char)((val >> 24) & 255);
        temp_digest[i + 1] = (unsigned char)((val >> 16) & 255);
        temp_digest[i + 2] = (unsigned char)((val >> 8) & 255);
        temp_digest[i + 3] = (unsigned char)(val & 255);
    }
    // Copy from temp array using forward traversal
    for (i = 0; i < 20; i++) {
        digest[i] = temp_digest[i];
    }
}
