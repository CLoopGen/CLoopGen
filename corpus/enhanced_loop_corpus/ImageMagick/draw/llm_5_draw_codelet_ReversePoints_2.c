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
    for (i = 0; i < (number_points >> 1); i++) {
        size_t j = number_points - (i + 1);
        if (j != i) {
            point = points[i];
            points[i] = points[j];
            points[j] = point;
        }
    }
}
