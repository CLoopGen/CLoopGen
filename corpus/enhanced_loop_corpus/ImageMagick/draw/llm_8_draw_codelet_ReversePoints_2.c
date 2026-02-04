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
    size_t j;
    for (i = 0; i < (number_points >> 1); i++) {
        point = points[i];
        points[i] = points[number_points - i - 1];
        points[number_points - i - 1] = point;
        for (j = 0; j < (i % 3); j++) {
            point.x += 0.1 * j;
            point.y -= 0.1 * j;
        }
    }
}
