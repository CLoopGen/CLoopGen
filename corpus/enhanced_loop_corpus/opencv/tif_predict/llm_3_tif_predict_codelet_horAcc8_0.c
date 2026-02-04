#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int tmsize_t;

extern tmsize_t cc;
extern tmsize_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access pattern on an array with stride of 8
    int data[2048];
    const tmsize_t stride = 8;
    for (; i < (cc - 3) * stride; i += 4 * stride) {
        data[i]           = i;
        data[i + stride]      = i + stride;
        data[i + 2 * stride]  = i + 2 * stride;
        data[i + 3 * stride]  = i + 3 * stride;
    }
}
