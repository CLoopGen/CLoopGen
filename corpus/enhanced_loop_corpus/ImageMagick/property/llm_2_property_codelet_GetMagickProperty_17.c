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
    // Variant 1: Strided memory access with stride of 2, unrolling the loop by accessing two elements per iteration
    // This changes the access pattern from sequential to strided, potentially improving cache behavior for certain data sizes
    ssize_t i;
    for (i = 0; i < (ssize_t)number_points; i += 2) {
        ssize_t idx1 = i;
        ssize_t idx2 = i + 1;

        if (idx1 < (ssize_t)number_points) {
            if (convex_hull[idx1].x < extreme.x) {
                extreme = convex_hull[idx1];
                continue;
            }
            if (convex_hull[idx1].x == extreme.x && convex_hull[idx1].y > extreme.y)
                extreme = convex_hull[idx1];
        }

        if (idx2 < (ssize_t)number_points) {
            if (convex_hull[idx2].x < extreme.x) {
                extreme = convex_hull[idx2];
                continue;
            }
            if (convex_hull[idx2].x == extreme.x && convex_hull[idx2].y > extreme.y)
                extreme = convex_hull[idx2];
        }
    }
}
