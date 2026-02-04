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

PrimitiveInfo *primitive_info;
size_t i;

void init_vars() {
    const size_t data_size = 64 * 1024;  // ~1MB of data (each PrimitiveInfo is ~16-32 bytes, depending on padding)
    
    primitive_info = calloc(data_size, sizeof(PrimitiveInfo));
    if (!primitive_info) exit(1);

    for (size_t idx = 0; idx < data_size - 1; idx++) {
        primitive_info[idx].primitive = AlphaPrimitive + (idx % (TextPrimitive - AlphaPrimitive));
        primitive_info[idx].point.x = 1.0 + idx;
        primitive_info[idx].point.y = 2.0 + idx;
        primitive_info[idx].coordinates = idx;
        primitive_info[idx].method = PointMethod + (idx % (ResetMethod - PointMethod));
        primitive_info[idx].text = NULL;
        primitive_info[idx].closed_subpath = (idx % 2) ? MagickTrue : MagickFalse;
    }

    primitive_info[data_size - 1].primitive = UndefinedPrimitive;
}