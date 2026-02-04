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
    size_t doubled_count = *number_vertices * 2;
    for (n = 0; n < doubled_count; n += 2) {
        size_t idx = n / 2;
        if (idx < *number_vertices) {
            convex_hull[idx] = (*monotone_chain[idx]);
        }
    }
}
