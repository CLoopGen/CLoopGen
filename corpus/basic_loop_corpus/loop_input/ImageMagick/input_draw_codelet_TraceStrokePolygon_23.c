#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef enum {
    MagickFalse = 0,
    MagickTrue = 1
} MagickBooleanType;

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

typedef struct _PrimitiveInfo {
    PointInfo point;
    size_t coordinates;
    PrimitiveType primitive;
    PaintMethod method;
    char *text;
    MagickBooleanType closed_subpath;
} PrimitiveInfo;

MagickBooleanType closed_path = MagickTrue;
PointInfo *stroke_q = NULL;
PrimitiveInfo *polygon_primitive = NULL;
PrimitiveInfo *stroke_polygon = NULL;
ssize_t i = 0;
ssize_t p = 0;
ssize_t q = 0;

#define DATA_SIZE (128 * 1024 * 1024 / sizeof(PointInfo))  // ~128MB of PointInfo data

void init_vars() {
    p = DATA_SIZE / 2;
    q = DATA_SIZE / 4;
    
    stroke_q = (PointInfo*)calloc(DATA_SIZE, sizeof(PointInfo));
    polygon_primitive = (PrimitiveInfo*)calloc(1, sizeof(PrimitiveInfo));
    stroke_polygon = (PrimitiveInfo*)calloc(p + q + 1, sizeof(PrimitiveInfo));

    if (!stroke_q || !polygon_primitive || !stroke_polygon) {
        exit(1);
    }

    for (size_t idx = 0; idx < DATA_SIZE; idx++) {
        stroke_q[idx].x = (double)(idx * 1.5);
        stroke_q[idx].y = (double)(idx * 2.3);
    }

    polygon_primitive[0].point.x = 100.0;
    polygon_primitive[0].point.y = 200.0;
    polygon_primitive[0].coordinates = 1;
    polygon_primitive[0].primitive = PointPrimitive;
    polygon_primitive[0].method = PointMethod;
    polygon_primitive[0].text = NULL;
    polygon_primitive[0].closed_subpath = MagickFalse;

    i = 0;
    closed_path = MagickTrue;
}