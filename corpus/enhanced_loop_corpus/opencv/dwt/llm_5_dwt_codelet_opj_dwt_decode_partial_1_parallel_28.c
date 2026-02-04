#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *a;
extern OPJ_INT32 dn;
extern OPJ_INT32 i;
extern OPJ_UINT32 off;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (off = 0; off < 4; off++) {
    OPJ_INT32 index_clamped_prev = i - 1;
    OPJ_INT32 index_clamped_curr = i;

    // Clamp indices without branching using conditional expressions
    index_clamped_prev = (index_clamped_prev < 0) ? 0 : 
                         (index_clamped_prev >= dn) ? dn - 1 : index_clamped_prev;
    index_clamped_curr = (index_clamped_curr < 0) ? 0 : 
                         (index_clamped_curr >= dn) ? dn - 1 : index_clamped_curr;

    OPJ_UINT32 addr_prev = (1 + (OPJ_UINT32)index_clamped_prev * 2) * 4 + off;
    OPJ_UINT32 addr_curr = (1 + (OPJ_UINT32)index_clamped_curr * 2) * 4 + off;
    OPJ_UINT32 addr_target = (OPJ_UINT32)(i) * 2 * 4 + off;

    OPJ_INT32 avg = (a[addr_prev] + a[addr_curr] + 2) >> 2;
    a[addr_target] -= avg;
}
}
