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

static PrimitiveInfo *allocated_primitive_info;
static PrimitiveInfo *allocated_p_array;

void init_vars() {
    size_t num_elements = 16777216; // ~134 MB of data (8B * 2 + 8 + 4 + 4 + 8 + 1 = ~29B per element -> ~487MB total), adjust to hit ~0.01s runtime
    allocated_primitive_info = calloc(num_elements, sizeof(PrimitiveInfo));
    allocated_p_array = calloc(num_elements, sizeof(PrimitiveInfo));

    if (!allocated_primitive_info || !allocated_p_array) {
        exit(1);
    }

    for (size_t idx = 0; idx < num_elements; idx++) {
        allocated_primitive_info[idx].point.x = 1.0 + idx * 0.1;
        allocated_primitive_info[idx].point.y = 2.0 + idx * 0.1;
        allocated_primitive_info[idx].coordinates = num_elements - idx;
        allocated_primitive_info[idx].primitive = LinePrimitive;
        allocated_primitive_info[idx].method = ReplaceMethod;
        allocated_primitive_info[idx].text = NULL;
        allocated_primitive_info[idx].closed_subpath = MagickFalse;

        allocated_p_array[idx].point.x = 3.0 + idx * 0.2;
        allocated_p_array[idx].point.y = 4.0 + idx * 0.2;
        allocated_p_array[idx].coordinates = idx;
        allocated_p_array[idx].primitive = PointPrimitive;
        allocated_p_array[idx].method = PointMethod;
        allocated_p_array[idx].text = NULL;
        allocated_p_array[idx].closed_subpath = MagickTrue;
    }

    primitive_info = allocated_primitive_info;
    p = &allocated_p_array[num_elements - 1];
}