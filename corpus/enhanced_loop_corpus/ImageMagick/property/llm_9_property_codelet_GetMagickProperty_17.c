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
    double min_x = extreme.x;
    double max_y = extreme.y;
    for (n = 0; n < (ssize_t)number_points; n++) {
        double dx = convex_hull[n].x - min_x;
        if (dx < 0 || (dx == 0 && convex_hull[n].y > max_y)) {
            min_x = convex_hull[n].x;
            max_y = convex_hull[n].y;
            extreme = convex_hull[n];
        }
    }
}
