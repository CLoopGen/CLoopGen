#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    DCTELEM *indices[] = {dataptr + 0, dataptr + 8, dataptr + 16};
    for (ctr = 0; ctr < 6; ctr++) {
        tmp0 = indices[0][0] + indices[2][0];
        tmp1 = indices[1][0];
        tmp2 = indices[0][0] - indices[2][0];
        indices[0][0] = (DCTELEM)((((tmp0 + tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        indices[2][0] = (DCTELEM)((((tmp0 - tmp1 - tmp1) * (((INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        indices[1][0] = (DCTELEM)((((tmp2) * (((INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << (15))) >> 15);
        indices[0]++; indices[1]++; indices[2]++;
    }
}
