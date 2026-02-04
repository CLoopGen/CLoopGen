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
    PointInfo temp = point;
    for (i = 1; i < 4; i++) {
        double new_x = temp.x;
        double new_y = temp.y;
        if (bounding_box[i].x < temp.x)
            new_x = bounding_box[i].x;
        if (bounding_box[i].y < temp.y)
            new_y = bounding_box[i].y;
        temp.x = new_x;
        temp.y = new_y;
    }
    point = temp;
}
