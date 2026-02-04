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
    double acc_x = 0.0, acc_y = 0.0;
    for (i = 0; i < 4; i++) {
        acc_x += bounding_box[i].x;
        acc_y += bounding_box[i].y;
    }
    for (i = 0; i < 4; i++) {
        bounding_box[i].x = (acc_x / 4.0) - point.x;
        bounding_box[i].y = (acc_y / 4.0) - point.y;
    }
}
