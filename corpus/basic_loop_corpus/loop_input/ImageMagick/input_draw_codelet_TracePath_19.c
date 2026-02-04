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

PrimitiveType primitive_type = LinePrimitive;
ssize_t i;
size_t number_coordinates;
size_t z_count;

#define DATA_SIZE (64 * 1024)

static PrimitiveInfo primitive_info_buffer[DATA_SIZE + 1]; // Extra space for pre-decrement
PrimitiveInfo *q = &primitive_info_buffer[DATA_SIZE];

void init_vars() {
    number_coordinates = DATA_SIZE;
    z_count = 2;
    i = 0;
    for (size_t idx = 0; idx <= DATA_SIZE; idx++) {
        primitive_info_buffer[idx].coordinates = 0;
        primitive_info_buffer[idx].primitive = UndefinedPrimitive;
        primitive_info_buffer[idx].method = UndefinedMethod;
        primitive_info_buffer[idx].text = NULL;
        primitive_info_buffer[idx].closed_subpath = MagickFalse;
        primitive_info_buffer[idx].point.x = 0.0;
        primitive_info_buffer[idx].point.y = 0.0;
    }
}