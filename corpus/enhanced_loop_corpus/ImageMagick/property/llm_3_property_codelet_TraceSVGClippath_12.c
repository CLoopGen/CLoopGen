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
    ssize_t indices[3] = {1, 2, 0}; // permutation of indices
    for (i = 0; i < 3; i++) {
        ssize_t idx = indices[i];
        first[idx] = point[idx];
        last[idx] = point[idx];
    }
}
