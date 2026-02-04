#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef long INT32;

typedef int DCTELEM;

extern INT32 tmp0;
extern INT32 tmp1;
extern INT32 tmp2;
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern DCTELEM *dataptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
// Use indirect indexing through a fixed index map to simulate non-regular strided access
static const int index_map[6] = {0, 5, 1, 4, 2, 3};
for (ctr = 0; ctr < 3; ctr++) {
    DCTELEM vals[6];
    for (int i = 0; i < 6; i++) {
        vals[i] = dataptr[index_map[i] * 8]; // Indirect strided read
    }
    tmp0 = vals[0] + vals[1];
    tmp11 = vals[2] + vals[3];
    tmp2 = vals[4] + vals[5];
    tmp10 = tmp0 + tmp2;
    tmp12 = tmp0 - tmp2;
    tmp0 = vals[0] - vals[1];
    tmp1 = vals[2] - vals[3];
    tmp2 = vals[4] - vals[5];
    dataptr[index_map[0]*8] = (DCTELEM)((((tmp10 + tmp11) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 15)) >> 15);
    dataptr[index_map[4]*8] = (DCTELEM)((((tmp12) * (((INT32)((2.1773242160000001) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 15)) >> 15);
    dataptr[index_map[3]*8] = (DCTELEM)((((tmp10 - tmp11 - tmp11) * (((INT32)((1.2570787219999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 15)) >> 15);
    tmp10 = ((tmp0 + tmp2) * (((INT32)((0.65071182900000002) * (((INT32)1) << 13) + 0.5))));
    dataptr[index_map[2]*8] = (DCTELEM)(((tmp10 + ((tmp0 + tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 15)) >> 15);
    dataptr[index_map[5]*8] = (DCTELEM)((((tmp0 - tmp1 - tmp2) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5)))) + ((INT32)1 << 15)) >> 15);
    dataptr[index_map[1]*8] = (DCTELEM)(((tmp10 + ((tmp2 - tmp1) * (((INT32)((1.7777777779999999) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << 15)) >> 15);
    dataptr += 8; // Move dataptr forward as in original
}
}
