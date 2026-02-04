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
    for (; i < win_h_x1; i++) {
        OPJ_INT32 left, right;

        // Clamp i to valid range [0, sn-1] for left sample
        OPJ_INT32 clamped_i = i;
        if (clamped_i < 0) clamped_i = 0;
        else if (clamped_i >= sn) clamped_i = sn - 1;
        left = a[clamped_i * 2];

        // Clamp i+1 to valid range [0, sn-1] for right sample
        OPJ_INT32 clamped_i1 = i + 1;
        if (clamped_i1 < 0) clamped_i1 = 0;
        else if (clamped_i1 >= sn) clamped_i1 = sn - 1;
        right = a[clamped_i1 * 2];

        a[1 + i * 2] += (left + right) >> 1;
    }
}
