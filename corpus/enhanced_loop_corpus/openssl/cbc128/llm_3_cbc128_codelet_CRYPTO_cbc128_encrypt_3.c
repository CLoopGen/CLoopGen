#include <stdio.h>

#include <inttypes.h>

extern unsigned char *out;
extern size_t n;
extern  unsigned char *iv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse consecutive memory access — traverse the array from high to low address
    // Maintains unit stride but reverses iteration order, accessing elements in descending index order
    for (size_t i = 15; n < 16 && i >= 0; --i) {
        out[i] = iv[i];
        if (i == 0) break; // Prevent underflow on unsigned size_t when i reaches 0
    }
}
