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
    if (!(min.x <= ex)) min.x = ex;
    if (!(min.y <= ey)) min.y = ey;
    if (!(max.x >= ex)) max.x = ex;
    if (!(max.y >= ey)) max.y = ey;
}
}
