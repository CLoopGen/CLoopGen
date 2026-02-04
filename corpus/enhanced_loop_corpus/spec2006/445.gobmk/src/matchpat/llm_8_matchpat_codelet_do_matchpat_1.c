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
    int stride = (19 + 1);
    int base_offset = (19 + 2) + m * stride + n;
    shift = 6; // Initialize shift to control bit placement

    for (i = m - 1; i <= m + 1; ++i) {  // Reduced trip count: from 4 to 3 iterations
        int row_base = base_offset + (i - m) * stride;
        for (j = n - 1; j <= n + 1; ++j) {  // Reduced inner trip count: from 4 to 3
            unsigned int this;
            int idx = row_base + (j - n);

            // Combined bounds check with early skip
            if ((unsigned int)i >= (unsigned int)board_size || (unsigned int)j >= (unsigned int)board_size) {
                this = 3;
            } else {
                this = board[idx];
                if (this == 0) continue;
                if (color == 2)
                    this = 3 - this;  // Simplified transformation: 1 <-> 2 when color==2
            }
            merged_val |= (this << shift);
            shift -= 2;
        }
    }
}
