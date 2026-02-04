#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo *bounding_box;
ssize_t i;
PointInfo point;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to ensure loop runtime
    bounding_box = aligned_alloc(32, data_size);
    if (!bounding_box) {
        exit(1);
    }

    for (size_t idx = 0; idx < (data_size / sizeof(PointInfo)); ++idx) {
        bounding_box[idx].x = (double)(idx + 1);
        bounding_box[idx].y = (double)(-(idx + 1));
    }

    point.x = 100.0;
    point.y = 200.0;
}