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
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    // This introduces an indirection vector that maps iteration order to actual array indices
    ssize_t indices[3] = {1, 2, 3}; // indirect mapping for i = 1,2,3
    for (i = 0; i < 3; i++) {
        PointInfo current = extent[indices[i]];
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
