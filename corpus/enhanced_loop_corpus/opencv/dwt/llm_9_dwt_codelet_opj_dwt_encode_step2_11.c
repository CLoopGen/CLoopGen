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
    OPJ_UINT32 step = 4;
    for (; i < imax; i += step) {
        // Reduced effective trip count with same overall coverage
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw += 2;
        if (i + 1 >= imax) break;
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw += 2;
        if (i + 2 >= imax) break;
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw += 2;
        if (i + 3 >= imax) break;
        fw[-1] += (fw[-2] + fw[0]) * c;
        fw += 2;
    }
}
