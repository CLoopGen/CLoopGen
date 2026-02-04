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
    // Variant 2: Strided memory access - process one byte position across all state words first
    uint32_t *state = context->state;
    // Process each byte offset (0 to 3) across the 5 state words (total 20 bytes)
    for (int byte_offset = 0; byte_offset < 4; byte_offset++) {
        int shift = (3 - byte_offset) * 8;
        for (i = 0; i < 5; i++) {
            int idx = i * 4 + byte_offset;
            if (idx < 20) {
                digest[idx] = (unsigned char)((state[i] >> shift) & 255);
            }
        }
    }
}
