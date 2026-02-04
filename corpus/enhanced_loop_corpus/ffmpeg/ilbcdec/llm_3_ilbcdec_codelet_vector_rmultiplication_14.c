#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *win;
extern int length;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using index remapping (bit-reversed indexing)
    // Simulates a bit-reversal permutation commonly used in FFT algorithms
    for (int i = 0; i < length; i++) {
        int rev = 0;
        int temp = i;
        int bits = 0;
        int len = length;

        // Calculate number of bits needed to represent indices
        while (len > 1) {
            bits++;
            len >>= 1;
        }

        // Compute bit-reversed index
        len = 1 << bits; // Restore power-of-2 length
        for (int j = 0; j < bits; j++) {
            rev = (rev << 1) | (temp & 1);
            temp >>= 1;
        }
        rev = rev << (bits - (i ? bits : 0)); // Adjust if leading zeros matter

        // Ensure rev is within bounds
        if (rev >= length) continue;

        out[rev] = (in[i] * win[-i]) >> shift;
    }
}
