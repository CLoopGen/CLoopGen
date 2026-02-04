#include <stdio.h>

#include <inttypes.h>

typedef unsigned char Intersection;

extern Intersection board[421];
extern int under_control[400];
extern int distance[400];
extern int pos;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    for (i = (19 + 2); i < (19 + 1) * (19 + 1); i++) {
        pos = i;
        if (!(board[pos] != 3))
            continue;
        else if (distance[pos] == -1)
            under_control[pos] = 0;
        else
            under_control[pos] = 1;
    }
}
