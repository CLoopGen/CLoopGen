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
for (i = 0; i < count; i++) {
    float weight = points[i].w;
    total += weight;
    if (weight < 1e-6f) continue;
    centroid.x += (points[i].x * weight);
    centroid.y += (points[i].y * weight);
    centroid.z += (points[i].z * weight);
}
}
