#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo last[3];
extern PointInfo point[3];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 6; i++) {
        ssize_t idx = i / 2;
        if (idx < 3) {
            last[idx].x += point[idx].x;
            last[idx].y += point[idx].y;
        }
    }
}
