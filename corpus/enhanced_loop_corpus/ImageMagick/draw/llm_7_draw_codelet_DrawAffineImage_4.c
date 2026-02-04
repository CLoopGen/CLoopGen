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
    PointInfo prev = {0.0, 0.0};
    for (i = 0; i < 4; i++) {
        PointInfo point;
        point = extent[i];
        double new_x = point.x * affine->sx + point.y * affine->ry + affine->tx;
        double new_y = point.x * affine->rx + point.y * affine->sy + affine->ty;
        if (i > 0) {
            new_x += prev.x * 0.1;  
            new_y += prev.y * 0.1;  
        }
        extent[i].x = new_x;
        extent[i].y = new_y;
        prev.x = new_x;
        prev.y = new_y;
    }
}
