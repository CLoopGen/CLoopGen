#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 win_l_x1;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < win_l_x1 && dn > 0; i++) {
    OPJ_INT32 clamped_i = i;
    if (clamped_i < 0) clamped_i = 0;
    else if (clamped_i >= dn) clamped_i = dn - 1;

    OPJ_INT32 prev_i = i - 1;
    if (prev_i < 0) prev_i = 0;
    if (prev_i >= dn) prev_i = dn - 1;

    OPJ_UINT32 base_curr = (1 + (OPJ_UINT32)(clamped_i) * 2) * 4;
    OPJ_UINT32 base_prev = (1 + (OPJ_UINT32)(prev_i) * 2) * 4;
    OPJ_UINT32 dest_base = (OPJ_UINT32)(i) * 2 * 4;

    for (off = 0; off < 4; off++) {
        OPJ_INT32 avg = (a[base_prev + off] + a[base_curr + off] + 2) >> 2;
        a[dest_base + off] -= avg;
    }
}
}
