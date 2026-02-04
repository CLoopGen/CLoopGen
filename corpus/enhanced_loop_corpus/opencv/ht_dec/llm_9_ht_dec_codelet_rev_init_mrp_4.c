#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint8_t OPJ_UINT8;

typedef uint64_t OPJ_UINT64;

typedef uint32_t OPJ_UINT32;

typedef int OPJ_BOOL;

typedef struct rev_struct {
    OPJ_UINT8 *data;
    OPJ_UINT64 tmp;
    OPJ_UINT32 bits;
    int size;
    OPJ_BOOL unstuff;
} rev_struct_t;

extern rev_struct_t *mrp;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < num * 2; ++i) {
    OPJ_UINT64 d = 0;
    OPJ_UINT32 d_bits = 1;
    if (i % 2 == 0 && mrp->size > 0) {
        d = *mrp->data--;
        d_bits = 8U - ((mrp->unstuff && ((d & 127) == 127)) ? 1U : 0U);
        mrp->tmp |= d << mrp->bits;
        mrp->bits += d_bits;
        mrp->unstuff = d > 143;
        --mrp->size;
    } else {
        d = (mrp->tmp & 1U);
        mrp->tmp >>= 1U;
        mrp->bits = (mrp->bits > 0) ? mrp->bits - 1U : 0U;
        d_bits = 1U;
    }
}
}
