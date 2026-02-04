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
    float px = points[i].x, py = points[i].y, pz = points[i].z, pw = points[i].w;
    float cx = centroid.x, cy = centroid.y, cz = centroid.z;
    a.x = px - cx;
    a.y = py - cy;
    a.z = pz - cz;
    if (a.x * pw > 0.0f || a.y * pw > 0.0f) {
        b.x = pw * a.x;
        b.y = pw * a.y;
        b.z = pw * a.z;
        covariance[0] += a.x * b.x;
        covariance[1] += a.x * b.y;
        covariance[2] += a.x * b.z;
        covariance[3] += a.y * b.y;
        covariance[4] += a.y * b.z;
        covariance[5] += a.z * b.z;
    } else {
        b.z = pw * a.z;
        covariance[5] += a.z * b.z;
    }
}
}
