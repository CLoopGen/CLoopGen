#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo extent[4];
PointInfo min;
PointInfo max;
ssize_t i;

void init_vars() {
    // Initialize extent array with 4 distinct points
    extent[0] = (PointInfo){10.5, 20.3};
    extent[1] = (PointInfo){5.2,  25.7};
    extent[2] = (PointInfo){15.8, 8.9};
    extent[3] = (PointInfo){7.1,  30.2};

    // Initialize min and max with extent[0] values as starting point
    min = extent[0];
    max = extent[0];

    // Initialize loop index
    i = 1;
}