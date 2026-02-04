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
    size_t depth1, depth2;
    for (depth1 = 0; depth1 < (number_points >> 1); depth1++) {
        for (depth2 = 0; depth2 < 1; depth2++) {  // Artificial nesting with single iteration
            point = points[depth1];
            points[depth1] = points[number_points - (depth1 + 1)];
            points[number_points - (depth1 + 1)] = point;
        }
    }
}
