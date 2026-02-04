#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

size_t *number_vertices;
PointInfo *convex_hull;
PointInfo **monotone_chain;
size_t n;

void init_vars() {
    const size_t data_size = 16777216; // ~128MB of PointInfo data (16M elements)

    number_vertices = (size_t*)malloc(sizeof(size_t));
    *number_vertices = data_size;

    convex_hull = (PointInfo*)calloc(data_size, sizeof(PointInfo));

    monotone_chain = (PointInfo**)malloc(data_size * sizeof(PointInfo*));
    for (size_t i = 0; i < data_size; ++i) {
        PointInfo* pt = (PointInfo*)malloc(sizeof(PointInfo));
        pt->x = (double)(i * 2);
        pt->y = (double)(i * 2 + 1);
        monotone_chain[i] = pt;
    }
}