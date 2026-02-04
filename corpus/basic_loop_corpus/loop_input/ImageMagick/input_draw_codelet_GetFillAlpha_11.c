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
ssize_t x;
ssize_t y;
PointInfo *q;
EdgeInfo *p;
ssize_t i;
ssize_t j;
ssize_t winding_number;

static PointInfo *all_points;
static EdgeInfo *edge_array;
static size_t total_edges = 100000;

void init_vars() {
    all_points = (PointInfo *)calloc(total_edges * 3, sizeof(PointInfo));
    edge_array = (EdgeInfo *)calloc(total_edges, sizeof(EdgeInfo));

    for (size_t idx = 0; idx < total_edges; ++idx) {
        PointInfo *pts = all_points + idx * 3;
        pts[0].x = (double)(idx % 1000);
        pts[0].y = (double)(500 - (idx % 999));
        pts[1].x = (double)(idx % 1000 + 10);
        pts[1].y = (double)(500 - (idx % 999) + 5);
        pts[2].x = (double)(idx % 1000 + 20);
        pts[2].y = (double)(500 - (idx % 999) - 5);

        EdgeInfo *edge = &edge_array[idx];
        edge->bounds.x1 = pts[0].x - 5.0;
        edge->bounds.y1 = pts[0].y - 10.0;
        edge->bounds.x2 = pts[2].x + 5.0;
        edge->bounds.y2 = pts[2].y + 10.0;
        edge->scanline = 0.0;
        edge->points = pts;
        edge->number_points = 3;
        edge->direction = (idx % 2) ? 1 : -1;
        edge->ghostline = MagickFalse;
        edge->highwater = 1;
    }

    polygon_info = (PolygonInfo *)malloc(sizeof(PolygonInfo));
    polygon_info->edges = edge_array;
    polygon_info->number_edges = total_edges;

    x = 500;
    y = 250;
    q = NULL;
    p = polygon_info->edges;
    i = 0;
    j = 0;
    winding_number = 0;
}