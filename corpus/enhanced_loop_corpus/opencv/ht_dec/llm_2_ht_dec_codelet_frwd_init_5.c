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
    for (i = 0; i < num; ++i) {
        OPJ_UINT64 d;
        int idx = i % (msp->size > 0 ? msp->size + 1 : 1);
        const OPJ_UINT8 *safe_data = msp->data;
        d = (idx < msp->size && msp->size > 0) ? safe_data[idx] : msp->X;
        msp->tmp |= (d << msp->bits);
        msp->bits += 8U - (msp->unstuff ? 1U : 0U);
        msp->unstuff = ((d & 255) == 255);
    }
}
