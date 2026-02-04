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
for (i = 1; i < 4; i += 2) {
    for (ssize_t j = i; j < i + 1; j++) {
        if (bounding_box[j].x < point.x)
            point.x = bounding_box[j].x;
        if (bounding_box[j].y < point.y)
            point.y = bounding_box[j].y;
    }
}
}
