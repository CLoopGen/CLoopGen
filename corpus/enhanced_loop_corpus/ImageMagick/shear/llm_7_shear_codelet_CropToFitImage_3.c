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
    double min_x = min.x, min_y = min.y;
    double max_x = max.x, max_y = max.y;
    for (i = 1; i < 4; i++) {
        double ex_x = extent[i].x;
        double ex_y = extent[i].y;
        if (min_x > ex_x)
            min_x = ex_x;
        if (min_y > ex_y)
            min_y = ex_y;
        if (max_x < ex_x)
            max_x = ex_x;
        if (max_y < ex_y)
            max_y = ex_y;
    }
    min.x = min_x;
    min.y = min_y;
    max.x = max_x;
    max.y = max_y;
}
