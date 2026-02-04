#include <stdio.h>

#include <inttypes.h>

extern  unsigned char *pass;
extern size_t passlen;
extern unsigned char *p;
extern size_t Plen;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping
    // Use a precomputed index array to access 'pass' in a shuffled order (simulated here with arithmetic)
    // Simulate indirect access by using a permutation function: (i * 7) % passlen as index into pass
    for (i = 0; i < Plen; i++) {
        size_t indirect_idx = (i * 7 + 1) % passlen; // Linear congruential mapping for variation
        *p++ = pass[indirect_idx];
    }
}
