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
    for (n = 0; n < (ssize_t)number_points; n++) {
        int update = 0;
        if (convex_hull[n].x > extreme.x) {
            update = 1;
        } else if (convex_hull[n].x == extreme.x) {
            if (convex_hull[n].y < extreme.y) {
                update = 1;
            }
        }
        if (update) {
            extreme = convex_hull[n];
        }
    }
}
