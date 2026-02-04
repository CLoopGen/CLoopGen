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
int indices[16];
int idx_count = 0;
for (int di = -1; di <= 2; ++di)
    for (int dj = -1; dj <= 2; ++dj)
        indices[idx_count++] = (19 + 2) + (m + di) * (19 + 1) + (n + dj);

shift = 6; // Reset shift to initial value expected before loop (assuming original starts at 6)
for (int k = 0; k < 16; ++k) {
    int i = (m - 1) + k / 4;
    int j = (n - 1) + k % 4;
    unsigned int this;
    if (!((unsigned int)(i) < (unsigned int)board_size && (unsigned int)(j) < (unsigned int)board_size))
        this = 3;
    else if ((this = board[indices[k]]) == 0) {
        shift -= 2;
        continue;
    }
    else if (color == 2)
        this = (1 + 2 - (this));
    merged_val |= (this << shift);
    shift -= 2;
}
}
