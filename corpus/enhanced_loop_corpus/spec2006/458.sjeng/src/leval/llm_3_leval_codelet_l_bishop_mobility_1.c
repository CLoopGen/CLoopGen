#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 2: Consecutive memory access using an index remapping (indirect-like access via offset array)
    // Simulate non-uniform access through a lookup table for indirect indexing
    static const int8_t offsets[] = {0, -11, -22, -33, -44, -55, -66, -77, -88, -99, -110, -121};
    int num_offsets = sizeof(offsets) / sizeof(offsets[0]);
    int temp_l = square - 11;
    int idx = 0;
    for (; idx < num_offsets; idx++) {
        l = temp_l + offsets[idx];
        if (board[l] != 13) break;
        m++;
    }
}
