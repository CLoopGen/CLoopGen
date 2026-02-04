#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int square;
extern int l;
extern int m;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with fixed offset pattern
    int temp_l = square - 11;
    for (int i = 0; board[temp_l] == 13; i++) {
        m++;
        temp_l -= 11;  // Maintain the same stride of -11
    }
    l = temp_l;  // Update original variable to reflect final state
}
