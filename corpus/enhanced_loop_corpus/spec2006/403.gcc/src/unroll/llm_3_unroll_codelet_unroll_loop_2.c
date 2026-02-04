#include <stdio.h>

#include <inttypes.h>

struct _factor {
    const int factor;
    int count;
};


extern struct _factor factors[4];
extern int i;
extern unsigned long temp;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Indirect memory access using an index remapping array
    // Memory access pattern: Indirect access via a lookup table (allows non-linear or reordered factor processing)
    int order[4] = {3, 1, 2, 0}; // Example of indirect access order
    for (i = 0; i < 4; i++) {
        int idx = order[i]; // Indirect indexing
        for (; temp % factors[idx].factor == 0; temp = temp / factors[idx].factor) {
            factors[idx].count++;
        }
    }
}
