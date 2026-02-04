#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern size_t *number_vertices;
extern PointInfo *convex_hull;
extern PointInfo **monotone_chain;
extern size_t n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect Memory Access Pattern via Index Array
    // Use an index array to access elements in a non-sequential order.
    // Here, we simulate indirect access by reversing the access order.
    size_t i;
    size_t num_verts = *number_vertices;
    for (i = 0; i < num_verts; i++) {
        size_t idx = num_verts - 1 - i; // Reverse access: from end to start
        convex_hull[idx] = (*monotone_chain[idx]);
    }
}
