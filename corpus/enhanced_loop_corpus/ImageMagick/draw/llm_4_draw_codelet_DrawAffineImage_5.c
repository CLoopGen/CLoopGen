#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extent[4];
extern PointInfo min;
extern PointInfo max;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 4; i++) {
    min.x = (min.x > extent[i].x) ? extent[i].x : min.x;
    min.y = (min.y > extent[i].y) ? extent[i].y : min.y;
    max.x = (max.x < extent[i].x) ? extent[i].x : max.x;
    max.y = (max.y < extent[i].y) ? extent[i].y : max.y;
}
}
