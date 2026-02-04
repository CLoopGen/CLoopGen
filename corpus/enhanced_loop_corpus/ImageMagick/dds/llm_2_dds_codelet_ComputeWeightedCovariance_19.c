#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct _DDSVector4 {
    float x;
    float y;
    float z;
    float w;
} DDSVector4;

typedef struct _DDSVector3 {
    float x;
    float y;
    float z;
} DDSVector3;

extern  size_t count;
extern  DDSVector4 *points;
extern float *covariance;
extern DDSVector3 centroid;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided Memory Access (process every 2nd element first, then the others)
    // This changes access pattern from sequential to strided, potentially affecting cache behavior
    size_t stride = 2;
    for (i = 0; i < count; i += stride) {
        DDSVector3 a, b;
        a.x = points[i].x - centroid.x;
        a.y = points[i].y - centroid.y;
        a.z = points[i].z - centroid.z;
        b.x = points[i].w * a.x;
        b.y = points[i].w * a.y;
        b.z = points[i].w * a.z;
        covariance[0] += a.x * b.x;
        covariance[1] += a.x * b.y;
        covariance[2] += a.x * b.z;
        covariance[3] += a.y * b.y;
        covariance[4] += a.y * b.z;
        covariance[5] += a.z * b.z;
    }
    for (i = 1; i < count; i += stride) {
        DDSVector3 a, b;
        a.x = points[i].x - centroid.x;
        a.y = points[i].y - centroid.y;
        a.z = points[i].z - centroid.z;
        b.x = points[i].w * a.x;
        b.y = points[i].w * a.y;
        b.z = points[i].w * a.z;
        covariance[0] += a.x * b.x;
        covariance[1] += a.x * b.y;
        covariance[2] += a.x * b.z;
        covariance[3] += a.y * b.y;
        covariance[4] += a.y * b.z;
        covariance[5] += a.z * b.z;
    }
}
