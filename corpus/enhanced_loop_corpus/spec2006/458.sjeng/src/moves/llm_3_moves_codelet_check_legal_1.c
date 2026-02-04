#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided access with increased stride and boundary check to avoid overflow
    const int stride = 24; // Larger stride for sparser access
    for (l = bking_loc + 12; l < 144 && board[l] == 13; l += stride)
        ;
}
