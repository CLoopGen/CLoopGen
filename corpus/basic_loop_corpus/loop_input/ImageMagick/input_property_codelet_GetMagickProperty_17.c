#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <time.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo extreme;
PointInfo *convex_hull;
ssize_t n;
size_t number_points;

void init_vars() {
    number_points = 16777216; // ~134 MB of data (16M * 8 bytes per point)

    convex_hull = (PointInfo*)aligned_alloc(64, number_points * sizeof(PointInfo));
    if (!convex_hull) {
        exit(1);
    }

    // Seed random generator for realistic data distribution
    srand((unsigned int)(time(NULL) ^ (uintptr_t)&number_points));

    // Initialize convex_hull with pseudo-random values
    for (size_t i = 0; i < number_points; i++) {
        convex_hull[i].x = ((double)rand() / RAND_MAX) * 1000.0;
        convex_hull[i].y = ((double)rand() / RAND_MAX) * 1000.0;
    }

    // Initialize extreme with a value likely to be replaced
    extreme.x = convex_hull[0].x;
    extreme.y = convex_hull[0].y;

    // Ensure at least one point has smaller x or same x and larger y
    size_t idx = rand() % number_points;
    convex_hull[idx].x = -1.0; // Guaranteed to be less than initial
    extreme = convex_hull[idx]; // Reset extreme after modification
}