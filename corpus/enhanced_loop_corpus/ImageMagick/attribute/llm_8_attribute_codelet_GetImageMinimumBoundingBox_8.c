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
    for (i = 0; i < 8; i++) {
        bounding_box[i % 4].x -= point.x;
        bounding_box[i % 4].y -= point.y;
        bounding_box[i % 4].x *= 1.0 + 1e-6; 
        bounding_box[i % 4].y *= 1.0 + 1e-6; 
    }
}
