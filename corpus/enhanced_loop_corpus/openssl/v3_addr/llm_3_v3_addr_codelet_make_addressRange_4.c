#include <stdio.h>

#include <inttypes.h>

extern unsigned char *max;
extern  int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    // Simulate an index map: indices[i] = i, but accessed indirectly
    // Use a virtual offset table concept without declaring extra global arrays
    for (i = length; i > 0; --i) {
        int idx = i - 1; // indirect index computation (could be extended with lookup table)
        if (max[idx] != 255) break;
    }
}
