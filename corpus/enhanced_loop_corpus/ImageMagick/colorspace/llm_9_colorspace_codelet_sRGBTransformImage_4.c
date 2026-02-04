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
const MagickRealType a = 0.21265600000000001;
const MagickRealType b = -0.11457199999999999;
const MagickRealType c = 0.5;
const MagickRealType d = 0.71515799999999996;
const MagickRealType e = -0.38542799999999999;
const MagickRealType f = -0.45415299999999997;
const MagickRealType g = 0.072186;
const MagickRealType h = -0.045846999999999999;

MagickRealType ia, ib, ic, id, ie, if_, ig, ih;

for (i = 0; i <= (ssize_t)32767UL; i++) {
    ia = (MagickRealType)(a * (double)i);
    ib = (MagickRealType)(b * (double)i);
    ic = (MagickRealType)(c * (double)i);
    id = (MagickRealType)(d * (double)i);
    ie = (MagickRealType)(e * (double)i);
    if_ = (MagickRealType)(f * (double)i);
    ig = (MagickRealType)(g * (double)i);
    ih = (MagickRealType)(h * (double)i);

    x_map[i].x = ia;
    x_map[i].y = ib;
    x_map[i].z = ic;
    y_map[i].x = id;
    y_map[i].y = ie;
    y_map[i].z = if_;
    z_map[i].x = ig;
    z_map[i].y = ic; // Reuse ic (0.5*i) to reduce computation
    z_map[i].z = ih;

    // Second half of original range processed with offset
    ssize_t j = i + 32768UL;
    if (j <= 65535UL) {
        x_map[j].x = (MagickRealType)(a * (double)j);
        x_map[j].y = (MagickRealType)(b * (double)j);
        x_map[j].z = (MagickRealType)(c * (double)j);
        y_map[j].x = (MagickRealType)(d * (double)j);
        y_map[j].y = (MagickRealType)(e * (double)j);
        y_map[j].z = (MagickRealType)(f * (double)j);
        z_map[j].x = (MagickRealType)(g * (double)j);
        z_map[j].y = (MagickRealType)(c * (double)j);
        z_map[j].z = (MagickRealType)(h * (double)j);
    }
}
}
