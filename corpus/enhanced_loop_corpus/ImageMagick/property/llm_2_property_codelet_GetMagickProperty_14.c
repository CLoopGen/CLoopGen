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
    // Variant 1: Strided memory access (stride of 2)
    for (n = 0; n < (ssize_t)number_points; n += 2) {
        if (convex_hull[n].y < extreme.y) {
            extreme = convex_hull[n];
            continue;
        }
        if (convex_hull[n].y != extreme.y)
            continue;
        if (convex_hull[n].x < extreme.x)
            extreme = convex_hull[n];
    }
    // Handle remaining element if number_points is odd
    if (number_points > 0 && (number_points % 2) == 1) {
        ssize_t last_idx = number_points - 1;
        if (convex_hull[last_idx].y < extreme.y) {
            extreme = convex_hull[last_idx];
        } else if (convex_hull[last_idx].y == extreme.y && convex_hull[last_idx].x < extreme.x) {
            extreme = convex_hull[last_idx];
        }
    }
}
