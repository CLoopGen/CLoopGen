#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 sn;
extern OPJ_INT32 win_h_x1;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access with Increased Stride
    // Modify access pattern to use a larger stride (e.g., every 4th element instead of every 2nd)
    // This increases cache line skips and alters spatial locality.

    const OPJ_INT32 stride = 4;
    for (; i < win_h_x1; i++) {
        OPJ_INT32 center = 1 + i * stride;
        OPJ_INT32 left = (i < 0 ? a[0 * stride] : (i >= sn ? a[(sn - 1) * stride] : a[i * stride]));
        OPJ_INT32 right = ((i + 1) < 0 ? a[0 * stride] : ((i + 1) >= sn ? a[(sn - 1) * stride] : a[(i + 1) * stride]));
        a[center] += (left + right) >> 1;
    }
}
