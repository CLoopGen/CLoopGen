#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

extern OPJ_INT32 *restrict row;
extern OPJ_INT32 *restrict tmp;
extern  OPJ_INT32 sn;
extern  OPJ_INT32 dn;
extern OPJ_INT32 i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < dn; i += 2) {
        if (i + 1 < dn) {
            row[i]     = row[2 * i + 1] + ((tmp[sn + i] + tmp[sn + i + 1] + 3) >> 2);
            row[i + 1] = row[2 * (i + 1) + 1] + ((tmp[sn + i + 1] + tmp[sn + i + 2] + 3) >> 2);
        }
    }
}
