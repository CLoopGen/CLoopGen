#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index lookup table (simulated via arithmetic)
    int limit = ((255 + 1) / 16) * 3;
    for (; in < limit; in++, out += (in & 1) ? 0 : 1) {
        // Use a scrambled but deterministic index (e.g., bit-reversal inspired for variation)
        int shifted = (in << 4) & 0xFF; // Create non-linear access pattern
        table[shifted] = out;
        table[-shifted] = -out;
    }
}
