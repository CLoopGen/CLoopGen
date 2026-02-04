#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int found = 0;
    for (int i = 0; i <= 3 && !found; i++) {
        dir = i; // Introduce loop-carried WAW: each iteration overwrites 'dir'
        if (squaresize[i] == j) {
            found = 1; // Create RAW dependency: 'found' read after write in same iteration
        }
    }
}
