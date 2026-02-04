#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t (*temp);
extern int16_t * bak;
extern int sum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index array
    // Simulates irregular access pattern via precomputed indices
    int indices[64];
    for (int j = 0; j < 64; j++) {
        indices[j] = 63 - j; // Reverse order access
    }
    sum = 0;
    for (i = 0; i < 64; i++) {
        int idx = indices[i];
        sum += (temp[idx] - bak[idx]) * (temp[idx] - bak[idx]);
    }
}
