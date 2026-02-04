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
for (i = -1; i <= 1; i++)
    for (j = -1; j <= 1; j++)
        if (board[((19 + 2) + (m + i) * (19 + 1) + (n + j))] == 0)
            values[((19 + 2) + (m + i) * (19 + 1) + (n + j))] += contribution;

}
