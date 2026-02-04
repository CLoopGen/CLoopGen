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
    // Variant 2: Strided Memory Access Pattern
    // Introduce a strided access over an array to simulate non-unit stride memory behavior.
    // Here, we use a larger buffer and access every 4th element to create stride-4 access.
    int buffer[128]; // Larger buffer to allow striding
    const int stride = 4;
    for (i = 0; i < shift2; i++) {
        guess = retval + bit_mask;
        buffer[i * stride] = guess; // Strided write: indices 0, 4, 8, ...
        accu = (int64_t)buffer[i * stride] * buffer[i * stride];
        square = (int)((accu + bit_mask) >> bits);
        if (x >= square)
            retval += bit_mask;
        bit_mask >>= 1;
    }
}
