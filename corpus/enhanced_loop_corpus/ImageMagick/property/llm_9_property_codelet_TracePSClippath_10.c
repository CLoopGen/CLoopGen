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
        double temp_x = point[idx].x;
        double temp_y = point[idx].y;
        if (i < 3) {
            first[idx].x = temp_x + temp_y;
            first[idx].y = temp_x - temp_y;
        } else {
            last[idx].x = temp_x * temp_y;
            last[idx].y = temp_x / (temp_y + 1e-9); // avoid division by zero
        }
    }
}
