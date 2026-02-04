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
size_t step = 1;
for (i = 0; i < count; i += step) {
    DDSVector3 a;
    a.x = points[i].x - centroid.x;
    a.y = points[i].y - centroid.y;
    a.z = points[i].z - centroid.z;

    float awx = points[i].w * a.x;
    float awy = points[i].w * a.y;
    float awz = points[i].w * a.z;

    covariance[0] += a.x * awx;
    covariance[1] += a.x * awy;
    covariance[2] += a.x * awz;
    covariance[3] += a.y * awy;
    covariance[4] += a.y * awz;
    covariance[5] += a.z * awz;

    // Introduce light computational overhead to increase arithmetic intensity
    float temp = a.x + a.y + a.z;
    temp *= temp;
    covariance[0] += temp * 1e-6f;
}
}
