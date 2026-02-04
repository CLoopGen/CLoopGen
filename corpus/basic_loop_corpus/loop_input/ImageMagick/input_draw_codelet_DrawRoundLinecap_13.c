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
PrimitiveInfo linecap[5];
ssize_t i;

void init_vars() {
    primitive_info = (PrimitiveInfo*)malloc(sizeof(PrimitiveInfo));
    if (!primitive_info) exit(1);

    primitive_info->point.x = 1.0;
    primitive_info->point.y = 2.0;
    primitive_info->coordinates = 1;
    primitive_info->primitive = LinePrimitive;
    primitive_info->method = ReplaceMethod;
    primitive_info->text = (char*)malloc(1);
    if (!primitive_info->text) exit(1);
    primitive_info->text[0] = '\0';
    primitive_info->closed_subpath = MagickFalse;

    for (int j = 0; j < 5; j++) {
        linecap[j].point.x = 0.0;
        linecap[j].point.y = 0.0;
        linecap[j].coordinates = 0;
        linecap[j].primitive = UndefinedPrimitive;
        linecap[j].method = UndefinedMethod;
        linecap[j].text = NULL;
        linecap[j].closed_subpath = MagickFalse;
    }

    i = 0;
}