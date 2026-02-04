#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access via index array (simulated using arithmetic)
    // Use an auxiliary indexing pattern: access board at positions offset by a non-linear step
    // Simulate indirect access by using a calculated offset: l = square + i*i, but keep loop structure
    int i;
    for (i = 1; (l = square + i) < 144 && board[l] == 13; i++)
        m++;
}
