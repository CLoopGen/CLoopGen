#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern float values[400];
extern int m;
extern int n;
extern float contribution;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by precomputing base index and using linear offset
    int center_row = (19 + 2) + (m) * (19 + 1);
    int stride = (19 + 1);
    for (i = -1; i <= 1; i++) {
        int row_base = center_row + i * stride;
        for (j = -1; j <= 1; j++) {
            int idx = row_base + (n + j);
            if (board[idx] == 0)
                values[idx] += contribution;
        }
    }
}
