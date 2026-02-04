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
DCTELEM *access_order[4] = {dataptr + 0, dataptr + 8, dataptr + 16, dataptr + 24}; // Indirect access via pointer array
for (ctr = 0; ctr < 2; ctr++) {
    tmp0 = *(access_order[0]) + *(access_order[2]);
    tmp1 = *(access_order[1]) + *(access_order[3]);
    tmp10 = *(access_order[0]) - *(access_order[2]);
    tmp11 = *(access_order[1]) - *(access_order[3]);
    *(access_order[0]) = (DCTELEM)((tmp0 + tmp1) << 3);
    *(access_order[3]) = (DCTELEM)((tmp0 - tmp1) << 3);
    tmp0 = ((tmp10 + tmp11) * (((INT32)4433)));
    tmp0 += ((INT32)1) << (13 - 3 - 1);
    *(access_order[1]) = (DCTELEM)((tmp0 + ((tmp10) * (((INT32)6270)))) >> (13 - 3));
    *(access_order[2]) = (DCTELEM)((tmp0 - ((tmp11) * (((INT32)15137)))) >> (13 - 3));
    // Simulate moving to next data segment by updating pointers
    for (int i = 0; i < 4; i++) access_order[i] += 1;
}
}
