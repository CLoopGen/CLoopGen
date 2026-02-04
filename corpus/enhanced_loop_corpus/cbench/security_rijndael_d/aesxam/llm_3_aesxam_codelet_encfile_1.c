#include <stdio.h>

#include <inttypes.h>

extern char inbuf[16];
extern char outbuf[16];
extern unsigned long i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index remapping (reverse order)
    unsigned long indices[16];
    for (i = 0; i < 16; ++i) {
        indices[i] = 15 - i; // reverse access pattern
    }
    for (i = 0; i < 16; ++i) {
        unsigned long j = indices[i];
        inbuf[j] ^= outbuf[j];
    }
}
