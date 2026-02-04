#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern int bits;
extern int retval;
extern int bit_mask;
extern int guess;
extern int square;
extern int i;
extern int64_t accu;
extern int shift2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern using a strided array traversal (stride of 2)
    // Simulate strided access by operating on a virtual "array" with step size
    int temp_buffer[128];  // Larger buffer to allow strided access
    int stride = 2;
    for (i = 0; i < shift2; i++) {
        guess = retval + bit_mask;
        accu = (int64_t)guess * guess;
        square = (int)((accu + bit_mask) >> bits);
        // Write to buffer with strided index
        temp_buffer[i * stride] = square;  // Strided write
        if (x >= temp_buffer[i * stride])
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
