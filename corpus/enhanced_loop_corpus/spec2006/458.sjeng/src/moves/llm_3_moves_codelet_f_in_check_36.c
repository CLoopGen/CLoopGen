#include <stdio.h>

#include <inttypes.h>

extern int board[144];
extern int wking_loc;
extern int l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Array
    // Use an auxiliary array of valid indices that follow the original stride pattern
    // (e.g., wking_loc+12, wking_loc+24, ... up to bounds) and iterate through them indirectly.
    // This simulates indirect access while preserving functional behavior.

    static const int stride_offsets[] = {
        12, 24, 36, 48, 60, 72, 84, 96, 108, 120, 132, 144, 156, 168, 180, 192
    };
    int num_steps = sizeof(stride_offsets) / sizeof(stride_offsets[0]);
    int temp_l;
    for (int i = 0; i < num_steps; ++i) {
        temp_l = wking_loc + stride_offsets[i];
        if (board[temp_l] != 13) {
            l = temp_l;
            break;
        }
        if (i == num_steps - 1) {
            l = temp_l;
        }
    }
}
