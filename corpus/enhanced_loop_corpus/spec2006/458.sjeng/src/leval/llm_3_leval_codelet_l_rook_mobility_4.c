#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access with offset indexing (flattened traversal)
    // Convert the original decrement-by-12 (column-like) access into a forward consecutive scan
    // Simulate same logical behavior by iterating upward in steps but using modulo arithmetic to mimic vertical alignment
    int base = (square - 12) % 12; // column index
    for (int col_offset = 0; ; col_offset += 12) {
        l = base + col_offset;
        if (l >= 144 || board[l] != 13) break;
        m++;
    }
    // Adjust l to reflect final position like original (optional restoration)
    l = base + (m * 12);
}
