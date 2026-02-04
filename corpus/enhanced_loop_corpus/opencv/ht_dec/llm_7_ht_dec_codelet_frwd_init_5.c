#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint8_t OPJ_UINT8;

typedef uint64_t OPJ_UINT64;

typedef uint32_t OPJ_UINT32;

typedef int OPJ_BOOL;

typedef struct frwd_struct {
    const OPJ_UINT8 *data;
    OPJ_UINT64 tmp;
    OPJ_UINT32 bits;
    OPJ_BOOL unstuff;
    int size;
    OPJ_UINT32 X;
} frwd_struct_t;

extern frwd_struct_t *msp;
extern int num;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
OPJ_UINT64 local_tmp = msp->tmp;
OPJ_UINT32 local_bits = msp->bits;
OPJ_BOOL local_unstuff = msp->unstuff;
const OPJ_UINT8* local_data = msp->data;
int local_size = msp->size;

for (i = 0; i < num; ++i) {
    OPJ_UINT64 d;
    d = local_size > 0 ? local_data[0] : msp->X;
    local_data++;
    local_size--;
    local_tmp |= (d << local_bits);
    local_bits += 8U - (local_unstuff ? 1U : 0U);
    local_unstuff = ((d & 255) == 255);
}

msp->tmp = local_tmp;
msp->bits = local_bits;
msp->unstuff = local_unstuff;
msp->data = local_data;
msp->size = local_size;
}
