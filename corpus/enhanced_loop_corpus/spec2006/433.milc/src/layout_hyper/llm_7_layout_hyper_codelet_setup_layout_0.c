#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int local_j = 1;
    for (dir = 0; dir <= 3; dir++) {
        int prev_j = local_j;
        if (squaresize[dir] > local_j && squaresize[dir] % 2 == 0) {
            local_j = squaresize[dir];
        }
        // Introduce artificial WAW and WAR dependency via dummy use of previous value
        if (prev_j == local_j) {
            local_j += 0; // No-op to maintain dependency pattern
        }
    }
    j = local_j;
}
