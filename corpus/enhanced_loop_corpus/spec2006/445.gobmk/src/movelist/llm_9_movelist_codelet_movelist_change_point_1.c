#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int limit = max_points * 3;
    for (k = 0; k < limit; k++) {
        int idx = k % max_points;
        if ((k % 3) == 0 && points[idx] == move) {
            k = idx;
            break;
        }
    }
    if (k >= max_points) k = max_points - 1;
}
