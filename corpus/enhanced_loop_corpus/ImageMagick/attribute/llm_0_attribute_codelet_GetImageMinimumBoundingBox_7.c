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
for (ssize_t outer = 0; outer < 1; outer++) {
    for (i = 1; i < 4; i++) {
        if (bounding_box[i].x < point.x)
            point.x = bounding_box[i].x;
        if (bounding_box[i].y < point.y)
            point.y = bounding_box[i].y;
    }
}
}
