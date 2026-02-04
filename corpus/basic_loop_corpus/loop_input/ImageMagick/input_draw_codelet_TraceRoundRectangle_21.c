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
static PrimitiveInfo *allocated_p_base;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // ~64MB to target ~0.01s runtime
    const size_t num_coords = data_size / sizeof(PrimitiveInfo);
    
    allocated_primitive_info = calloc(num_coords, sizeof(PrimitiveInfo));
    if (!allocated_primitive_info) exit(1);
    
    allocated_p_base = calloc(num_coords + 1, sizeof(PrimitiveInfo));
    if (!allocated_p_base) exit(1);
    
    primitive_info = allocated_primitive_info;
    primitive_info->coordinates = num_coords;
    primitive_info->primitive = LinePrimitive;
    
    p = &allocated_p_base[num_coords]; // so that p-- moves backward through valid memory
    
    for (size_t idx = 0; idx < num_coords; idx++) {
        allocated_primitive_info[idx].point.x = (double)(idx + 1);
        allocated_primitive_info[idx].point.y = (double)(idx + 2);
        allocated_primitive_info[idx].coordinates = num_coords;
        allocated_primitive_info[idx].primitive = (idx % 2) ? LinePrimitive : PointPrimitive;
        allocated_primitive_info[idx].method = (idx % 3) ? PointMethod : ReplaceMethod;
        allocated_primitive_info[idx].text = NULL;
        allocated_primitive_info[idx].closed_subpath = (idx % 5 == 0) ? MagickTrue : MagickFalse;
    }
}