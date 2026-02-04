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
    // Variant 2: Indirect memory access using an index array to simulate indirect addressing
    // This introduces a level of indirection in array access, typical in gather operations
    ssize_t indices[3] = {0, 1, 2}; // Indirect indices, could be dynamic in real use cases
    for (i = 0; i < 3; i++) {
        ssize_t idx = indices[i]; // Load index indirectly
        first[idx] = point[idx];
        last[idx] = point[idx];
    }
}
