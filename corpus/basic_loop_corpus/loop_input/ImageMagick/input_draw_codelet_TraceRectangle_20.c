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
    const size_t data_size = 64 * 1024 * sizeof(PrimitiveInfo);
    primitive_info_buffer = aligned_alloc(64, data_size);
    p_buffer = aligned_alloc(64, data_size);

    if (!primitive_info_buffer || !p_buffer) {
        exit(1);
    }

    for (size_t idx = 0; idx < 64 * 1024; idx++) {
        primitive_info_buffer[idx].point.x = 1.0 + idx * 0.01;
        primitive_info_buffer[idx].point.y = 2.0 + idx * 0.01;
        primitive_info_buffer[idx].coordinates = 64 * 1024;
        primitive_info_buffer[idx].primitive = LinePrimitive;
        primitive_info_buffer[idx].method = ReplaceMethod;
        primitive_info_buffer[idx].text = NULL;
        primitive_info_buffer[idx].closed_subpath = MagickFalse;

        p_buffer[idx].point.x = 3.0 + idx * 0.01;
        p_buffer[idx].point.y = 4.0 + idx * 0.01;
        p_buffer[idx].coordinates = 64 * 1024;
        p_buffer[idx].primitive = PointPrimitive;
        p_buffer[idx].method = PointMethod;
        p_buffer[idx].text = NULL;
        p_buffer[idx].closed_subpath = MagickTrue;
    }

    primitive_info = &primitive_info_buffer[0];
    p = &p_buffer[64 * 1024 - 1];
}