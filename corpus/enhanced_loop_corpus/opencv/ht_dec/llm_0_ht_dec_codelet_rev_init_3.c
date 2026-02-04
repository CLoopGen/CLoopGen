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

extern rev_struct_t *vlcp;
extern int tnum;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < tnum; ++i) {
    OPJ_UINT64 d;
    OPJ_UINT32 d_bits;
    for (int j = 0; j < 1; ++j) {  // Nested single-iteration loop to increase depth
        d = *vlcp->data--;
        d_bits = 8U - ((vlcp->unstuff && ((d & 127) == 127)) ? 1U : 0U);
        vlcp->tmp |= d << vlcp->bits;
        vlcp->bits += d_bits;
        vlcp->unstuff = d > 143;
    }
}
}
