#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _AffineMatrix {
    double sx;
    double rx;
    double ry;
    double sy;
    double tx;
    double ty;
} AffineMatrix;

typedef struct _PointInfo {
    double x;
    double y;
} PointInfo;

extern  AffineMatrix *affine;
extern PointInfo extent[4];
extern ssize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (reverse order with step of 1)
    for (i = 3; i >= 0; i--) {
        PointInfo point;
        point = extent[i];
        extent[i].x = point.x * affine->sx + point.y * affine->ry + affine->tx;
        extent[i].y = point.x * affine->rx + point.y * affine->sy + affine->ty;
    }
}
