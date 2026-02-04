#include <stdio.h>

#include <inttypes.h>

typedef long INT32;

extern INT32 *rgb_ycc_tab;
extern INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    INT32 *base = rgb_ycc_tab;
    const INT32 step = 255 + 1;
    for (i = 0; i <= 255; i++) {
        // Use consecutive memory layout by precomputing all offsets
        base[i]                    = ((INT32)((0.29899999999999999) * (1L << 16) + 0.5)) * i;
        base[i +   step]           = ((INT32)((0.58699999999999997) * (1L << 16) + 0.5)) * i;
        base[i + 2*step]           = ((INT32)((0.114) * (1L << 16) + 0.5)) * i + ((INT32)1 << (16 - 1));
        base[i + 3*step]           = (-((INT32)((0.16874) * (1L << 16) + 0.5))) * i;
        base[i + 4*step]           = (-((INT32)((0.33126) * (1L << 16) + 0.5))) * i;
        base[i + 5*step]           = ((INT32)((0.5) * (1L << 16) + 0.5)) * i + ((INT32)128 << 16) + ((INT32)1 << (16 - 1)) - 1;
        base[i + 6*step]           = (-((INT32)((0.41869000000000001) * (1L << 16) + 0.5))) * i;
        base[i + 7*step]           = (-((INT32)((0.081309999999999993) * (1L << 16) + 0.5))) * i;
    }
}
