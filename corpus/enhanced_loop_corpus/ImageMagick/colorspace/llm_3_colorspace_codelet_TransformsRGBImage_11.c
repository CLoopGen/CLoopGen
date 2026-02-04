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
extern TransformPacket *y_map;
extern TransformPacket *x_map;
extern TransformPacket *z_map;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index remapping table (reverse order traversal)
    // Simulates non-linear access pattern by processing elements from end to start
    TransformPacket* x_base = x_map;
    TransformPacket* y_base = y_map;
    TransformPacket* z_base = z_map;
    for (i = 65535UL; i >= 0; i--) {
        ssize_t idx = 65535UL - i;  // Reverse index mapping
        x_base[idx].x = 0.99999999999914679 * (double)idx;
        y_base[idx].x = 0.5 * (-1.2188941887145875E-6) * (2. * (double)idx - 65535UL);
        z_base[idx].x = 0.5 * 1.401999588656144 * (2. * (double)idx - 65535UL);
        x_base[idx].y = 0.99999975910502514 * (double)idx;
        y_base[idx].y = 0.5 * (-0.34413567816504304) * (2. * (double)idx - 65535UL);
        z_base[idx].y = 0.5 * (-0.71413649331646789) * (2. * (double)idx - 65535UL);
        x_base[idx].z = 1.0000012404000462 * (double)idx;
        y_base[idx].z = 0.5 * 1.7720000660723041 * (2. * (double)idx - 65535UL);
        z_base[idx].z = 0.5 * 2.1453384174593273E-6 * (2. * (double)idx - 65535UL);
    }
}
