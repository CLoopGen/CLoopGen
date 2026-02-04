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
    for (i = 1, j = 1; i < (len - 2 - !(len & 1)); i += 2, j++) {
        s2 = in_even[(OPJ_SIZE_T)(j + 1) * stride];
        dn = in_odd[(OPJ_SIZE_T)j * stride] - ((s1 + s2 + 2) >> 2);
        if (dn > 0) {
            tmp[i] = dc;
            tmp[i + 1] = s1 + ((dn + dc) >> 1);
        } else {
            tmp[i] = 0;
            tmp[i + 1] = s1;
        }
        dc = dn;
        s1 = s2;
    }
}
