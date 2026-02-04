#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <math.h>

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

size_t count;
DDSVector4 *points;
DDSVector3 centroid;
float total;
size_t i;

void init_vars() {
    count = 16777216; // ~64 MB of data (16,777,216 elements * 4 bytes per float * 4 components)
    points = (DDSVector4*)aligned_alloc(32, count * sizeof(DDSVector4));
    if (!points) {
        abort();
    }

    for (size_t idx = 0; idx < count; idx++) {
        points[idx].x = (float)(idx % 100) * 0.1f;
        points[idx].y = (float)((idx + 10) % 100) * 0.1f;
        points[idx].z = (float)((idx + 20) % 100) * 0.1f;
        points[idx].w = (float)((idx + 30) % 50) * 0.2f + 1.0f;
    }

    centroid.x = 0.0f;
    centroid.y = 0.0f;
    centroid.z = 0.0f;
    total = 0.0f;
    i = 0;
}