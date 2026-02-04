#include <stdio.h>

#include <inttypes.h>

extern int reg_alloc_order[53];
extern int pos;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-sequential writes
    int indices[8];
    int base = ((20 + 1) + 7) + 1;
    for (int j = 0; j < 8; j++) {
        indices[j] = j; // Store sequential indices
    }
    for (i = 0; i < 8; i++) {
        reg_alloc_order[pos + indices[i]] = base + i;
    }
    pos += 8; // Update pos after block write
}
