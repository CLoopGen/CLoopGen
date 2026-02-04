#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp_dist = distances[0] + 1500;
    for (r = 0; r < num_moves; r++) {
        if (distances[r] > temp_dist) {
            break;
        }
    }
}
