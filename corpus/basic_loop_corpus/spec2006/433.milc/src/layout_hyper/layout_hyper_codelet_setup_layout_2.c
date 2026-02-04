#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (dir = 0; dir <= 3; dir++)
    if (squaresize[dir] == j)
        break;

}
