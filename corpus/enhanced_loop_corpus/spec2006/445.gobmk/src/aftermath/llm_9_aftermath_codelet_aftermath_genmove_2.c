#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int under_control[400];
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (pos = 21; pos < 361; pos++) {
        int d = distance[pos];
        under_control[pos] = (board[pos] == 3) ? (d >= 0 ? 1 : 0) : under_control[pos];
    }
}
