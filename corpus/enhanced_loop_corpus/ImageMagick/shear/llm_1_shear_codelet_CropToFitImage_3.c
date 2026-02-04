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
// Decreased effective loop depth by unrolling the original loop manually
i = 1;
if (min.x > extent[i].x)
    min.x = extent[i].x;
if (min.y > extent[i].y)
    min.y = extent[i].y;
if (max.x < extent[i].x)
    max.x = extent[i].x;
if (max.y < extent[i].y)
    max.y = extent[i].y;

i = 2;
if (min.x > extent[i].x)
    min.x = extent[i].x;
if (min.y > extent[i].y)
    min.y = extent[i].y;
if (max.x < extent[i].x)
    max.x = extent[i].x;
if (max.y < extent[i].y)
    max.y = extent[i].y;

i = 3;
if (min.x > extent[i].x)
    min.x = extent[i].x;
if (min.y > extent[i].y)
    min.y = extent[i].y;
if (max.x < extent[i].x)
    max.x = extent[i].x;
if (max.y < extent[i].y)
    max.y = extent[i].y;
}
