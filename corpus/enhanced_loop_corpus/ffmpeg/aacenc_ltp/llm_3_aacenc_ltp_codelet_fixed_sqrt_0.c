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
    // Use a fixed stride (e.g., 4) in accessing pre-allocated arrays to simulate non-unit strides
    // This could model scenarios where data is interleaved or padded.
    
    const int stride = 4;
    int buffer_size = shift2 * stride;
    
    int* strided_retval = (int*)alloca(buffer_size * sizeof(int));
    int* strided_bit_mask = (int*)alloca(buffer_size * sizeof(int));
    int* strided_guess = (int*)alloca(buffer_size * sizeof(int));
    int* strided_square = (int*)alloca(buffer_size * sizeof(int));
    int64_t* strided_accu = (int64_t*)alloca(buffer_size * sizeof(int64_t));

    for (i = 0; i < shift2; i++) {
        int idx = i * stride;  // Strided index

        strided_retval[idx] = (i == 0) ? retval : strided_retval[(i-1)*stride] + strided_bit_mask[(i-1)*stride];
        strided_bit_mask[idx] = (i == 0) ? bit_mask : strided_bit_mask[(i-1)*stride] >> 1;
        strided_guess[idx] = strided_retval[idx] + strided_bit_mask[idx];
        strided_accu[idx] = (int64_t)strided_guess[idx] * strided_guess[idx];
        strided_square[idx] = (int)((strided_accu[idx] + strided_bit_mask[idx]) >> bits);

        if (x >= strided_square[idx])
            strided_retval[idx] += strided_bit_mask[idx];
    }

    // Update final values to preserve external state
    retval = strided_retval[(shift2 - 1) * stride];
    bit_mask = strided_bit_mask[(shift2 - 1) * stride] >> 1;
}
