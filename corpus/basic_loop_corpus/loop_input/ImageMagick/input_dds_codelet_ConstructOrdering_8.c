#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

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
DDSVector3 axis;
float dps[16];
ssize_t i;
unsigned char *o;

void init_vars() {
    count = 16777216; // ~64 MB of input data: 16M * (sizeof(DDSVector4) + sizeof(float) + sizeof(unsigned char)) ≈ 64-70 MB

    points = (DDSVector4*)aligned_alloc(32, count * sizeof(DDSVector4));
    o = (unsigned char*)aligned_alloc(32, count * sizeof(unsigned char));
    if (!points || !o) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (size_t idx = 0; idx < count; ++idx) {
        points[idx].x = 1.0f + (float)(idx % 1000) / 100.0f;
        points[idx].y = 2.0f + (float)(idx % 1500) / 100.0f;
        points[idx].z = 3.0f + (float)(idx % 2000) / 100.0f;
        points[idx].w = 1.0f;
    }

    axis.x = 0.5f;
    axis.y = -0.3f;
    axis.z = 0.8f;

    memset(dps, 0, sizeof(dps));

    memset(o, 0, count * sizeof(unsigned char));

    i = 0;
}