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
    // Variant 2: Indirect memory access using an index map (simulated via fixed offset array)
    // Define a reverse access order through an index lookup table (kept local for clarity)
    int index_map[16];
    for (int j = 0; j < 16; j++) {
        index_map[j] = 15 - j; // Reverse mapping: 15,14,...,0
    }
    carry_next = 0;
    for (i = 0; i < 16; i++) {
        int mapped_idx = index_map[i];
        carry_next = in[mapped_idx] >> (8 - shift);
        out[mapped_idx] = (in[mapped_idx] << shift) | carry;
        carry = carry_next;
    }
}
