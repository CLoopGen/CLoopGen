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
ssize_t i;

static PrimitiveInfo *internal_primitive_info = NULL;
static size_t data_size = 1 << 20; // ~8MB of data (each PrimitiveInfo is ~64 bytes)

void init_vars() {
    internal_primitive_info = calloc(data_size, sizeof(PrimitiveInfo));
    if (!internal_primitive_info) exit(1);

    for (size_t idx = 0; idx < data_size - 1; idx++) {
        internal_primitive_info[idx].point.x = 0.0;
        internal_primitive_info[idx].point.y = 0.0;
        internal_primitive_info[idx].coordinates = 0;
        internal_primitive_info[idx].primitive = AlphaPrimitive;
        internal_primitive_info[idx].method = UndefinedMethod;
        internal_primitive_info[idx].text = NULL;
        internal_primitive_info[idx].closed_subpath = MagickFalse;
    }

    internal_primitive_info[data_size - 1].primitive = UndefinedPrimitive;

    primitive_info = internal_primitive_info;
    i = 0;
}