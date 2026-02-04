#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp10;
extern INT32 tmp11;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (ctr = 0; ctr < 2; ctr++) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 3];
    tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
    tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
    
    // Introduce temporary variables to break WAW and WAR dependencies
    INT32 new_tmp0 = (tmp0 + tmp1) << 3;
    INT32 new_tmp1 = (tmp0 - tmp1) << 3;
    INT32 new_tmp2 = ((tmp10 + tmp11) * (((INT32)4433))) + (((INT32)1) << (13 - 3 - 1));
    INT32 result1 = (new_tmp2 + ((tmp10) * (((INT32)6270)))) >> (13 - 3);
    INT32 result2 = (new_tmp2 - ((tmp11) * (((INT32)15137)))) >> (13 - 3);

    // Eliminate write-after-write on dataptr by using temporaries and updating only once
    DCTELEM save0 = (DCTELEM)new_tmp0;
    DCTELEM save1 = (DCTELEM)result1;
    DCTELEM save2 = (DCTELEM)new_tmp1;
    DCTELEM save3 = (DCTELEM)result2;

    dataptr[8 * 0] = save0;
    dataptr[8 * 1] = save1;
    dataptr[8 * 2] = save2;
    dataptr[8 * 3] = save3;

    dataptr++;
}
}
