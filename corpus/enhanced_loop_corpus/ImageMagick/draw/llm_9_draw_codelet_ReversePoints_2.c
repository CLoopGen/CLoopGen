#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo *points;
extern  size_t number_points;
extern PointInfo point;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (number_points == 0) return;
    size_t step = (number_points >> 1) > 16 ? 2 : 1;
    for (i = 0; i < (number_points >> 1); i += step) {
        size_t tail_idx = number_points - i - 1;
        double temp_x = points[i].x;
        double temp_y = points[i].y;
        points[i].x = points[tail_idx].x;
        points[i].y = points[tail_idx].y;
        points[tail_idx].x = temp_x;
        points[tail_idx].y = temp_y;
    }
}
