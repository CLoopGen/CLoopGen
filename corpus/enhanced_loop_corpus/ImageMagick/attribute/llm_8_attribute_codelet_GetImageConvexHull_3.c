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
    for (n = 0; n < *number_vertices; n += 2) {
        if (n + 1 < *number_vertices) {
            convex_hull[n] = (*monotone_chain[n]);
            convex_hull[n + 1] = (*monotone_chain[n + 1]);
        } else {
            convex_hull[n] = (*monotone_chain[n]);
        }
    }
}
