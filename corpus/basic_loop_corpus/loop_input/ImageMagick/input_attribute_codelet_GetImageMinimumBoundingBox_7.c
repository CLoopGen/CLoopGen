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
    // Allocate bounding_box with 5 elements to safely access index 1..3
    bounding_box = (PointInfo*)calloc(5, sizeof(PointInfo));
    
    // Initialize bounding_box values
    for (int idx = 0; idx < 5; idx++) {
        bounding_box[idx].x = 100.0 + idx * 10.0;
        bounding_box[idx].y = 200.0 + idx * 15.0;
    }
    
    // Initialize point to values larger than bounding_box[1..3] to ensure updates
    point.x = 999.0;
    point.y = 888.0;
}