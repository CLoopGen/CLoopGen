#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo first[3];
extern PointInfo last[3];
extern PointInfo point[3];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 6; i++) {
    ssize_t idx = i % 3;
    double dx = point[idx].x;
    double dy = point[idx].y;
    first[idx].x += dx * dx;
    first[idx].y += dy * dy;
    last[idx].x = first[idx].x;
    last[idx].y = first[idx].y;
}
}
