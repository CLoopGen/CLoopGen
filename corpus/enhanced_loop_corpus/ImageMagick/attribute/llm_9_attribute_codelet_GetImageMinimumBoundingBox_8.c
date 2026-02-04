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
    for (i = 0; i < 2; i++) {
        PointInfo temp1, temp2;
        temp1.x = bounding_box[2*i].x - point.x;
        temp1.y = bounding_box[2*i].y - point.y;
        temp2.x = bounding_box[2*i+1].x - point.x;
        temp2.y = bounding_box[2*i+1].y - point.y;
        bounding_box[2*i] = temp1;
        bounding_box[2*i+1] = temp2;
    }
}
