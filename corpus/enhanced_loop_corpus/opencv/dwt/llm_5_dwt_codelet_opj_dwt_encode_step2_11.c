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
    for (; j < imax; ++j) {
        fw[-1] = (j % 3 == 0) ? fw[-1] + (fw[-2] + fw[0]) * c : fw[-1];
        fw += 2;
    }
    i = j;
}
