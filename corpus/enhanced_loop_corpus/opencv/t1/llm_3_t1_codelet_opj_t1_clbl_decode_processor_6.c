#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_INT32 *restrict datap;
extern OPJ_UINT32 i;
extern OPJ_UINT32 cblk_size;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *indices = (OPJ_INT32*)malloc(cblk_size * sizeof(OPJ_INT32));
    if (!indices) return;
    for (OPJ_UINT32 j = 0; j < cblk_size; ++j) {
        indices[j] = j;
    }
    for (i = 0; i < cblk_size; ++i) {
        datap[indices[i]] /= 2;
    }
    free(indices);
}
