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
    for (j = n - 1; j <= n + 2; shift -= 2, ++j) {
        unsigned int this;
        if ((unsigned int)(i) < (unsigned int)board_size && (unsigned int)(j) < (unsigned int)board_size) {
            this = board[((19 + 2) + (i) * (19 + 1) + (j))];
            if (this != 0) {
                if (color == 2) {
                    this = (1 + 2 - this);
                }
                merged_val |= (this << shift);
            }
        } else {
            this = 3;
            merged_val |= (this << shift);
        }
    }
}
}
