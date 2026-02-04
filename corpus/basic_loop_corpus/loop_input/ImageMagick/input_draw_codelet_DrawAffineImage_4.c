#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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

AffineMatrix *affine;
PointInfo extent[4];
ssize_t i;

void init_vars() {
    affine = (AffineMatrix*)malloc(sizeof(AffineMatrix));
    if (!affine) exit(1);
    
    affine->sx = 2.0;
    affine->rx = 0.5;
    affine->ry = -0.3;
    affine->sy = 1.8;
    affine->tx = 10.0;
    affine->ty = 20.0;
    
    extent[0].x = 0.0; extent[0].y = 0.0;
    extent[1].x = 100.0; extent[1].y = 0.0;
    extent[2].x = 100.0; extent[2].y = 100.0;
    extent[3].x = 0.0; extent[3].y = 100.0;
    
    i = 0;
}