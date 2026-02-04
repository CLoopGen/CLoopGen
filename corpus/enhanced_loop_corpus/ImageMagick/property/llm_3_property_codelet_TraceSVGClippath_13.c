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
    // Variant 2: Indirect memory access using an index array to simulate scatter/gather pattern
    ssize_t indices[3] = {0, 1, 2};  // Logical index mapping (could be rearranged for more complex patterns)
    for (i = 0; i < 3; i++) {
        ssize_t idx = indices[i];
        last[idx] = point[idx];
    }
}
