#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array to simulate non-linear traversal
    int indices[144];
    for (int i = 0; i < 144; i++)
        indices[i] = (square + 11 + 11 * i) % 144;  // Generate indirect strided access pattern

    int temp_l = square + 11;
    for (int i = 0; temp_l < 144 && board[temp_l] == 13; i++) {
        m++;
        temp_l = indices[i];
    }
}
