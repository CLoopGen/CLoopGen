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
    DCTELEM *base_ptr = dataptr + 8 * ctr; // Strided base per iteration
    tmp0 = base_ptr[0] + base_ptr[24];
    tmp1 = base_ptr[8] + base_ptr[16];
    tmp10 = base_ptr[0] - base_ptr[24];
    tmp11 = base_ptr[8] - base_ptr[16];
    base_ptr[0] = (DCTELEM)((tmp0 + tmp1) << 3);
    base_ptr[16] = (DCTELEM)((tmp0 - tmp1) << 3);
    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp0 += ((INT32)1) << (13 - 3 - 1);
    base_ptr[8] = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 - 3));
    base_ptr[24] = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 - 3));
}
}
