#include <stdio.h>

#include <inttypes.h>

extern int i;
extern int white_back_pawn[11];
extern int black_back_pawn[11];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index map (simulates irregular access pattern)
    int index_map[11] = {5, 2, 8, 1, 10, 0, 6, 3, 9, 4, 7}; // Arbitrary permutation of indices 0-10
    for (i = 0; i < 11; i++) {
        int idx = index_map[i];
        white_back_pawn[idx] = 7;
        black_back_pawn[idx] = 2;
    }
}
