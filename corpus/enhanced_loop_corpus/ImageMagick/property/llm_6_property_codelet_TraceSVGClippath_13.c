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
    PointInfo temp[3];
    for (i = 0; i < 3; i++) {
        temp[i] = point[i];
    }
    for (i = 0; i < 3; i++) {
        last[i] = temp[i];
    }
}
