#include <stdio.h>

#include <inttypes.h>

typedef unsigned long LONG;

extern int i;
extern LONG W[80];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive backward traversal with reversed loop direction
    // Alters memory access pattern by traversing from high to low indices
    // Maintains data dependency safety by reversing the iteration order
    for (i = 79; i >= 16; --i) {
        W[i] = W[i - 3] ^ W[i - 8] ^ W[i - 14] ^ W[i - 16];
    }
}
