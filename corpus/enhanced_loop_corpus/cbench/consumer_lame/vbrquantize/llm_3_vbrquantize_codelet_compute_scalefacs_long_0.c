#include <stdio.h>

#include <inttypes.h>

typedef double FLOAT8;

extern int pretab[];
extern int sfb;
extern FLOAT8 sf[21];
extern int ifqstep_inv;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping table
    // Simulate indirect access via a fixed offset map (e.g., reverse traversal order within bounds)
    static const int index_map[10] = {20,19,18,17,16,15,14,13,12,11}; // Reverse order for sfb from 11 to 20
    for (int i = 0; i < 10; i++) {
        sfb = index_map[i];
        if (sf[sfb] + pretab[sfb] / ifqstep_inv > 0)
            break;
    }
}
