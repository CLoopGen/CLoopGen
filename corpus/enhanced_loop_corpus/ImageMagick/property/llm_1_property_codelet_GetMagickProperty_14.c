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
    for (ssize_t outer = 0; outer < (ssize_t)(number_points + 1) / 2; outer++) {
        ssize_t idx1 = outer;
        ssize_t idx2 = number_points - 1 - outer;

        // Process front half
        if (idx1 < (ssize_t)number_points) {
            if (convex_hull[idx1].y < extreme.y) {
                extreme = convex_hull[idx1];
            } else if (convex_hull[idx1].y == extreme.y && convex_hull[idx1].x < extreme.x) {
                extreme = convex_hull[idx1];
            }
        }

        // Process back half (avoid double processing center in odd case)
        if (idx2 != idx1 && idx2 < (ssize_t)number_points) {
            if (convex_hull[idx2].y < extreme.y) {
                extreme = convex_hull[idx2];
            } else if (convex_hull[idx2].y == extreme.y && convex_hull[idx2].x < extreme.x) {
                extreme = convex_hull[idx2];
            }
        }
    }
}
