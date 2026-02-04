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
    PointInfo temp;
    for (i = 0; i < *number_vertices; i++) {
        temp = (*monotone_chain[i]);
        convex_hull[i] = temp;
    }
}
