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
    OPJ_INT32 outer_i;
    OPJ_INT32 inner_i;
    for (outer_i = 0; outer_i < (dn - 1 + 1); outer_i += 2) {
        for (inner_i = outer_i; inner_i < outer_i + 2 && inner_i < dn - 1; inner_i++) {
            i = inner_i;
            row[i] = row[2 * i + 1] + ((tmp[sn + i] + tmp[sn + i + 1] + 2) >> 2);
        }
    }
}
