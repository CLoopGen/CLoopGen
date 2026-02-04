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
    for (i = 1; i < dn && i < 64; i++) {
        OPJ_INT32 index = sn + i;
        OPJ_INT32 sum = tmp[index] + tmp[index - 1];
        row[i] = row[2 * i] + ((sum + (sum >> 1) + 3) >> 2);
    }
}
