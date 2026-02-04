#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern PointInfo extreme;
extern PointInfo *convex_hull;
extern ssize_t n;
extern size_t number_points;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access via Index Mapping Array
    // Simulate indirect access using a precomputed index permutation (e.g., reverse order access)
    // We assume the index array is created on-stack for demonstration (practical use may require heap or static)
    ssize_t *indices = (ssize_t*)malloc(number_points * sizeof(ssize_t));
    if (!indices) return; // Handle allocation failure

    // Create reverse index mapping: access from last to first
    for (size_t i = 0; i < number_points; i++) {
        indices[i] = (ssize_t)(number_points - 1 - i);
    }

    // Traverse using indirect indexing
    for (n = 0; n < (ssize_t)number_points; n++) {
        ssize_t idx = indices[n]; // Indirect access index
        if (convex_hull[idx].x > extreme.x) {
            extreme = convex_hull[idx];
            continue;
        }
        if (convex_hull[idx].x != extreme.x)
            continue;
        if (convex_hull[idx].y < extreme.y)
            extreme = convex_hull[idx];
    }

    free(indices);
}
