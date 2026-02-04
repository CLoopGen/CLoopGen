#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index mapping array (simulating indirect pattern)
    int indices[4] = {1, 3, 0, 2};  // Custom access order
    for (dir = 0; dir <= 3; dir++)
        if (squaresize[indices[dir]] == j)
            break;
}
