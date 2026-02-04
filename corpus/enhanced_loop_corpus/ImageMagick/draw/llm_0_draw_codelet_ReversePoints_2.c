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
    size_t outer_i;
    for (outer_i = 0; outer_i < (number_points >> 2); outer_i++) {
        size_t inner_i;
        for (inner_i = 0; inner_i < 2; inner_i++) {
            size_t idx = outer_i * 2 + inner_i;
            if (idx >= (number_points >> 1)) break;
            point = points[idx];
            points[idx] = points[number_points - (idx + 1)];
            points[number_points - (idx + 1)] = point;
        }
    }
}
