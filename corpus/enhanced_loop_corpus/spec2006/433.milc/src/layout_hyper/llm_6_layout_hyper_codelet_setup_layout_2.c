#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_dir = -1;
    for (int i = 0; i <= 3; i++) {
        if (squaresize[i] == j) {
            temp_dir = i;
            break;
        }
    }
    dir = temp_dir; // Introduce WAW dependency: write to 'dir' after loop
}
