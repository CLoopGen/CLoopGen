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
    // Variant 2: Indirect memory access using an index map (simulating non-sequential access pattern)
    ssize_t index_map[4] = {0, 2, 1, 3}; // Custom access order: 0, 2, 1, 3
    for (i = 0; i < 4; i++) {
        ssize_t idx = index_map[i];
        PointInfo point;
        point = extent[idx];
        extent[idx].x = point.x * affine->sx + point.y * affine->ry + affine->tx;
        extent[idx].y = point.x * affine->rx + point.y * affine->sy + affine->ty;
    }
}
