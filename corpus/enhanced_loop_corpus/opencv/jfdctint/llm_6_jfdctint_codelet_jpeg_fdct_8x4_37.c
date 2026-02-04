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
for (ctr = 8 - 1; ctr >= 0; ctr--) {
    tmp0 = dataptr[8 * 0] + dataptr[8 * 3] + (((INT32)1) << (2 - 1));
    tmp1 = dataptr[8 * 1] + dataptr[8 * 2];
    tmp10 = dataptr[8 * 0] - dataptr[8 * 3];
    tmp11 = dataptr[8 * 1] - dataptr[8 * 2];
    
    // Introduce temporary variables to break and rewire dependencies
    INT32 t0 = (tmp0 + tmp1) >> 2;
    INT32 t1 = (tmp0 - tmp1) >> 2;
    INT32 t2 = ((tmp10 + tmp11) * ((INT32)4433)) + (((INT32)1) << (13 + 2 - 1));
    INT32 t3 = (t2 + (tmp10 * ((INT32)6270))) >> (13 + 2);
    INT32 t4 = (t2 - (tmp11 * ((INT32)15137))) >> (13 + 2);

    // Eliminate WAW and WAR hazards by writing results only at the end
    dataptr[8 * 0] = (DCTELEM)t0;
    dataptr[8 * 2] = (DCTELEM)t1;
    dataptr[8 * 1] = (DCTELEM)t3;
    dataptr[8 * 3] = (DCTELEM)t4;

    dataptr++;
}
}
