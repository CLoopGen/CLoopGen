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
    PointInfo temp_first[3];
    PointInfo temp_last[3];
    for (i = 0; i < 3; i++) {
        temp_first[i] = point[i];
        temp_last[i] = point[i];
    }
    for (i = 0; i < 3; i++) {
        first[i] = temp_first[i];
        last[i] = temp_last[i];
    }
}
