#include <stdio.h>

#include <inttypes.h>

extern int move;
extern int max_points;
extern int points[];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (k = 0; k < max_points; k += 2) {
        if (points[k] == move)
            break;
    }
    // Handle case where max_points is odd and last element was skipped
    if (k >= max_points && (max_points % 2 == 1)) {
        k = max_points - 1;
        if (points[k] == move)
            return;
    }
}
