#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with offset adjustment
    // Instead of strided access (every 12th element backwards), we use a local array-like traversal
    // by mapping the same logical operation over a transformed index set.
    int base = wking_loc / 12;
    for (l = (base - 1) * 12 + (wking_loc % 12); l >= 0 && board[l] == 13; l -= 12)
        ;
}
