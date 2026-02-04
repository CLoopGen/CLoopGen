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
    // Variant 2: Indirect Memory Access via Index Remapping
    // Use a fixed index remapping table to alter access order to delta array
    // This changes memory access pattern to non-sequential: e.g., 3,1,2,0
    const int index_map[4] = {3, 1, 2, 0};
    for (k = 0; k < 4; k++) {
        int mapped_index = index_map[k];
        if (board[move + 2 * delta[mapped_index]] == color) {
            apos = move + 2 * delta[mapped_index];
            break;
        }
    }
}
