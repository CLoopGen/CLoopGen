#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int nsquares[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (dir = 0; dir <= 3; dir += 2) {
        if (squaresize[dir] == j && nsquares[dir] > 1) {
            break;
        }
        if (dir + 1 <= 3 && squaresize[dir + 1] == j && nsquares[dir + 1] > 1) {
            dir++; 
            break;
        }
    }
}
