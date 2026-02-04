#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t OPJ_INT32;

typedef size_t OPJ_SIZE_T;

extern OPJ_INT32 *tmp;
extern  OPJ_INT32 len;
extern  OPJ_SIZE_T stride;
extern OPJ_INT32 i;
extern OPJ_INT32 j;
extern OPJ_INT32 s1;
extern OPJ_INT32 s2;
extern OPJ_INT32 dc;
extern OPJ_INT32 dn;
extern  OPJ_INT32 *in_even;
extern  OPJ_INT32 *in_odd;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    OPJ_INT32 temp_dc = dc;
    OPJ_INT32 temp_s1 = s1;
    for (i = 1, j = 1; i < (len - 2 - !(len & 1)); i += 2, j++) {
        s2 = in_even[(OPJ_SIZE_T)(j + 1) * stride];
        dn = in_odd[(OPJ_SIZE_T)j * stride] - ((temp_s1 + s2 + 2) >> 2);
        tmp[i] = temp_dc;
        tmp[i + 1] = temp_s1 + ((dn + temp_dc) >> 1);
        temp_dc = dn;
        temp_s1 = s2;
    }
    dc = temp_dc;
    s1 = temp_s1;
}
