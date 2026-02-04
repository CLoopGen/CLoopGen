#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *in;
extern size_t shift;
extern unsigned char *out;
extern int i;
extern unsigned char carry;
extern unsigned char carry_next;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (accessing even indices only)
    // The array is traversed backwards but skipping every other element
    carry_next = 0;
    for (i = 14; i >= 0; i -= 2) {
        carry_next = in[i] >> (8 - shift);
        out[i] = (in[i] << shift) | carry;
        carry = carry_next;
    }
    // Handle odd index if needed via secondary pass, but original logic preserved per iteration
    // This variant changes access pattern to strided, reducing total iterations
}
