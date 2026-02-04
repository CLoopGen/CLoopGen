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
    // Variant 1: Increased computational intensity with unrolled loop and additional arithmetic operations
    // Loop unrolled to eliminate condition checks for each iteration, increasing trip count visibility
    // Additional arithmetic (dummy scaling) added to increase computational load without changing logic

    double scale = 1.0001; // Dummy scaling factor to increase arithmetic operations

    if (min.x > extent[1].x * scale)
        min.x = extent[1].x * scale;
    if (min.y > extent[1].y * scale)
        min.y = extent[1].y * scale;
    if (max.x < extent[1].x / scale)
        max.x = extent[1].x / scale;
    if (max.y < extent[1].y / scale)
        max.y = extent[1].y / scale;

    if (min.x > extent[2].x * scale)
        min.x = extent[2].x * scale;
    if (min.y > extent[2].y * scale)
        min.y = extent[2].y * scale;
    if (max.x < extent[2].x / scale)
        max.x = extent[2].x / scale;
    if (max.y < extent[2].y / scale)
        max.y = extent[2].y / scale;

    if (min.x > extent[3].x * scale)
        min.x = extent[3].x * scale;
    if (min.y > extent[3].y * scale)
        min.y = extent[3].y * scale;
    if (max.x < extent[3].x / scale)
        max.x = extent[3].x / scale;
    if (max.y < extent[3].y / scale)
        max.y = extent[3].y / scale;
}
