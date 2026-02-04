#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    int indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = j; // Populate index array in reverse logic not applied, but enables indirect access
    }
    for (i = 0; i < 64; i++) {
        int idx = indices[i]; // Use indirect indexing
        sum += ((block[idx]) >= 0 ? (block[idx]) : (-(block[idx])));
    }
}
