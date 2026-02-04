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
    size_t i;
    for (i = 1; i < *number_vertices; i++) {
        convex_hull[i] = (*monotone_chain[i-1]);
    }
    if (*number_vertices > 0) {
        convex_hull[0] = (*monotone_chain[0]);
    }
}
