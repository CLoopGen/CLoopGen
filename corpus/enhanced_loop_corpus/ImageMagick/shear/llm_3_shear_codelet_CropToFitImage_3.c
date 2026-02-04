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
    // Variant 2: Indirect memory access using an index array to alter access pattern
    // Define a fixed indirect access sequence (e.g., reorder traversal: 3,1,2)
    ssize_t indices[3] = {3, 1, 2};
    for (i = 0; i < 3; i++) {
        ssize_t idx = indices[i]; // Indirect access via lookup
        if (min.x > extent[idx].x)
            min.x = extent[idx].x;
        if (min.y > extent[idx].y)
            min.y = extent[idx].y;
        if (max.x < extent[idx].x)
            max.x = extent[idx].x;
        if (max.y < extent[idx].y)
            max.y = extent[idx].y;
    }
}
