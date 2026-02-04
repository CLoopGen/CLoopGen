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
    OPJ_INT32 acc = 0;
    for (i = 1; i < dn; i++) {
        acc += tmp[sn + (i - 1)]; 
        row[i] = row[2 * i] + ((acc + tmp[sn + i] + 2) >> 2);
    }
}
