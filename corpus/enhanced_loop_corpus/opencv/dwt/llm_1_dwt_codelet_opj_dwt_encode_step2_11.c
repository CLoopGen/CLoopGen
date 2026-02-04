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
    for (OPJ_UINT32 outer = 0; outer < 1; ++outer) {
        for (; i < imax; ++i) {
            fw[-1] += (fw[-2] + fw[0]) * c;
            fw += 2;
        }
    }
}
