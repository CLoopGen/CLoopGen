#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo first[3];
PointInfo last[3];
PointInfo point[3];
size_t i;

void init_vars() {
    for (size_t idx = 0; idx < 3; idx++) {
        point[idx].x = (double)(idx + 1) * 1.1;
        point[idx].y = (double)(idx + 1) * 2.2;
        first[idx].x = 0.0;
        first[idx].y = 0.0;
        last[idx].x = 0.0;
        last[idx].y = 0.0;
    }
    i = 0;
}