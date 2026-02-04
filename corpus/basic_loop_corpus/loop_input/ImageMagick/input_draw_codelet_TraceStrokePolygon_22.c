#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

typedef enum {
    UndefinedPrimitive,
    AlphaPrimitive,
    ArcPrimitive,
    BezierPrimitive,
    CirclePrimitive,
    ColorPrimitive,
    EllipsePrimitive,
    ImagePrimitive,
    LinePrimitive,
    PathPrimitive,
    PointPrimitive,
    PolygonPrimitive,
    PolylinePrimitive,
    RectanglePrimitive,
    RoundRectanglePrimitive,
    TextPrimitive
} PrimitiveType;

typedef enum {
    UndefinedMethod,
    PointMethod,
    ReplaceMethod,
    FloodfillMethod,
    FillToBorderMethod,
    ResetMethod
} PaintMethod;

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

typedef struct _PrimitiveInfo {
    PointInfo point;
    size_t coordinates;
    PrimitiveType primitive;
    PaintMethod method;
    char *text;
    MagickBooleanType closed_subpath;
} PrimitiveInfo;

PointInfo *stroke_p;
PrimitiveInfo *polygon_primitive;
PrimitiveInfo *stroke_polygon;
ssize_t i;
ssize_t p;

void init_vars() {
    p = 5000000; // ~200 MB of data: 5M elements * (16+8+4+4+8+1) ≈ 200MB

    stroke_p = (PointInfo*)calloc(p, sizeof(PointInfo));
    polygon_primitive = (PrimitiveInfo*)calloc(1, sizeof(PrimitiveInfo));
    stroke_polygon = (PrimitiveInfo*)calloc(p, sizeof(PrimitiveInfo));

    if (!stroke_p || !polygon_primitive || !stroke_polygon) {
        exit(1);
    }

    for (ssize_t idx = 0; idx < p; idx++) {
        stroke_p[idx].x = (double)(idx % 1000) + 0.5;
        stroke_p[idx].y = (double)((idx / 1000) % 1000) + 0.5;
    }

    polygon_primitive[0].point.x = 10.0;
    polygon_primitive[0].point.y = 20.0;
    polygon_primitive[0].coordinates = 1;
    polygon_primitive[0].primitive = PointPrimitive;
    polygon_primitive[0].method = PointMethod;
    polygon_primitive[0].text = NULL;
    polygon_primitive[0].closed_subpath = MagickFalse;
}