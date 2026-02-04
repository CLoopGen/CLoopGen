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
    // Variant 2: Strided memory access pattern with indirect indexing
    // Use a strided access pattern over a simulated register array with step size > 1
    // Variables are mapped to indices with non-unit stride to change access pattern

    int reg_file[16];  // Expanded register file simulation with padding for striding
    int stride = 4;    // Access every 4th element to create strided pattern

    for (i = 0; i < shift2; i++) {
        // Map logical variables to strided positions in reg_file
        reg_file[0 * stride] = retval;     // reg_file[0]
        reg_file[1 * stride] = bit_mask;   // reg_file[4]
        reg_file[2 * stride] = x;          // reg_file[8]
        reg_file[3 * stride] = bits;       // reg_file[12]

        guess = reg_file[0 * stride] + reg_file[1 * stride];
        accu = (int64_t)guess * guess;
        square = (int)((accu + reg_file[1 * stride]) >> reg_file[3 * stride]);
        if (reg_file[2 * stride] >= square)
            retval += reg_file[1 * stride];
        bit_mask >>= 1;
    }
}
