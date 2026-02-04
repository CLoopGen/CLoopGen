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
    for (ssize_t block_start = 0; block_start <= 65535; block_start += 16) {
        for (ssize_t offset = 0; offset < 16 && (block_start + offset) <= 65535; offset++) {
            ssize_t i = block_start + offset;
            x_map[i].x = (MagickRealType)(0.29883900000000002 * (double)i);
            x_map[i].y = (MagickRealType)(-0.16873669999999999 * (double)i);
            x_map[i].z = (MagickRealType)(0.5 * (double)i);
            y_map[i].x = (MagickRealType)(0.58681099999999997 * (double)i);
            y_map[i].y = (MagickRealType)(-0.331264 * (double)i);
            y_map[i].z = (MagickRealType)(-0.418688 * (double)i);
            z_map[i].x = (MagickRealType)(0.11434999999999999 * (double)i);
            z_map[i].y = (MagickRealType)(0.5 * (double)i);
            z_map[i].z = (MagickRealType)(-0.081311999999999995 * (double)i);
        }
    }
}
