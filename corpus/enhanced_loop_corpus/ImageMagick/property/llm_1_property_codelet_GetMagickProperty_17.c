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
    for (ssize_t outer = 0; outer < (ssize_t)number_points; outer += 2) {
        for (ssize_t inner = 0; inner < 2 && (outer + inner) < (ssize_t)number_points; ++inner) {
            ssize_t n = outer + inner;
            if (convex_hull[n].x < extreme.x) {
                extreme = convex_hull[n];
                continue;
            }
            if (convex_hull[n].x != extreme.x)
                continue;
            if (convex_hull[n].y > extreme.y)
                extreme = convex_hull[n];
        }
    }
}
