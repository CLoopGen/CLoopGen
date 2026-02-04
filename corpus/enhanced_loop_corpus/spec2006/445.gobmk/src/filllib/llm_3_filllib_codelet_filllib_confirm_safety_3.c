#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int delta[8];
extern Intersection board[421];
extern int move;
extern int color;
extern int k;
extern int apos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive Array-Like Access Using Offset Vector
    // Precompute the addresses to enable consecutive-like memory access pattern
    Intersection *b = board;
    const int *d = delta;
    int base = move;
    // Unroll and restructure to promote potential vectorization or cache coherence
    // Access is now based on direct offset calculation in sequence
    int offsets[4];
    for (int i = 0; i < 4; i++) {
        offsets[i] = base + d[i + 4];
    }
    for (int i = 0; i < 4; i++) {
        if (b[offsets[i]] == color) {
            apos = offsets[i];
            break;
        }
    }
}
