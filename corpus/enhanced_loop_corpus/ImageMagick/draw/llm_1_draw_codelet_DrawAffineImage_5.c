#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extent[4];
extern PointInfo min;
extern PointInfo max;
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 1; i < 4; i += 2) {
    for (ssize_t j = i; j < i + 2 && j < 4; j++) {
        if (min.x > extent[j].x)
            min.x = extent[j].x;
        if (min.y > extent[j].y)
            min.y = extent[j].y;
        if (max.x < extent[j].x)
            max.x = extent[j].x;
        if (max.y < extent[j].y)
            max.y = extent[j].y;
    }
}
}
