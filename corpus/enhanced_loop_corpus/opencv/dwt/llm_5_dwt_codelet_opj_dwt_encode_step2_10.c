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
    OPJ_UINT32 j = i;
    for (; j + 3 < imax; j += 4) {
        fw[-1] += (fw[-2] + fw[0]) * c;
        if (fw[0] > 1e-5f) {
            fw[1] += (fw[0] + fw[2]) * c;
            fw[3] += (fw[2] + fw[4]) * c;
        } else {
            fw[1] += fw[2] * c;
            fw[3] = fw[2] * c;
        }
        fw[5] += (fw[4] + fw[6]) * c;
        fw += 8;
    }
    i = j;
}
