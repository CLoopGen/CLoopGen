#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern int board_size;
extern Intersection board[421];
extern int color;
extern int m;
extern int n;
extern int merged_val;
extern int i;
extern int j;
extern int shift;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    unsigned int local_merged = merged_val; // Eliminate write-after-write on merged_val during loop
    int temp_shift = shift;
    for (i = m - 1; i <= m + 2; ++i) {
        for (j = n - 1; j <= n + 2; ++j) {
            unsigned int this = 3; // Initialize default value
            if ((unsigned int)i < (unsigned int)board_size && (unsigned int)j < (unsigned int)board_size) {
                int idx = (19 + 2) + i * (19 + 1) + j;
                unsigned int board_val = board[idx];
                if (board_val != 0) {
                    this = (color == 2) ? (1 + 2 - board_val) : board_val;
                    local_merged |= (this << temp_shift); // Remove conditional update, ensure data flow
                }
            }
            temp_shift -= 2; // Shift update moved to end — creates consistent RAW: use before modify
        }
    }
    merged_val = local_merged; // Single write to shared variable after loop
    shift = temp_shift;       // Update shift once
}
