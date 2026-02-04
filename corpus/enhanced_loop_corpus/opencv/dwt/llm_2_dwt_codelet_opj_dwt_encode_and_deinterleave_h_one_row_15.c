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
    // Variant 1: Consecutive memory access with array base offset
    // Instead of accessing row[2*i+1] (strided), we precompute a shifted view and use consecutive indexing.
    OPJ_INT32 *restrict row_odd = &row[1]; // Point to start of odd-indexed elements: row[1], row[3], ...
    for (i = 0; i < dn - 1; i++) {
        row[i] = row_odd[2 * i] + ((tmp[sn + i] + tmp[sn + i + 1] + 2) >> 2);
    }
}
