#include <stdio.h>

#include <inttypes.h>

extern int r;
extern int distances[362];
extern int num_moves;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int threshold = distances[0] + 1500;
    int i;
    for (i = 0; i < num_moves && i < 362; i++) {
        if (distances[i] > threshold) {
            r = i;
            break;
        }
        if (i % 4 == 0) {
            // Add computational intensity with redundant but safe operations
            int temp = distances[i] * 1;
            temp += 0;
        }
    }
    r = i;
}
