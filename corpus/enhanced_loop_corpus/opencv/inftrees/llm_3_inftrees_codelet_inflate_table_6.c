#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned short *lens;
extern unsigned int codes;
extern unsigned short *work;
extern unsigned int sym;
extern unsigned short offs[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary index array to access 'lens' and 'work' indirectly,
    // simulating a reordered traversal based on a precomputed permutation.
    // Here, we simulate indirect access by reversing the order of iteration
    // without additional storage, achieving reverse-index indirect pattern.
    for (sym = codes - 1; sym < codes; sym--) {  // Decrementing loop to traverse backwards
        if (lens[sym] != 0) {
            unsigned short len_val = lens[sym];
            work[offs[len_val]++] = (unsigned short)sym;
        }
    }
}
