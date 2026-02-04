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
for (i = 0; i < count; i += 2) {
    DDSVector3 a1, b1, a2, b2;
    if (i + 1 < count) {
        a1.x = points[i].x - centroid.x;
        a1.y = points[i].y - centroid.y;
        a1.z = points[i].z - centroid.z;
        b1.x = points[i].w * a1.x;
        b1.y = points[i].w * a1.y;
        b1.z = points[i].w * a1.z;

        a2.x = points[i+1].x - centroid.x;
        a2.y = points[i+1].y - centroid.y;
        a2.z = points[i+1].z - centroid.z;
        b2.x = points[i+1].w * a2.x;
        b2.y = points[i+1].w * a2.y;
        b2.z = points[i+1].w * a2.z;

        covariance[0] += a1.x * b1.x + a2.x * b2.x;
        covariance[1] += a1.x * b1.y + a2.x * b2.y;
        covariance[2] += a1.x * b1.z + a2.x * b2.z;
        covariance[3] += a1.y * b1.y + a2.y * b2.y;
        covariance[4] += a1.y * b1.z + a2.y * b2.z;
        covariance[5] += a1.z * b1.z + a2.z * b2.z;
    } else {
        a1.x = points[i].x - centroid.x;
        a1.y = points[i].y - centroid.y;
        a1.z = points[i].z - centroid.z;
        b1.x = points[i].w * a1.x;
        b1.y = points[i].w * a1.y;
        b1.z = points[i].w * a1.z;

        covariance[0] += a1.x * b1.x;
        covariance[1] += a1.x * b1.y;
        covariance[2] += a1.x * b1.z;
        covariance[3] += a1.y * b1.y;
        covariance[4] += a1.y * b1.z;
        covariance[5] += a1.z * b1.z;
    }
}
}
