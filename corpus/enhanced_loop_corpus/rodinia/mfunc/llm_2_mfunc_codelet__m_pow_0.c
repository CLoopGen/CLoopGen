#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int p;
extern int max_bit;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory-like access simulation using a step greater than 1
    // Though no actual array is present, we simulate a strided progression in bit checking
    for (max_bit = 0; ; max_bit += 2) {  // Stride of 2
        if ((p >> (max_bit + 1)) == 0) {
            max_bit -= (max_bit > 0); // Adjust to ensure correct final value when overshooting
            break;
        }
        if ((p >> (max_bit + 2)) == 0) { // Check next stride boundary early
            max_bit++; // Step by one more if needed
            break;
        }
    }
}
