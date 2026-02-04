#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (r = 1; r < num_moves && r < 362; r += 2) {
        int diff = distances[r] - distances[0];
        if (diff > 1500)
            break;
    }
}
