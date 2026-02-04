#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int bking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulating indirect addressing pattern)
    // Precomputed indirect indices: assume we traverse elements in a scrambled but deterministic order
    // Here, we simulate indirect access by following a fixed permutation within the valid range
    static const int8_t offset_map[100] = { /* small segment of shuffled increments */
        1, 3, 2, 5, 4, 7, 6, 9, 8, 11,
        10, 13, 12, 15, 14, 17, 16, 19, 18, 21,
        20, 23, 22, 25, 24, 27, 26, 29, 28, 31,
        30, 33, 32, 35, 34, 37, 36, 39, 38, 41,
        40, 43, 42, 45, 44, 47, 46, 49, 48, 51,
        50, 53, 52, 55, 54, 57, 56, 59, 58, 61,
        60, 63, 62, 65, 64, 67, 66, 69, 68, 71,
        70, 73, 72, 75, 74, 77, 76, 79, 78, 81,
        80, 83, 82, 85, 84, 87, 86, 89, 88, 91,
        90, 93, 92, 95, 94, 97, 96, 99, 98, 100
    };
    int temp_l = bking_loc + 1;
    int i = 0;
    for (; i < 100 && temp_l < 144 && board[temp_l] == 13; ++i) {
        temp_l += offset_map[i];
    }
    // Finalize l: if broken due to condition, scan forward from last valid base
    l = temp_l;
    while (l < 144 && board[l] == 13) {
        l++;
    }
}
