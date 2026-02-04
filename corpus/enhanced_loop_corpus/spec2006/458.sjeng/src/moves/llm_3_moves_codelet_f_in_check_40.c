#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index array to simulate strided access
    int indices[144];
    int size = 0;
    int start = wking_loc + 11;
    // Precompute indirect access path (strided by 11)
    for (int i = start; i < 144; i += 11) {
        indices[size++] = i;
    }
    // Traverse using indirect addressing
    for (l = 0; l < size && board[indices[l]] == 13; l++)
        ;
    // Map final logical value of l back to the board index
    l = (l < size) ? indices[l] : start + size * 11;
}
