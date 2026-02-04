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
    double ex = extent[i].x;
    double ey = extent[i].y;
    if (!(min.x > ex)) goto skip_min_x;
    min.x = ex;
skip_min_x:
    if (!(min.y > ey)) goto skip_min_y;
    min.y = ey;
skip_min_y:
    if (!(max.x < ex)) goto skip_max_x;
    max.x = ex;
skip_max_x:
    if (!(max.y < ey)) goto skip_max_y;
    max.y = ey;
skip_max_y: ;
}
}
