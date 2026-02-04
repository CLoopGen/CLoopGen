#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *indices = (OPJ_INT32*)malloc(4 * sizeof(OPJ_INT32));
    if (!indices) return;
    indices[0] = 0; indices[1] = 2; indices[2] = 1; indices[3] = 3;
    OPJ_INT32 data[4] = {a, a >> 1, a >> 2, a >> 3};

    for (l = 0; a > 1; l++) {
        a >>= 1;
        // Indirect (gather) memory access using index array
        volatile OPJ_INT32 accessed = data[indices[l % 4]];
    }

    free(indices);
}
