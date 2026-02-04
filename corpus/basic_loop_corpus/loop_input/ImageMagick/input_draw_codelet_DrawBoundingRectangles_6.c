#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _SegmentInfo {
    double x1;
    double y1;
    double x2;
    double y2;
} SegmentInfo;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _EdgeInfo {
    SegmentInfo bounds;
    double scanline;
    PointInfo *points;
    size_t number_points;
    ssize_t direction;
    MagickBooleanType ghostline;
    size_t highwater;
} EdgeInfo;

typedef struct _PolygonInfo {
    EdgeInfo *edges;
    size_t number_edges;
} PolygonInfo;

PolygonInfo *polygon_info;
ssize_t i;
SegmentInfo bounds;

void init_vars() {
    const size_t num_edges = 5000000;  // Adjusted to achieve ~0.01s runtime

    // Allocate edges array
    EdgeInfo *edges = (EdgeInfo *)calloc(num_edges, sizeof(EdgeInfo));
    if (!edges) exit(1);

    // Initialize each edge with valid bounds
    for (size_t idx = 0; idx < num_edges; idx++) {
        edges[idx].bounds.x1 = 1000.0 + (double)(idx % 800);
        edges[idx].bounds.y1 = 1000.0 + (double)((idx * 7) % 600);
        edges[idx].bounds.x2 = 1200.0 + (double)((idx * 3) % 800);
        edges[idx].bounds.y2 = 1200.0 + (double)((idx * 5) % 600);
        edges[idx].scanline = 0.0;
        edges[idx].points = NULL;
        edges[idx].number_points = 0;
        edges[idx].direction = 1;
        edges[idx].ghostline = MagickFalse;
        edges[idx].highwater = 0;
    }

    // Allocate and initialize polygon_info
    polygon_info = (PolygonInfo *)malloc(sizeof(PolygonInfo));
    if (!polygon_info) exit(1);

    polygon_info->edges = edges;
    polygon_info->number_edges = num_edges;

    // Initialize bounds to extreme values to ensure updates in loop
    bounds.x1 = 2000.0;
    bounds.y1 = 2000.0;
    bounds.x2 = -1000.0;
    bounds.y2 = -1000.0;
}