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
    for (i = 1; i < 4; i++) {
        double x_val = extent[i].x;
        double y_val = extent[i].y;

        // Introduce temporary variables to break direct WAW and RAW dependencies
        // by decoupling loads from stores. This reduces loop-carried dependencies
        // and allows more compiler optimizations.

        double new_min_x = (min.x > x_val) ? x_val : min.x;
        double new_min_y = (min.y > y_val) ? y_val : min.y;
        double new_max_x = (max.x < x_val) ? x_val : max.x;
        double new_max_y = (max.y < y_val) ? y_val : max.y;

        min.x = new_min_x;
        min.y = new_min_y;
        max.x = new_max_x;
        max.y = new_max_y;
    }
}
