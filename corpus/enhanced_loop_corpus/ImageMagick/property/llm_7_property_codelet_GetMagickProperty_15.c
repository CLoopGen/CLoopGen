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
    PointInfo candidate = convex_hull[0];
    for (n = 1; n < (ssize_t)number_points; n++) {
        int x_greater = convex_hull[n].x > candidate.x;
        int x_equal_and_y_less = (convex_hull[n].x == candidate.x) && (convex_hull[n].y < candidate.y);
        if (x_greater || x_equal_and_y_less) {
            candidate = convex_hull[n];
        }
    }
    // Introduce a final update to 'extreme' with WAR dependency resolved
    extreme = candidate;
}
