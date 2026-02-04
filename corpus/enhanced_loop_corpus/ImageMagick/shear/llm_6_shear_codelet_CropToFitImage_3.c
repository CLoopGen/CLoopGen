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
    PointInfo temp_min = min;
    PointInfo temp_max = max;
    for (i = 1; i < 4; i++) {
        temp_min.x = (temp_min.x > extent[i].x) ? extent[i].x : temp_min.x;
        temp_min.y = (temp_min.y > extent[i].y) ? extent[i].y : temp_min.y;
        temp_max.x = (temp_max.x < extent[i].x) ? extent[i].x : temp_max.x;
        temp_max.y = (temp_max.y < extent[i].y) ? extent[i].y : temp_max.y;
    }
    min = temp_min;
    max = temp_max;
}
