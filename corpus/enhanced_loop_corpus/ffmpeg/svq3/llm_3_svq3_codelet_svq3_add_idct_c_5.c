#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int16_t *block;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Fixed Offsets
    // Use a constant stride pattern and precomputed offsets for improved predictability
    const int stride = 4;
    const int offsets[4] = {0, 1, 2, 3}; // Logical column indices

    for (i = 0; i < 4; i++) {
        const int base = i * stride;

        const int val0 = block[base + offsets[0]];
        const int val1 = block[base + offsets[1]];
        const int val2 = block[base + offsets[2]];
        const int val3 = block[base + offsets[3]];

        const int z0 = 13 * (val0 + val2);
        const int z1 = 13 * (val0 - val2);
        const int z2 = 7 * val1 - 17 * val3;
        const int z3 = 17 * val1 + 7 * val3;

        block[base + offsets[0]] = z0 + z3;
        block[base + offsets[1]] = z1 + z2;
        block[base + offsets[2]] = z1 - z2;
        block[base + offsets[3]] = z0 - z3;
    }
}
