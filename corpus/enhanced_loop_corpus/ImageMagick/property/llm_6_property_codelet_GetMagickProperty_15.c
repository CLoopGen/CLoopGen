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
    PointInfo temp_extreme = extreme;
    for (n = 0; n < (ssize_t)number_points; n++) {
        if (convex_hull[n].x > temp_extreme.x) {
            temp_extreme = convex_hull[n];
        } else if (convex_hull[n].x == temp_extreme.x) {
            if (convex_hull[n].y < temp_extreme.y) {
                temp_extreme = convex_hull[n];
            }
        }
    }
    extreme = temp_extreme;
}
