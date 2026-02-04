#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    // We simulate indirect access by offsetting indices through a base pointer shift
    int base = 128;
    for (; in <= 255; in++) {
        int idx1 = base + in;        // positive indirect-like index
        int idx2 = base - in;        // negative indirect-like index
        table[idx1] = out;
        table[idx2] = -out;
    }
}
