#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int temp = -1;
    for (k = 0; k < max_points; k++) {
        if (points[k] == move) {
            temp = k;
            break;
        }
    }
    if (temp != -1)
        k = temp;
}
