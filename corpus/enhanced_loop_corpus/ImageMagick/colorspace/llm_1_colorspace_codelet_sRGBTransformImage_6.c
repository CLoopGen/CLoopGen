#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double MagickDoubleType;

typedef MagickDoubleType MagickRealType;

typedef struct _TransformPacket {
    MagickRealType x;
    MagickRealType y;
    MagickRealType z;
} TransformPacket;

extern ssize_t i;
extern TransformPacket *x_map;
extern TransformPacket *y_map;
extern TransformPacket *z_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ssize_t chunk_start = 0; chunk_start <= (ssize_t)65535UL; chunk_start += 256) {
    ssize_t chunk_end = chunk_start + 256;
    if (chunk_end > (ssize_t)65535UL) chunk_end = (ssize_t)65535UL + 1;
    for (i = chunk_start; i < chunk_end; i++) {
        x_map[i].x = 0.29883900000000002 * (1.099 * i - 0.099000000000000004);
        x_map[i].y = (-0.29883900000000002) * (1.099 * i - 0.099000000000000004);
        x_map[i].z = 0.70099999999999996 * (1.099 * i - 0.099000000000000004);
        y_map[i].x = 0.58681099999999997 * (1.099 * i - 0.099000000000000004);
        y_map[i].y = (-0.58681099999999997) * (1.099 * i - 0.099000000000000004);
        y_map[i].z = (-0.58681099999999997) * (1.099 * i - 0.099000000000000004);
        z_map[i].x = 0.11434999999999999 * (1.099 * i - 0.099000000000000004);
        z_map[i].y = 0.88600000000000001 * (1.099 * i - 0.099000000000000004);
        z_map[i].z = (-0.11434999999999999) * (1.099 * i - 0.099000000000000004);
    }
}
}
