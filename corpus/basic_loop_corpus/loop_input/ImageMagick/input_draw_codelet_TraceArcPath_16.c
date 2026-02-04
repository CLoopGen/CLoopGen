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
PrimitiveInfo *p;
ssize_t i;

static PrimitiveInfo *primitive_info_buffer;
static PrimitiveInfo *p_buffer;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01 sec runtime
    primitive_info_buffer = (PrimitiveInfo*)calloc(data_size, sizeof(PrimitiveInfo));
    p_buffer = (PrimitiveInfo*)calloc(data_size + 1, sizeof(PrimitiveInfo));

    if (!primitive_info_buffer || !p_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < data_size; ++idx) {
        primitive_info_buffer[idx].point.x = (double)(idx * 1.5);
        primitive_info_buffer[idx].point.y = (double)(idx * 2.7);
        primitive_info_buffer[idx].coordinates = data_size;
        primitive_info_buffer[idx].primitive = LinePrimitive;
        primitive_info_buffer[idx].method = ReplaceMethod;
        primitive_info_buffer[idx].text = NULL;
        primitive_info_buffer[idx].closed_subpath = MagickFalse;
    }

    primitive_info = &primitive_info_buffer[0];
    p = &p_buffer[data_size]; 
}