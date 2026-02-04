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
for (i = 0; i < 8; i += 2) {
    PointInfo point1, point2;
    point1 = extent[i % 4];
    point2 = extent[(i + 1) % 4];

    extent[i % 4].x = point1.x * affine->sx + point1.y * affine->ry + affine->tx;
    extent[i % 4].y = point1.x * affine->rx + point1.y * affine->sy + affine->ty;

    extent[(i + 1) % 4].x = point2.x * affine->sx + point2.y * affine->ry + affine->tx;
    extent[(i + 1) % 4].y = point2.x * affine->rx + point2.y * affine->sy + affine->ty;
}
}
