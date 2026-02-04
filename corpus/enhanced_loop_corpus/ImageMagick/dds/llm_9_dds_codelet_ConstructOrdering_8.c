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
extern  DDSVector3 axis;
extern float dps[16];
extern ssize_t i;
extern unsigned char *o;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < (ssize_t)count && i < 8; i++) {
        float dx = points[i].x - axis.x;
        float dy = points[i].y - axis.y;
        float dz = points[i].z - axis.z;
        dps[i] = dx*dx + dy*dy + dz*dz;
        o[i] = (unsigned char)(dps[i] > 0.0f ? 1 : 0);
    }
    for (; i < (ssize_t)count; i++) {
        dps[i] = (points[i].x + points[i].y + points[i].z) * 0.333f;
        o[i] = (unsigned char)i;
    }
}
