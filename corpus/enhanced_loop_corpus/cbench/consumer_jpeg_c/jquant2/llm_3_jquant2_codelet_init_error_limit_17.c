#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate irregular access pattern
    // Simulate an auxiliary index mapping without requiring additional inputs
    int offset = 128;
    for (; in < ((255 + 1) / 16) * 3; in++, out += (in & 1) ? 0 : 1) {
        int idx = (in * in + 3 * in + 1) % 256; // Pseudo-random index generation within bounds
        table[idx + offset] = out;
        table[-(idx + offset)] = -out;
    }
}
