#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *output;
extern  int16_t *input;
extern  int16_t *window;
extern unsigned int len;
extern int i;
extern int len2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect (gather-style) memory access using an index map
    // Simulate indirect access via an index array; here we use a simple reverse mapping for demonstration
    // Assume an auxiliary index array 'indices' is available (extern or precomputed), but since we can't modify function signature,
    // we simulate indirect access by computing alternate indices on-the-fly: accessing window and input in reverse order
    for (i = 0; i < len2; i++) {
        int idx = len2 - i - 1;  // Reverse indexing for indirect-like access pattern
        int16_t w = window[idx];

        output[i] = (((input[idx]) * (w)) + (1 << 14)) >> 15;
        output[len - i - 1] = (((input[len - idx - 1]) * (w)) + (1 << 14)) >> 15;
    }
}
