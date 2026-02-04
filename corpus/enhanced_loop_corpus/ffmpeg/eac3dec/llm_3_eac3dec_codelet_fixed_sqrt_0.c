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
    // Variant 2: Indirect memory access via pointer array to simulate irregular access pattern
    int* vars[5];
    vars[0] = &retval;
    vars[1] = &bit_mask;
    vars[2] = &guess;
    vars[3] = &square;
    vars[4] = (int*)&accu; // Treat accu's lower part as addressable (conceptual)

    for (i = 0; i < shift2; i++) {
        *vars[2] = *vars[0] + *vars[1];                          // guess = retval + bit_mask
        accu = (int64_t)(*vars[2]) * (*vars[2]);                 // accu = guess * guess
        *vars[3] = (int)((accu + *vars[1]) >> bits);              // square = (accu + bit_mask) >> bits
        if (x >= *vars[3])
            *vars[0] += *vars[1];                                // retval += bit_mask
        *vars[1] >>= 1;                                          // bit_mask >>= 1
    }
}
