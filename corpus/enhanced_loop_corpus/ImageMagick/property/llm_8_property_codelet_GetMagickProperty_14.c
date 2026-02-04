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
    for (n = 0; n < (ssize_t)number_points; n += 2) {
        if (n + 1 < (ssize_t)number_points) {
            // Process two points per iteration to reduce trip count and increase computational intensity
            PointInfo p1 = convex_hull[n];
            PointInfo p2 = convex_hull[n + 1];

            if (p1.y < extreme.y) {
                extreme = p1;
            } else if (p1.y == extreme.y && p1.x < extreme.x) {
                extreme = p1;
            }

            if (p2.y < extreme.y) {
                extreme = p2;
            } else if (p2.y == extreme.y && p2.x < extreme.x) {
                extreme = p2;
            }
        } else {
            // Handle the last point if number_points is odd
            PointInfo p = convex_hull[n];
            if (p.y < extreme.y) {
                extreme = p;
            } else if (p.y == extreme.y && p.x < extreme.x) {
                extreme = p;
            }
        }
    }
}
