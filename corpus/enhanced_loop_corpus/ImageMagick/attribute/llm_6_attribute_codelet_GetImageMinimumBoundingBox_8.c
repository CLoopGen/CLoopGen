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
    double px = point.x;
    double py = point.y;
    for (i = 0; i < 4; i++) {
        double temp_x = bounding_box[i].x - px;
        double temp_y = bounding_box[i].y - py;
        bounding_box[i].x = temp_x;
        bounding_box[i].y = temp_y;
    }
}
