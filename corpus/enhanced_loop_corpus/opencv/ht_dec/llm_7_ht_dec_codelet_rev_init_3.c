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
OPJ_UINT64 local_tmp = vlcp->tmp;
OPJ_UINT32 local_bits = vlcp->bits;
OPJ_BOOL local_unstuff = vlcp->unstuff;
OPJ_UINT8 *local_data = vlcp->data;

for (i = 0; i < tnum; ++i) {
    OPJ_UINT64 d = *local_data--;
    OPJ_UINT32 d_bits = 8U - ((local_unstuff && ((d & 127) == 127)) ? 1U : 0U);
    local_tmp |= d << local_bits;
    local_bits += d_bits;
    local_unstuff = d > 143;
}

vlcp->tmp = local_tmp;
vlcp->bits = local_bits;
vlcp->unstuff = local_unstuff;
vlcp->data = local_data;
}
