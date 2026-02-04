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
    for (i = 1; i < 4; i++) {
        PointInfo curr = bounding_box[i];
        point.x = (curr.x < point.x) ? curr.x : point.x;
        point.y = (curr.y < point.y) ? curr.y : point.y;
    }
}
