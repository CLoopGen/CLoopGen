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
for (i = 0; i < count; i++) {
    DDSVector3 a, b;
    float w = points[i].w;
    if (w == 0.0f) continue;
    a.x = points[i].x - centroid.x;
    a.y = points[i].y - centroid.y;
    a.z = points[i].z - centroid.z;
    b.x = w * a.x;
    b.y = w * a.y;
    b.z = w * a.z;
    covariance[0] += a.x * b.x;
    covariance[1] += a.x * b.y;
    covariance[2] += a.x * b.z;
    covariance[3] += a.y * b.y;
    covariance[4] += a.y * b.z;
    covariance[5] += a.z * b.z;
}
}
