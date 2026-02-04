#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (k = 0; k < max_points; k += step) {
        if (points[k] == move) {
            break;
        }
        if (k + 1 < max_points && points[k + 1] == move) {
            k++;
            break;
        }
    }
}
