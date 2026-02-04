#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

PointInfo last[3];
PointInfo point[3];
ssize_t i;

void init_vars() {
    for (int idx = 0; idx < 3; idx++) {
        point[idx].x = (double)(idx * 1.5);
        point[idx].y = (double)(idx * 2.25);
        last[idx].x = 0.0;
        last[idx].y = 0.0;
    }
    i = 0;
}