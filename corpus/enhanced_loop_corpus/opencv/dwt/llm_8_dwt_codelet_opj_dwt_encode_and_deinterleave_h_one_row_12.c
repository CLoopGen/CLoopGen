#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *restrict row;
extern OPJ_INT32 *restrict tmp;
extern  OPJ_INT32 sn;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < sn - 2; i += 2) {
        OPJ_INT32 idx1 = i * 2;
        OPJ_INT32 idx2 = (i + 1) * 2;
        tmp[sn + i] = row[idx1 + 1] - ((row[idx1] + row[idx2]) >> 1);
        if (i + 1 < sn - 1) {
            OPJ_INT32 idx3 = (i + 2) * 2;
            tmp[sn + i + 1] = row[idx2 + 1] - ((row[idx2] + row[idx3]) >> 1);
        }
    }
}
