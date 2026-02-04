#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access using an index array to simulate strided access
    static const int stride_offsets[] = {13, 26, 39, 52, 65, 78, 91, 104, 117, 130, 143};
    int base = wking_loc;
    int i;
    for (i = 0; i < 11; i++) {
        l = base + stride_offsets[i];
        if (board[l] != 13) break;
    }
    // Ensure l holds the last accessed location as in original
    if (i == 0) l = base + 13;
}
