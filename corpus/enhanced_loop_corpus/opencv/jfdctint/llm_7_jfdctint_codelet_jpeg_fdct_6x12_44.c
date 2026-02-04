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
for (;;) {
    JSAMPROW local_elemptr = sample_data[ctr] + start_col;  // Introduce local copy to reduce aliasing effects
    INT32 t0, t1, t2, t10, t11, t12;  // Use distinct temporaries to eliminate WAW and WAR dependencies

    t0 = ((int)(local_elemptr[0])) + ((int)(local_elemptr[5]));
    t11 = ((int)(local_elemptr[1])) + ((int)(local_elemptr[4]));
    t2 = ((int)(local_elemptr[2])) + ((int)(local_elemptr[3]));
    t10 = t0 + t2;
    t12 = t0 - t2;

    INT32 sub0 = ((int)(local_elemptr[0])) - ((int)(local_elemptr[5]));  // Break RAW by computing early and storing
    INT32 sub1 = ((int)(local_elemptr[1])) - ((int)(local_elemptr[4]));
    INT32 sub2 = ((int)(local_elemptr[2])) - ((int)(local_elemptr[3]));

    dataptr[0] = (DCTELEM)((t10 + t11 - 6 * 128) << 2);
    dataptr[2] = (DCTELEM)(((((t12) * (((INT32)((1.224744871) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[4] = (DCTELEM)(((((t10 - t11 - t11) * (((INT32)((0.70710678100000002) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));

    INT32 combined_term = (((((sub0 + sub2) * (((INT32)((0.366025404) * (((INT32)1) << 13) + 0.5))))) + ((INT32)1 << ((13 - 2) - 1))) >> (13 - 2));
    dataptr[1] = (DCTELEM)(combined_term + ((sub0 + sub1) << 2));
    dataptr[3] = (DCTELEM)((sub0 - sub1 - sub2) << 2);
    dataptr[5] = (DCTELEM)(combined_term + ((sub2 - sub1) << 2));

    ctr++;
    if (ctr != 8) {
        if (ctr == 12)
            break;
        dataptr += 8;
    } else
        dataptr = workspace;
}
}
