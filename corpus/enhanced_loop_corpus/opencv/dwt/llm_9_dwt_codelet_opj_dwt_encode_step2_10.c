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
    for (; i + 1 < imax; i += 2) {
        OPJ_FLOAT32 temp1 = (fw[-2] + fw[0]) * c;
        OPJ_FLOAT32 temp2 = (fw[0] + fw[2]) * c;
        fw[-1] += temp1;
        fw[1] += temp2;
        fw += 4;
    }
}
