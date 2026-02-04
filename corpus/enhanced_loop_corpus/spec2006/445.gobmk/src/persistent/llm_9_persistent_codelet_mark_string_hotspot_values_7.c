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
for (i = 0; i <= 2; i += 2)
    for (j = 0; j <= 2; j += 2)
        if (board[((19 + 2) + (m + i - 1) * (19 + 1) + (n + j - 1))] == 0)
            values[((19 + 2) + (m + i - 1) * (19 + 1) + (n + j - 1))] += contribution;
}
