#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 a;
extern OPJ_INT32 l;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 *access_pattern = (OPJ_INT32*)malloc(32 * sizeof(OPJ_INT32));
    if (!access_pattern) return;
    for (l = 0; a > 1; l += 2) { // Strided access: increment index by 2
        access_pattern[l] = a;
        a >>= 1;
    }
    free(access_pattern);
}
