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
    float temp_dps;
    unsigned char temp_o;
    for (i = 0; i < (ssize_t)count; i++) {
        temp_dps = (points[i].x * axis.x) + (points[i].y * axis.y) + (points[i].z * axis.z);
        dps[i] = temp_dps;
        temp_o = (unsigned char)i;
        o[i] = temp_o;
    }
}
