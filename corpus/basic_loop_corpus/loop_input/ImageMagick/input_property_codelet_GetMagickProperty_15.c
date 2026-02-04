#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <string.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo extreme;
PointInfo *convex_hull;
ssize_t n;
size_t number_points;

void init_vars() {
    number_points = 20000000; // ~20M points, roughly 300MB for PointInfo array

    convex_hull = (PointInfo *)aligned_alloc(64, number_points * sizeof(PointInfo));
    
    if (!convex_hull) {
        exit(1);
    }

    srand((unsigned int)time(NULL));
    
    for (size_t i = 0; i < number_points; i++) {
        convex_hull[i].x = ((double)rand() / RAND_MAX) * 1000.0;
        convex_hull[i].y = ((double)rand() / RAND_MAX) * 1000.0;
    }

    extreme.x = -1.0;
    extreme.y = __builtin_inff();
}