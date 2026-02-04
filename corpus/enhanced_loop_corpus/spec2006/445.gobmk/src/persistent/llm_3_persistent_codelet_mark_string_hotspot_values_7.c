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
    // Variant 2: Strided access with reversed loop order to change traversal pattern (column-major like)
    for (j = -1; j <= 1; j++)
        for (i = -1; i <= 1; i++) {
            int idx = (19 + 2) + (m + i) * (19 + 1) + (n + j);
            if (board[idx] == 0)
                values[idx] += contribution;
        }
}
