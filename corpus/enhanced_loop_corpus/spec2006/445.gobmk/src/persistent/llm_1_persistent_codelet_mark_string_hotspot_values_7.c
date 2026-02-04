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
    if (board[((19 + 2) + (m + i) * (19 + 1) + (n + 0))] == 0)
        values[((19 + 2) + (m + i) * (19 + 1) + (n + 0))] += contribution;
for (i = -1; i <= 1; i++)
    if (board[((19 + 2) + (m + i) * (19 + 1) + (n + 1))] == 0)
        values[((19 + 2) + (m + i) * (19 + 1) + (n + 1))] += contribution;
for (i = -1; i <= 1; i++)
    if (board[((19 + 2) + (m + i) * (19 + 1) + (n + (-1)))] == 0)
        values[((19 + 2) + (m + i) * (19 + 1) + (n + (-1)))] += contribution;
}
