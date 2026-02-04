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
for (i = 0; i <= (ssize_t)(0.017999999999999999 * 65535UL); i++) {
    MagickRealType idx = i;
    TransformPacket temp_x, temp_y, temp_z;
    
    temp_x.x = 0.0053819999999999996 * idx;
    temp_x.y = (-0.0032959999999999999) * idx;
    temp_x.z = 0.0094099999999999999 * idx;
    
    temp_y.x = 0.010566000000000001 * idx;
    temp_y.y = (-0.0064710000000000002) * idx;
    temp_y.z = (-0.0078799999999999998) * idx;
    
    temp_z.x = 0.002052 * idx;
    temp_z.y = 0.0097680000000000006 * idx;
    temp_z.z = (-0.0015299999999999999) * idx;
    
    x_map[i] = temp_x;
    y_map[i] = temp_y;
    z_map[i] = temp_z;
}
}
