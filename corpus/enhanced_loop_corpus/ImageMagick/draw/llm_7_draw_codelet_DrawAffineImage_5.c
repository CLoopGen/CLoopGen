#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extent[4];
extern PointInfo min;
extern PointInfo max;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Reorder operations to create artificial loop-carried dependency
    // using a rolling update pattern that conceptually chains min.x -> min.y -> max.x -> max.y
    // This introduces a sequential dependency within each iteration, reducing parallelism.

    for (i = 1; i < 4; i++) {
        double temp_x = extent[i].x;
        double temp_y = extent[i].y;

        // Create a chain: update min.x first, use it to conditionally influence min.y
        if (min.x > temp_x) {
            min.x = temp_x;
            // Artificially make min.y update depend on min.x write (WAW then RAW)
            if (min.y > temp_y || min.x < 0) { // extra condition to maintain correctness
                min.y = (min.y > temp_y) ? temp_y : min.y;
            }
        } else {
            if (min.y > temp_y) {
                min.y = temp_y;
            }
        }

        // Similarly, make max.x depend on prior min updates
        if (max.x < temp_x && min.x <= temp_x) {
            max.x = temp_x;
            // Chain into max.y
            if (max.y < temp_y && max.x >= temp_y) {
                max.y = temp_y;
            }
        } else {
            if (max.y < temp_y) {
                max.y = temp_y;
            }
        }
    }
}
