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
    // Variant 1: Strided memory access (access every second element in a padded pattern)
    // We assume the bounding_box array has at least 7 elements to allow striding safely
    for (i = 0; i < 7; i += 2) {
        if (i < 4) {
            bounding_box[i].x -= point.x;
            bounding_box[i].y -= point.y;
        }
    }
}
