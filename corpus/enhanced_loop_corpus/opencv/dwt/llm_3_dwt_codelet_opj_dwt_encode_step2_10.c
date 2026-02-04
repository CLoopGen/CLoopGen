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
    OPJ_FLOAT32 *base = fw;
    OPJ_UINT32 idx[4];
    for (; i + 3 < imax; i += 4) {
        idx[0] = i * 2;     // Strided index generation: access pattern scaled by 2
        idx[1] = i * 2 + 1;
        idx[2] = i * 2 + 2;
        idx[3] = i * 2 + 3;

        base[idx[0] + 7] += (base[idx[0] + 6] + base[idx[0] + 8]) * c;
        base[idx[1] + 7] += (base[idx[1] + 6] + base[idx[1] + 8]) * c;
        base[idx[2] + 7] += (base[idx[2] + 6] + base[idx[2] + 8]) * c;
        base[idx[3] + 7] += (base[idx[3] + 6] + base[idx[3] + 8]) * c;
    }
    fw += (imax / 4) * 8;  // Adjust global fw pointer as in original stride effect
}
