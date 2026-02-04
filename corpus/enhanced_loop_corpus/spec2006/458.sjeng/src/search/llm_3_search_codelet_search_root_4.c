#include <stdio.h>

#include <inttypes.h>

typedef struct {
    int from;
    int target;
    int captured;
    int promoted;
    int castled;
    int ep;
} move_s;

extern int ply;
extern int pv_length[300];
extern move_s pv[300][300];
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via pointer arithmetic)
    int *indices = &pv_length[ply]; // Base for indirect indexing logic
    for (j = ply; j < pv_length[ply]; j++) {
        int idx = j; // Simulate indirect access (could be from a lookup table in practice)
        pv[ply - 1][idx] = pv[ply][idx];
    }
}
