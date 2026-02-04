#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>
#include <stdint.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo extreme;
PointInfo *convex_hull;
ssize_t n;
size_t number_points;

void init_vars() {
    number_points = 20000000; // ~160 MB for PointInfo array (20M * 16 bytes)

    convex_hull = (PointInfo*)aligned_alloc(32, number_points * sizeof(PointInfo));
    if (!convex_hull) {
        exit(1);
    }

    extreme.x = 1e30;
    extreme.y = 1e30;

    for (size_t i = 0; i < number_points; i++) {
        convex_hull[i].x = (double)(rand() % 1000000) / 10.0;
        convex_hull[i].y = (double)(rand() % 1000000) / 10.0;
    }
}