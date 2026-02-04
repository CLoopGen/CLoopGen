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
    const ssize_t step = 4;
    for (; i <= (ssize_t)65535UL; i += step) {
        MagickRealType base_val = 1.099 * i - 0.099000000000000004;
        MagickRealType next_val1 = 1.099 * (i+1) - 0.099000000000000004;
        MagickRealType next_val2 = 1.099 * (i+2) - 0.099000000000000004;
        MagickRealType next_val3 = 1.099 * (i+3) - 0.099000000000000004;

        // Unroll and compute 4 iterations at once to increase arithmetic density
        x_map[i].x = 0.29883900000000002 * base_val;
        x_map[i].y = (-0.29883900000000002) * base_val;
        x_map[i].z = 0.70099999999999996 * base_val;
        y_map[i].x = 0.58681099999999997 * base_val;
        y_map[i].y = (-0.58681099999999997) * base_val;
        y_map[i].z = (-0.58681099999999997) * base_val;
        z_map[i].x = 0.11434999999999999 * base_val;
        z_map[i].y = 0.88600000000000001 * base_val;
        z_map[i].z = (-0.11434999999999999) * base_val;

        if (i+1 <= 65535UL) {
            x_map[i+1].x = 0.29883900000000002 * next_val1;
            x_map[i+1].y = (-0.29883900000000002) * next_val1;
            x_map[i+1].z = 0.70099999999999996 * next_val1;
            y_map[i+1].x = 0.58681099999999997 * next_val1;
            y_map[i+1].y = (-0.58681099999999997) * next_val1;
            y_map[i+1].z = (-0.58681099999999997) * next_val1;
            z_map[i+1].x = 0.11434999999999999 * next_val1;
            z_map[i+1].y = 0.88600000000000001 * next_val1;
            z_map[i+1].z = (-0.11434999999999999) * next_val1;
        }

        if (i+2 <= 65535UL) {
            x_map[i+2].x = 0.29883900000000002 * next_val2;
            x_map[i+2].y = (-0.29883900000000002) * next_val2;
            x_map[i+2].z = 0.70099999999999996 * next_val2;
            y_map[i+2].x = 0.58681099999999997 * next_val2;
            y_map[i+2].y = (-0.58681099999999997) * next_val2;
            y_map[i+2].z = (-0.58681099999999997) * next_val2;
            z_map[i+2].x = 0.11434999999999999 * next_val2;
            z_map[i+2].y = 0.88600000000000001 * next_val2;
            z_map[i+2].z = (-0.11434999999999999) * next_val2;
        }

        if (i+3 <= 65535UL) {
            x_map[i+3].x = 0.29883900000000002 * next_val3;
            x_map[i+3].y = (-0.29883900000000002) * next_val3;
            x_map[i+3].z = 0.70099999999999996 * next_val3;
            y_map[i+3].x = 0.58681099999999997 * next_val3;
            y_map[i+3].y = (-0.58681099999999997) * next_val3;
            y_map[i+3].z = (-0.58681099999999997) * next_val3;
            z_map[i+3].x = 0.11434999999999999 * next_val3;
            z_map[i+3].y = 0.88600000000000001 * next_val3;
            z_map[i+3].z = (-0.11434999999999999) * next_val3;
        }
    }
}
