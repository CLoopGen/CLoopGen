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

EdgeInfo *p;
PolygonInfo **restrict polygon_info;
SegmentInfo bounds;
ssize_t i;

#define NUM_EDGES 5000000

void init_vars() {
    // Allocate and initialize bounds
    bounds.x1 = 1e30;
    bounds.y1 = 1e30;
    bounds.x2 = -1e30;
    bounds.y2 = -1e30;

    // Allocate polygon_info array (array of pointers to PolygonInfo)
    polygon_info = (PolygonInfo**)calloc(1, sizeof(PolygonInfo*));
    
    // Allocate one PolygonInfo
    polygon_info[0] = (PolygonInfo*)malloc(sizeof(PolygonInfo));
    
    // Set number of edges based on performance target
    polygon_info[0]->number_edges = NUM_EDGES;
    
    // Allocate edges array
    polygon_info[0]->edges = (EdgeInfo*)calloc(NUM_EDGES, sizeof(EdgeInfo));
    
    // Initialize edges with meaningful data
    for (size_t idx = 0; idx < NUM_EDGES; idx++) {
        EdgeInfo* edge = &polygon_info[0]->edges[idx];
        
        // Randomish but deterministic values
        double base_val = (double)idx * 0.001;
        
        edge->bounds.x1 = base_val + 1.0;
        edge->bounds.y1 = base_val + 2.0;
        edge->bounds.x2 = base_val + 3.0;
        edge->bounds.y2 = base_val + 4.0;
        
        edge->scanline = base_val;
        edge->number_points = 0;
        edge->points = NULL;
        edge->direction = (idx % 2) ? 1 : -1;
        edge->ghostline = (idx % 10 == 0) ? MagickTrue : MagickFalse;
        edge->highwater = idx;
    }
    
    // Initialize p to point to first edge (will be overwritten in loop)
    p = polygon_info[0]->edges;
}