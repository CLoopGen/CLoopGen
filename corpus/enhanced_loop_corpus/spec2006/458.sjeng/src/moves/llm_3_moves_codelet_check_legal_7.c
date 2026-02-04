#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Pointer Chaining
    int* ptr = &board[bking_loc + 11];
    int** indirect_ptr_array[10]; // Simulate indirect access (limited depth)
    int i;
    for (i = 0; i < 10; ++i) {
        indirect_ptr_array[i] = &ptr;
        if (*ptr != 13) {
            l = (int)(ptr - board);
            return;
        }
        ptr += 11;
    }
    // Fallback to original if deep traversal needed
    for (l = (int)(ptr - board); board[l] == 13; l += 11)
        ;
}
