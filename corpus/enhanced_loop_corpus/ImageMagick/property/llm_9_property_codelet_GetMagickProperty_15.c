#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extreme;
extern PointInfo *convex_hull;
extern ssize_t n;
extern size_t number_points;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    double extreme_x = extreme.x;
    double extreme_y = extreme.y;
    ssize_t update_flag = 0;

    for (n = 0; n < (ssize_t)number_points; n++) {
        double dx = convex_hull[n].x - extreme_x;
        double dy = convex_hull[n].y - extreme_y;

        if (dx > 0 || (dx == 0 && dy < 0)) {
            extreme_x = convex_hull[n].x;
            extreme_y = convex_hull[n].y;
            update_flag = 1;
        }
    }

    if (update_flag) {
        extreme.x = extreme_x;
        extreme.y = extreme_y;
    }
}
