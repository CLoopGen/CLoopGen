#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *out;
extern  int16_t *in;
extern  int16_t *coef;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic offset)
    // Using indirect pattern: accessing elements based on a transformed index (reverse traversal)
    for (i = 1; i < length; i++) {
        int idx = length - 1 - i;  // Reverse indexing
        out[idx] = (coef[idx] * in[idx] + 16384) >> 15;
    }
}
