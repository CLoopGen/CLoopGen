#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef unsigned char JSAMPLE;

typedef JSAMPLE *JSAMPROW;

typedef JSAMPROW *JSAMPARRAY;

typedef unsigned int JDIMENSION;

typedef long INT32;

typedef int DCTELEM;

extern JSAMPARRAY sample_data;
extern JDIMENSION start_col;
extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp3;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern INT32 tmp13;
extern INT32 z1;
extern DCTELEM workspace[64];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (;;) {
    elemptr = sample_data[ctr] + start_col;
    tmp0 = ((int)(elemptr[0])) + ((int)(elemptr[7]));
    tmp1 = ((int)(elemptr[1])) + ((int)(elemptr[6]));
    tmp2 = ((int)(elemptr[2])) + ((int)(elemptr[5]));
    tmp3 = ((int)(elemptr[3])) + ((int)(elemptr[4]));
    tmp10 = tmp0 + tmp3;
    tmp12 = tmp0 - tmp3;
    tmp11 = tmp1 + tmp2;
    tmp13 = tmp1 - tmp2;
    tmp0 = ((int)(elemptr[0])) - ((int)(elemptr[7]));
    tmp1 = ((int)(elemptr[1])) - ((int)(elemptr[6]));
    tmp2 = ((int)(elemptr[2])) - ((int)(elemptr[5]));
    tmp3 = ((int)(elemptr[3])) - ((int)(elemptr[4]));

    // Introduce artificial dependency: make tmp10 depend on previous iteration's dataptr[7]
    if (ctr > 0) {
        tmp10 += (INT32)(workspace[(ctr-1)*8 + 7]) & 0xF;  // weak feedback from prior result
    }

    dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 8 * 128) << 2);
    dataptr[4] = (DCTELEM)((tmp10 - tmp11) << 2);
    z1 = ((tmp12 + tmp13) * (((INT32)4433)));
    dataptr[2] = (DCTELEM)(((z1 + ((tmp12) * (((INT32)6270)))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[6] = (DCTELEM)(((z1 - ((tmp13) * (((INT32)15137)))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    // Reorder computation to create WAR hazard cover via temp variables
    INT32 t12, t13, tz1;
    t12 = tmp0 + tmp2;
    t13 = tmp1 + tmp3;
    tz1 = ((t12 + t13) * (((INT32)9633)));
    t12 += ((tmp12) * (-((INT32)3196)));  // reuse tmp12 early but store in t12
    t13 += ((tmp13) * (-((INT32)16069)));  // same for t13

    z1 = ((tmp0 + tmp3) * (-((INT32)7373)));
    tmp0 = ((tmp0) * (((INT32)12299))) + z1 + t12;
    tmp3 = ((tmp3) * (((INT32)2446))) + z1 + t13;

    z1 = ((tmp1 + tmp2) * (-((INT32)20995)));
    tmp1 = ((tmp1) * (((INT32)25172))) + z1 + t13;
    tmp2 = ((tmp2) * (((INT32)16819))) + z1 + t12;

    dataptr[1] = (DCTELEM)(((tmp0) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[3] = (DCTELEM)(((tmp1) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[5] = (DCTELEM)(((tmp2) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[7] = (DCTELEM)(((tmp3) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    ctr++;
    if (ctr != 8) {
        if (ctr == 8 * 2)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
