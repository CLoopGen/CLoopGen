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
    ssize_t i;
    for (n = 0; n < (ssize_t)number_points; n += 2) {
        for (i = 0; i < 2 && (n + i) < (ssize_t)number_points; i++) {
            ssize_t idx = n + i;
            if (convex_hull[idx].x > extreme.x) {
                extreme = convex_hull[idx];
            } else if (convex_hull[idx].x == extreme.x && convex_hull[idx].y < extreme.y) {
                extreme = convex_hull[idx];
            }
        }
    }
}
