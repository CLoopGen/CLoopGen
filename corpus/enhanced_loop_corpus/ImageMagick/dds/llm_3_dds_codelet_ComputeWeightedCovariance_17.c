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
    // Variant 2: Indirect access via index mapping (reverse order traversal)
    for (i = 0; i < count; i++) {
        size_t idx = count - 1 - i; // reverse indexing
        total += points[idx].w;
        centroid.x += (points[idx].x * points[idx].w);
        centroid.y += (points[idx].y * points[idx].w);
        centroid.z += (points[idx].z * points[idx].w);
    }
}
