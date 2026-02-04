#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic offset)
    int *indirect_base = &board[square + 1];
    for (int idx = 0; indirect_base[idx * 3] == 13; idx++)
        m++;
}
