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
extern DDSVector3 centroid;
extern float total;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    size_t stride = 2;
    for (i = 0; i < count; i += stride) {
        if (i + 0 < count) {
            total += points[i + 0].w;
            centroid.x += (points[i + 0].x * points[i + 0].w);
            centroid.y += (points[i + 0].y * points[i + 0].w);
            centroid.z += (points[i + 0].z * points[i + 0].w);
        }
        if (i + 1 < count) {
            total += points[i + 1].w;
            centroid.x += (points[i + 1].x * points[i + 1].w);
            centroid.y += (points[i + 1].y * points[i + 1].w);
            centroid.z += (points[i + 1].z * points[i + 1].w);
        }
    }
}
