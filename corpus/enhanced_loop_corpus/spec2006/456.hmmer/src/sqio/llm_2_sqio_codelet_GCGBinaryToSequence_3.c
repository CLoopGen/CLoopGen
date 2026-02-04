#include <stdio.h>

#include <inttypes.h>

extern char *seq;
extern int len;
extern int bpos;
extern int spos;
extern char twobit;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with reversed iteration order
    // Instead of processing each 4-bit chunk in reverse within the inner loop,
    // we precompute indices and write in forward consecutive order using a single loop.
    int total_chars = len;
    for (int idx = 0; idx < total_chars; idx++) {
        int src_index = idx / 4;          // Which byte in seq contains the 2-bit code
        int bit_offset = (3 - (idx % 4)) * 2; // Bit position within the byte (descending)
        char encoded = seq[src_index];
        char two_bit = (encoded >> bit_offset) & 3;
        switch (two_bit) {
            case 0:
                seq[idx] = 'C';
                break;
            case 1:
                seq[idx] = 'T';
                break;
            case 2:
                seq[idx] = 'A';
                break;
            case 3:
                seq[idx] = 'G';
                break;
        }
    }
}
