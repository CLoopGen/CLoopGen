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
for (i = 0; i < num; ++i) {
    OPJ_UINT64 d;
    OPJ_UINT32 d_bits;
    if (mrp->size <= 0) {
        d = 0;
    } else {
        d = *mrp->data--;
        mrp->size--;
    }
    d_bits = 8U;
    if (mrp->unstuff && ((d & 127) == 127)) {
        d_bits = 7U;
    }
    mrp->tmp |= d << mrp->bits;
    mrp->bits += d_bits;
    mrp->unstuff = (d > 143);
}
}
