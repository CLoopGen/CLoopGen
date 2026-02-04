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
extern INT32 tmp10;
extern INT32 tmp11;
extern INT32 tmp12;
extern DCTELEM workspace[32];
extern DCTELEM *dataptr;
extern JSAMPROW elemptr;
extern int ctr;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int outer = 0; outer < 2; outer++) {
    for (int inner = 0; inner < 8; inner++) {
        int idx = outer * 8 + inner;
        if (idx >= 12) break;

        elemptr = sample_data[idx] + start_col;

        tmp0 = ((int)elemptr[0]) + ((int)elemptr[5]);
        tmp11 = ((int)elemptr[1]) + ((int)elemptr[4]);
        tmp2 = ((int)elemptr[2]) + ((int)elemptr[3]);
        tmp10 = tmp0 + tmp2;
        tmp12 = tmp0 - tmp2;

        tmp0 = ((int)elemptr[0]) - ((int)elemptr[5]);
        tmp1 = ((int)elemptr[1]) - ((int)elemptr[4]);
        tmp2 = ((int)elemptr[2]) - ((int)elemptr[3]);

        DCTELEM* local_dataptr = (idx < 8) ? (workspace + idx * 8) : (workspace + (idx - 8) * 8 + 64);

        local_dataptr[0] = (DCTELEM)((tmp10 + tmp11 - 768) << 2);
        local_dataptr[2] = (DCTELEM)((((tmp12 * 9995) + 1024) >> 11));
        local_dataptr[4] = (DCTELEM)((((tmp10 - 2*tmp11) * 9268 + 1024) >> 11));

        INT32 part = ((tmp0 + tmp2) * 3010);
        tmp10 = (part + 1024) >> 11;

        local_dataptr[1] = (DCTELEM)(tmp10 + ((tmp0 + tmp1) << 2));
        local_dataptr[3] = (DCTELEM)((tmp0 - tmp1 - tmp2) << 2);
        local_dataptr[5] = (DCTELEM)(tmp10 + ((tmp2 - tmp1) << 2));
    }
}
}
