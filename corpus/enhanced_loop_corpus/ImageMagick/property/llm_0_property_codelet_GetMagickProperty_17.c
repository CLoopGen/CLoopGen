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
    for (ssize_t i = 0; i < (ssize_t)number_points; i++) {
        if (convex_hull[i].x < extreme.x) {
            extreme = convex_hull[i];
            continue;
        }
        if (convex_hull[i].x != extreme.x)
            continue;
        if (convex_hull[i].y > extreme.y)
            extreme = convex_hull[i];
    }
}
