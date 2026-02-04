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
    if (*number_vertices > 0) {
        n = 0;
        for (size_t step = 0; step < *number_vertices; step++, n++) {
            convex_hull[n] = (*monotone_chain[n]);
        }
    }
}
