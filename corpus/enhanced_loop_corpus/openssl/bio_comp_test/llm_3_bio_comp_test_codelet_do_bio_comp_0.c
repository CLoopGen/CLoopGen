#include <stdio.h>

#include <inttypes.h>

extern unsigned char *original;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via computed indices)
    // Simulating indirect access by reversing the order of indices (reverse traversal mapped indirectly)
    for (i = 0; i < 32 * 1024; i++) {
        int idx = (32 * 1024 - 1) - i;  // Reverse mapping: indirect-like access pattern
        original[idx] = i & 255;
    }
}
