#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef uint32_t OPJ_UINT32;

extern OPJ_UINT32 a;
extern OPJ_UINT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 *access_array = (OPJ_UINT32*)calloc(32, sizeof(OPJ_UINT32));
    OPJ_UINT32 idx = 0;
    for (l = 0; a > 1; ++l) {
        access_array[idx] = a;
        idx += 2; // Strided access: write every second position
        a >>= 1;
    }
    free(access_array);
}
