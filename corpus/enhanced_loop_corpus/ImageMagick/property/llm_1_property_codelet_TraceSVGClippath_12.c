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
    for (i = 0; i < 3; i += 2) {
        for (ssize_t j = i; j < i + 2 && j < 3; j++) {
            first[j] = point[j];
            last[j] = point[j];
        }
    }
}
