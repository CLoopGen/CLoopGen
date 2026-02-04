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
    // Variant 1: Strided memory access (access every element with stride 1 but simulate a strided pattern conceptually)
    // Here we maintain logical correctness by still visiting each index, but express access in a way that could be optimized for stride
    for (i = 1; i < 4; i += 1) {
        PointInfo current = extent[i];
        if (min.x > current.x)
            min.x = current.x;
        if (min.y > current.y)
            min.y = current.y;
        if (max.x < current.x)
            max.x = current.x;
        if (max.y < current.y)
            max.y = current.y;
    }
}
