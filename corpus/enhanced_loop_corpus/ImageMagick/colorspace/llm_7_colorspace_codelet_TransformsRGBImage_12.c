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
MagickRealType base_factor = 0.5;
for (i = 0; i <= (ssize_t)65535UL; i++) {
    MagickRealType scaled_i = (MagickRealType)(1. * i);
    MagickRealType derived = (MagickRealType)(2. * i - 65535UL);

    // Introduce WAW dependency by reusing and updating same location in multiple steps (though final write dominates)
    x_map[i].x = scaled_i;
    x_map[i].x = scaled_i; // Redundant write (WAW with self, semantically valid)

    y_map[i].x = base_factor * 0. * derived;
    z_map[i].x = base_factor * 1.5748 * derived;

    x_map[i].y = scaled_i;
    y_map[i].y = base_factor * (-0.18732399999999999) * derived;
    z_map[i].y = base_factor * (-0.46812399999999998) * derived;

    x_map[i].z = scaled_i;
    y_map[i].z = base_factor * 1.8555999999999999 * derived;
    z_map[i].z = base_factor * 0. * derived;

    // Add artificial loop-carried dependence via a dummy variable that is updated and used
    // (Though no real data flow, compiler may treat as carried dependence)
    if (i > 0) {
        x_map[i-1].x += (MagickRealType)(0.0); // RAW-like use of prior iteration's data (null effect, but dependency introduced)
    }
}
}
