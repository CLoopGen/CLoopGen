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
    for (; i + 7 < imax; i += 8) {
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw[1] += (fw[0] + fw[2]) * c;
        fw[3] += (fw[2] + fw[4]) * c;
        fw[5] += (fw[4] + fw[6]) * c;
        fw[7] += (fw[6] + fw[8]) * c;
        fw[9] += (fw[8] + fw[10]) * c;
        fw[11] += (fw[10] + fw[12]) * c;
        fw[13] += (fw[12] + fw[14]) * c;
        fw += 16;
    }
}
