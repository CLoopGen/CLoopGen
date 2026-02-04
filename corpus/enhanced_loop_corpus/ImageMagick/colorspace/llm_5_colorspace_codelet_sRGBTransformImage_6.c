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
for (; i <= (ssize_t)65535UL; i++) {
    const MagickRealType factor = 1.099 * i - 0.099000000000000004;
    const MagickRealType a = 0.29883900000000002 * factor;
    const MagickRealType b = 0.58681099999999997 * factor;
    const MagickRealType c = 0.11434999999999999 * factor;
    const MagickRealType d = 0.70099999999999996 * factor;
    const MagickRealType e = 0.88600000000000001 * factor;

    if (i < 32768) {
        x_map[i].x = a;
        x_map[i].y = -a;
        x_map[i].z = d;
    } else {
        y_map[i].x = b;
        y_map[i].y = -b;
        y_map[i].z = -b;
    }

    if ((i & 1) && i >= 16384) {
        z_map[i].x = c;
        z_map[i].y = e;
        z_map[i].z = -c;
    }
}
}
