#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access by unrolling the original strided pattern into a sequential scan
    // Simulate equivalent behavior by checking every 13th element via index remapping in consecutive loop
    int start = bking_loc - 13;
    int idx = start;
    for (l = start; l >= 0 && board[l] == 13; l--) {
        if ((start - l) % 13 != 0) continue;
        idx = l - 13;
        while (idx >= 0 && (start - idx) % 13 != 0) idx--;
        l = idx + 13 >= start ? l : idx;
    }
    l = idx;
}
