#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int16_t *v1;
extern  int16_t *v2;
extern int length;
extern int scaling;
extern int64_t sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Reverse sequential memory access
    // Traverse arrays from the last element to the first
    // This maintains unit stride but changes spatial locality direction
    sum = 0;  // Reset sum for correctness
    for (int i = length - 1; i >= 0; i--) {
        sum += (v1[i] * v2[i]) >> scaling;
    }
}
