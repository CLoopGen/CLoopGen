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
    for (i = 0; i < sn - 1; i++) {
        OPJ_INT32 index = 2 * i;
        OPJ_INT32 val_left = row[index];
        OPJ_INT32 val_right = row[index + 2];
        OPJ_INT32 avg = (val_left + val_right) >> 1;
        OPJ_INT32 diff = row[index + 1] - avg;
        if (diff > 0) {
            tmp[sn + i] = diff;
        } else {
            tmp[sn + i] = 0;
        }
    }
}
