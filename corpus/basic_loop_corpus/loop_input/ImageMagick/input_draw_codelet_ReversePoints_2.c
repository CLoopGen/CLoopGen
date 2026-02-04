#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo *points;
size_t number_points;
PointInfo point;
size_t i;

void init_vars() {
    number_points = 16777216; // ~256MB of data: 16777216 * 16 bytes per PointInfo
    points = (PointInfo*)aligned_alloc(32, number_points * sizeof(PointInfo));
    if (!points) {
        exit(1);
    }
    for (size_t idx = 0; idx < number_points; idx++) {
        points[idx].x = (double)(idx + 1);
        points[idx].y = (double)(-(idx + 1));
    }
}