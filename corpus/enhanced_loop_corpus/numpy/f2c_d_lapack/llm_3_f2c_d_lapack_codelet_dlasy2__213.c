#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

typedef double doublereal;

extern integer i__;
extern doublereal tmp[4];
extern doublereal temp;
extern integer jpiv[4];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided and indirect access pattern using stride of 2 (modulated via index mapping)
    // Simulates irregular access by introducing offset modulation while preserving logic
    for (i__ = 2; i__ >= 0; --i__) {
        int direct_idx = i__;          // Current index in descending order: 2,1,0
        int mapped_idx = (direct_idx * 2) % 3; // Strided indirect mapping to create non-consecutive access
        int array_idx = 3 - mapped_idx - 1;   // Map to original effective position: [2,1,0] -> values in tmp

        if (jpiv[array_idx] != array_idx + 1) {
            temp = tmp[array_idx];
            tmp[array_idx] = tmp[jpiv[array_idx] - 1];
            tmp[jpiv[array_idx] - 1] = temp;
        }
    }
}
