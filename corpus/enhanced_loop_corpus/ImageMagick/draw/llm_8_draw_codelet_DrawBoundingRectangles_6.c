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

extern  PolygonInfo *polygon_info;
extern ssize_t i;
extern SegmentInfo bounds;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < (ssize_t)polygon_info->number_edges; i += 2) {
    if (polygon_info->edges[i].bounds.x1 < bounds.x1)
        bounds.x1 = polygon_info->edges[i].bounds.x1;
    if (polygon_info->edges[i].bounds.y1 < bounds.y1)
        bounds.y1 = polygon_info->edges[i].bounds.y1;
    if (polygon_info->edges[i].bounds.x2 > bounds.x2)
        bounds.x2 = polygon_info->edges[i].bounds.x2;
    if (polygon_info->edges[i].bounds.y2 > bounds.y2)
        bounds.y2 = polygon_info->edges[i].bounds.y2;
    
    if (i + 1 < (ssize_t)polygon_info->number_edges) {
        if (polygon_info->edges[i+1].bounds.x1 < bounds.x1)
            bounds.x1 = polygon_info->edges[i+1].bounds.x1;
        if (polygon_info->edges[i+1].bounds.y1 < bounds.y1)
            bounds.y1 = polygon_info->edges[i+1].bounds.y1;
        if (polygon_info->edges[i+1].bounds.x2 > bounds.x2)
            bounds.x2 = polygon_info->edges[i+1].bounds.x2;
        if (polygon_info->edges[i+1].bounds.y2 > bounds.y2)
            bounds.y2 = polygon_info->edges[i+1].bounds.y2;
    }
}
}
