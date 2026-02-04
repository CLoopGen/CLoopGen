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
// Decreased loop depth conceptually by unrolling the loop completely (depth reduced to zero nested loops, fully unrolled)
PointInfo point0 = extent[0];
extent[0].x = point0.x * affine->sx + point0.y * affine->ry + affine->tx;
extent[0].y = point0.x * affine->rx + point0.y * affine->sy + affine->ty;

PointInfo point1 = extent[1];
extent[1].x = point1.x * affine->sx + point1.y * affine->ry + affine->tx;
extent[1].y = point1.x * affine->rx + point1.y * affine->sy + affine->ty;

PointInfo point2 = extent[2];
extent[2].x = point2.x * affine->sx + point2.y * affine->ry + affine->tx;
extent[2].y = point2.x * affine->rx + point2.y * affine->sy + affine->ty;

PointInfo point3 = extent[3];
extent[3].x = point3.x * affine->sx + point3.y * affine->ry + affine->tx;
extent[3].y = point3.x * affine->rx + point3.y * affine->sy + affine->ty;
}
