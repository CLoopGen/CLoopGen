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
    double min_x = point.x;
    double min_y = point.y;
    for (i = 1; i < 4; i++) {
        if (bounding_box[i].x < min_x)
            min_x = bounding_box[i].x;
        if (bounding_box[i].y < min_y)
            min_y = bounding_box[i].y;
    }
    point.x = min_x;
    point.y = min_y;
}
