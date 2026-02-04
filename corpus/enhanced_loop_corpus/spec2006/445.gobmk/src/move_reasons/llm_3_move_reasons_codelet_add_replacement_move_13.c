#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int replacement_map[400];
extern int from;
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use an auxiliary index array to access board and replacement_map indirectly
    // Simulate indirect access using a precomputed permutation (conceptually)
    // Here we simulate it with modular arithmetic as index transformation
    int start = (19 + 2);
    int end = (19 + 1) * (19 + 1);
    int N = end - start;
    for (int i = 0; i < N; i++) {
        // Pseudo-random but deterministic indirect indexing
        pos = start + (i * 101) % N;  // Strided wrap-around for indirect-like access
        if (pos < end && (board[pos] != 3) && replacement_map[pos] == from)
            replacement_map[pos] = replacement_map[from];
    }
}
