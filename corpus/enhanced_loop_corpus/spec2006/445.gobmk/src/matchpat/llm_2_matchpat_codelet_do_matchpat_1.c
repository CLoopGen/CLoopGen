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
for (i = m - 1; i <= m + 2; ++i) {
    int base_idx = (19 + 2) + (i) * (19 + 1) + (n - 1);
    for (j = n - 1; j <= n + 2; shift -= 2, ++j) {
        unsigned int this;
        if (!((unsigned int)(i) < (unsigned int)board_size && (unsigned int)(j) < (unsigned int)board_size))
            this = 3;
        else if ((this = board[base_idx + (j - (n - 1))]) == 0)
            continue;
        else if (color == 2)
            this = (1 + 2 - (this));
        merged_val |= (this << shift);
    }
}
}
