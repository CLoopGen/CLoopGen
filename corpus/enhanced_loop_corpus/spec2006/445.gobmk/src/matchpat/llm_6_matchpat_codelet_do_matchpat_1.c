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
    int temp_shift = shift; // Introduce local copy to modify data dependency
    for (i = m - 1; i <= m + 2; ++i) {
        int row_base = (19 + 2) + i * (19 + 1); // Hoist invariant calculation
        for (j = n - 1; j <= n + 2; ++j, temp_shift -= 2) {
            unsigned int this;
            if (!((unsigned int)(i) < (unsigned int)board_size && (unsigned int)(j) < (unsigned int)board_size)) {
                this = 3;
            } else {
                int index = row_base + j;
                this = board[index];
                if (this == 0)
                    continue;
                if (color == 2)
                    this = (1 + 2 - this);
            }
            merged_val |= (this << temp_shift); // WAW dependency now on merged_val is preserved but shift decoupled
        }
    }
    shift = temp_shift; // Update original shift only after loop (introduces loop-carried WAW on shift)
}
