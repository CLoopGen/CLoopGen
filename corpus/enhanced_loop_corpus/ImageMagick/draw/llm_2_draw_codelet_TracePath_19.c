#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
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

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

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

extern PrimitiveType primitive_type;
extern PrimitiveInfo *q;
extern ssize_t i;
extern size_t number_coordinates;
extern size_t z_count;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with forward traversal and stride of 2
    // Instead of decrementing q once per iteration, we decrement by 2 to create a strided access pattern.
    // We adjust the loop bound to avoid out-of-bounds access.
    ssize_t stride = 2;
    ssize_t effective_coords = (ssize_t)number_coordinates / stride;
    for (i = 0; i < effective_coords; i++) {
        q -= stride;  // Strided backward access
        q->primitive = primitive_type;
        if (z_count > 1)
            q->method = FillToBorderMethod;
    }
}
