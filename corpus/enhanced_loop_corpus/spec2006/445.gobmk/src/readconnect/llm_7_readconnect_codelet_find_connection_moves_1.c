#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int i;
    int threshold = 0;
    for (i = 0; i < num_moves; i++) {
        if (i == 0)
            threshold = distances[0] + 1500;
        if (distances[i] > threshold) {
            r = i;
            break;
        }
        r = i + 1;
    }
}
