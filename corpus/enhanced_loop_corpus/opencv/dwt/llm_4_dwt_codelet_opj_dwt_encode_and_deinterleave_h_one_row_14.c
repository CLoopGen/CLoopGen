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
    for (i = 1; i < sn; i++) {
        if (i % 2 == 0) {
            tmp[sn + i] = row[2 * i] - ((row[2 * i + 1] + row[2 * (i - 1) + 1]) >> 1);
        } else {
            tmp[sn + i] = row[2 * i];
        }
    }
}
