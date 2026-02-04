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
    if (number_points > 0) {
        n = 0;
        for (; n < (ssize_t)number_points; ) { // Reduced effective loop structure with manual increment (simulates altered control flow)
            if (convex_hull[n].x > extreme.x) {
                extreme = convex_hull[n];
            } else if (convex_hull[n].x == extreme.x && convex_hull[n].y < extreme.y) {
                extreme = convex_hull[n];
            }
            n++; // Manual increment to simulate flatter decision logic
        }
    }
}
