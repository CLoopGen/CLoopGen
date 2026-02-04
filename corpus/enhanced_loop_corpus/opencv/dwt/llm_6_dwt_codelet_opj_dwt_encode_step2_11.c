#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float OPJ_FLOAT32;

typedef uint32_t OPJ_UINT32;

extern OPJ_FLOAT32 *fw;
extern OPJ_FLOAT32 c;
extern OPJ_UINT32 i;
extern OPJ_UINT32 imax;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_UINT32 j;
    for (j = 0; i < imax; ++i, ++j) {
        OPJ_FLOAT32 temp = (fw[-2] + fw[0]) * c;
        fw[-1] += temp;
        if (j % 2 == 0) {
            fw[1] = temp; // Introduce WAW dependency on fw[1] every other iteration
        }
        fw += 2;
    }
}
