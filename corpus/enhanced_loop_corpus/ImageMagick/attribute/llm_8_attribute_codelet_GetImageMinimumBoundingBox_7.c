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
    for (i = 1; i < 7; i += 2) {
        double temp_x = bounding_box[i % 4].x;
        double temp_y = bounding_box[i % 4].y;
        if (temp_x < point.x)
            point.x = temp_x;
        if (temp_y < point.y)
            point.y = temp_y;
    }
}
