#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo *bounding_box;
extern ssize_t i;
extern PointInfo point;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array
    ssize_t indices[] = {3, 1, 2}; // Custom access order
    for (i = 0; i < 3; i++) {
        ssize_t idx = indices[i];
        if (bounding_box[idx].x < point.x)
            point.x = bounding_box[idx].x;
        if (bounding_box[idx].y < point.y)
            point.y = bounding_box[idx].y;
    }
}
