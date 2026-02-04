#include <stdio.h>

#include <inttypes.h>

extern int board_size;
extern int m;
extern int n;
extern int left_corner[19];
extern int top_row;
extern char mn[400];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Eliminate loop-carried dependency by unrolling assumption and scanning row-major without early outer break
    int local_found = 0;
    for (m = 0; m < board_size && !local_found; m++) {
        for (n = 0; n < board_size && !local_found; n++) {
            int index = (19 + 2) + m * (19 + 1) + n;
            if (mn[index]) {
                // RAW dependency: left_corner and top_row depend on current m, n, and mn
                left_corner[0] = index;
                top_row = m;
                local_found = 1;  // Introduce local control to remove direct loop-carried dependency via global state
            }
        }
    }
    // No further propagation beyond first occurrence due to flag-based exit
}
