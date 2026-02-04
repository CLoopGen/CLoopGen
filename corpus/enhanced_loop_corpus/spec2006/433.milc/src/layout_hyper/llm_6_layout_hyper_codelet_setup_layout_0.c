#include <stdio.h>

#include <inttypes.h>

extern int squaresize[4];
extern int j;
extern int dir;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_j = 1;
    int temp_dir = 0;
    for (; temp_dir <= 3; temp_dir++) {
        if (squaresize[temp_dir] > temp_j && squaresize[temp_dir] % 2 == 0) {
            temp_j = squaresize[temp_dir];
        }
    }
    j = temp_j;
}
