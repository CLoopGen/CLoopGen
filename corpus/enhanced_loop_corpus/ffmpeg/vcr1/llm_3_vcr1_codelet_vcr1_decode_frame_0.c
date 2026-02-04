#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct VCR1Context {
    int delta[16];
    int offset[4];
} VCR1Context;

extern VCR1Context * a;
extern  uint8_t *bytestream;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory write using pointer arithmetic for coalesced access
    int *delta_ptr = a->delta;
    for (i = 0; i < 16; i++) {
        *delta_ptr++ = *bytestream;
        bytestream += 2; // Read every second byte, but write deltas consecutively
    }
}
