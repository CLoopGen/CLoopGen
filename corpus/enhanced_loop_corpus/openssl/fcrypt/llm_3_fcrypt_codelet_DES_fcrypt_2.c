#include <stdio.h>

#include <inttypes.h>

extern  unsigned char cov_2char[64];
extern char *ret;
extern unsigned int i;
extern unsigned int j;
extern unsigned int y;
extern unsigned char bb[9];
extern unsigned char c;
extern unsigned char u;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (Index Array-Based) Memory Access Pattern
    // Use a precomputed index map to read bits from non-sequential positions in bb[]
    // This simulates indirect access via an index array that defines custom traversal order.
    static const unsigned char access_order[48] = {
        0,0,0,0,0,0, 1,1,1,1,1,1, 2,2,2,2,2,2, 3,3,3,3,3,3,
        4,4,4,4,4,4, 5,5,5,5,5,5, 6,6,6,6,6,6, 7,7,7,7,7,7
    }; // Each byte accessed 6 times consecutively — indirect but structured
    static const unsigned char bit_masks[6] = {128, 64, 32, 16, 8, 4}; // Fixed sequence of masks

    for (i = 2; i < 13; i++) {
        c = 0;
        for (j = 0; j < 6; j++) {
            unsigned int idx = (i - 2) * 6 + j; // Map loop iteration to access index
            y = access_order[idx];             // Indirect byte selection
            u = bit_masks[j];                  // Deterministic bit within byte
            c <<= 1;
            if (bb[y] & u)
                c |= 1;
        }
        ret[i] = cov_2char[c];
    }
}
