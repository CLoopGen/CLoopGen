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
    // Variant 1: Strided memory access with stride of 2
    for (i = 1; i < 4; i += 2) {
        if (bounding_box[i].x < point.x)
            point.x = bounding_box[i].x;
        if (bounding_box[i].y < point.y)
            point.y = bounding_box[i].y;
    }
    // Handle potential middle element if stride skips it
    if (2 < 4 && bounding_box[2].x < point.x)
        point.x = bounding_box[2].x;
    if (2 < 4 && bounding_box[2].y < point.y)
        point.y = bounding_box[2].y;
}
